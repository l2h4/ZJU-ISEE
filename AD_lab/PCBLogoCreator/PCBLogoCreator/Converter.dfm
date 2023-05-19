object ConverterForm: TConverterForm
  Left = 18
  Top = 9
  BorderStyle = bsDialog
  Caption = 'PCB Logo Creator'
  ClientHeight = 265
  ClientWidth = 511
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 200
    Height = 200
    Center = True
    Proportional = True
    Stretch = True
  end
  object XStatusBar1: TXStatusBar
    Left = 0
    Top = 240
    Width = 511
    Height = 25
    Enabled = False
    Panels = <>
    ParentShowHint = False
    ShowHint = False
    SimplePanel = True
    SimpleText = '   Ready...'
    SizeGrip = False
  end
  object XPProgressBar1: TXPProgressBar
    Left = 76
    Top = 247
    Width = 423
    Height = 15
    Position = 0
    Step = 0
  end
  object GroupBox1: TGroupBox
    Left = 215
    Top = 5
    Width = 200
    Height = 231
    Caption = ' Converter Options '
    TabOrder = 1
    object lImageSize: TLabel
      Left = 75
      Top = 72
      Width = 46
      Height = 13
      Caption = ' 0 x 0 mils'
    end
    object ImageSizeLabel: TLabel
      Left = 13
      Top = 72
      Width = 59
      Height = 13
      Caption = 'Image size : '
    end
    object lScalingFactor: TLabel
      Left = 13
      Top = 131
      Width = 85
      Height = 13
      Caption = 'Scaling Factor %: '
    end
    object Label2: TLabel
      Left = 13
      Top = 21
      Width = 66
      Height = 13
      Caption = 'Board Layer : '
    end
    object lImageSizeMM: TLabel
      Left = 75
      Top = 90
      Width = 45
      Height = 13
      Caption = ' 0 x 0 mm'
    end
    object cbNegative: TCheckBox
      Left = 13
      Top = 157
      Width = 97
      Height = 21
      Caption = 'Negative'
      TabOrder = 0
    end
    object cbMirrorX: TCheckBox
      Left = 13
      Top = 178
      Width = 58
      Height = 21
      Caption = 'Mirror X'
      TabOrder = 1
    end
    object cbMirrorY: TCheckBox
      Left = 13
      Top = 199
      Width = 56
      Height = 21
      Caption = 'Mirror Y'
      TabOrder = 2
    end
    object UpDown1: TUpDown
      Left = 150
      Top = 127
      Width = 15
      Height = 21
      Associate = eScalingFactor
      Min = 0
      Max = 1000
      Position = 100
      TabOrder = 3
      Wrap = False
    end
    object eScalingFactor: TEdit
      Left = 110
      Top = 127
      Width = 40
      Height = 21
      TabOrder = 4
      Text = '100'
      OnChange = eScalingFactorChange
    end
    object ComboBoxLayers: TComboBox
      Left = 13
      Top = 36
      Width = 120
      Height = 21
      ItemHeight = 13
      TabOrder = 5
      Text = 'Top Layer'
      Items.Strings = (
        'Top Layer'
        'Mid Layer 1'
        'Mid Layer 2'
        'Mid Layer 3'
        'Mid Layer 4'
        'Mid Layer 5'
        'Mid Layer 6'
        'Mid Layer 7'
        'Mid Layer 8'
        'Mid Layer 9'
        'Mid Layer 10'
        'Mid Layer 11'
        'Mid Layer 12'
        'Mid Layer 13'
        'Mid Layer 14'
        'Mid Layer 15'
        'Mid Layer 16'
        'Mid Layer 17'
        'Mid Layer 18'
        'Mid Layer 19'
        'Mid Layer 20'
        'Mid Layer 21'
        'Mid Layer 22'
        'Mid Layer 23'
        'Mid Layer 24'
        'Mid Layer 25'
        'Mid Layer 26'
        'Mid Layer 27'
        'Mid Layer 28'
        'Mid Layer 29'
        'Mid Layer 30'
        'Bottom Layer'
        'Top Overlay'
        'Bottom Overlay'
        'Top Paste'
        'Bottom Paste'
        'Top Solder Mask'
        'Bottom Solder Mask'
        'Internal Plane 1'
        'Internal Plane 2'
        'Internal Plane 3'
        'Internal Plane 4'
        'Internal Plane 5'
        'Internal Plane 6'
        'Internal Plane 7'
        'Internal Plane 8'
        'Internal Plane 9'
        'Internal Plane 10'
        'Internal Plane 11'
        'Internal Plane 12'
        'Internal Plane 13'
        'Internal Plane 14'
        'Internal Plane 15'
        'Internal Plane 16'
        'Drill Guide'
        'Keep Out Layer'
        'Mechanical Layer 1'
        'Mechanical Layer 2'
        'Mechanical Layer 3'
        'Mechanical Layer 4'
        'Mechanical Layer 5'
        'Mechanical Layer 6'
        'Mechanical Layer 7'
        'Mechanical Layer 8'
        'Mechanical Layer 9'
        'Mechanical Layer 10'
        'Mechanical Layer 11'
        'Mechanical Layer 12'
        'Mechanical Layer 13'
        'Mechanical Layer 14'
        'Mechanical Layer 15'
        'Mechanical Layer 16'
        'Drill Drawing'
        'Multi Layer'
        'BackGround'
        'Connect Layer'
        'DRC Errors'
        'Highlight Layer'
        'Grid Color 1'
        'Grid Color 10'
        'Pad Hole Layer'
        'Via Hole Layer')
    end
  end
  object exitbutton: TButton
    Left = 424
    Top = 66
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 3
    OnClick = exitbuttonClick
  end
  object convertbutton: TButton
    Left = 424
    Top = 38
    Width = 75
    Height = 25
    Caption = 'Convert'
    TabOrder = 4
    OnClick = convertbuttonClick
  end
  object loadbutton: TButton
    Left = 424
    Top = 10
    Width = 75
    Height = 25
    Caption = 'Load'
    TabOrder = 5
    OnClick = loadbuttonClick
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 43
    Top = 105
  end
end
