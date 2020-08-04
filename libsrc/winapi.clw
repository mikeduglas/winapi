!Base Windows classes
!28.07.2020 revision
!mikeduglas (c) 2019-2020

  MEMBER

  INCLUDE('winapi.inc'), ONCE

  MAP
    INCLUDE('printf.inc')

    MODULE('win api')
      winapi::GetParent(HWND hwnd),HWND,PASCAL,NAME('GetParent')
      winapi::SetParent(HWND hWndChild, HWND hWndNewParent),HWND,PASCAL,PROC,NAME('SetParent')
      winapi::CallWindowProc(LONG lpPrevWndFunc,HWND hWnd, UNSIGNED wMsg, UNSIGNED wParam, LONG lParam), LONG, PASCAL, NAME('CallWindowProcA')
      winapi::DefWindowProc(HWND hWnd, UNSIGNED wMsg, UNSIGNED wParam, LONG lParam),LONG,PASCAL,NAME('DefWindowProcA')
      winapi::SetWindowLong(HWND hWnd, LONG nIndex, LONG dwNewLong), LONG, PASCAL, PROC, NAME('SetWindowLongA')
      winapi::GetWindowLong(HWND hWnd,LONG nIndex), LONG, PASCAL, NAME('GetWindowLongA')
      winapi::SendMessage(HWND hWnd, UNSIGNED uMsg, UNSIGNED wParam, LONG lParam), BOOL, PASCAL, PROC, NAME('SendMessageA')
      winapi::PostMessage(HWND hWnd, UNSIGNED nMsg, UNSIGNED wParam, LONG lParam), BOOL, PASCAL, PROC, NAME('PostMessageA')
      winapi::PeekMessage(LONG lpMsg, HWND hWnd, LONG wMsgFilterMin, LONG wMsgFilterMax, LONG wRemoveMsg), BOOL, PASCAL, PROC, NAME('PeekMessageA')
      winapi::ShowWindow(HWND hWnd, SIGNED nCmdShow),BOOL,PASCAL,PROC,NAME('ShowWindow')
      winapi::SetForegroundWindow(HWND hwnd),BOOL,PASCAL,PROC,NAME('SetForegroundWindow')
      winapi::GetClientRect(HWND hWnd,*_RECT_ lpRect), BOOL, RAW, PASCAL, PROC, NAME('GetClientRect')
      winapi::GetWindowRect(HWND hWnd,*_RECT_ lpRect), BOOL, RAW, PASCAL, PROC, NAME('GetWindowRect')
      winapi::SetWindowPos(HWND hWnd,HWND hWndInsertAfter,LONG x,LONG y,LONG cx,LONG cy,ULONG uFlags), BOOL, PASCAL, PROC, NAME('SetWindowPos')
      winapi::ScreenToClient(HWND hWnd, *POINT ppt), BOOL, RAW, PASCAL, PROC, NAME('ScreenToClient')
      winapi::ClientToScreen(HWND hWnd, *POINT ppt), BOOL, RAW, PASCAL, PROC, NAME('ClientToScreen')
      winapi::GetDC(HWND hwnd), HDC, PASCAL, NAME('GetDC')
      winapi::GetDCEx(HWND hwnd, HRGN hrgnClip, ULONG flags), HDC, PASCAL, NAME('GetDCEx')
      winapi::ReleaseDC(HWND hwnd, HDC hdc), BOOL, PASCAL, PROC, NAME('ReleaseDC')
      winapi::DeleteDC(HDC hdc), BOOL, PASCAL, PROC, NAME('DeleteDC')
      winapi::WindowFromDC(HDC HDC),HWND,PASCAL,NAME('WindowFromDC')
      winapi::FillRect(HDC hdc, *_RECT_ lprc, HBRUSH hbr), BOOL, RAW, PASCAL, PROC, NAME('FillRect')
      winapi::CreateCompatibleDC(HDC hdc), HDC, PASCAL, NAME('CreateCompatibleDC')
      winapi::SelectObject(HDC hdc, HGDIOBJ hgdiobj), HGDIOBJ, PASCAL, PROC, NAME('SelectObject')
      winapi::GetObject(HGDIOBJ hgdiobj, LONG cbBuffer, LONG lpvObject), LONG, PASCAL, NAME('GetObjectA'), PROC
      winapi::GetDIBits(HDC hdc, HBITMAP hbmp, UNSIGNED uStartScan, UNSIGNED cScanLines, LONG lpvBits, LONG lpbi, UNSIGNED uUsage), SIGNED, RAW, PASCAL, NAME('GetDIBits'), PROC
      winapi::DrawIconEx(HDC hDC,SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,HBRUSH hbrFlickerFreeDraw,UNSIGNED diFlags),BOOL,PASCAL,PROC,NAME('DrawIconEx')
      winapi::CreateSolidBrush(COLORREF crColor), HBRUSH, PASCAL, NAME('CreateSolidBrush')
      winapi::DeleteObject(HGDIOBJ hObj), BOOL, RAW, PASCAL, NAME('DeleteObject'), PROC
      winapi::CreateCompatibleBitmap(HDC hdc, SIGNED cx, SIGNED cy), HBITMAP, PASCAL, NAME('CreateCompatibleBitmap')
      winapi::LoadImage(HINSTANCE hInst, *CSTRING szIcon, UNSIGNED uType, SIGNED cxDesired, SIGNED cyDesired, UNSIGNED fuLoad),HANDLE,PASCAL,RAW,NAME('LoadImageA')
      winapi::CreatePen(SIGNED fnPenStyle, SIGNED nWidth, COLORREF crColor), HPEN, PASCAL, NAME('CreatePen')
      winapi::MoveToEx(HDC hdc, SIGNED x, SIGNED y, *POINT lpPoint), BOOL, RAW, PASCAL, PROC, NAME('MoveToEx')
      winapi::LineTo(HDC hdc, SIGNED x, SIGNED y), BOOL, PASCAL, PROC, NAME('LineTo')
      winapi::StretchBlt(HDC hdcDest, SIGNED nXDest, SIGNED nYDest, SIGNED nWidthDest, SIGNED |
        nHeightDest, HDC hdcSrc, SIGNED nXSrc, SIGNED nYSrc, SIGNED nWSrc, SIGNED nHSrc, LONG dwRop), BOOL, PASCAL, PROC, NAME('StretchBlt')
      winapi::BitBlt(HDC hDcDest, SIGNED nXDest, SIGNED nYDest, SIGNED nWidth, SIGNED nHeight, HDC hDcSrc, SIGNED nXSrc, SIGNED nYSrc, ULONG dwRop), BOOL, RAW, PASCAL, NAME('BitBlt'), PROC
      winapi::UpdateWindow(HWND hWnd),BOOL,PASCAL,PROC,NAME('UpdateWindow')
      winapi::EnableWindow(HWND hWnd,BOOL bEnable),BOOL,PASCAL,PROC,NAME('EnableWindow')
      winapi::RedrawWindow(HWND hWnd, *_RECT_ lprcUpdate, HRGN hrgnUpdate, UNSIGNED flags), BOOL, RAW, PASCAL, PROC, NAME('RedrawWindow')
      winapi::DrawText(HDC hdc, LONG lpchText, LONG cchText, *_RECT_ lprc, LONG format), LONG, PROC, RAW, PASCAL, NAME('DrawTextA')
      winapi::TextOut(HDC hdc, LONG x, LONG y, LONG pText, LONG len), BOOL, PROC, PASCAL, NAME('TextOutA')
      winapi::GetTextColor(HDC HDC), COLORREF, PROC, PASCAL, NAME('GetTextColor')
      winapi::SetTextColor(HDC HDC, COLORREF color), COLORREF, PROC, PASCAL, NAME('SetTextColor')
      winapi::GetBkColor(HDC HDC), COLORREF, PROC, PASCAL, NAME('GetBkColor')
      winapi::SetBkColor(HDC HDC, COLORREF color), COLORREF, PROC, PASCAL, NAME('SetBkColor')
      winapi::SetBkMode(HDC HDC, LONG mode), LONG, PROC, PASCAL, NAME('SetBkMode')
      winapi::CreateFont(SIGNED nHeight, SIGNED nWidth, SIGNED nEscapement, SIGNED nOrientation, SIGNED fnWeight, UNSIGNED fdwItalic, |
        UNSIGNED fdwUnderline, UNSIGNED fdwStrikeOut, UNSIGNED fdwCharSet, UNSIGNED fdwOutputPrecision, UNSIGNED fdwClipPrecision, | 
        UNSIGNED fdwQuality, UNSIGNED fdwPitchAndFamily, *CSTRING lpszFace), HFONT, PASCAL, RAW, NAME('CreateFontA')
      winapi::GetDeviceCaps(HANDLE pDC, LONG pIndex), LONG, PASCAL, NAME('GetDeviceCaps')
      winapi::MulDiv(LONG,LONG,LONG), LONG, PASCAL, NAME('MulDiv')
      winapi::ExcludeClipRect(HDC hdc, LONG left, LONG top, LONG right, LONG bottom), LONG, PROC, PASCAL, NAME('ExcludeClipRect')
      winapi::SetCapture(HWND hwnd), HWND, PASCAL, PROC, NAME('SetCapture')
      winapi::ReleaseCapture(), BOOL, PASCAL, PROC, NAME('ReleaseCapture')
      winapi::InvalidateRect(HWND hwnd, *_RECT_ lpRect, BOOL bErase),BOOL,RAW,PASCAL,PROC,NAME('InvalidateRect')
      winapi::InvalidateRect(HWND hwnd, LONG lpRect, BOOL bErase),BOOL,RAW,PASCAL,PROC,NAME('InvalidateRect')
      winapi::GetDlgCtrlID(HWND hwnd), LONG, PASCAL, NAME('GetDlgCtrlID')

      winapi::GetScrollInfo(HWND hwnd, SIGNED fnBar, *SCROLLINFO lpsi),BOOL,RAW,PASCAL,NAME('GetScrollInfo')
      winapi::ShowScrollBar(HWND hwnd, SIGNED wBar, BOOL bShow),BOOL,PASCAL,PROC,NAME('ShowScrollBar')

      winapi::CreateFile(*CSTRING,ULONG,ULONG,LONG,ULONG,ULONG,UNSIGNED=0),UNSIGNED,RAW,PASCAL,NAME('CreateFileA')
      winapi::ReadFile(HANDLE hFile, LONG lpBuffer, LONG dwBytes, *LONG dwBytesRead, LONG lpOverlapped),BOOL,RAW,PASCAL,PROC,NAME('ReadFile')
      winapi::WriteFile(HANDLE hFile, LONG lpBuffer, LONG dwBytes, *LONG dwBytesWritten, LONG lpOverlapped),BOOL,RAW,PASCAL,PROC,NAME('WriteFile')
      winapi::CloseHandle(HANDLE hFile),BOOL,PASCAL,PROC,NAME('CloseHandle')
      winapi::GetFileSize(HANDLE hFile, LONG pFileSizeHigh),LONG,RAW,PASCAL,NAME('GetFileSize')

      winapi::GetTempPath(UNSIGNED nBufferLength, *CSTRING lpBuffer), UNSIGNED, PASCAL, RAW, PROC, NAME('GetTempPathA')
      winapi::GetTempFileName(*CSTRING lpPathName, *CSTRING lpPrefixString, UNSIGNED uUnique, *CSTRING lpTempFileName), UNSIGNED, PASCAL, RAW, PROC, NAME('GetTempFileNameA')

      winapi::PtInRect(*_RECT_ rc, POINT pt),BOOL,RAW,PASCAL,NAME('PtInRect')

      winapi::SetTimer(HWND hWnd, UNSIGNED nIDEvent, UNSIGNED uElapse, long lpTimerFunc),UNSIGNED,PASCAL,PROC,NAME('SetTimer')
      winapi::KillTimer(HWND hWnd, UNSIGNED uIDEvent),BOOL,PASCAL,PROC,NAME('KillTimer')

      winapi::BeginPaint(HWND hWnd, *PAINTSTRUCT lpPaint),HDC,RAW,PASCAL,PROC,NAME('BeginPaint')
      winapi::EndPaint(HWND hWnd, *PAINTSTRUCT lpPaint),BOOL,RAW,PROC,PASCAL,NAME('EndPaint')

      winapi::Ellipse(HDC hdc,LONG pLeft,LONG pTop,LONG pRight,LONG pBottom),BOOL,PROC,PASCAL,NAME('Ellipse')
      winapi::Polygon(HDC HDC, LONG apt, LONG cpt),BOOL,PASCAL,PROC,NAME('Polygon')

      winapi::PlaySound(*CSTRING pszSound, HMODULE hmod, UNSIGNED fdwSound),BOOL,PROC,RAW,PASCAL,NAME('PlaySoundA')

      winapi::GetModuleHandle(<*CSTRING pszModuleName>),HMODULE,PASCAL,RAW,NAME('GetModuleHandleA')
      winapi::FindResource(HMODULE hModule, *CSTRING lpName, *CSTRING lpType),HRSRC,PASCAL,RAW,NAME('FindResourceA')
      winapi::LoadResource(HMODULE hModule, HRSRC hResInfo),HGLOBAL,PASCAL,NAME('LoadResource')
      winapi::LockResource(HGLOBAL hResData),LONG,PASCAL,NAME('LockResource')
      winapi::SizeofResource(HMODULE hModule, HRSRC hResInfo),UNSIGNED,PASCAL,NAME('SizeofResource')

      winapi::mciSendString(*CSTRING lpszCommand, <*CSTRING lpszReturnString>, UNSIGNED cchReturn, HANDLE  hwndCallback),MCIERROR,RAW,PASCAL,NAME('mciSendStringA')
      winapi::mciGetErrorString(MCIERROR fdwError, *CSTRING lpszErrorText, UNSIGNED cchErrorText),BOOL,RAW,PASCAL,NAME('mciGetErrorStringA')

      winapi::memcpy(LONG lpDest,LONG lpSource,LONG nCount),LONG,PROC,NAME('_memcpy')
      winapi::GetLastError(), LONG, PASCAL, NAME('GetLastError')
    END
  END

winapi::OS_INVALID_HANDLE_VALUE   EQUATE(-1)
DWORD                         EQUATE(ULONG)

!-- Screen capture
BITMAPFILEHEADER              GROUP, TYPE
bfType                          USHORT
bfSize                          DWORD
bfReserved1                     USHORT
bfReserved2                     USHORT
bfOffBits                       DWORD
                              END

!-- In Clarion 6 BITMAP declaration has a bug
winBITMAP                     GROUP, TYPE
bmType                          LONG
bmWidth                         LONG
bmHeight                        LONG
bmWidthBytes                    LONG
bmPlanes                        USHORT
bmBitsPixel                     USHORT
bmBits                          LONG
                              END

!-- PlaySound flags
SND_SYNC                      EQUATE(0)
SND_ASYNC                     EQUATE(1)
SND_NODEFAULT                 EQUATE(2)
SND_MEMORY                    EQUATE(4)
SND_LOOP                      EQUATE(8)
SND_NOSTOP                    EQUATE(16)
SND_NOWAIT                    EQUATE(2000h)
SND_ALIAS                     EQUATE(10000h)
SND_ALIAS_ID                  EQUATE(110000h)
SND_FILENAME                  EQUATE(20000h)
SND_RESOURCE                  EQUATE(40004h)
SND_PURGE                     EQUATE(40h)
SND_APPLICATION               EQUATE(80h)
SND_ALIAS_SYSTEMASTERISK      EQUATE(10835)
SND_ALIAS_SYSTEMQUESTION      EQUATE(16211)
SND_ALIAS_SYSTEMHAND          EQUATE(18515)
SND_ALIAS_SYSTEMEXIT          EQUATE(17747)
SND_ALIAS_SYSTEMSTART         EQUATE(21331)
SND_ALIAS_SYSTEMWELCOME       EQUATE(22355)
SND_ALIAS_SYSTEMEXCLAMATION   EQUATE(8531)
SND_ALIAS_SYSTEMDEFAULT       EQUATE(17491)

!!!region static functions
COLORREF::FromRGB             PROCEDURE(BYTE r, BYTE g, BYTE b)
  CODE
  RETURN BOR(BOR(BSHIFT(b, 16), BSHIFT(g, 8)), r)
  
COLORREF::FromClarion         PROCEDURE(LONG pClaColor)
clrGrp                          GROUP, OVER(pClaColor), PRE(colorGrp)
r                                 BYTE
g                                 BYTE
b                                 BYTE
                                END
  CODE
  RETURN COLORREF::FromRGB(clrGrp:r, clrGrp:g, clrGrp:b)
  
COLORREF::ToRGB               PROCEDURE(COLORREF pWinColor, *BYTE r, *BYTE g, *BYTE b)
clrGrp                          GROUP, OVER(pWinColor), PRE(colorGrp)
r                                 BYTE
g                                 BYTE
b                                 BYTE
                                END
  CODE
  r = clrGrp:r
  g = clrGrp:g
  b = clrGrp:b

COLORREF::ToClarion           PROCEDURE(COLORREF pWinColor)
winClrGrp                       GROUP, OVER(pWinColor), PRE(winClrGrp)
r                                 BYTE
g                                 BYTE
b                                 BYTE
                                END
claColor                        LONG, AUTO
ClaClrGrp                       GROUP, OVER(claColor), PRE(ClaClrGrp)
r                                 BYTE
g                                 BYTE
b                                 BYTE
                                END
  CODE
  ClaClrGrp :=: winClrGrp
  RETURN claColor
!!!endregion
  
!!!region TWnd
TWnd.Construct                PROCEDURE()
  CODE
  
TWnd.Destruct                 PROCEDURE()
  CODE
  SELF.ResetWndProc()
  SELF.W &= NULL
  
TWnd.Init                     PROCEDURE(<*WINDOW w>)
  CODE
  IF NOT OMITTED(w)
    SELF.W &= w
  ELSE
    SELF.W &= SYSTEM{PROP:Target}
  END
  SELF.FEQ = 0
  SELF.SetHandle(SELF.W{PROP:Handle})
  
TWnd.Init                     PROCEDURE(LONG pFeq)
  CODE
  SELF.FEQ = pFeq
  SELF.W &= NULL
  SELF.SetHandle(SELF.FEQ{PROP:Handle})

TWnd.GetHandle                PROCEDURE()
  CODE
  RETURN SELF.hwnd

TWnd.SetHandle                PROCEDURE(HWND hwnd)
  CODE
  SELF.hwnd = hwnd

TWnd.GetWindow                PROCEDURE()
  CODE
  RETURN SELF.W
  
TWnd.SetWndProc               PROCEDURE(LONG lpCallback, LONG lpUserData)
  CODE
  !- save previous window proc and data
  SELF.wndProc = SELF.GetWindowLong(GWL_WNDPROC)
  SELF.userData = SELF.GetWindowLong(GWL_USERDATA)
  !- set new window user data and proc
  SELF.SetWindowLong(GWL_USERDATA, lpUserData)
  SELF.SetWindowLong(GWL_WNDPROC, lpCallback)

TWnd.ResetWndProc             PROCEDURE()
  CODE
  IF SELF.wndProc <> 0
    !- restore previous window proc
    SELF.SetWindowLong(GWL_WNDPROC, SELF.wndProc)
    SELF.wndProc = 0
    
    IF SELF.userData <> 0
      SELF.SetWindowLong(GWL_USERDATA, SELF.userData)
      SELF.userData = 0
    END
  END

TWnd.CallWindowProc           PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam)
userData                        LONG, AUTO
rv                              LONG, AUTO
  CODE
  IF SELF.wndProc
    !- save our user data
    userData = SELF.GetWindowLong(GWL_USERDATA)
    
    !- restore prev user data
    IF SELF.userData
      SELF.SetWindowLong(GWL_USERDATA, SELF.userData)
    END
    
    !- call previous window proc
    rv = winapi::CallWindowProc(SELF.wndProc, SELF.hWnd, wMsg, wParam, lParam)

    !- restore our user data
    SELF.SetWindowLong(GWL_USERDATA, userData)
    
    !- return winapi::CallWindowProc result
    RETURN rv
  ELSE
    !- call default window proc
    RETURN SELF.DefWindowProc(wMsg, wParam, lParam)
  END

TWnd.DefWindowProc            PROCEDURE(UNSIGNED wMsg, UNSIGNED wParam, LONG lParam)
  CODE
  RETURN winapi::DefWindowProc(SELF.hWnd, wMsg, wParam, lParam)

TWnd.GetWndProc               PROCEDURE()
  CODE
  RETURN SELF.wndProc
    
TWnd.GetUserData              PROCEDURE()
  CODE
  RETURN SELF.userData

TWnd.GetFEQ                   PROCEDURE()
  CODE
  RETURN SELF.FEQ
  
TWnd.GetParent                PROCEDURE()
  CODE
  RETURN winapi::GetParent(SELF.hwnd)
  
TWnd.SetParent                PROCEDURE(HWND hWndNewParent)
  CODE
  RETURN winapi::SetParent(SELF.hwnd, hWndNewParent)
  
TWnd.SetParent                PROCEDURE(TWnd hWndNewParent)
  CODE
  RETURN SELF.SetParent(hWndNewParent.GetHandle())
    
TWnd.SetProp                  PROCEDURE(LONG prop, ? value)
  CODE
  IF NOT SELF.W &= NULL
    SELF.W{prop} = value
  ELSE
    SELF.FEQ{prop} = value
  END
  
TWnd.GetProp                  PROCEDURE(LONG prop)
  CODE
  IF NOT SELF.W &= NULL
    RETURN SELF.W{prop}
  ELSE
    RETURN SELF.FEQ{prop}
  END

TWnd.SetWindowLong            PROCEDURE(LONG nIndex, LONG dwNewLong)
  CODE
  RETURN winapi::SetWindowLong(SELF.hwnd, nIndex, dwNewLong)

TWnd.GetWindowLong            PROCEDURE(LONG nIndex)
  CODE
  RETURN winapi::GetWindowLong(SELF.hwnd, nIndex)
  
TWnd.SendMessage              PROCEDURE(UNSIGNED uMsg, UNSIGNED wParam, LONG lParam)
  CODE
  RETURN winapi::SendMessage(SELF.hwnd, uMsg, wParam, lParam)
  
TWnd.PostMessage              PROCEDURE(UNSIGNED uMsg, UNSIGNED wParam, LONG lParam)
  CODE
  RETURN winapi::PostMessage(SELF.hwnd, uMsg, wParam, lParam)
  
TWnd.PeekMessage              PROCEDURE(LONG lpMsg, LONG wMsgFilterMin = 0, LONG wMsgFilterMax = 0, LONG wRemoveMsg = 0)
  CODE
  RETURN winapi::PeekMessage(lpMsg, SELF.hwnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
  
TWnd.SendEraseBkgnd           PROCEDURE()
dc                              TDC
  CODE
  RETURN SELF.SendMessage(WM_ERASEBKGND, dc.GetDC(SELF.hwnd), 0)
  
TWnd.GetClientRect            PROCEDURE(*_RECT_ rc)
  CODE
  winapi::GetClientRect(SELF.hwnd, rc)

TWnd.GetClientRect            PROCEDURE(*TRect rc)
r                               LIKE(_RECT_)
  CODE
  SELF.GetClientRect(r)
  rc.Assign(r)
  
TWnd.GetWindowRect            PROCEDURE(*_RECT_ rc)
  CODE
  winapi::GetWindowRect(SELF.hwnd, rc)

TWnd.GetWindowRect            PROCEDURE(*TRect rc)
r                               LIKE(_RECT_)
  CODE
  SELF.GetWindowRect(r)
  rc.Assign(r)

TWnd.GetRelativeRect          PROCEDURE(*_RECT_ rc)
  CODE
  SELF.GetRelativeRect(SELF.GetParent(), rc)
  
TWnd.GetRelativeRect          PROCEDURE(*TRect rc)
  CODE
  SELF.GetRelativeRect(SELF.GetParent(), rc)

TWnd.GetRelativeRect          PROCEDURE(HWND pParentHwnd, *_RECT_ rc)
parentWin                       TWnd
  CODE
  parentWin.SetHandle(pParentHwnd)
  SELF.GetRelativeRect(parentWin, rc)

TWnd.GetRelativeRect          PROCEDURE(HWND pParentHwnd, *TRect rc)
r                               LIKE(_RECT_)
  CODE
  SELF.GetRelativeRect(pParentHwnd, r)
  rc.Assign(r)
  
TWnd.GetRelativeRect          PROCEDURE(TWnd pWin, *_RECT_ prc)
r                               LIKE(_RECT_)
  CODE
  !- get screen coordinates
  SELF.GetWindowRect(r)
  !- transform to parent client coordinates
  pWin.ScreenToClient(r)
  prc = r

TWnd.GetRelativeRect          PROCEDURE(TWnd pWin, *TRect rc)
r                               LIKE(_RECT_)
  CODE
  SELF.GetRelativeRect(pWin, r)
  rc.Assign(r)
  
TWnd.SetWindowPos             PROCEDURE(HWND hWndInsertAfter, LONG x, LONG y, LONG cx, LONG cy, ULONG uFlags)
  CODE
  RETURN winapi::SetWindowPos(SELF.hwnd, hWndInsertAfter, x, y, cx, cy, uFlags)
  
TWnd.ScreenToClient           PROCEDURE(*POINT ppt)
  CODE
  winapi::ScreenToClient(SELF.hwnd, ppt)
  
TWnd.ScreenToClient           PROCEDURE(*_RECT_ prc)
pt1                             LIKE(POINT), AUTO
pt2                             LIKE(POINT), AUTO
  CODE
  pt1.x = prc.left
  pt1.y = prc.top
  pt2.x = prc.right
  pt2.y = prc.bottom
  SELF.ScreenToClient(pt1)
  SELF.ScreenToClient(pt2)
  prc.left = pt1.x
  prc.top = pt1.y
  prc.right = pt2.x
  prc.bottom = pt2.y

TWnd.ScreenToClient           PROCEDURE(*TRect prc)
rc                              LIKE(_RECT_), AUTO
  CODE
  prc.AssignTo(rc)
  SELF.ScreenToClient(rc)
  prc.Assign(rc)
  
TWnd.ClientToScreen           PROCEDURE(*POINT ppt)
  CODE
  winapi::ClientToScreen(SELF.hwnd, ppt)
  
TWnd.ClientToScreen           PROCEDURE(*_RECT_ prc)
pt1                             LIKE(POINT), AUTO
pt2                             LIKE(POINT), AUTO
  CODE
  pt1.x = prc.left
  pt1.y = prc.top
  pt2.x = prc.right
  pt2.y = prc.bottom
  SELF.ClientToScreen(pt1)
  SELF.ClientToScreen(pt2)
  prc.left = pt1.x
  prc.top = pt1.y
  prc.right = pt2.x
  prc.bottom = pt2.y

TWnd.ClientToScreen           PROCEDURE(*TRect prc)
rc                              LIKE(_RECT_), AUTO
  CODE
  prc.AssignTo(rc)
  SELF.ClientToScreen(rc)
  prc.Assign(rc)

TWnd.InvalidateRect           PROCEDURE(_RECT_ rc, BOOL bErase)
  CODE
  RETURN winapi::InvalidateRect(SELF.hwnd, rc, bErase)
  
TWnd.InvalidateRect           PROCEDURE(TRect rc, BOOL bErase)
oRect                           LIKE(_RECT_), AUTO
  CODE
  oRect :=: rc
  RETURN winapi::InvalidateRect(SELF.hwnd, oRect, bErase)
  
TWnd.InvalidateRect           PROCEDURE(BOOL bErase)
  CODE
  RETURN winapi::InvalidateRect(SELF.hwnd, 0, bErase)

TWnd.ShowWindow               PROCEDURE(SIGNED nCmdShow)
  CODE
  RETURN winapi::ShowWindow(SELF.hwnd, nCmdShow)
  
TWnd.SetForegroundWindow      PROCEDURE()
  CODE
  RETURN winapi::SetForegroundWindow(SELF.hwnd)
  
TWnd.UpdateWindow             PROCEDURE()
  CODE
  RETURN winapi::UpdateWindow(SELF.hwnd)
  
TWnd.EnableWindow             PROCEDURE(BOOL pEnable)
  CODE
  RETURN winapi::EnableWindow(SELF.hwnd, pEnable)

TWnd.Redraw                   PROCEDURE(_RECT_ rc)
  CODE
  winapi::RedrawWindow(SELF.hwnd, rc, 0, RDW_INVALIDATE + RDW_UPDATENOW + RDW_ALLCHILDREN)

TWnd.Redraw                   PROCEDURE(TRect rc)
oRect                           LIKE(_RECT_), AUTO
  CODE
  oRect :=: rc
  SELF.Redraw(oRect)

TWnd.SetCapture               PROCEDURE()
  CODE
  RETURN winapi::SetCapture(SELF.hwnd)
  
TWnd.ReleaseCapture           PROCEDURE()
  CODE
  RETURN winapi::ReleaseCapture()

TWnd.GetDlgCtrlID             PROCEDURE()
  CODE
  RETURN winapi::GetDlgCtrlID(SELF.hwnd)
  
TWnd.GetBitmap                PROCEDURE(<_RECT_ pRect>, LONG dwRop=SRCCOPY)
!http://stackoverflow.com/questions/3291167/how-can-i-take-a-screenshot-in-a-windows-application
hdcWindow                       TDC
hdcMemory                       TDC
r                               GROUP(_RECT_).
w                               LONG, AUTO
h                               LONG, AUTO
hBitmap                         TBitmap
hOldBitmap                      TBitmap
pbi                             &STRING
bih                             &BITMAPINFOHEADER
lpBits                          &STRING !memory pointer
bmpFile                         TIODevice
hdr                             GROUP(BITMAPFILEHEADER). ! bitmap file-header
dwTmp                           LONG, AUTO
sBits                           &STRING
  CODE
  ! get the device context of the window
  hdcWindow.GetDC(SELF.hwnd)
  
  ! get the device context to put it in
  hdcMemory.CreateCompatibleDC(hdcWindow)
  
  IF OMITTED(pRect) OR (pRect.left=0 AND pRect.top=0 AND pRect.right=0 AND pRect.bottom=0)
    !- get client rect
    SELF.GetClientRect(r)
  ELSE
    r = pRect
  END

  w = r.right - r.left
  h = r.bottom - r.top
  
  ! Create a compatible bitmap from the Window DC
  hBitmap.CreateCompatibleBitmap(hdcWindow, w, h)
  
  ! get a new bitmap, save current bitmap
  hOldBitmap.SetHandle(hBitmap.SelectObject(hdcMemory))
  
!  hdcMemory.BitBlt(0, 0, w, h, hdcWindow, r.left, r.top, SRCCOPY)
!  hdcMemory.BitBlt(0, 0, w, h, hdcWindow, r.left, r.top, NOTSRCCOPY)
  hdcMemory.BitBlt(0, 0, w, h, hdcWindow, r.left, r.top, dwRop)
  
  hBitmap.SetHandle(hOldBitmap.SelectObject(hdcMemory))
  
  hdcMemory.DeleteDC()

  ! now your image is held in hBitmap. You can save it or do whatever with it
  pbi &= hBitmap.CreateBitmapInfoStruct()

  IF NOT pbi &= NULL
    bih &= ADDRESS(pbi)

    lpBits &= NEW STRING(bih.biSizeImage)
  
    ! Retrieve the color table (RGBQUAD array) and the bits  
    ! (array of palette indices) from the DIB.  
    IF hdcWindow.GetDIBits(hBitmap, 0, bih.biHeight, ADDRESS(lpBits), ADDRESS(pbi), DIB_RGB_COLORS)
      hdr.bfType = 04d42h        ! 0x42 = "B" 0x4d = "M"  
        
      ! Compute the size of the entire file.  
      hdr.bfSize = SIZE(BITMAPFILEHEADER) + bih.biSize + bih.biClrUsed * SIZE(RGBQUAD) + bih.biSizeImage
      hdr.bfReserved1 = 0 
      hdr.bfReserved2 = 0 
    
      ! Compute the offset to the array of color indices.  
      hdr.bfOffBits = SIZE(BITMAPFILEHEADER) + bih.biSize + bih.biClrUsed * SIZE(RGBQUAD)
    
      sBits &= NEW STRING(SIZE(BITMAPFILEHEADER) + (SIZE(BITMAPINFOHEADER) + bih.biClrUsed * SIZE(RGBQUAD)) + bih.biSizeImage)
      winapi::memcpy(ADDRESS(sBits), ADDRESS(hdr), SIZE(BITMAPFILEHEADER))
      sBits[SIZE(BITMAPFILEHEADER)+1 : LEN(sBits)] = SUB(pbi, 1, SIZE(BITMAPINFOHEADER) + bih.biClrUsed * SIZE(RGBQUAD)) & lpBits
    ELSE
      printd('GetDIBits error %i', winapi::GetLastError())
    END
    
    DISPOSE(lpBits)
    DISPOSE(pbi)
  ELSE
    printd('CreateBitmapInfoStruct failed, bi.biSizeImage = 0')
  END
      
  hdcWindow.ReleaseDC()

  RETURN sBits

TWnd.SaveBitmap               PROCEDURE(STRING pFIleName, <_RECT_ pRect>)
bmpFile                         TDiskFile
sBits                           &STRING, AUTO
rc                              BOOL(FALSE)
  CODE
  sBits &= SELF.GetBitmap(pRect)
  IF NOT sBits &= NULL
    rc = bmpFile.SaveFile(pFIleName, sBits)
    DISPOSE(sBits)
  ELSE
    RETURN FALSE
  END
  
TWnd.CopyBitmap               PROCEDURE(SIGNED pImageFeq, <_RECT_ pRect>)
sBits                           &STRING
  CODE
  ASSERT(pImageFeq <> 0 AND pImageFeq{PROP:Type} = CREATE:image, 'Invalid control type.')
  IF pImageFeq = 0 OR pImageFeq{PROP:Type} <> CREATE:image
    RETURN FALSE
  END
  
  sBits &= SELF.GetBitmap(pRect)
  IF NOT sBits &= NULL
    pImageFeq{PROP:ImageBits} = sBits
    DISPOSE(sBits)
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
  
TWnd.GetScrollInfo            PROCEDURE(SIGNED fnBar, *SCROLLINFO lpsi)
rc                              BOOL, AUTO
  CODE
  rc = winapi::GetScrollInfo(SELF.hwnd, fnBar, lpsi)
  IF NOT rc
    printd('GetScrollInfo failed, error %i', winapi::GetLastError())
  END
  RETURN rc
  
TWnd.GetScrollRange           PROCEDURE(*SIGNED pHMin, *SIGNED pHMax, *SIGNED pVMin, *SIGNED pVMax)
si                              LIKE(SCROLLINFO)
  CODE
  CLEAR(pHMin, -1)
  CLEAR(pHMax, -1)
  CLEAR(pVMin, +1)
  CLEAR(pVMax, +1)
  !- retrieve horiz range
  si.cbSize = SIZE(SCROLLINFO)
  si.fMask = SIF_RANGE
  IF SELF.GetScrollInfo(SB_HORZ, si)
    pHMin = si.nMin
    pHMax = si.nMax
  END
  !- retrieve vert range
  si.cbSize = SIZE(SCROLLINFO)
  si.fMask = SIF_RANGE
  IF SELF.GetScrollInfo(SB_VERT, si)
    pVMin = si.nMin
    pVMax = si.nMax
  END

TWnd.GetScrollRange           PROCEDURE(*_RECT_ pRect)
  CODE
  SELF.GetScrollRange(pRect.left, pRect.right, pRect.top, pRect.bottom)
  
TWnd.ShowScrollBar            PROCEDURE(SIGNED wBar, BOOL bShow)
  CODE
  RETURN winapi::ShowScrollBar(SELF.hwnd, wBar, bShow)
!!!endregion

!!!region TCWnd
TCWnd.Init                    PROCEDURE(<*WINDOW w>)
  CODE
  IF NOT OMITTED(w)
    SELF.W &= w
  ELSE
    SELF.W &= SYSTEM{PROP:Target}
  END
  SELF.hwnd = SELF.W{PROP:ClientHandle}
!!!endregion
  
!!!region TPoint
TPoint.Offset                 PROCEDURE(SIGNED xOffset, SIGNED yOffset)
  CODE
  SELF.x += xOffset
  SELF.y += yOffset
  
TPoint.Offset                 PROCEDURE(*POINT pt)
  CODE
  SELF.Offset(pt.x, pt.y)
  
TPoint.Offset                 PROCEDURE(*TPoint pt)
  CODE
  SELF.Offset(pt.x, pt.y)
 
TPoint.Offset                 PROCEDURE(*SIZE sz)
  CODE
  SELF.Offset(sz.cx, sz.cy)

TPoint.Equal                  PROCEDURE(*POINT pt)
  CODE
  IF pt.x = SELF.x AND pt.y = SELF.y
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
  
TPoint.Equal                  PROCEDURE(*TPoint pt)
  CODE
  IF pt.x = SELF.x AND pt.y = SELF.y
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
  
TPoint.ToString               PROCEDURE()
  CODE
  RETURN printf('(%i,%i)', SELF.x, SELF.y)
!!!endregion
  
!!!region TRect
TRect.Width                   PROCEDURE()
  CODE
  RETURN SELF.right - SELF.left

TRect.Width                   PROCEDURE(SIGNED pNewWidth)
  CODE
  SELF.right += (pNewWidth-SELF.Width())
  
TRect.Height                  PROCEDURE()
  CODE
  RETURN SELF.bottom - SELF.top

TRect.Height                  PROCEDURE(SIGNED pNewHeight)
  CODE
  SELF.bottom += (pNewHeight-SELF.Height())

TRect.Assign                  PROCEDURE(_RECT_ rc)
  CODE
  SELF.Assign(rc.left, rc.top, rc.right, rc.bottom)

TRect.Assign                  PROCEDURE(*TRect rc)
  CODE
  SELF.Assign(rc.left, rc.top, rc.right, rc.bottom)

TRect.Assign                  PROCEDURE(SIGNED left, SIGNED top, SIGNED right, SIGNED bottom)
  CODE
  SELF.left = left
  SELF.top = top
  SELF.right = right
  SELF.bottom = bottom

TRect.AssignTo                PROCEDURE(*_RECT_ rc)
  CODE
  rc.left = SELF.left
  rc.top = SELF.top
  rc.right = SELF.right
  rc.bottom = SELF.bottom
  
TRect.AssignTo                PROCEDURE(*TRect rc)
  CODE
  rc.Assign(SELF.left, SELF.top, SELF.right, SELF.bottom)

TRect.Equal                   PROCEDURE(_RECT_ rc)
  CODE
  IF SELF.left = rc.left AND SELF.top = rc.top AND SELF.right = rc.right AND SELF.bottom = rc.bottom
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
  
TRect.Equal                   PROCEDURE(*TRect rc)
r                               LIKE(_RECT_)
  CODE
  rc.AssignTo(r)
  RETURN SELF.Equal(r)
  
TRect.PtInRect                PROCEDURE(SIGNED pX, SIGNED pY)
pt                              LIKE(POINT)
  CODE
  pt.x = pX
  pt.y = pY
  RETURN SELF.PtInRect(pt)

TRect.PtInRect                PROCEDURE(*POINT pt)
rc                              LIKE(_RECT_)
  CODE
  SELF.AssignTo(rc)
  RETURN winapi::PtInRect(rc, pt)

TRect.PtInRect                PROCEDURE(*TPoint pt)
  CODE
  RETURN SELF.PtInRect(pt.x, pt.y)
  
TRect.Intersect               PROCEDURE(_RECT_ rc)
  CODE
  IF (rc.left > SELF.right) OR (rc.right < SELF.left) OR (rc.top > SELF.bottom) OR (rc.bottom < SELF.top)
    RETURN FALSE
  ELSE
    RETURN TRUE
  END
  
TRect.Intersect               PROCEDURE(*TRect rc)
r2                              LIKE(_RECT_)
  CODE
  rc.AssignTo(r2)
  RETURN SELF.Intersect(r2)

TRect.ToString                PROCEDURE()
  CODE
  RETURN printf('(%i,%i,%i,%i)', SELF.left, SELF.top, SELF.right, SELF.bottom)
!!!endregion
  
!!!region TDC
TDC.Construct                 PROCEDURE()
  CODE
  
TDC.Destruct                  PROCEDURE()
  CODE
  SELF.ReleaseDC()
  
TDC.FromHDC                   PROCEDURE(HDC pDC)
  CODE
  SELF.ReleaseDC()
  SELF.handle = pDC
  SELF.hwnd = SELF.WindowFromDC()
  
TDC.GetDC                     PROCEDURE(HWND hwnd)
  CODE
  SELF.ReleaseDC()
  SELF.hwnd = hwnd
  SELF.handle = winapi::GetDC(hwnd)
  RETURN SELF.handle
  
TDC.GetDCEx                   PROCEDURE(HWND hwnd, ULONG flags)
  CODE
  SELF.ReleaseDC()
  SELF.hwnd = hwnd
  SELF.handle = winapi::GetDCEx(hwnd, 0, flags)
  RETURN SELF.handle
  
TDC.CreateCompatibleDC        PROCEDURE(*TDC pDC)
  CODE
  RETURN SELF.CreateCompatibleDC(pDC.handle)
  
TDC.CreateCompatibleDC        PROCEDURE(HDC hdc)
  CODE
  SELF.handle = winapi::CreateCompatibleDC(hdc)
  RETURN SELF.handle

TDC.FillRect                  PROCEDURE(*_RECT_ r, TBrush br)
  CODE
  RETURN winapi::FillRect(SELF.handle, r, br.GetHandle())

TDC.FillRect                  PROCEDURE(*TRect r, TBrush br)
rc                              LIKE(_RECT_), AUTO
  CODE
  r.AssignTo(rc)
  RETURN SELF.FillRect(rc, br)
  
TDC.MoveTo                    PROCEDURE(SIGNED x, SIGNED y, <*POINT lpPoint>)
pt                              LIKE(POINT), AUTO
  CODE
  winapi::MoveToEx(SELF.handle, x, y, pt)
  IF NOT OMITTED(lpPoint)
    lpPoint = pt
  END

TDC.LineTo                    PROCEDURE(SIGNED x, SIGNED y)
  CODE
  winapi::LineTo(SELF.handle, x, y)

TDC.StretchBlt                PROCEDURE(_RECT_ rcDest, *TDC dcSrc, _RECT_ rcSrc, LONG dwRop = SRCCOPY)
  CODE
  RETURN winapi::StretchBlt(SELF.handle, rcDest.left, rcDest.top, rcDest.right - rcDest.left, rcDest.bottom - rcDest.top, | 
    dcSrc.GetHandle(), rcSrc.left, rcSrc.top, rcSrc.right - rcSrc.left, rcSrc.bottom - rcSrc.top, dwRop)

TDC.BitBlt                    PROCEDURE(SIGNED pX, SIGNED pY, SIGNED pW, SIGNED pH, *TDC dcSrc, SIGNED srcX, SIGNED srcY, LONG dwRop = SRCCOPY)
  CODE
  RETURN winapi::BitBlt(SELF.handle, pX, pY, pW, pH, dcSrc.GetHandle(), srcX, srcY, dwRop)

TDC.GetDIBits                 PROCEDURE(TBitmap hbmp, UNSIGNED uStartScan, UNSIGNED cScanLines, LONG lpvBits, LONG lpbi, UNSIGNED uUsage)
  CODE
  RETURN winapi::GetDIBits(SELF.handle, hbmp.GetHandle(), uStartScan, cScanLines, lpvBits, lpbi, uUsage)
  
TDC.GetTextColor              PROCEDURE()
  CODE
  RETURN COLORREF::ToClarion(winapi::GetTextColor(SELF.handle))

TDC.SetTextColor              PROCEDURE(LONG pClaColor)
  CODE
  winapi::SetTextColor(SELF.handle, COLORREF::FromClarion(pClaColor))
  
TDC.GetBkColor                PROCEDURE()
  CODE
  RETURN COLORREF::ToClarion(winapi::GetBkColor(SELF.handle))

TDC.SetBkColor                PROCEDURE(LONG pClaColor)
  CODE
  winapi::SetBkColor(SELF.handle, COLORREF::FromClarion(pClaColor))

TDC.SetBkMode                 PROCEDURE(LONG pMode)
  CODE
  RETURN winapi::SetBkMode(SELF.handle, pMode)

TDC.DrawText                  PROCEDURE(STRING pText, *_RECT_ pRect, LONG pFormat)
szText                          CSTRING(LEN(CLIP(pText)) + 1 + 4) !- 4 extra chars if DT_END_ELLIPSIS or DT_PATH_ELLIPSIS flags are specified
iTextHeight                     LONG, AUTO
  CODE
  IF BAND(pFormat, DT_END_ELLIPSIS) OR BAND(pFormat, DT_PATH_ELLIPSIS)
    szText = CLIP(pText) &'    '
  ELSE
    szText = CLIP(pText)
  END
  
  iTextHeight = winapi::DrawText(SELF.handle, ADDRESS(szText), -1, pRect, pFormat)
  RETURN iTextHeight
  
TDC.DrawText                  PROCEDURE(STRING pText, *TRect pRect, LONG pFormat)
rc                              LIKE(_RECT_), AUTO
iTextHeight                     LONG, AUTO
  CODE
  pRect.AssignTo(rc)
  iTextHeight = SELF.DrawText(pText, rc, pFormat)
  pRect.Assign(rc)
  RETURN iTextHeight
  
TDC.TextOut                   PROCEDURE(LONG pX, LONG pY, STRING pText)
  CODE
  RETURN winapi::TextOut(SELF.handle, pX, pY, ADDRESS(pText), LEN(CLIP(pText)))
  
TDC.Ellipse                   PROCEDURE(LONG pLeft, LONG pTop, LONG pRight, LONG pBottom)
  CODE
  RETURN winapi::Ellipse(SELF.handle, pLeft, pTop, pRight, pBottom)
  
TDC.Ellipse                   PROCEDURE(*_RECT_ rc)
  CODE
  RETURN SELF.Ellipse(rc.left, rc.top, rc.right, rc.bottom)

TDC.Ellipse                   PROCEDURE(*TRect rc)
  CODE
  RETURN SELF.Ellipse(rc.left, rc.top, rc.right, rc.bottom)

TDC.Polygon                   PROCEDURE(LONG apt, LONG cpt)
  CODE
  RETURN winapi::Polygon(SELF.handle, apt, cpt)
  
TDC.ExcludeClipRect           PROCEDURE(*_RECT_ pRect)
  CODE
  RETURN winapi::ExcludeClipRect(SELF.handle, pRect.left, pRect.top, pRect.right, pRect.bottom)

TDC.ExcludeClipRect           PROCEDURE(*TRect pRect)
r                               LIKE(_RECT_), AUTO
  CODE
  pRect.AssignTo(r)
  RETURN SELF.ExcludeClipRect(r)

TDC.ReleaseDC                 PROCEDURE()
  CODE
  IF SELF.handle
    IF SELF.hwnd
      winapi::ReleaseDC(SELF.hwnd, SELF.handle)
    ELSE
      winapi::DeleteDC(SELF.handle)
    END
  END
      
  SELF.hwnd = 0
  SELF.handle = 0

TDC.DeleteDC                  PROCEDURE()
  CODE
  IF SELF.handle
    winapi::DeleteDC(SELF.handle)
    SELF.handle = 0
  END
  
TDC.BeginPaint                PROCEDURE(HWND hWnd, *PAINTSTRUCT lpPaint)
  CODE
  SELF.hwnd = hWnd
  SELF.handle = winapi::BeginPaint(hWnd, lpPaint)
  RETURN SELF.handle
  
TDC.EndPaint                  PROCEDURE(*PAINTSTRUCT lpPaint)
  CODE
  winapi::EndPaint(SELF.hwnd, lpPaint)
  
TDC.GetHandle                 PROCEDURE()
  CODE
  RETURN SELF.handle
  
TDC.WindowFromDC              PROCEDURE()
  CODE
  RETURN winapi::WindowFromDC(SELF.handle)
  
TDC.DrawIconEx                PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,HBRUSH hbrFlickerFreeDraw,UNSIGNED diFlags)
  CODE
  RETURN winapi::DrawIconEx(SELF.handle, xLeft, yTop, hIcon, cxWidth, cyWidth, iStepIfAniCur, hbrFlickerFreeDraw, diFlags)
  
TDC.DrawIconEx                PROCEDURE(SIGNED xLeft,SIGNED yTop,HICON hIcon,SIGNED cxWidth,SIGNED cyWidth,UNSIGNED iStepIfAniCur,*TBrush brFlickerFreeDraw,UNSIGNED diFlags)
  CODE
  RETURN winapi::DrawIconEx(SELF.handle, xLeft, yTop, hIcon, cxWidth, cyWidth, iStepIfAniCur, brFlickerFreeDraw.GetHandle(), diFlags)
  
TDC.DrawImage                 PROCEDURE(STRING pImageFile, UNSIGNED pW, UNSIGNED pH)
bm                              TBitmap
hdcImg                          TDC
  CODE
  IF bm.LoadImage(pImageFile, IMAGE_BITMAP, pW, pH, LR_LOADFROMFILE)
    hdcImg.CreateCompatibleDC(SELF)
    bm.SelectObject(hdcImg)
    SELF.BitBlt(0, 0, pW, pH, hdcImg, 0, 0, SRCCOPY)
    hdcImg.DeleteDC()
    bm.DeleteObject()
    RETURN TRUE
  END
  
  RETURN FALSE

TDC.DrawImage                 PROCEDURE(STRING pImageFile, *TRect rc)
  CODE
  RETURN SELF.DrawImage(pImageFile, rc.Width(), rc.Height())
!!!endregion
  
!!!region TGdiObj
TGdiObj.Construct             PROCEDURE()
  CODE
  
TGdiObj.Destruct              PROCEDURE()
  CODE
    
TGdiObj.GetHandle             PROCEDURE()
  CODE
  RETURN SELF.handle

TGdiObj.SetHandle             PROCEDURE(HGDIOBJ handle)
  CODE
  IF SELF.handle = handle
    !- same object
    RETURN
  END
  
  IF SELF.handle
    !- delete old object
    SELF.DeleteObject()
  END
  
  SELF.handle = handle
  
TGdiObj.SelectObject          PROCEDURE(HDC pDC, <*TGdiObj replacedObject>)
hobj                            HGDIOBJ(0)
  CODE
  IF pDC AND SELF.handle
    hobj = winapi::SelectObject(pDC, SELF.handle)
    
    IF NOT OMITTED(replacedObject)
      replacedObject.SetHandle(hobj)
    END
  END
  
  RETURN hobj
  
TGdiObj.SelectObject          PROCEDURE(*TDC pDC, <*TGdiObj replacedObject>)
  CODE
  RETURN SELF.SelectObject(pDC.GetHandle(), replacedObject)

TGdiObj.DeleteObject          PROCEDURE()
  CODE
  IF SELF.handle
    winapi::DeleteObject(SELF.handle)
    SELF.handle = 0
  END
  
TGdiObj.GetObject             PROCEDURE(LONG cbBuffer, LONG lpvObject)
  CODE
  RETURN winapi::GetObject(SELF.handle, cbBuffer, lpvObject)
!!!endregion

!!!region TPen
TPen.CreatePen                PROCEDURE(SIGNED penStyle, SIGNED nWidth, COLORREF color)
  CODE
  SELF.SetHandle(winapi::CreatePen(penStyle, nWidth, color))
  RETURN SELF.handle
!!!endregion
  
!!!region TBrush
TBrush.CreateSolidBrush       PROCEDURE(COLORREF color)
  CODE
  SELF.SetHandle(winapi::CreateSolidBrush(color))
  RETURN SELF.handle

TBrush.CreateSolidBrush       PROCEDURE(BYTE r, BYTE g, BYTE b)
  CODE
  RETURN SELF.CreateSolidBrush(COLORREF::FromRGB(r, g, b))
!!!endregion
  
!!!region Bitmap
TBitmap.CreateCompatibleBitmap    PROCEDURE(HDC pDC, SIGNED cx, SIGNED cy)
  CODE
  SELF.SetHandle(winapi::CreateCompatibleBitmap(pDC, cx, cy))
  RETURN SELF.handle

TBitmap.CreateCompatibleBitmap    PROCEDURE(*TDC pDC, SIGNED cx, SIGNED cy)
  CODE
  RETURN SELF.CreateCompatibleBitmap(pDC.GetHandle(), cx, cy)
  
TBitmap.CreateBitmapInfoStruct    PROCEDURE()
bmp                                 GROUP(winBITMAP).
cClrBits                            USHORT, AUTO
pbmi                                &STRING !*BITMAPINFO
bmih                                GROUP(BITMAPINFOHEADER).

  CODE
  ! Retrieve the bitmap color format, width, and height.  
  IF SELF.GetObject(SIZE(winBITMAP), ADDRESS(bmp))
    ! Convert the color format to a count of bits.  
    cClrBits = bmp.bmPlanes * bmp.bmBitsPixel
    IF cClrBits = 1
      cClrBits = 1 
    ELSIF cClrBits <= 4
      cClrBits = 4
    ELSIF cClrBits <= 8
      cClrBits = 8
    ELSIF cClrBits <= 16
      cClrBits = 16
    ELSIF cClrBits <= 24 
      cClrBits = 24
    ELSE 
      cClrBits = 32
    END
  
    IF cClrBits < 24
      !Allocate memory for the BITMAPINFO structure. (This structure
      !contains a BITMAPINFOHEADER structure and an array of RGBQUAD
      !data structures.)
      pbmi &= NEW STRING(SIZE(BITMAPINFOHEADER) + SIZE(RGBQUAD) * BSHIFT(1, cClrBits))
    ELSE
      !There is no RGBQUAD array for these formats: 24-bit-per-pixel or 32-bit-per-pixel
      pbmi &= NEW STRING(SIZE(BITMAPINFOHEADER))
    END

    ! Initialize the fields in the BITMAPINFO structure.  

    bmih.biSize = SIZE(BITMAPINFOHEADER)
    bmih.biWidth = bmp.bmWidth
    bmih.biHeight = bmp.bmHeight
    bmih.biPlanes = bmp.bmPlanes
    bmih.biBitCount = bmp.bmBitsPixel
    IF cClrBits < 24
      bmih.biClrUsed = BSHIFT(1, cClrBits)
    END
  
    ! all colors are required.
    bmih.biCompression = 0

    ! Compute the number of bytes in the array of color  
    ! indices and store the result in biSizeImage.  
    ! The width must be DWORD aligned unless the bitmap is RLE 
    ! compressed. 
    bmih.biSizeImage = ((bmih.biWidth * cClrBits + 31) / 32) * 4 * bmih.biHeight
    ! Set biClrImportant to 0, indicating that all of the  
    ! device colors are important.  
    bmih.biClrImportant = 0
  
    pbmi[1 : SIZE(BITMAPINFOHEADER)] = bmih
  ELSE
    printd('GetObject error %i', winapi::GetLastError())
  END
  
  RETURN pbmi

TBitmap.LoadImage             PROCEDURE(HINSTANCE hInst, STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE)
szImage                         CSTRING(LEN(CLIP(pImage))+1)
  CODE
  szImage = CLIP(pImage)
  SELF.handle = winapi::LoadImage(hInst, szImage, uType, cxDesired, cyDesired, fuLoad)
  RETURN SELF.handle

TBitmap.LoadImage             PROCEDURE(STRING pImage, UNSIGNED uType=IMAGE_BITMAP, SIGNED cxDesired=0, SIGNED cyDesired=0, UNSIGNED fuLoad=LR_LOADFROMFILE)
  CODE
  RETURN SELF.LoadImage(0, pImage, uType, cxDesired, cyDesired, fuLoad)
!!!endregion
  
!!!region TLogicalFont
TLogicalFont.CreateFont       PROCEDURE(HDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT)
nHeight                         SIGNED, AUTO
nWeight                         SIGNED(FONT:regular)
bItalic                         UNSIGNED(FALSE)
bUnderline                      UNSIGNED(FALSE)
bStrikeout                      UNSIGNED(FALSE)
szFace                          CSTRING(LEN(CLIP(pTypeface)) + 1), AUTO
  CODE
  nHeight = -winapi::MulDiv(pSize, winapi::GetDeviceCaps(pDC, 90), 72)  !LOGPIXELSY = 90 Logical pixels inch in Y
  
  IF BAND(pStyle, FONT:bold) = FONT:bold
    nWeight = FONT:bold
  END
    
  IF BAND(pStyle, FONT:italic) = FONT:italic
    bItalic = TRUE
  END

  IF BAND(pStyle, FONT:underline) = FONT:underline
    bUnderline = TRUE
  END

  IF BAND(pStyle, FONT:strikeout) = FONT:strikeout
    bStrikeout = TRUE
  END

  szFace = CLIP(pTypeface)
  SELF.SetHandle(winapi::CreateFont(nHeight, 0, 0, 0, nWeight, bItalic, bUnderline, bStrikeout, pCharset, 0, 0, 0, 0, szFace))
  RETURN SELF.handle

TLogicalFont.CreateFont       PROCEDURE(*TDC pDC, STRING pTypeface, UNSIGNED pSize, UNSIGNED pStyle = FONT:regular, LONG pCharset = CHARSET:DEFAULT)
  CODE
  RETURN SELF.CreateFont(pDC.GetHandle(), pTypeface, pSize, pStyle, pCharset)
!!!endregion
  
!!!region TIODevice
TIODevice.GetHandle           PROCEDURE()
  CODE
  RETURN SELF.handle
  
TIODevice.CreateFile          PROCEDURE(STRING pFilename, ULONG dwDesiredAccess, | 
                                ULONG dwShareMode, LONG lpSecurityAttributes, | 
                                ULONG dwCreationDisposition, | 
                                ULONG dwFlagsAndAttributes, | 
                                HANDLE hTemplateFile)
szFilename                      CSTRING(256)
h                               HANDLE, AUTO
  CODE
  szFilename = LONGPATH(pFilename)
  h = winapi::CreateFile(szFilename, dwDesiredAccess, dwShareMode, lpSecurityAttributes, | 
    dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)
  IF h <> winapi::OS_INVALID_HANDLE_VALUE
    SELF.handle = h
    RETURN TRUE
  ELSE
    printd('CreateFile(%s) error %i', pFilename, winapi::GetLastError())
    RETURN FALSE
  END

TIODevice.ReadFile            PROCEDURE(LONG lpBuffer, LONG dwBytes, *LONG dwBytesRead, LONG lpOverlapped)
  CODE
  IF SELF.handle
    IF winapi::ReadFile(SELF.handle, lpBuffer, dwBytes, dwBytesRead, lpOverlapped)
      RETURN TRUE
    ELSE
      printd('ReadFile error %i', winapi::GetLastError())
    END
  END
  
  RETURN FALSE
  
TIODevice.WriteFile           PROCEDURE(LONG lpBuffer, LONG dwBytes, *LONG dwBytesWritten, LONG lpOverlapped)
  CODE
  IF SELF.handle
    IF winapi::WriteFile(SELF.handle, lpBuffer, dwBytes, dwBytesWritten, lpOverlapped)
      RETURN TRUE
    ELSE
      printd('WriteFile error %i', winapi::GetLastError())
    END
  ELSE
    RETURN FALSE
  END
  
TIODevice.WriteFile           PROCEDURE(*GROUP pGrp)
dwBytesWritten                  LONG, AUTO
  CODE
  RETURN SELF.WriteFile(ADDRESS(pGrp), SIZE(pGrp), dwBytesWritten, 0)
    
TIODevice.WriteFile           PROCEDURE(*STRING pStr, <LONG pStrSize>)
dwBytesWritten                  LONG, AUTO
  CODE
  IF OMITTED(pStrSize) OR pStrSize = 0
    pStrSize = LEN(pStr)
  END
  
  RETURN SELF.WriteFile(ADDRESS(pStr), pStrSize, dwBytesWritten, 0)
    
TIODevice.WriteFile           PROCEDURE(STRING pStr, <LONG pStrSize>)
  CODE
  RETURN SELF.WriteFile(pStr, pStrSize)

TIODevice.WriteMem            PROCEDURE(LONG pAddr, LONG pSize)
dwBytesWritten                  LONG, AUTO
  CODE
  RETURN SELF.WriteFile(pAddr, pSize, dwBytesWritten, 0)

TIODevice.WriteByte           PROCEDURE(BYTE pVal)
  CODE
  RETURN SELF.WriteMem(ADDRESS(pVal), SIZE(pVal))

TIODevice.WriteShort          PROCEDURE(SHORT pVal)
  CODE
  RETURN SELF.WriteMem(ADDRESS(pVal), SIZE(pVal))

TIODevice.WriteLong           PROCEDURE(LONG pVal)
  CODE
  RETURN SELF.WriteMem(ADDRESS(pVal), SIZE(pVal))

TIODevice.WriteReal           PROCEDURE(REAL pVal)
  CODE
  RETURN SELF.WriteMem(ADDRESS(pVal), SIZE(pVal))

TIODevice.CloseHandle         PROCEDURE()
  CODE
  IF SELF.handle
    RETURN winapi::CloseHandle(SELF.handle)
  ELSE
    RETURN FALSE
  END
  
TIODevice.GetFileSize         PROCEDURE(<*LONG pFileSizeHigh>)
lpFileSizeLo                    LONG, AUTO
lpFileSizeHi                    LONG, AUTO
  CODE
  IF SELF.handle
    lpFileSizeLo = winapi::GetFileSize(SELF.handle, ADDRESS(lpFileSizeHi))
    IF NOT OMITTED(pFileSizeHigh)
      pFileSizeHigh = lpFileSizeHi
    END
    RETURN lpFileSizeLo
  ELSE
    IF NOT OMITTED(pFileSizeHigh)
      pFileSizeHigh = 0
    END
    RETURN 0
  END
!!!endregion
  
!!!region TDiskFile
TDiskFile.LoadFile            PROCEDURE(STRING pFilename, ULONG dwDesiredAccess=GENERIC_READ, ULONG dwCreationDisposition=OPEN_EXISTING)
sData                           &STRING
dwFileSize                      LONG
dwBytesRead                     LONG
  CODE
  IF SELF.CreateFile(pFilename, dwDesiredAccess, 0, 0, dwCreationDisposition, 0, 0)
    dwFileSize = SELF.GetFileSize()
    IF dwFileSize > 0
      sData &= NEW STRING(dwFileSize)
      SELF.ReadFile(ADDRESS(sData), dwFileSize, dwBytesRead, 0)
    END
    SELF.CloseHandle()
  END

  RETURN sData

TDiskFile.SaveFile            PROCEDURE(STRING pFilename, LONG pData, LONG pDataLen, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS)
dwBytesWritten                  LONG
bRC                             LONG, AUTO
  CODE
  IF SELF.CreateFile(pFilename, dwDesiredAccess, 0, 0, dwCreationDisposition, 0, 0)
    IF SELF.WriteFile(pData, pDataLen, dwBytesWritten, 0)
      SELF.CloseHandle()
      RETURN TRUE
    END
  ELSE
    RETURN FALSE
  END
  
TDiskFile.SaveFile            PROCEDURE(STRING pFilename, *STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS)
  CODE
  RETURN SELF.SaveFile(pFilename, ADDRESS(pData), LEN(pData), dwDesiredAccess, dwCreationDisposition)
  
TDiskFile.SaveFile            PROCEDURE(STRING pFilename, STRING pData, ULONG dwDesiredAccess=GENERIC_WRITE, ULONG dwCreationDisposition=CREATE_ALWAYS)
  CODE
  RETURN SELF.SaveFile(pFilename, pData, dwDesiredAccess, dwCreationDisposition)
!!!endregion
  
!!!region TTempFile
TTempFile.GetTempPath         PROCEDURE()
szTempPath                      CSTRING(260)
  CODE
  winapi::GetTempPath(SIZE(szTempPath), szTempPath)
  RETURN CLIP(szTempPath)
  
TTempFile.GetTempFileName     PROCEDURE(STRING pPathName, STRING pPrefixString, UNSIGNED uUnique=0)
szTempPath                      CSTRING(LEN(CLIP(pPathName))+1), AUTO
szTempName                      CSTRING(260), AUTO
szPrefix                        CSTRING(LEN(CLIP(pPrefixString))+1), AUTO
  CODE
  szTempPath = CLIP(pPathName)
  szPrefix = CLIP(pPrefixString)
  winapi::GetTempFileName(szTempPath, szPrefix, uUnique, szTempName)
  REMOVE(szTempName)  !- If uUnique is zero, GetTempFileName creates an empty file and closes it.
  RETURN CLIP(szTempName)
  
TTempFile.GetTempFileName     PROCEDURE(<STRING pExt>)
tmpName                         STRING(260), AUTO
  CODE
  tmpName = SELF.GetTempFileName(SELF.GetTempPath(), 'tmp')
  IF pExt <> ''
    tmpName = printf('%s.%s', tmpName, pExt)
  END
  RETURN(tmpName)
!!!endregion

!!!region TTimer
TTimer.SetTimer               PROCEDURE(HWND hwnd, UNSIGNED nIDEvent, UNSIGNED uElapse, LONG lpTimerFunc)
  CODE
  SELF.hwnd = hwnd
  SELF.nIDEvent = nIDEvent
  SELF.uTimer = winapi::SetTimer(hwnd, nIDEvent, uElapse, lpTimerFunc)
  RETURN SELF.uTimer

TTimer.SetTimer               PROCEDURE(HWND hwnd, UNSIGNED uElapse)
  CODE
  RETURN SELF.SetTimer(hwnd, 251266, uElapse, 0)

TTimer.SetTimer               PROCEDURE(UNSIGNED uElapse)
w                               TWnd
  CODE
  IF SELF.hwnd
    RETURN SELF.SetTimer(SELF.hwnd, uElapse)
  ELSE
    w.Init()
    RETURN SELF.SetTimer(w.GetHandle(), uElapse)
  END
  
TTimer.KillTimer              PROCEDURE()
rc                              BOOL, AUTO
  CODE
  IF SELF.hwnd
    rc = winapi::KillTimer(SELF.hwnd, SELF.nIDEvent)
  ELSE
    rc =  winapi::KillTimer(SELF.hwnd, SELF.uTimer)
  END
  SELF.hwnd = 0
  SELF.nIDEvent = 0
  SELF.uTimer = 0
 
  RETURN rc
  
TTimer.GetTimerID             PROCEDURE()
  CODE
  IF SELF.hwnd
    RETURN SELF.nIDEvent
  ELSE
    RETURN SELF.uTimer
  END
!!!endregion
  
!!!region SoundPlayer
TSoundPlayer.PlaySound        PROCEDURE(STRING pSound, HMODULE hmod, UNSIGNED fdwSound)
szSound                         CSTRING(LEN(CLIP(pSound))+1)
  CODE
  szSound = CLIP(pSound)
!  printd('PlaySound(%Z, %i, %i)', szSound, hmod, fdwSound)
  RETURN winapi::PlaySound(szSound, hmod, fdwSound)
  
TSoundPlayer.PlayFromFile     PROCEDURE(STRING pFile, UNSIGNED fOptions=0)
fdwSound                        UNSIGNED, AUTO
  CODE
  fdwSound = BOR(BOR(SND_FILENAME, SND_NODEFAULT), fOptions)
  RETURN SELF.PlaySound(pFile, 0, fdwSound)
  
TSoundPlayer.PlayFromResource PROCEDURE(STRING pResourceName, UNSIGNED fOptions=0)
fdwSound                        UNSIGNED, AUTO
  CODE
  fdwSound = BOR(BOR(SND_RESOURCE, SND_NODEFAULT), fOptions)
  RETURN SELF.PlaySound(pResourceName, winapi::GetModuleHandle(), fdwSound)
  
TSoundPlayer.PlaySystemEvent  PROCEDURE(STRING pEventName, UNSIGNED fOptions=0)
fdwSound                        UNSIGNED, AUTO
  CODE
  fdwSound = BOR(SND_ALIAS, fOptions)
  RETURN SELF.PlaySound(pEventName, 0, fdwSound)
  
TSoundPlayer.StopSound        PROCEDURE()
szSound                         &CSTRING
  CODE
  RETURN winapi::PlaySound(szSound, 0, 0)
!!!endregion
  
!!!region TResource
TResource.Construct           PROCEDURE()
  CODE
  
TResource.Destruct            PROCEDURE()
  CODE
  SELF.DisposeResource()
  
TResource.DisposeResource     PROCEDURE()
  CODE
  IF NOT SELF.sResData &= NULL
    DISPOSE(SELF.sResData)
    SELF.sResData &= NULL
  END
  
TResource.GetModuleHandle     PROCEDURE(<STRING pModuleName>)
szModuleName                    CSTRING(LEN(CLIP(pModuleName))+1), AUTO
  CODE
  IF pModuleName
    szModuleName = CLIP(pModuleName)
    SELF.hModule = winapi::GetModuleHandle(szModuleName)
  ELSE
    SELF.hModule = winapi::GetModuleHandle()
  END
  IF SELF.hModule=0
    printd('GetModuleHandle(%Z) failed, error %i', szModuleName, winapi::GetLastError())
  END
  RETURN SELF.hModule
  
TResource.FindResource        PROCEDURE(HMODULE hModule, STRING pName, STRING pType)
szName                          CSTRING(LEN(CLIP(pName))+1), AUTO
szType                          CSTRING(LEN(CLIP(pType))+1), AUTO
  CODE
  szName = CLIP(pName)
  szType = CLIP(pType)
  SELF.hResInfo = winapi::FindResource(hModule, szName, szType)
  IF SELF.hResInfo=0
    printd('FindResource(%i,%Z,%Z) failed, error %i', hModule, szName, szType, winapi::GetLastError())
  END
  RETURN SELF.hResInfo
  
TResource.FindResource        PROCEDURE(STRING pName, STRING pType)
  CODE
  RETURN SELF.FindResource(SELF.hModule, pName, pType)
  
TResource.LoadResource        PROCEDURE(HMODULE hModule, HRSRC hResInfo)
  CODE
  SELF.hResData = winapi::LoadResource(hModule, hResInfo)
  IF SELF.hResData=0
    printd('LoadResource(%i,%i) failed, error %i', hModule, hResInfo, winapi::GetLastError())
  END
  RETURN SELF.hResData
  
TResource.LoadResource        PROCEDURE()
  CODE
  RETURN SELF.LoadResource(SELF.hModule, SELF.hResInfo)
  
TResource.LockResource        PROCEDURE(HGLOBAL hResData)
aResData                        LONG, AUTO
  CODE
  aResData = winapi::LockResource(hResData)
  IF aResData=0
    printd('LockResource(%i) failed, error %i', hResData, winapi::GetLastError())
  END
  RETURN aResData
  
TResource.LockResource        PROCEDURE()
  CODE
  RETURN SELF.LockResource(SELF.hResData)
  
TResource.SizeofResource      PROCEDURE(HMODULE hModule, HRSRC hResInfo)
  CODE
  RETURN winapi::SizeofResource(hModule, hResInfo)
  
TResource.SizeofResource      PROCEDURE()
  CODE
  RETURN SELF.SizeofResource(SELF.hModule, SELF.hResInfo)
  
TResource.GetResource         PROCEDURE(STRING pModuleName, STRING pName, STRING pType)
aData                           LONG, AUTO
nLen                            UNSIGNED, AUTO
  CODE
  SELF.DisposeResource()
  IF SELF.GetModuleHandle(pModuleName)
    IF SELF.FindResource(pName, pType)
      IF SELF.LoadResource()
        aData = SELF.LockResource()
        IF aData
          nLen = SELF.SizeofResource()
          SELF.sResData &= NEW STRING(nLen)
          winapi::memcpy(ADDRESS(SELF.sResData), aData, nLen)
        END
      END
    END
  END
  RETURN SELF.sResData
  
TResource.GetResource         PROCEDURE(STRING pName, STRING pType)
  CODE
  RETURN SELF.GetResource('', pName, pType)
  
TResource.GetResource         PROCEDURE()
  CODE
  RETURN SELF.sResData
!!!endregion
  
!!!region TMCIDevice
TMCIDevice.SendString         PROCEDURE(STRING pCommand, <*STRING pReturnString>, HANDLE hwndCallback = 0)
szCommand                       CSTRING(LEN(CLIP(pCommand))+1), AUTO
szReturnString                  CSTRING(LEN(CLIP(pReturnString))+1), AUTO
rc                              MCIERROR, AUTO
  CODE
  szCommand = CLIP(pCommand)
  IF NOT OMITTED(pReturnString)
    rc = winapi::mciSendString(szCommand, szReturnString, LEN(pReturnString), hwndCallback)
    IF rc = 0
      pReturnString = szReturnString
    END
  ELSE
    rc = winapi::mciSendString(szCommand,,0,hwndCallback)
  END
  SELF.lastError = rc
  RETURN rc
  
TMCIDevice.GetErrorString     PROCEDURE(MCIERROR fdwError)
szErrortext                     CSTRING(256), AUTO
  CODE
  IF winapi::mciGetErrorString(fdwError, szErrortext, LEN(szErrortext))
    RETURN CLIP(szErrortext)
  ELSE
    RETURN 'Unknown error'
  END
  
TMCIDevice.GetErrorString     PROCEDURE()
  CODE
  RETURN SELF.GetErrorString(SELF.lastError)
!!!endregion
  
!!!region TMpegVideo
TMpegVideo.Construct          PROCEDURE()
  CODE
  SELF.theAlias = 'mp3'
  
TMpegVideo.Destruct           PROCEDURE()
  CODE
  SELF.Close()
  
TMpegVideo.Open               PROCEDURE(STRING pFilename)
cmd                             ANY
  CODE
  SELF.Close()
  !- Try to open as mpegvideo
  cmd = printf('open "%s" type mpegvideo alias %s', pFilename, SELF.theAlias)
  IF SELF.SendString(cmd)<> 0
    !- Let MCI deside which file type the song is
    cmd = printf('open "%s" alias %s', pFilename, SELF.theAlias)
    IF SELF.SendString(cmd) = 0
      RETURN TRUE
    ELSE
      printd('%s error %i (%Z)', cmd, SELF.lastError, SELF.GetErrorString())
    END
  END
  RETURN FALSE
  
TMpegVideo.Close              PROCEDURE()
cmd                             ANY
  CODE
  cmd = printf('close %s', SELF.theAlias)
  SELF.SendString(cmd)
  
TMpegVideo.Play               PROCEDURE()
cmd                             ANY
  CODE
  cmd = printf('play %s', SELF.theAlias)
  IF SELF.SendString(cmd) = 0
    RETURN TRUE
  ELSE
    printd('%s error %i (%Z)', cmd, SELF.lastError, SELF.GetErrorString())
    SELF.Close()
    RETURN FALSE
  END
  
TMpegVideo.Pause              PROCEDURE()
cmd                             ANY
  CODE
  IF SELF.IsPaused()
    SELF.Resume()
  ELSIF SELF.IsPlaying()
    cmd = printf('pause %s', SELF.theAlias)
    SELF.SendString(cmd)
  END
  
TMpegVideo.Stop               PROCEDURE()
cmd                             ANY
  CODE
  cmd = printf('stop %s', SELF.theAlias)
  SELF.SendString(cmd)
  SELF.Close()
  
TMpegVideo.Resume             PROCEDURE()
cmd                             ANY
  CODE
  cmd = printf('resume %s', SELF.theAlias)
  SELF.SendString(cmd)
  
TMpegVideo.IsPlaying          PROCEDURE()
cmd                             ANY
returnData                      STRING(7), AUTO
  CODE
  cmd = printf('status %s mode', SELF.theAlias)
  SELF.SendString(cmd, returnData)
  IF returnData = 'playing'
    RETURN TRUE
  END
  RETURN FALSE

TMpegVideo.IsPaused           PROCEDURE()
cmd                             ANY
returnData                      STRING(6), AUTO
  CODE
  cmd = printf('status %s mode', SELF.theAlias)
  SELF.SendString(cmd, returnData)
  IF returnData = 'paused'
    RETURN TRUE
  END
  RETURN FALSE

TMpegVideo.IsStopped          PROCEDURE()
cmd                             ANY
returnData                      STRING(7), AUTO
  CODE
  cmd = printf('status %s mode', SELF.theAlias)
  SELF.SendString(cmd, returnData)
  IF returnData = 'stopped'
    RETURN TRUE
  END
  RETURN FALSE

TMpegVideo.GetPosition        PROCEDURE()
cmd                             ANY
returnData                      STRING(32)
  CODE
  cmd = printf('status %s position', SELF.theAlias)
  SELF.SendString(cmd, returnData)
  RETURN returnData

TMpegVideo.SetPosition        PROCEDURE(LONG milliseconds)
cmd                             ANY
  CODE
  IF SELF.IsPlaying()
    cmd = printf('play %s from %i', SELF.theAlias, milliseconds)
    SELF.SendString(cmd)
  ELSE
    cmd = printf('seek %s to %i', SELF.theAlias, milliseconds)
    SELF.SendString(cmd)
  END
  
TMpegVideo.GetLength          PROCEDURE()
cmd                             ANY
returnData                      STRING(32)
  CODE
  IF SELF.IsPlaying()
    cmd = printf('status %s length', SELF.theAlias)
    SELF.SendString(cmd, returnData)
    RETURN returnData
  ELSE
    RETURN 0
  END
  
TMpegVideo.SetVolume          PROCEDURE(LONG pVolume)
cmd                             ANY
  CODE
  IF pVolume >= 0 AND pVolume <= 1000
    cmd = printf('setaudio %s volume to %i', SELF.theAlias, pVolume)
    SELF.SendString(cmd)
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
  
TMpegVideo.SetBalance         PROCEDURE(LONG pBalance)
cmd                             ANY
  CODE
  IF pBalance >= 0 AND pBalance <= 1000
    cmd = printf('setaudio %s left volume to %i', SELF.theAlias, 1000-pBalance)
    SELF.SendString(cmd)
    cmd = printf('setaudio %s right volume to %i', SELF.theAlias, pBalance)
    SELF.SendString(cmd)
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
!!!endregion