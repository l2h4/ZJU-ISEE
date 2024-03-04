onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib DataRam_opt

do {wave.do}

view wave
view structure
view signals

do {DataRam.udo}

run -all

quit -force
