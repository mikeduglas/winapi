!Base Windows classes
!26.07.2020 revision
!mikeduglas (c) 2019-2020

  INCLUDE('svapi.inc'), ONCE

  MAP
    MODULE('winapi.clw')
      COLORREF::FromRGB(BYTE r, BYTE g, BYTE b), COLORREF
      COLORREF::FromClarion(LONG pClaColor), COLORREF
      COLORREF::ToRGB(COLORREF pWinColor, *BYTE r, *BYTE g, *BYTE b)
      COLORREF::ToClarion(COLORREF pWinColor), LONG
    END
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
Init                            PROCEDURE(LONG pFeq), VIRTUAL
GetHandle                       PROCEDURE(), HWND
SetHandle                       PROCEDURE(HWND hwnd)
GetWindow                       PROCEDURE(), *WINDOW

SetWndProc                      PROCEDURE(LONG lpCallback, LONG lpUserData) !- ADDRESS(proc), ADDRESS(self)
ResetWndProc                    PROCEDURE()
CallWindowProc                  PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam), LONG
DefWindowProc                   PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam), LONG
GetWndProc                      PROCEDURE(), LONG     !- returns _previous_ window proc address
GetUserData                     PROCEDURE(), LONG     !- returns _previous_ window user data

GetFEQ                          PROCEDURE(), SIGNED
GetParent                       PROCEDURE(), HWND
SetParent                       PROCEDURE(HWND hWndNewParent), HWND, PROC
SetParent                       PROCEDURE(TWnd hWndNewParent), HWND, PROC

SetProp                         PROCEDURE(LONG prop, ? value)
GetProp                         PROCEDURE(LONG prop), ?

SetWindowLong                   PROCEDURE(LONG nIndex, LONG dwNewLong), LONG, PROC
GetWindowLong                   PROCEDURE(LONG nIndex), LONG

SendMessage                     PROCEDURE(UNSIGNED uMsg, UNSIGNED wParam, LONG lParam), BOOL, PROC
PostMessage                     PROCEDURE(UNSIGNED nMsg, UNSIGNED wParam, LONG lParam), BOOL, PROC
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

ScreenToClient                  PROCEDURE(*POINT ppt)
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

Redraw                          PROCEDURE(_RECT_ rc)
Redraw                          PROCEDURE(TRect rc)

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

Equal                           PROCEDURE(_RECT_ rc), BOOL
Equal                           PROCEDURE(*TRect rc), BOOL

!- determines whether the specified point lies within the specified rectangle.
PtInRect                        PROCEDURE(SIGNED pX, SIGNED pY), BOOL
PtInRect                        PROCEDURE(*POINT pt), BOOL
PtInRect                        PROCEDURE(*TPoint pt), BOOL

ToString                        PROCEDURE(), STRING
                              END

!- Device context
TDC                           CLASS, TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
handle                          HDC, PRIVATE
hwnd                            HWND, PRIVATE

Construct                       PROCEDURE()
Destruct                        PROCEDURE(), VIRTUAL

FromHDC                         PROCEDURE(HDC pDC)
GetDC                           PROCEDURE(HWND hwnd), HDC, PROC
GetDCEx                         PROCEDURE(HWND hwnd, ULONG flags), HDC, PROC
CreateCompatibleDC              PROCEDURE(*TDC pDC), HDC, PROC
CreateCompatibleDC              PROCEDURE(HDC hdc), HDC, PROC
FillRect                        PROCEDURE(*_RECT_ r, TBrush br), BOOL, PROC
FillRect                        PROCEDURE(*TRect r, TBrush br), BOOL, PROC
MoveTo                          PROCEDURE(SIGNED x, SIGNED y, <*POINT lpPoint>)
LineTo                          PROCEDURE(SIGNED x, SIGNED y)
StretchBlt                      PROCEDURE(_RECT_ rcDest, *TDC dcSrc, _RECT_ rcSrc, LONG dwRop = SRCCOPY), BOOL, PROC
BitBlt                          PROCEDURE(SIGNED pX, SIGNED pY, SIGNED pW, SIGNED pH, *TDC dcSrc, SIGNED srcX, SIGNED srcY, LONG dwRop = SRCCOPY), BOOL, PROC
GetDIBits                       PROCEDURE(TBitmap hbmp, UNSIGNED uStartScan, UNSIGNED cScanLines, LONG lpvBits, LONG lpbi, UNSIGNED uUsage), SIGNED

GetTextColor                    PROCEDURE(), LONG
SetTextColor                    PROCEDURE(LONG pClaColor)
GetBkColor                      PROCEDURE(), LONG
SetBkColor                      PROCEDURE(LONG pClaColor)
DrawText                        PROCEDURE(STRING pText, *_RECT_ pRect, LONG pFormat), LONG, PROC
DrawText                        PROCEDURE(STRING pText, *TRect pRect, LONG pFormat), LONG, PROC
TextOut                         PROCEDURE(LONG pX, LONG pY, STRING pText), BOOL, PROC

Ellipse                         PROCEDURE(LONG pLeft, LONG pTop, LONG pRight, LONG pBottom), BOOL, PROC
Ellipse                         PROCEDURE(*_RECT_ rc), BOOL, PROC
Ellipse                         PROCEDURE(*TRect rc), BOOL, PROC

!!!<summary>Draws a polygon consisting of two or more vertices connected by straight lines.
!!!The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.
!!!</summary>
!!!<param name="apt">An address of an array of POINT structures that specify the vertices of the polygon, in logical coordinates.</param>
!!!<param name="cpt">The number of vertices in the array. This value must be greater than or equal to 2.</param>
Polygon                         PROCEDURE(LONG apt, LONG cpt), BOOL, PROC

ExcludeClipRect                 PROCEDURE(*_RECT_ pRect), LONG, PROC
ExcludeClipRect                 PROCEDURE(*TRect pRect), LONG, PROC

ReleaseDC                       PROCEDURE()
DeleteDC                        PROCEDURE()

BeginPaint                      PROCEDURE(HWND hWnd, *PAINTSTRUCT lpPaint), HDC, PROC
EndPaint                        PROCEDURE(*PAINTSTRUCT lpPaint)

GetHandle                       PROCEDURE(), HDC
WindowFromDC                    PROCEDURE(), HWND

DrawIconEx                      PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,HBRUSH hbrFlickerFreeDraw,UNSIGNED diFlags),BOOL,PROC
DrawIconEx                      PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,*TBrush brFlickerFreeDraw,UNSIGNED diFlags),BOOL,PROC

DrawImage                       PROCEDURE(STRING pImageFile, *TRect rc), BOOL, PROC
DrawImage                       PROCEDURE(STRING pImageFile, UNSIGNED pW, UNSIGNED pH), BOOL, PROC
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

LoadImage                       PROCEDURE(HINSTANCE hInst, STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE), HBITMAP, PROC
LoadImage                       PROCEDURE(STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE), HBITMAP, PROC
                              END

!- Font
TLogicalFont                  CLASS(TGdiObj), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
CreateFont                      PROCEDURE(HDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT), HFONT, PROC
CreateFont                      PROCEDURE(*TDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT), HFONT, PROC
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
                              END

!- File
TDiskFile                     CLASS(TIODevice), TYPE, MODULE('winapi.clw'), LINK('winapi.clw')
LoadFile                        PROCEDURE(STRING pFilename, ULONG dwDesiredAccess=GENERIC_READ, ULONG dwCreationDisposition=OPEN_EXISTING), *STRING
SaveFile                        PROCEDURE(STRING pFilename, LONG pData, LONG pDataLen, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
SaveFile                        PROCEDURE(STRING pFilename, *STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
SaveFile                        PROCEDURE(STRING pFilename, STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS), BOOL, PROC
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

!- TODO: Custom font