!uxtheme support.
!17.04.2021 revision
!mikeduglas 2021
!mikeduglas@yandex.ru

  INCLUDE('winapi.inc'), ONCE
  INCLUDE('uxthemeequ.inc'), ONCE

TUxTheme                      CLASS, TYPE, MODULE('uxtheme.clw'), LINK('uxtheme.clw')
hTheme                          HTHEME, PROTECTED

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

OpenThemeData                   PROCEDURE(TWnd wnd, STRING pClassList), HTHEME, PROC
CloseThemeData                  PROCEDURE(), HRESULT, PROC
GetThemeSysColorBrush           PROCEDURE(LONG iColorId),HBRUSH
GetThemeSysFont                 PROCEDURE(LONG iFontId, *tagLOGFONTW plf), HRESULT, PROC
DrawThemeTextEx                 PROCEDURE(TDC dc, LONG iPartId, LONG iStateId, |
                                  STRING pText, UNSIGNED dwTextFlags, TRect pRect, typDTTOPTS pOptions), HRESULT, PROC
HitTestThemeBackground          PROCEDURE(TDC dc, LONG iPartId, LONG iStateId, UNSIGNED dwOptions, |
                                  TRect pRect, HRGN hrgn, POINT ptTest, *USHORT pwHitTestCode), HRESULT, PROC
                              END
