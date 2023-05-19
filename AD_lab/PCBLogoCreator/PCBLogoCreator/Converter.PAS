{...................................................................................}
{ Summary Converts a monochrome image as a PCB Logo into a series of thin           }
{         PCB tracks that can be placed on a PCB document as a logo.                }
{                                                                                   }
{         Scan Pixel algorithm provided by                                          }
{         Paul D. Fincato                                                           }
{         fincato@infinet.com                                                       }
{                                                                                   }
{        Version 1.2                                                                }
{        Change scale to percentage                                                 }
{        Allow not integer values for scaling (bitmap can be scaled less then 1)    }
{        Make changes to form as the Image Size string was getting clipped          }
{        Don't exit program on non b/w file type                                    }
{        Add Metric support                                                         }
{        Darren Moore Mar 2005                                                      }
{                                                                                   }
{       Version 1.3                                                                 }
{       Fixed bug flippedX Height, changed to Width                                 }
{       Fixed bug with scaling                                                      }
{          The way the scaling was done, if the size was less then 100%             }
{           the image was not drawn correctly                                       }
{         Removed data being saved to an intermediate file                          }
{         Made other changes to improve speed (overall speed now x 2)               }
{		  Darren Moore Jul 2005														}
{                                                                                   }
{...................................................................................}

{......................................................................................................................}
Procedure RunConverterScript;
Begin
    // Set the default layer to Top layer.
    ConverterForm.ComboBoxLayers.ItemIndex := 0;
    ConverterForm.ConvertButton.Enabled    := False;
    ConverterForm.ShowModal;
End;
{......................................................................................................................}

{......................................................................................................................}
Procedure TConverterForm.eScalingFactorChange(Sender: TObject);
Begin
    lImageSize.Caption := IntToStr(Image1.Picture.Width  * (eScalingFactor.Text / 100)) + ' x ' +
                          IntToStr(Image1.Picture.Height * (eScalingFactor.Text / 100)) + ' mils';
    lImageSizeMM.Caption := IntToStr(Image1.Picture.Width  * (eScalingFactor.Text / 3937)) + ' x ' +
                          IntToStr(Image1.Picture.Height * (eScalingFactor.Text / 3937)) + ' mm';
End;
{......................................................................................................................}

{......................................................................................................................}
Procedure TConverterForm.loadbuttonClick(Sender: TObject);
Begin
    If OpenPictureDialog1.Execute then
    Begin
        XPProgressBar1.Position := 0;
        XStatusBar1.SimpleText  := '  Loading...';
        XStatusBar1.Update;

        // loading a monochrome bitmap only
        Image1.Picture.LoadFromFile(OpenPictureDialog1.FileName);

        // Check if image is monochrome, otherwise prompt a warning
        If Image1.Picture.Bitmap.PixelFormat <> pf1bit Then
        Begin
            ShowWarning('The image file must be monochrome!');
              Exit;
        End;

        lImageSize.Caption := IntToStr(Image1.Picture.Width)  + ' x ' +
                              IntToStr(Image1.Picture.Height) + ' mils';
        lImageSizeMM.Caption := IntToStr(Image1.Picture.Width  * (eScalingFactor.Text / 3937)) + ' x ' +
                                IntToStr(Image1.Picture.Height * (eScalingFactor.Text / 3937)) + ' mm';

        convertbutton.Enabled  := True;
        XStatusBar1.SimpleText := '  Ready...';
        XStatusBar1.Update;
    End;
End;
{......................................................................................................................}

{......................................................................................................................}
Procedure TConverterForm.convertbuttonClick(Sender: TObject);
Var
    x, y, xt, FlipY, FlipX  : Integer;
    PixelColor              : TColor;
    Start                   : Boolean;
    PCBBoard                : IPCB_Board;
    PCBLayer                : TLayer;
    ScaleFactor             : Integer;
    PCBTrack                : IPCB_Track;
    Sheet                   : IPCB_Sheet;
    OffSet                  : TCoord;
    BaseX1, BaseX2, BaseY   : TCoord;

Begin
    Screen.Cursor      := crHourGlass;
    XPProgressBar1.Max := Image1.Picture.Height;

   // Create a standalone blank PCB document
    CreateNewDocumentFromDocumentKind('PCB');

    // GetCurrentPCBBoard returns a IPCB_Board type.
    PCBBoard := PCBServer.GetCurrentPCBBoard;
    If PCBBoard = Nil Then
    Begin
        ShowWarning('A PCB document was not created properly.');
        Exit;
    End
    Else
    Begin
        PCBBoard   := PCBServer.GetCurrentPCBBoard;
        PCBLayer   := String2Layer(ComboBoxLayers.Items[ComboBoxLayers.ItemIndex]);
        ScaleFactor := StrToInt(eScalingFactor.Text)/100;
        // ensure the layer selected is displayed in the PCB workspace
        PCBBoard.LayerIsDisplayed[PCBLayer] := True;
        Sheet  := PCBBoard.PCBSheet;
        OffSet := MilsToCoord(100);
    End;
	xt := 0;
	// do this calc here once to help speed up the loop..
	If (cbMirrorX.Checked) Then
    Begin
		BaseX1  := Sheet.SheetX + Offset - MilsToCoord(ScaleFactor/3);
		BaseX2  := Sheet.SheetX + Offset + MilsToCoord((ScaleFactor/3));
	End
	Else
	Begin
       	BaseX1  := Sheet.SheetX + Offset + MilsToCoord(ScaleFactor/3);
        BaseX2  := Sheet.SheetX + Offset - MilsToCoord((ScaleFactor/3));
	End;

	BaseY   := Sheet.SheetY + Offset;

	XStatusBar1.SimpleText  := ' Converting...';
	XStatusBar1.Update;

    For Y := 0 to Image1.Picture.Height Do
    Begin
        XPProgressBar1.Position := Y;
        XPProgressBar1.Update;

        If (cbMirrorY.Checked) Then
            FlipY := Y
        Else
            FlipY := Abs(Y - Image1.Picture.Height);

		// Denotes the start of a line on a row of an image
        Start := False;

        For  X := 0 To Image1.Picture.Width Do
        Begin
            PixelColor := Image1.Canvas.Pixels[x,y];

            If cbMirrorX.Checked Then
                FlipX := abs(X - Image1.Picture.Width)
            Else
                FlipX  := X;

            If (cbNegative.Checked) Then
            Begin
                Case PixelColor Of
                     clWhite :
                        If Not (Start) Then
                        Begin
                             xt    := FlipX;
                             Start := True;
                        End;

                     clBlack :
                        Begin
                            If (Start) Then
                            Begin
                            // place a new track on the blank PCB
                            PCBTrack       := PCBServer.PCBObjectFactory(eTrackObject, eNoDimension, eCreate_Default);
                            PCBTrack.Width := MilsToCoord(ScaleFactor);
                            PCBTrack.X1    := BaseX1 + MilsToCoord(xt * ScaleFactor);
                            PCBTrack.Y1    := BaseY + MilsToCoord(FlipY * ScaleFactor);
                            PCBTrack.X2    := BaseX2 + MilsToCoord(FlipX * ScaleFactor);
                            PCBTrack.Y2    := PCBTrack.Y1;
                            PCBTrack.Layer := PCBLayer;
                            PCBBoard.AddPCBObject(PCBTrack);
                            Start := False;
                            End;
                        End;
                 End;
            End
            Else
            Begin
                Case PixelColor Of
                    clBlack:
                        If Not (Start) Then
                        Begin
                            xt    := FlipX;
                            Start := True;
                        End;

                    clWhite:
                        Begin
                            If (Start) Then
                            Begin
                            // place a new track on the blank PCB
                            PCBTrack       := PCBServer.PCBObjectFactory(eTrackObject, eNoDimension, eCreate_Default);
                            PCBTrack.Width := MilsToCoord(ScaleFactor);
                            PCBTrack.X1    := BaseX1 + MilsToCoord(xt * ScaleFactor);
                            PCBTrack.Y1    := BaseY + MilsToCoord(FlipY * ScaleFactor);
                            PCBTrack.X2    := BaseX2 + MilsToCoord(FlipX * ScaleFactor);
                            PCBTrack.Y2    := PCBTrack.Y1;
                            PCBTrack.Layer := PCBLayer;
                            PCBBoard.AddPCBObject(PCBTrack);
                            Start := False;
                            End;
                        End;
                 End;
            End;
        End;
            If Start Then
                Begin
            // place a new track on the blank PCB
            PCBTrack       := PCBServer.PCBObjectFactory(eTrackObject, eNoDimension, eCreate_Default);
            PCBTrack.Width := MilsToCoord(ScaleFactor);
            PCBTrack.X1    := BaseX1 + MilsToCoord(xt * ScaleFactor);
            PCBTrack.Y1    := BaseY + MilsToCoord(FlipY * ScaleFactor);
            PCBTrack.X2    := BaseX2 + MilsToCoord(FlipX * ScaleFactor);
            PCBTrack.Y2    := PCBTrack.Y1;
            PCBTrack.Layer := PCBLayer;
            PCBBoard.AddPCBObject(PCBTrack);
            End;

        End;

    Client.SendMessage('PCB:Zoom', 'Action=All' , 255, Client.CurrentView);

    Screen.Cursor          := crArrow;
    XStatusBar1.SimpleText := ' Done...';
    XStatusBar1.Update;

    // Hide this form when a PCB document is created and a new logo added..
    ConverterForm.Hide;

    // toggle buttons
    LoadButton.Enabled    := True;

    // Unhide form
    ConverterForm.Show;
End;
{......................................................................................................................}

{......................................................................................................................}
Procedure TConverterForm.exitbuttonClick(Sender: TObject);
Begin
    Close;
End;
{......................................................................................................................}



