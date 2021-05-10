!Base Windows classes
!10.05.2021 revision
!mikeduglas (c) 2019-2021
!mikeduglas@yandex.ru, mikeduglas66@gmail.com

  INCLUDE('svapi.inc'), ONCE

!- means that a method expects UTF-16LE encoded string
STRINGW                       EQUATE(STRING)

  MAP
    MODULE('winapi.clw')
      COLORREF::FromRGB(BYTE r, BYTE g, BYTE b), COLORREF
      COLORREF::FromClarion(LONG pClaColor), COLORREF
      COLORREF::ToRGB(COLORREF pWinColor, *BYTE r, *BYTE g, *BYTE b)
      COLORREF::ToClarion(COLORREF pWinColor), LONG
    END
  END

tagWINDOWPLACEMENT            GROUP, TYPE
length                          UNSIGNED
flags                           UNSIGNED
showCmd                         UNSIGNED
ptMinPosition                   LIKE(POINT)
ptMaxPosition                   LIKE(POINT)
rcNormalPosition                LIKE(_RECT_)
rcDevice                        LIKE(_RECT_)
                              END


!- Window{PROP:Handle}
TWnd                          CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
W                               &WINDOW, PROTECTED
FEQ                             SIGNED, PROTECTED
hwnd                            HWND, PROTECTED
wndProc                         LONG, PRIVATE
userData                        LONG, PRIVATE

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

Init                            PROCEDURE(<*WINDOW w>), VIRTUAL
Init                            PROCEDURE(SIGNED pFeq), VIRTUAL
GetHandle                       PROCEDURE(), HWND
SetHandle                       PROCEDURE(HWND hwnd)
GetWindow                       PROCEDURE(), *WINDOW  !- returns a WINDOW passed as an argument to Init.
GetClassName                    PROCEDURE(), STRING
!!!<summary>Determines whether the specified window handle identifies an existing window.</summary>
IsWindow                        PROCEDURE(), BOOL

SetWndProc                      PROCEDURE(LONG lpCallback, LONG lpUserData) !- ADDRESS(proc), ADDRESS(self)
ResetWndProc                    PROCEDURE()
CallWindowProc                  PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam), LONG, PROC
DefWindowProc                   PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam), LONG
GetWndProc                      PROCEDURE(), LONG     !- returns _previous_ window proc address
GetUserData                     PROCEDURE(), LONG     !- returns _previous_ window user data

GetFEQ                          PROCEDURE(), SIGNED
GetParent                       PROCEDURE(), HWND
SetParent                       PROCEDURE(HWND hWndNewParent), HWND, PROC
SetParent                       PROCEDURE(TWnd hWndNewParent), HWND, PROC

GetDesktopWindow                PROCEDURE(), HWND, PROC   !- sets hwnd to desktop window and returns it.
GetWindow                       PROCEDURE(UNSIGNED uCmd), HWND    !- winapi call

!!!<summary>Gets Clarion property value</summary>
GetProp                         PROCEDURE(LONG prop), ?
!!!<summary>Sets Clarion property value</summary>
SetProp                         PROCEDURE(LONG prop, ? value)

GetWindowLong                   PROCEDURE(LONG nIndex), LONG
SetWindowLong                   PROCEDURE(LONG nIndex, LONG dwNewLong), LONG, PROC

!!!<summary>Gets Window property value</summary>
GetPropA                        PROCEDURE(STRING pPropId), HANDLE
!!!<summary>Sets Window property value</summary>
SetPropA                        PROCEDURE(STRING pPropId, HANDLE pData), BOOL, PROC

SendMessage                     PROCEDURE(UNSIGNED uMsg, UNSIGNED wParam, LONG lParam), LONG, PROC
PostMessage                     PROCEDURE(UNSIGNED uMsg, UNSIGNED wParam, LONG lParam), BOOL, PROC
PeekMessage                     PROCEDURE(LONG lpMsg, LONG wMsgFilterMin = 0, LONG wMsgFilterMax = 0, LONG wRemoveMsg = 0), BOOL, PROC

SendEraseBkgnd                  PROCEDURE(), BOOL, PROC

GetClientRect                   PROCEDURE(*_RECT_ rc)
GetClientRect                   PROCEDURE(*TRect rc)

GetWindowRect                   PROCEDURE(*_RECT_ rc)
GetWindowRect                   PROCEDURE(*TRect rc)

GetRelativeRect                 PROCEDURE(*_RECT_ rc) !- get relative to parent window coordinates
GetRelativeRect                 PROCEDURE(*TRect rc) !- get relative to parent window coordinates
GetRelativeRect                 PROCEDURE(HWND pParentHwnd, *_RECT_ rc) !- get relative to window coordinates
GetRelativeRect                 PROCEDURE(HWND pParentHwnd, *TRect rc) !- get relative to window coordinates
GetRelativeRect                 PROCEDURE(TWnd pWin, *_RECT_ rc)!- get relative to window coordinates
GetRelativeRect                 PROCEDURE(TWnd pWin, *TRect rc)!- get relative to window coordinates

SetWindowPos                    PROCEDURE(HWND hWndInsertAfter, LONG x, LONG y, LONG cx, LONG cy, ULONG uFlags), BOOL, PROC
!!!<summary>
!!!Changes the position and dimensions of the specified window.
!!!For a top-level window, the position and dimensions are relative to the upper-left corner of the screen.
!!!For a child window, they are relative to the upper-left corner of the parent window's client area.
!!!</summary>
!!!<param name="bRepaint">
!!!Indicates whether the window is to be repainted. If this parameter is TRUE, the window receives a message.
!!!If the parameter is FALSE, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of moving a child window.
!!!</param>
MoveWindow                      PROCEDURE(LONG x, LONG y, LONG nWidth, LONG nHeight, BOOL bRepaint), BOOL, PROC
DestroyWindow                   PROCEDURE(), BOOL, PROC
IsZoomed                        PROCEDURE(), BOOL

ScreenToClient                  PROCEDURE(*POINT ppt)
ScreenToClient                  PROCEDURE(*TPoint ppt)
ScreenToClient                  PROCEDURE(*_RECT_ prc)
ScreenToClient                  PROCEDURE(*TRect prc)
ClientToScreen                  PROCEDURE(*POINT ppt)
ClientToScreen                  PROCEDURE(*_RECT_ prc)
ClientToScreen                  PROCEDURE(*TRect prc)

InvalidateRect                  PROCEDURE(_RECT_ rc, BOOL bErase), BOOL, PROC
InvalidateRect                  PROCEDURE(TRect rc, BOOL bErase), BOOL, PROC
InvalidateRect                  PROCEDURE(BOOL bErase), BOOL, PROC

ShowWindow                      PROCEDURE(SIGNED nCmdShow), BOOL, PROC
SetForegroundWindow             PROCEDURE(), BOOL, PROC
UpdateWindow                    PROCEDURE(), BOOL, PROC
EnableWindow                    PROCEDURE(BOOL pEnable), BOOL, PROC

IsWindowVisible                 PROCEDURE(), BOOL

RedrawWindow                    PROCEDURE(_RECT_ rc, HRGN hrgnUpdate, UNSIGNED pFlags), BOOL, PROC
RedrawWindow                    PROCEDURE(TRect rc, HRGN hrgnUpdate, UNSIGNED pFlags), BOOL, PROC

Redraw                          PROCEDURE(_RECT_ rc), BOOL, PROC
Redraw                          PROCEDURE(TRect rc), BOOL, PROC

SetCapture                      PROCEDURE(), HANDLE, PROC
ReleaseCapture                  PROCEDURE(), BOOL, PROC

GetDlgCtrlID                    PROCEDURE(), LONG

!- pRect (0,0) based (i.e. from (0,0) to (w,h)
GetBitmap                       PROCEDURE(<_RECT_ pRect>, LONG dwRop=SRCCOPY), *STRING  !- For IMAGEs only!
SaveBitmap                      PROCEDURE(STRING pFIleName, <_RECT_ pRect>), BOOL, PROC !- For IMAGEs only!
CopyBitmap                      PROCEDURE(SIGNED pImageFeq, <_RECT_ pRect>), BOOL, PROC !- For IMAGEs only!

GetScrollInfo                   PROCEDURE(SIGNED fnBar, *SCROLLINFO lpsi), BOOL, PROC
GetScrollRange                  PROCEDURE(*SIGNED pHMin, *SIGNED pHMax, *SIGNED pVMin, *SIGNED pVMax)
GetScrollRange                  PROCEDURE(*_RECT_ pRect)
ShowScrollBar                   PROCEDURE(SIGNED wBar, BOOL bShow), BOOL, PROC

!!!<summary>Associate a hot key with the window.
!!!When the user presses the hot key, the system activates the window.</summary>
!!!<param name="pChar"></param>
!!!<param name="pModifier">One or more of the following values from CommCtrl.h:
!!!HOTKEYF_SHIFT 0x04
!!!HOTKEYF_CONTROL 0x02
!!!HOTKEYF_ALT 0x04
!!!HOTKEYF_EXT 0x08
!!!</param>
!!!<returns>
!!!-1: The function is unsuccessful the hot key is invalid.
!!!0: The function is unsuccessful the window is invalid.
!!!1: The function is successful, and no other window has the same hot key.
!!!2: The function is successful, but another window already has the same hot key.
!!!</returns>
SetHotKey                       PROCEDURE(STRING pChar, USHORT pModifier), SIGNED, PROC

GetFocus                        PROCEDURE(), HWND
SetFocus                        PROCEDURE(), HWND, PROC
Focused                         PROCEDURE(), BOOL

!!!<summary>Retrieves the length, in characters, of the specified window's title bar text (if the window has a title bar). If the specified window is a control, the function retrieves the length of the text within the control. However, GetWindowTextLength cannot retrieve the length of the text of an edit control in another application.</summary>
GetWindowTextLength             PROCEDURE(), LONG
GetWindowTextLengthW            PROCEDURE(), LONG
GetWindowText                   PROCEDURE(), STRING
GetWindowTextW                  PROCEDURE(), STRING

!- GetWindowSubclass requires Comctl32.dll version 6.0 or later
GetWindowSubclass               PROCEDURE(LONG pfnSubclass, ULONG uIdSubclass, *UNSIGNED dwRefData), BOOL, PROC
SetWindowSubclass               PROCEDURE(LONG pfnSubclass, ULONG uIdSubclass, UNSIGNED dwRefData), BOOL, PROC
RemoveWindowSubclass            PROCEDURE(LONG pfnSubclass, ULONG uIdSubclass), BOOL, PROC
DefSubclassProc                 PROCEDURE(ULONG wMsg, UNSIGNED wParam, LONG lParam), LONG, PROC

ShowCaret                       PROCEDURE(), BOOL, PROC
HideCaret                       PROCEDURE(), BOOL, PROC

!!!<summary>
!!!Retrieves a handle to the top-level window whose class name and window name match the specified strings. 
!!!This function does not search child windows. This function does not perform a case-sensitive search.
!!!</summary>
FindWindow                      PROCEDURE(STRING pClassName, STRING pWindowName), HWND, PROC
!!!<summary>
!!!Retrieves a handle to the top-level window whose window name matches the specified strings. 
!!!This function does not search child windows. This function does not perform a case-sensitive search.
!!!</summary>
FindWindow                      PROCEDURE(STRING pWindowName), HWND, PROC
FindWindowEx                    PROCEDURE(HWND hWndParent, HWND hWndChildAfter, STRING pClassName, STRING pWindowName), HWND, PROC
FindWindowEx                    PROCEDURE(HWND hWndParent, HWND hWndChildAfter, STRING pWindowName), HWND, PROC
FindWindowEx                    PROCEDURE(HWND hWndChildAfter, STRING pWindowName), HWND, PROC

GetWindowPlacement              PROCEDURE(*tagWINDOWPLACEMENT pwndpl), BOOL, PROC
                              END

!- Window{PROP:ClientHandle}
TCWnd                         CLASS(TWnd), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
Init                            PROCEDURE(<*WINDOW w>), DERIVED
                              END

TPoint                        CLASS(POINT), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
Offset                          PROCEDURE(SIGNED xOffset, SIGNED yOffset) !- Adds values to the x and y members of the TPoint
Offset                          PROCEDURE(*POINT pt)
Offset                          PROCEDURE(*TPoint pt)
Offset                          PROCEDURE(*SIZE sz)
Equal                           PROCEDURE(*POINT pt), BOOL
Equal                           PROCEDURE(*TPoint pt), BOOL

ToString                        PROCEDURE(), STRING
                              END

!- Rectangle
TRect                         CLASS(_RECT_), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
Width                           PROCEDURE(), SIGNED
Width                           PROCEDURE(SIGNED pNewWidth)
Height                          PROCEDURE(), SIGNED
Height                          PROCEDURE(SIGNED pNewHeight)

!- assign rc to self
Assign                          PROCEDURE(_RECT_ rc)
Assign                          PROCEDURE(*TRect rc)
Assign                          PROCEDURE(SIGNED left, SIGNED top, SIGNED right, SIGNED bottom)

!- assign self to rc
AssignTo                        PROCEDURE(*_RECT_ rc)
AssignTo                        PROCEDURE(*TRect rc)

!- assign a rect by the address (win api may pass a rect address in wParam/lParam)
AssignPtr                       PROCEDURE(LONG rcAddr)

Equal                           PROCEDURE(_RECT_ rc), BOOL
Equal                           PROCEDURE(*TRect rc), BOOL

!- determines whether the specified point lies within the specified rectangle.
PtInRect                        PROCEDURE(SIGNED pX, SIGNED pY), BOOL
PtInRect                        PROCEDURE(*POINT pt), BOOL
PtInRect                        PROCEDURE(*TPoint pt), BOOL

Intersect                       PROCEDURE(_RECT_ rc), BOOL
Intersect                       PROCEDURE(*TRect rc), BOOL

ToString                        PROCEDURE(), STRING
                              END

!- Device context
TDC                           CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
handle                          HDC, PRIVATE
hwnd                            HWND, PRIVATE

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

FromHDC                         PROCEDURE(HDC pDC)
FromHDC                         PROCEDURE(HDC pDC, HWND hwnd)
GetDC                           PROCEDURE(HWND hwnd), HDC, PROC
GetDC                           PROCEDURE(TWnd wnd), HDC, PROC
GetDCEx                         PROCEDURE(HWND hwnd, HRGN hrgn, ULONG flags), HDC, PROC
GetDCEx                         PROCEDURE(TWnd wnd, HRGN hrgn, ULONG flags), HDC, PROC
GetDCEx                         PROCEDURE(HWND hwnd, ULONG flags), HDC, PROC
GetDCEx                         PROCEDURE(TWnd wnd, ULONG flags), HDC, PROC
CreateCompatibleDC              PROCEDURE(*TDC pDC), HDC, PROC
CreateCompatibleDC              PROCEDURE(HDC hdc), HDC, PROC
FillRect                        PROCEDURE(*_RECT_ r, TBrush br), BOOL, PROC
FillRect                        PROCEDURE(*TRect r, TBrush br), BOOL, PROC
!!!<summary>Draws a border around the specified rectangle by using the specified brush.
!!! The width and height of the border are always one logical unit.</summary>
FrameRect                       PROCEDURE(*_RECT_ r, TBrush br), BOOL, PROC
!!!<summary>Draws a border around the specified rectangle by using the specified brush.
!!! The width and height of the border are always one logical unit.</summary>
FrameRect                       PROCEDURE(*TRect r, TBrush br), BOOL, PROC
MoveTo                          PROCEDURE(SIGNED x, SIGNED y, <*POINT lpPoint>)
LineTo                          PROCEDURE(SIGNED x, SIGNED y)
StretchBlt                      PROCEDURE(_RECT_ rcDest, *TDC dcSrc, _RECT_ rcSrc, LONG dwRop = SRCCOPY), BOOL, PROC
StretchBlt                      PROCEDURE(*TRect rcDest, *TDC dcSrc, *TRect rcSrc, LONG dwRop = SRCCOPY), BOOL, PROC
BitBlt                          PROCEDURE(SIGNED pX, SIGNED pY, SIGNED pW, SIGNED pH, *TDC dcSrc, SIGNED srcX, SIGNED srcY, LONG dwRop = SRCCOPY), BOOL, PROC
BitBlt                          PROCEDURE(*TRect rcDest, *TDC dcSrc, SIGNED srcX, SIGNED srcY, LONG dwRop = SRCCOPY), BOOL, PROC
GetDIBits                       PROCEDURE(TBitmap hbmp, UNSIGNED uStartScan, UNSIGNED cScanLines, LONG lpvBits, LONG lpbi, UNSIGNED uUsage), SIGNED

StretchDIBits                   PROCEDURE(SIGNED pDestX, SIGNED pDestY, SIGNED pDestW, SIGNED pDestH, SIGNED pSrcX, SIGNED pSrcY, SIGNED pSrcW, SIGNED pSrcH, LONG lpBits, LONG lpbmi, UNSIGNED iUsage, ULONG rop), SIGNED, PROC
StretchDIBits                   PROCEDURE(TRect rcDest, TRect rcSrc, LONG lpBits, LONG lpbmi, UNSIGNED iUsage, ULONG rop), SIGNED, PROC
GetStretchBltMode               PROCEDURE(), LONG
SetStretchBltMode               PROCEDURE(LONG pMode), LONG, PROC

!!!<summary>
!!!Retrieves a handle to an object of the specified type that has been selected into the specified device context (DC).
!!!</summary>
!!!<param name="pObjType">The object type to be queried. This parameter can be one of the following values:
!!!OBJ_BITMAP, OBJ_BRUSH, OBJ_COLORSPACE, OBJ_FONT, OBJ_PAL, OBJ_PEN.
!!!</param>
GetCurrentObject                PROCEDURE(UNSIGNED pObjType), HGDIOBJ

GetTextColor                    PROCEDURE(), LONG
SetTextColor                    PROCEDURE(LONG pClaColor)
GetBkColor                      PROCEDURE(), LONG
SetBkColor                      PROCEDURE(LONG pClaColor)
!!!<summary>Sets the background mix mode of the specified device context.
!!!The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.
!!!</summary>
!!!<link>https://docs.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setbkmode</link>
!!!<param name="pMode">The background mode. This parameter can be one of the following values: TRANSPARENT (1), OPAQUE (2).</param>
!!!<returns>If the function succeeds, the return value specifies the previous background mode.
!!!If the function fails, the return value is zero.
!!!</returns>
SetBkMode                       PROCEDURE(LONG pMode), LONG, PROC

DrawText                        PROCEDURE(STRING pText, *_RECT_ pRect, LONG pFormat, BOOL pNoClip = FALSE), LONG, PROC
DrawText                        PROCEDURE(STRING pText, *TRect pRect, LONG pFormat, BOOL pNoClip = FALSE), LONG, PROC
DrawTextW                       PROCEDURE(STRINGW pText, *_RECT_ pRect, LONG pFormat), LONG, PROC
DrawTextW                       PROCEDURE(STRINGW pText, *TRect pRect, LONG pFormat), LONG, PROC
TextOut                         PROCEDURE(LONG pX, LONG pY, STRING pText), BOOL, PROC

!!!<summary>Computes the width and height of the specified string of text.</summary>
!!!<param name="pText">The text string.</param>
!!!<param name="pSize">SIZE structure that receives the dimensions of the string, in logical units.</param>
!!!<returns>If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.</returns>
GetTextExtentPoint32            PROCEDURE(STRING pText, *SIZE pSize), BOOL, PROC
!!!<summary>Computes the width and height of the specified string of text.</summary>
!!!<param name="pText">The text string.</param>
!!!<param name="pSize">SIZE structure that receives the dimensions of the string, in logical units.</param>
!!!<returns>If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.</returns>
GetTextExtentPoint32W           PROCEDURE(STRINGW pText,*SIZE pSize), BOOL, PROC

!!!<summary>Draws an ellipse. The center of the ellipse is the center of the specified bounding rectangle. The ellipse is outlined by using the current pen and is filled by using the current brush.
!!!</summary>
Ellipse                         PROCEDURE(LONG pLeft, LONG pTop, LONG pRight, LONG pBottom), BOOL, PROC
!!!<summary>Draws an ellipse. The center of the ellipse is the center of the specified bounding rectangle. The ellipse is outlined by using the current pen and is filled by using the current brush.
!!!</summary>
Ellipse                         PROCEDURE(*_RECT_ rc), BOOL, PROC
!!!<summary>Draws an ellipse. The center of the ellipse is the center of the specified bounding rectangle. The ellipse is outlined by using the current pen and is filled by using the current brush.
!!!</summary>
Ellipse                         PROCEDURE(*TRect rc), BOOL, PROC
!!!<summary>Draws a rectangle. The rectangle is outlined by using the current pen and filled by using the current brush.
!!!</summary>
Rectangle                       PROCEDURE(LONG pLeft, LONG pTop, LONG pRight, LONG pBottom), BOOL, PROC
!!!<summary>Draws a rectangle. The rectangle is outlined by using the current pen and filled by using the current brush.
!!!</summary>
Rectangle                       PROCEDURE(*_RECT_ rc), BOOL, PROC
!!!<summary>Draws a rectangle. The rectangle is outlined by using the current pen and filled by using the current brush.
!!!</summary>
Rectangle                       PROCEDURE(*TRect rc), BOOL, PROC
!!!<summary>Draws a polygon consisting of two or more vertices connected by straight lines.
!!!The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.
!!!</summary>
!!!<param name="apt">An address of an array of POINT structures that specify the vertices of the polygon, in logical coordinates.</param>
!!!<param name="cpt">The number of vertices in the array. This value must be greater than or equal to 2.</param>
Polygon                         PROCEDURE(LONG apt, LONG cpt), BOOL, PROC
!!!<summary>Draws an elliptical arc.</summary>
!!!<param name="x1">The x-coordinate, in logical units, of the upper-left corner of the bounding rectangle.</param>
!!!<param name="y1">The y-coordinate, in logical units, of the upper-left corner of the bounding rectangle.</param>
!!!<param name="x2">The x-coordinate, in logical units, of the lower-right corner of the bounding rectangle.</param>
!!!<param name="y2">The y-coordinate, in logical units, of the lower-right corner of the bounding rectangle.</param>
!!!<param name="x3">The x-coordinate, in logical units, of the ending point of the radial line defining the starting point of the arc.</param>
!!!<param name="y3">The x-coordinate, in logical units, of the ending point of the radial line defining the starting point of the arc.</param>
!!!<param name="x4">The x-coordinate, in logical units, of the ending point of the radial line defining the ending point of the arc.</param>
!!!<param name="y4">The x-coordinate, in logical units, of the ending point of the radial line defining the ending point of the arc.</param>
Arc                             PROCEDURE(LONG x1,LONG y1,LONG x2,LONG y2,LONG x3,LONG y3,LONG x4,LONG y4), BOOL, PROC
Arc                             PROCEDURE(TRect rc, TPoint pt1, TPoint pt2), BOOL, PROC

Pie                             PROCEDURE(LONG left,LONG top,LONG right,LONG bottom,LONG xr1,LONG yr1,LONG xr2,LONG yr2), BOOL, PROC
Pie                             PROCEDURE(TRect rc, TPoint pt1, TPoint pt2), BOOL, PROC

!!!<summary>Retrieves the current arc direction for the specified device context. Arc and rectangle functions use the arc direction.</summary>
!!!<returns>the current arc direction; it can be any one of the following values:
!!!AD_COUNTERCLOCKWISE (1)	Arcs and rectangles are drawn counterclockwise.
!!!AD_CLOCKWISE (2)	Arcs and rectangles are drawn clockwise.
!!!</returns>
GetArcDirection                 PROCEDURE(), LONG
!!!<summary>Sets the drawing direction to be used for arc and rectangle functions.</summary>
!!!<param name="dir">The new arc direction. This parameter can be one of the following values.</param>
!!!<returns>If the function succeeds, the return value specifies the old arc direction. If the function fails, the return value is zero.</returns>
SetArcDirection                 PROCEDURE(LONG dir), LONG, PROC

DrawFocusRect                   PROCEDURE(*_RECT_ rc), BOOL, PROC
DrawFocusRect                   PROCEDURE(*TRect rc), BOOL, PROC

ExcludeClipRect                 PROCEDURE(*_RECT_ pRect), LONG, PROC
ExcludeClipRect                 PROCEDURE(*TRect pRect), LONG, PROC

ReleaseDC                       PROCEDURE()
DeleteDC                        PROCEDURE()

BeginPaint                      PROCEDURE(HWND hWnd, *PAINTSTRUCT lpPaint), HDC, PROC
EndPaint                        PROCEDURE(*PAINTSTRUCT lpPaint)

GetHandle                       PROCEDURE(), HDC
SetHandle                       PROCEDURE(HDC pDC)

WindowFromDC                    PROCEDURE(), HWND

DrawIconEx                      PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,HBRUSH hbrFlickerFreeDraw,UNSIGNED diFlags),BOOL,PROC
DrawIconEx                      PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,*TBrush brFlickerFreeDraw,UNSIGNED diFlags),BOOL,PROC

DrawImage                       PROCEDURE(STRING pImageFile, *TRect rc), BOOL, PROC
DrawImage                       PROCEDURE(STRING pImageFile, UNSIGNED pW, UNSIGNED pH), BOOL, PROC

GetDeviceCaps                   PROCEDURE(LONG pIndex), LONG
                              END

!- GDI object
TGdiObj                       CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
handle                          HGDIOBJ, PROTECTED

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

GetHandle                       PROCEDURE(), HGDIOBJ
SetHandle                       PROCEDURE(HGDIOBJ handle)

SelectObject                    PROCEDURE(HDC pDC, <*TGdiObj replacedObject>), HGDIOBJ, PROC
SelectObject                    PROCEDURE(*TDC pDC, <*TGdiObj replacedObject>), HGDIOBJ, PROC
DeleteObject                    PROCEDURE()
GetObject                       PROCEDURE(LONG cbBuffer, LONG lpvObject), LONG
                              END

!- Pen
TPen                          CLASS(TGdiObj), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
CreatePen                       PROCEDURE(SIGNED penStyle, SIGNED nWidth, COLORREF color), HPEN, PROC
                              END

!- Brush
TBrush                        CLASS(TGdiObj), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
CreateSolidBrush                PROCEDURE(COLORREF color), HBRUSH, PROC
CreateSolidBrush                PROCEDURE(BYTE r, BYTE g, BYTE b), HBRUSH, PROC
                              END

!- Bitmap
TBitmap                       CLASS(TGdiObj), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
CreateCompatibleBitmap          PROCEDURE(HDC pDC, SIGNED cx, SIGNED cy), HBITMAP, PROC
CreateCompatibleBitmap          PROCEDURE(*TDC pDC, SIGNED cx, SIGNED cy), HBITMAP, PROC
CreateBitmapInfoStruct          PROCEDURE(), *STRING !returns a reference to BITMAPINFO
CreateDIBSection                PROCEDURE(HDC pDC, *BITMAPINFO bmi, UNSIGNED usage, <*LONG ppvBits>, <HANDLE hSection>, <UNSIGNED offset>), HBITMAP, PROC

LoadImage                       PROCEDURE(HINSTANCE hInst, STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE), HBITMAP, PROC
LoadImage                       PROCEDURE(STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE), HBITMAP, PROC
                              END

!- Font
tagLOGFONTA                   GROUP, TYPE
lfHeight                        LONG
lfWidth                         LONG
lfEscapement                    LONG
lfOrientation                   LONG
lfWeight                        LONG
lfItalic                        BYTE
lfUnderline                     BYTE
lfStrikeOut                     BYTE
lfCharSet                       BYTE
lfOutPrecision                  BYTE
lfClipPrecision                 BYTE
lfQuality                       BYTE
lfPitchAndFamily                BYTE
lfFaceName                      CSTRING(32)
                              END
tagLOGFONTW                   GROUP, TYPE
lfHeight                        LONG
lfWidth                         LONG
lfEscapement                    LONG
lfOrientation                   LONG
lfWeight                        LONG
lfItalic                        BYTE
lfUnderline                     BYTE
lfStrikeOut                     BYTE
lfCharSet                       BYTE
lfOutPrecision                  BYTE
lfClipPrecision                 BYTE
lfQuality                       BYTE
lfPitchAndFamily                BYTE
lfFaceName                      STRING(64)  !- 32 WCHARs including the terminating NULL
                              END
TLogicalFont                  CLASS(TGdiObj), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
CreateFont                      PROCEDURE(HDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT), HFONT, PROC
CreateFont                      PROCEDURE(*TDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT), HFONT, PROC
CreateFontIndirect              PROCEDURE(*tagLOGFONTA lplf), HFONT, PROC
CreateFontIndirectW              PROCEDURE(*tagLOGFONTW lplf), HFONT, PROC
GetProperties                   PROCEDURE(*tagLOGFONTA lplf), BOOL, PROC
GetPropertiesW                   PROCEDURE(*tagLOGFONTW lplf), BOOL, PROC
                              END

!- I/O device
TIODevice                     CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
handle                          HANDLE, PROTECTED

GetHandle                       PROCEDURE(), HANDLE
CreateFile                      PROCEDURE(STRING pFilename, ULONG dwDesiredAccess, | 
                                  ULONG dwShareMode, LONG lpSecurityAttributes, | 
                                  ULONG dwCreationDisposition, | 
                                  ULONG dwFlagsAndAttributes, | 
                                  HANDLE hTemplateFile), BOOL, PROC
ReadFile                        PROCEDURE(LONG lpBuffer, LONG dwBytes, *LONG dwBytesRead, LONG lpOverlapped), BOOL, PROC
WriteFile                       PROCEDURE(LONG lpBuffer, LONG dwBytes, *LONG dwBytesWritten, LONG lpOverlapped), BOOL, PROC
WriteFile                       PROCEDURE(*GROUP pGrp), BOOL, PROC
WriteFile                       PROCEDURE(*STRING pStr, <LONG pStrSize>), BOOL, PROC
WriteFile                       PROCEDURE(STRING pStr, <LONG pStrSize>), BOOL, PROC
WriteMem                        PROCEDURE(LONG pAddr, LONG pSize), BOOL, PROC
WriteByte                       PROCEDURE(BYTE pVal), BOOL, PROC
WriteShort                      PROCEDURE(SHORT pVal), BOOL, PROC
WriteLong                       PROCEDURE(LONG pVal), BOOL, PROC
WriteReal                       PROCEDURE(REAL pVal), BOOL, PROC
CloseHandle                     PROCEDURE(), BOOL, PROC
GetFileSize                     PROCEDURE(<*LONG pFileSizeHigh>), LONG
!!!<summary>Moves the file pointer of the specified file.</summary>
!!!<param name="plDistanceToMove">A number of bytes to move the file pointer.</param>
!!!<param name="pdwMoveMethod">The starting point for the file pointer move. 
!!!This parameter can be one of the following values:
!!!FILE_BEGIN (0) - The starting point is zero or the beginning of the file.
!!!FILE_CURRENT (1) - The starting point is the current value of the file pointer.
!!!FILE_END (2) - The starting point is the current end-of-file position.
!!!</param>
SetFilePointer                  PROCEDURE(LONG plDistanceToMove, ULONG pdwMoveMethod), ULONG
                              END

!- File
TDiskFile                     CLASS(TIODevice), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
LoadFile                        PROCEDURE(STRING pFilename, ULONG dwDesiredAccess=GENERIC_READ, ULONG dwCreationDisposition=OPEN_EXISTING), *STRING
SaveFile                        PROCEDURE(STRING pFilename, LONG pData, LONG pDataLen, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
SaveFile                        PROCEDURE(STRING pFilename, *STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
SaveFile                        PROCEDURE(STRING pFilename, STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
AppendFile                      PROCEDURE(STRING pFilename, *STRING pData), BOOL, PROC
AppendFile                      PROCEDURE(STRING pFilename, STRING pData), BOOL, PROC
                              END

!- Temp files
TTempFile                     CLASS(TDiskFile), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
GetTempPath                     PROCEDURE(), STRING
GetTempFileName                 PROCEDURE(STRING pPathName, STRING pPrefixString, UNSIGNED uUnique=0), STRING
GetTempFileName                 PROCEDURE(<STRING pExt>), STRING
                              END

!- Timer
TTimer                        CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
hwnd                            HWND, PRIVATE
nIDEvent                        UNSIGNED, PRIVATE
uTimer                          UNSIGNED, PRIVATE

SetTimer                        PROCEDURE(HWND hwnd, UNSIGNED nIDEvent, UNSIGNED uElapse, LONG lpTimerFunc), UNSIGNED, PROC
SetTimer                        PROCEDURE(HWND hwnd, UNSIGNED uElapse), UNSIGNED, PROC
SetTimer                        PROCEDURE(UNSIGNED uElapse), UNSIGNED, PROC
KillTimer                       PROCEDURE(), BOOL, PROC
GetTimerID                      PROCEDURE(), UNSIGNED
                              END

!- SoundPlayer (WAV format)
TSoundPlayer                  CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
PlaySound                       PROCEDURE(STRING pSound, HMODULE hmod, UNSIGNED fdwSound), BOOL, PROC
PlayFromFile                    PROCEDURE(STRING pFile, UNSIGNED fOptions=0), BOOL, PROC
PlayFromResource                PROCEDURE(STRING pResourceName, UNSIGNED fOptions=0), BOOL, PROC
PlaySystemEvent                 PROCEDURE(STRING pEventName, UNSIGNED fOptions=0), BOOL, PROC
StopSound                       PROCEDURE(), BOOL, PROC
                              END

!- Resources
HRSRC                         EQUATE(HANDLE)

TResource                     CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
hModule                         HMODULE, PRIVATE  !- call GetModuleHandle to obtaion it
hResInfo                        HRSRC, PRIVATE    !- call FindResource to obtaion it
hResData                        HGLOBAL, PRIVATE  !- call LoadResource to obtaion it
sResData                        &STRING, PROTECTED

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL
DisposeResource                 PROCEDURE()

GetModuleHandle                 PROCEDURE(<STRING pModuleName>), HMODULE, PROC
FindResource                    PROCEDURE(HMODULE hModule, STRING pName, STRING pType), HRSRC
FindResource                    PROCEDURE(STRING pName, STRING pType), HRSRC, PROC
LoadResource                    PROCEDURE(HMODULE hModule, HRSRC hResInfo), HGLOBAL
LoadResource                    PROCEDURE(), HGLOBAL, PROC
LockResource                    PROCEDURE(HGLOBAL hResData), LONG
LockResource                    PROCEDURE(), LONG
SizeofResource                  PROCEDURE(HMODULE hModule, HRSRC hResInfo), UNSIGNED
SizeofResource                  PROCEDURE(), UNSIGNED
!- returns a resource data from an exe or dll
GetResource                     PROCEDURE(STRING pModuleName, STRING pName, STRING pType), *STRING, PROC
!- returns a resource data from this module
GetResource                     PROCEDURE(STRING pName, STRING pType), *STRING, PROC
!- returns previously obtained resource data
GetResource                     PROCEDURE(), *STRING
                              END

!- MCI device
!- https://docs.microsoft.com/ru-ru/windows/win32/multimedia/multimedia-command-strings?redirectedfrom=MSDN

!- mciSendString return type
MCIERROR                      EQUATE(UNSIGNED)

TMCIDevice                    CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
lastError                       MCIERROR

SendString                      PROCEDURE(STRING pCommand, <*STRING pReturnString>, HANDLE hwndCallback = 0), MCIERROR, PROC
GetErrorString                  PROCEDURE(MCIERROR fdwError), STRING
GetErrorString                  PROCEDURE(), STRING
                              END

!- MCI: MpegVideo type (mp3 files)
TMpegVideo                    CLASS(TMCIDevice), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
theAlias                        STRING(10), PRIVATE

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

Open                            PROCEDURE(STRING pFilename), BOOL, PROC
Close                           PROCEDURE()
Play                            PROCEDURE(), BOOL, PROC
Pause                           PROCEDURE()   !- toggle pause state
Stop                            PROCEDURE()
Resume                          PROCEDURE()
IsPlaying                       PROCEDURE(), BOOL
IsPaused                        PROCEDURE(), BOOL
IsStopped                       PROCEDURE(), BOOL
GetPosition                     PROCEDURE(), LONG
SetPosition                     PROCEDURE(LONG milliseconds)
GetLength                       PROCEDURE(), LONG
SetVolume                       PROCEDURE(LONG pVolume), BOOL, PROC
SetBalance                      PROCEDURE(LONG pBalance), BOOL, PROC
                              END

!https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics
TSystemMetrics                CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
GetSystemMetrics                PROCEDURE(LONG nIndex, UNSIGNED pDpi=0), LONG
GetSystemMetricsForDpi          PROCEDURE(LONG nIndex, UNSIGNED pDpi), LONG

!!!<summary>
!!!The flags that specify how the system arranged minimized windows.
!!!</summary>
Arrange                         PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The value that specifies how the system is started:
!!! 0 Normal boot
!!! 1 Fail-safe boot
!!! 2 Fail-safe with network boot
!!!A fail-safe boot (also called SafeBoot, Safe Mode, or Clean Boot) bypasses the user startup files.
!!!</summary>
CleanBoot                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The number of display monitors on a desktop.
!!!</summary>
CMonitors                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The number of buttons on a mouse, or zero if no mouse is installed.
!!!</summary>
CMouseButtons                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Reflects the state of the laptop or slate mode, 0 for Slate Mode and non-zero otherwise.
!!!</summary>
ConvertibleSlateMode            PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a window border, in pixels. This is equivalent to the SM_CXEDGE value for windows with the 3-D look.
!!!</summary>
CxBorder                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a cursor, in pixels. The system cannot create cursors of other sizes.
!!!</summary>
CxCursor                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This value is the same as SM_CXFIXEDFRAME.
!!!</summary>
CxDlgFrame                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the rectangle around the location of a first click in a double-click sequence, in pixels.
!!!The second click must occur within the rectangle that is defined by SM_CXDOUBLECLK and SM_CYDOUBLECLK for the system to consider the two clicks a double-click. The two clicks must also occur within a specified time.
!!!</summary>
CxDoubleClk                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The number of pixels on either side of a mouse-down point that the mouse pointer can move before a drag operation begins.
!!!This allows the user to click and release the mouse button easily without unintentionally starting a drag operation.
!!!If this value is negative, it is subtracted from the left of the mouse-down point and added to the right of it.
!!!</summary>
CxDrag                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a 3-D border, in pixels. This metric is the 3-D counterpart of SM_CXBORDER.
!!!</summary>
CxEdge                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The thickness of the frame around the perimeter of a window that has a caption but is not sizable, in pixels. SM_CXFIXEDFRAME is the height of the horizontal border, and SM_CYFIXEDFRAME is the width of the vertical border.
!!!This value is the same as SM_CXDLGFRAME.
!!!</summary>
CxFixedFrame                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the left and right edges of the focus rectangle that the DrawFocusRect draws. This value is in pixels.
!!!</summary>
CxFocusBorder                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This value is the same as SM_CXSIZEFRAME.
!!!</summary>
CxFrame                         PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the client area for a full-screen window on the primary display monitor, in pixels.
!!!To get the coordinates of the portion of the screen that is not obscured by the system taskbar or by application desktop toolbars, 
!!! call the SystemParametersInfo function with the SPI_GETWORKAREA value.
!!!</summary>
CxFullScreen                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the arrow bitmap on a horizontal scroll bar, in pixels.
!!!</summary>
CxHScroll                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the thumb box in a horizontal scroll bar, in pixels.
!!!</summary>
CxHThumb                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default width of an icon, in pixels. 
!!!The LoadIcon function can load only icons with the dimensions that SM_CXICON and SM_CYICON specifies.
!!!</summary>
CxIcon                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a grid cell for items in large icon view, in pixels.
!!!</summary>
CxIconSpacing                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default width, in pixels, of a maximized top-level window on the primary display monitor.
!!!</summary>
CxMaximized                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default maximum width of a window that has a caption and sizing borders, in pixels.
!!!</summary>
CxMaxTrack                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the default menu check-mark bitmap, in pixels.
!!!</summary>
CxMenuCheck                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of menu bar buttons, such as the child window close button that is used in the multiple document interface, in pixels.
!!!</summary>
CxMenuSize                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The minimum width of a window, in pixels.
!!!</summary>
CxMin                           PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a minimized window, in pixels.
!!!</summary>
CxMinimized                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a grid cell for a minimized window, in pixels.
!!!</summary>
CxMinSpacing                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The minimum tracking width of a window, in pixels.
!!!</summary>
CxMinTrack                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The amount of border padding for captioned windows, in pixels.
!!!</summary>
CxPaddedBorder                  PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the screen of the primary display monitor, in pixels.
!!!</summary>
CxScreen                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a button in a window caption or title bar, in pixels.
!!!</summary>
CxSize                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The thickness of the sizing border around the perimeter of a window that can be resized, in pixels.
!!!</summary>
CxSizeFrame                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The recommended width of a small icon, in pixels.
!!!</summary>
CxSMIcon                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of small caption buttons, in pixels.
!!!</summary>
CxSMSize                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of the virtual screen, in pixels.
!!!</summary>
CxVirtualScreen                 PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The width of a vertical scroll bar, in pixels.
!!!</summary>
CxVScroll                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a window border, in pixels.
!!!</summary>
CyBorder                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a caption area, in pixels.
!!!</summary>
CyCaption                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a cursor, in pixels. The system cannot create cursors of other sizes.
!!!</summary>
CyCursor                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This value is the same as SM_CYFIXEDFRAME.
!!!</summary>
CyDlgFrame                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the rectangle around the location of a first click in a double-click sequence, in pixels.
!!!</summary>
CyDoubleClk                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The number of pixels above and below a mouse-down point that the mouse pointer can move before a drag operation begins.
!!!</summary>
CyDrag                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a 3-D border, in pixels. This is the 3-D counterpart of SM_CYBORDER.
!!!</summary>
CyEdge                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The thickness of the frame around the perimeter of a window that has a caption but is not sizable, in pixels.
!!!</summary>
CyFixedFrame                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the top and bottom edges of the focus rectangle drawn by DrawFocusRect. This value is in pixels.
!!!</summary>
CyFocusBorder                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This value is the same as SM_CYSIZEFRAME.
!!!</summary>
CyFrame                         PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the client area for a full-screen window on the primary display monitor, in pixels.
!!!</summary>
CyFullScreen                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a horizontal scroll bar, in pixels.
!!!</summary>
CyHScroll                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default height of an icon, in pixels.
!!!</summary>
CyIcon                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a grid cell for items in large icon view, in pixels.
!!!</summary>
CyIconSpacing                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!For double byte character set versions of the system, this is the height of the Kanji window at the bottom of the screen, in pixels.
!!!</summary>
CyKanjiWindow                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default height, in pixels, of a maximized top-level window on the primary display monitor.
!!!</summary>
CyMaximized                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The default maximum height of a window that has a caption and sizing borders, in pixels.
!!!</summary>
CyMaxTrack                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a single-line menu bar, in pixels.
!!!</summary>
CyMenu                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the default menu check-mark bitmap, in pixels.
!!!</summary>
CyMenuCheck                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of menu bar buttons, such as the child window close button that is used in the multiple document interface, in pixels.
!!!</summary>
CyMenuSize                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The minimum height of a window, in pixels.
!!!</summary>
CyMin                           PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a minimized window, in pixels.
!!!</summary>
CyMinimized                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a grid cell for a minimized window, in pixels.
!!!</summary>
CyMinSpacing                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The minimum tracking height of a window, in pixels.
!!!</summary>
CyMinTrack                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the screen of the primary display monitor, in pixels.
!!!</summary>
CyScreen                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a button in a window caption or title bar, in pixels.
!!!</summary>
CySize                          PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The thickness of the sizing border around the perimeter of a window that can be resized, in pixels.
!!!</summary>
CySizeFrame                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of a small caption, in pixels.
!!!</summary>
CySMCaption                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The recommended height of a small icon, in pixels.
!!!</summary>
CySMIcon                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of small caption buttons, in pixels.
!!!</summary>
CySMSize                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the virtual screen, in pixels.
!!!</summary>
CyVirtualScreen                 PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the arrow bitmap on a vertical scroll bar, in pixels.
!!!</summary>
CyVScroll                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The height of the thumb box in a vertical scroll bar, in pixels.
!!!</summary>
CyVThumb                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if User32.dll supports DBCS; otherwise, 0.
!!!</summary>
DBCSEnabled                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the debug version of User.exe is installed; otherwise, 0.
!!!</summary>
Debug                           PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the current operating system is Windows 7 or Windows Server 2008 R2 and the Tablet PC Input service is started; otherwise, 0. 
!!!</summary>
Digitizer                       PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if Input Method Manager/Input Method Editor features are enabled; otherwise, 0.
!!!</summary>
IMMEnabled                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if there are digitizers in the system; otherwise, 0.
!!!</summary>
MaximumTouches                  PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the current operating system is the Windows XP, Media Center Edition, 0 if not.
!!!</summary>
MediaCenter                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if drop-down menus are right-aligned with the corresponding menu-bar item; 0 if the menus are left-aligned.
!!!</summary>
MenuDropAlignment               PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the system is enabled for Hebrew and Arabic languages, 0 if not.
!!!</summary>
MidEastEnabled                  PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if a mouse is installed; otherwise, 0.
!!!</summary>
MousePresent                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if a mouse with a horizontal scroll wheel is installed; otherwise 0.
!!!</summary>
MouseHorizontalWheelPresent     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if a mouse with a vertical scroll wheel is installed; otherwise 0.
!!!</summary>
MouseWheelPresent               PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The least significant bit is set if a network is present; otherwise, it is cleared. The other bits are reserved for future use.
!!!</summary>
Network                         PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the Microsoft Windows for Pen computing extensions are installed; zero otherwise.
!!!</summary>
PenWindows                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This system metric is used in a Terminal Services environment to determine if the current Terminal Server session is being remotely controlled. 
!!!Its value is nonzero if the current session is remotely controlled; otherwise, 0.
!!!</summary>
RemoteControl                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!This system metric is used in a Terminal Services environment. 
!!!If the calling process is associated with a Terminal Services client session, the return value is nonzero. 
!!!If the calling process is associated with the Terminal Services console session, the return value is 0. 
!!!</summary>
RemoteSession                   PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if all the display monitors have the same color format, otherwise, 0. 
!!!</summary>
SameDisplayFormat               PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The build number if the system is Windows Server 2003 R2; otherwise, 0.
!!!</summary>
ServerR2                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the user requires an application to present information visually in situations where it would otherwise present the information only in audible form; otherwise, 0.
!!!</summary>
ShowSounds                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the current session is shutting down; otherwise, 0.
!!!</summary>
ShuttingDown                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the computer has a low-end (slow) processor; otherwise, 0.
!!!</summary>
SlowMachine                     PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the current operating system is Windows 7 Starter Edition, Windows Vista Starter, or Windows XP Starter Edition; otherwise, 0.
!!!</summary>
Starter                         PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the meanings of the left and right mouse buttons are swapped; otherwise, 0.
!!!</summary>
SwapButton                      PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Reflects the state of the docking mode, 0 for Undocked Mode and non-zero otherwise. 
!!!</summary>
SystemDocked                    PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!Nonzero if the current operating system is the Windows XP Tablet PC edition or if the current operating system is Windows Vista or Windows 7 and the Tablet PC Input service is started; otherwise, 0. 
!!!</summary>
TabletPC                        PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The coordinates for the left side of the virtual screen.
!!!</summary>
XVirtualScreen                  PROCEDURE(UNSIGNED pDpi=0), LONG
!!!<summary>
!!!The coordinates for the top of the virtual screen.
!!!</summary>
YVirtualScreen                  PROCEDURE(UNSIGNED pDpi=0), LONG
                              END

!- MultiByteToWideChar/WideCharToMultiByte
  OMIT('**_CP_UTF16_**', CP_UTF16 = 0FFFFFFFFh)
CP_UTF16                      EQUATE(0FFFFFFFFh)
!'**_CP_UTF16_**'

TStringEncoding               CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
MultiByteToWideChar             PROCEDURE(UNSIGNED Codepage, ULONG dwFlags, ULONG LpMultuByteStr, |
                                  LONG cbMultiByte, ULONG LpWideCharStr, LONG cchWideChar), ULONG, PROC
WideCharToMultiByte             PROCEDURE(UNSIGNED Codepage, ULONG dwFlags, ULONG LpWideCharStr, LONG cchWideChar, |
                                  ULONG lpMultuByteStr, LONG cbMultiByte, ULONG LpDefalutChar, ULONG lpUsedDefalutChar), ULONG, PROC
!!!<summary>Converts input string from one encoding to another.</summary>
!!!<param name="pInput">Input string.</param>
!!!<param name="pInputCodepage">Input code page, like CP_ACP, CP_UTF8.</param>
!!!<param name="pOutputCodepage">Output code page; pass -1 to convert to UTF16.</param>
Convert                         PROCEDURE(STRING pInput, UNSIGNED pInputCodepage, UNSIGNED pOutputCodepage), STRING
!!!<summary>Converts input string from utf-8.</summary>
FromUtf8                        PROCEDURE(STRING pInput, UNSIGNED pCodepage = CP_ACP), STRING
!!!<summary>Converts input string to utf-8.</summary>
ToUtf8                          PROCEDURE(STRING pInput, UNSIGNED pCodepage = CP_ACP), STRING
!!!<summary>Converts input string from utf-16.</summary>
FromUtf16                       PROCEDURE(STRING pInput, UNSIGNED pCodepage = CP_ACP), STRING
!!!<summary>Converts input string to utf-16.</summary>
!!!<returns>utf-16 encoded string without null terminator <0,0>.
ToUtf16                          PROCEDURE(STRING pInput, UNSIGNED pCodepage = CP_ACP), STRING
!!!<summary>Converts input string to utf-16.</summary>
!!!<returns>utf-16 encoded string with null terminator <0,0>.
ToCWStr                         PROCEDURE(STRING pInput, UNSIGNED pCodepage = CP_ACP), STRING
                              END


!- TODO: Custom font