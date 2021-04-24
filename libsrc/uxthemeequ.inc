!uxtheme support.
!17.04.2021 revision
!mikeduglas 2021
!mikeduglas@yandex.ru

HTHEME                        EQUATE(HANDLE)

!- Defines the options for the DrawThemeTextEx function.
!- https://docs.microsoft.com/en-us/windows/win32/api/uxtheme/ns-uxtheme-dttopts
typDTTOPTS                    GROUP, TYPE
dwSize                          UNSIGNED
dwFlags                         UNSIGNED
crText                          COLORREF
crBorder                        COLORREF
crShadow                        COLORREF
iTextShadowType                 LONG
ptShadowOffset                  LIKE(POINT)
iBorderSize                     LONG
iFontPropId                     LONG
iColorPropId                    LONG
iStateId                        LONG
fApplyOverlay                   BOOL
iGlowSize                       LONG
pfnDrawTextCallback             LONG    !- DTT_CALLBACK_PROC
lParam                          LONG
                              END

!- Values used in GetThemeSysColorBrush.
TMT_SCROLLBAR                 EQUATE(0641h) !The color of scroll bars.
TMT_BACKGROUND                EQUATE(0642h) !The color of the background.
TMT_ACTIVECAPTION             EQUATE(0643h) !The color of the caption area on an active window.
TMT_INACTIVECAPTION           EQUATE(0644h) !The color of the caption area on an inactive window.
TMT_WINDOW                    EQUATE(0646h) !The color of a window.
TMT_WINDOWFRAME               EQUATE(0647h) !The color of the frame around a window.
TMT_MENUTEXT                  EQUATE(0648h) !The color of text drawn on a menu.
TMT_WINDOWTEXT                EQUATE(0649h) !The color of text drawn in a window.
TMT_CAPTIONTEXT               EQUATE(064Ah) !The color of text drawn in the caption area of an active window.
TMT_ACTIVEBORDER              EQUATE(064Bh) !The color of the border around an active window.
TMT_INACTIVEBORDER            EQUATE(064Ch) !The color of the border around an inactive window.
TMT_APPWORKSPACE              EQUATE(064Dh) !The color of the application workspace.
TMT_HIGHLIGHT                 EQUATE(064Eh) !The color of a highlight.
TMT_HIGHLIGHTTEXT             EQUATE(064Fh) !The color of highlighted text.
TMT_BTNFACE                   EQUATE(0650h) !The color of a button face.
TMT_BTNSHADOW                 EQUATE(0651h) !The color of the shadow underneath a button.
TMT_GRAYTEXT                  EQUATE(0652h) !The color of dimmed text.
TMT_BTNTEXT                   EQUATE(0653h) !The color of text contained within a button.
TMT_INACTIVECAPTIONTEXT       EQUATE(0654h) !The color of the text in the caption area of an inactive window.
TMT_BTNHIGHLIGHT              EQUATE(0655h) !The color of the highlight around a button.
TMT_DKSHADOW3D                EQUATE(0656h) !The color of three-dimensional dark shadows.
TMT_LIGHT3D                   EQUATE(0657h) !The color of three-dimensional light areas.
TMT_INFOTEXT                  EQUATE(0658h) !The color of informational text.
TMT_INFOBK                    EQUATE(0659h) !The color of the background behind informational text.
TMT_BUTTONALTERNATEFACE       EQUATE(065Ah) !The color of the alternate face of a button.
TMT_HOTTRACKING               EQUATE(065Bh) !The color of highlight applied when a user moves the mouse over a control.
TMT_GRADIENTACTIVECAPTION     EQUATE(065Ch) !The gradient color applied to the caption area of an active window.
TMT_GRADIENTINACTIVECAPTION   EQUATE(065Dh) !The gradient color applied to the caption area of an inactive window.
TMT_MENUHILIGHT               EQUATE(065Eh) !The color of highlight drawn on a menu item when the user moves the mouse over it.
TMT_MENUBAR                   EQUATE(065Fh) !The color of the menu bar.

!- Values used in GetThemeSysFont.
TMT_CAPTIONFONT               EQUATE(0321h) !The font used by window captions.
TMT_SMALLCAPTIONFONT          EQUATE(0322h) !The font used by window small captions.
TMT_MENUFONT                  EQUATE(0323h) !The font used by menus.
TMT_STATUSFONT                EQUATE(0324h) !The font used in status messages.
TMT_MSGBOXFONT                EQUATE(0325h) !The font used to display messages in a message box.
TMT_ICONTITLEFONT             EQUATE(0326h) !The font used for icons.
