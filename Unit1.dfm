object Form1: TForm1
  Left = 525
  Top = 380
  Width = 664
  Height = 268
  Caption = #1050#1091#1088#1089#1086#1074#1086#1081' '#1048#1086#1082#1096#1072' '#1044'.'#1040'. '#1055#1054#1079'-21'
  Color = 11599797
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object SG: TStringGrid
    Left = 8
    Top = 8
    Width = 633
    Height = 177
    ColCount = 8
    DefaultColWidth = 77
    FixedCols = 0
    RowCount = 2
    TabOrder = 1
    Visible = False
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 633
    Height = 113
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1087#1077#1088#1074#1091#1102' '#1079#1072#1087#1080#1089#1100' '#1092#1072#1081#1083#1072
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 573
      Height = 13
      Caption = 
        #1053#1072#1079#1074#1072#1085#1080#1077' '#1074#1099#1089#1090#1072#1074#1082#1080'         '#1052#1077#1089#1090#1086' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103'       '#1054#1088#1075#1072#1085#1080#1079#1072#1090#1086#1088'    ' +
        '               '#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1101#1082#1089#1087#1086#1079#1080#1094'.  '#1062#1077#1085#1072' '#1087#1086#1089#1077#1097#1077#1085#1080#1103
    end
    object Label2: TLabel
      Left = 48
      Top = 64
      Width = 73
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1079#1072#1087#1080#1089#1080
      Visible = False
    end
    object Edit1: TEdit
      Left = 16
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 136
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 256
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 376
      Top = 40
      Width = 129
      Height = 21
      TabOrder = 3
    end
    object Edit5: TEdit
      Left = 504
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object ComboBox1: TComboBox
      Left = 200
      Top = 80
      Width = 145
      Height = 21
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 5
      Text = #1059#1085#1080#1074#1077#1088#1089#1072#1083#1100#1085#1072#1103
      Items.Strings = (
        #1059#1085#1080#1074#1077#1088#1089#1072#1083#1100#1085#1072#1103
        #1057#1087#1077#1094#1080#1072#1083#1080#1079#1080#1088#1086#1074#1072#1085#1085#1072#1103
        #1061#1091#1076#1086#1078#1077#1089#1090#1074#1077#1085#1085#1072#1103)
    end
    object DateTimePicker1: TDateTimePicker
      Left = 352
      Top = 80
      Width = 97
      Height = 21
      CalAlignment = dtaLeft
      Date = 43538.6250904977
      Time = 43538.6250904977
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 6
    end
    object DateTimePicker2: TDateTimePicker
      Left = 456
      Top = 80
      Width = 81
      Height = 21
      CalAlignment = dtaLeft
      Date = 43538.6253690625
      Time = 43538.6253690625
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 7
    end
    object Button1: TButton
      Left = 544
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Go!'
      TabOrder = 8
      OnClick = Button1Click
    end
    object Edit6: TEdit
      Left = 40
      Top = 80
      Width = 89
      Height = 21
      TabOrder = 9
      Text = '1'
      Visible = False
    end
  end
  object MainMenu1: TMainMenu
    Left = 624
    Top = 336
    object N1: TMenuItem
      Caption = #1056#1072#1073#1086#1090#1072' '#1089' '#1092#1072#1081#1083#1086#1084
      Checked = True
      OnClick = N1Click
      object N3: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100' '#1092#1072#1081#1083
        Checked = True
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100' '#1074' '#1082#1086#1085#1077#1094' '#1092#1072#1081#1083#1072
        Checked = True
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100' '#1087#1086' '#1085#1086#1084#1077#1088#1091
        Checked = True
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089#1086#1076#1077#1088#1078#1080#1084#1086#1077' '#1092#1072#1081#1083#1072
        Checked = True
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100' '#1087#1086' '#1085#1086#1084#1077#1088#1091
        Checked = True
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1074#1099#1089#1090#1072#1074#1086#1082' '#1087#1086' '#1090#1080#1087#1091
        Checked = True
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1089#1088#1086#1082#1072' '#1074#1099#1089#1090#1072#1074#1082#1080
        Checked = True
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1054#1090#1073#1086#1088' '#1074#1099#1089#1090#1072#1074#1086#1082' '#1087#1086' '#1082#1086#1083'-'#1074#1091' '#1101#1082#1089#1087#1086#1079#1080#1094#1080#1081
        Checked = True
        OnClick = N10Click
      end
      object N11: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1092#1072#1081#1083
        Checked = True
        OnClick = N11Click
      end
      object N12: TMenuItem
        Caption = #1056#1077#1079#1077#1088#1074#1085#1072#1103' '#1082#1086#1087#1080#1103' '#1092#1072#1081#1083#1072
        Checked = True
        OnClick = N12Click
      end
      object N13: TMenuItem
        Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1092#1072#1081#1083#1072
        Checked = True
        OnClick = N13Click
      end
    end
    object N2: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N2Click
    end
  end
end
