@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION
setlocal
REM go to the folder where this bat script is located
cd /d %~dp0

set /a EXPECTED_CLI_MAJOR=0
set /a EXPECTED_CLI_MINOR=18

FOR %%I IN (.) DO SET DIRECTORY_NAME=%%~nI%%~xI

where /q arduino-cli
IF ERRORLEVEL 1 (
    GOTO NOTINPATHERROR
)

REM parse arduino-cli version
FOR /F "tokens=1-3 delims==." %%I IN ('arduino-cli version') DO (
    FOR /F "tokens=1-3 delims== " %%X IN ('echo %%I') DO (
        set /A CLI_MAJOR=%%Z
    )
    SET /A CLI_MINOR=%%J
    FOR /F "tokens=1-3 delims== " %%X IN ('echo %%K') DO (
        set /A CLI_REV=%%X
    )
)

if !CLI_MINOR! LSS !EXPECTED_CLI_MINOR! (
    GOTO UPGRADECLI
)

if !CLI_MAJOR! NEQ !EXPECTED_CLI_MAJOR! (
    echo You're using an untested version of Arduino CLI, this might cause issues (found: %CLI_MAJOR%.%CLI_MINOR%.%CLI_REV%, expected: %EXPECTED_CLI_MAJOR%.%EXPECTED_CLI_MINOR%.x )
) else (
    if !CLI_MINOR! NEQ !EXPECTED_CLI_MINOR! (
        echo You're using an untested version of Arduino CLI, this might cause issues (found: %CLI_MAJOR%.%CLI_MINOR%.%CLI_REV%, expected: %EXPECTED_CLI_MAJOR%.%EXPECTED_CLI_MINOR%.x )
    )
)

echo Finding Arduino Mbed core...

(arduino-cli core list  2> nul) | findstr "arduino:mbed_nano"
IF %ERRORLEVEL% NEQ 0 (
    GOTO INSTALLMBEDCORE
)

:AFTERINSTALLMBEDCORE

echo Finding Arduino Mbed core OK

echo Finding Arduino Nano 33 BLE...

set COM_PORT=""

for /f "tokens=1" %%i in ('arduino-cli board list ^| findstr "Arduino Nano 33 BLE" ^| findstr "COM"') do (
    set COM_PORT=%%i
)

IF %COM_PORT% == "" (
    GOTO NOTCONNECTED
)

echo Finding Arduino Nano 33 BLE OK at %COM_PORT%

(arduino-cli core list  2> nul) | findstr "arduino:mbed_nano"
IF %ERRORLEVEL% NEQ 0 (
    set FQBN="arduino:mbed:nano33ble"
) ELSE (
    set FQBN="arduino:mbed_nano:nano33ble"
)

CALL arduino-cli upload -p %COM_PORT% --fqbn %FQBN% --input-dir .

IF %ERRORLEVEL% NEQ 0 (
    GOTO FLASHINGFAILEDERROR
)

echo Flashed your Arduino Nano 33 BLE development board
echo To set up your development with Edge Impulse, run 'edge-impulse-daemon'
echo To run your impulse on your development board, run 'edge-impulse-run-impulse'

@pause
exit /b 0

:NOTINPATHERROR
echo Cannot find 'arduino-cli' in your PATH. Install the Arduino CLI before you continue
echo Installation instructions: https://arduino.github.io/arduino-cli/latest/
@pause
exit /b 1

:INSTALLMBEDCORE
echo Installing Arduino Mbed core...
arduino-cli core update-index
arduino-cli core install arduino:mbed_nano@4.0.2
echo Installing Arduino Mbed core OK
GOTO AFTERINSTALLMBEDCORE

:NOTCONNECTED
echo Cannot find a connected Arduino Nano 33 BLE development board via 'arduino-cli board list'
echo If your board is connected, double-tap on the RESET button to bring the board in recovery mode
@pause
exit /b 1

:UPGRADECLI
echo You need to upgrade your Arduino CLI version (now: %CLI_MAJOR%.%CLI_MINOR%.%CLI_REV%, but required: %EXPECTED_CLI_MAJOR%.%EXPECTED_CLI_MINOR%.x or higher)
echo See https://arduino.github.io/arduino-cli/installation/ for upgrade instructions
@pause
exit /b 1

:FLASHINGFAILEDERROR
@pause
exit /b %ERRORLEVEL%
