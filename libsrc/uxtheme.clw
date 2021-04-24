!uxtheme support.
!17.04.2021 revision
!mikeduglas 2021
!mikeduglas@yandex.ru

  MEMBER

  INCLUDE('uxtheme.inc'), ONCE
  INCLUDE('svcomdef.inc'), ONCE

  MAP
    MODULE('win api')
      winapi::LoadLibrary(*CSTRING szLibFileName),HINSTANCE,PASCAL,RAW,NAME('LoadLibraryA')
      winapi::FreeLibrary(LONG hModule),BOOL,PASCAL,PROC,NAME('FreeLibrary')
      winapi::GetProcAddress(LONG hModule, *CSTRING szProcName),LONG,PASCAL,RAW,NAME('GetProcAddress')
      winapi::GetProcAddress(LONG hModule, LONG pOrdinalValue),LONG,PASCAL,RAW,NAME('GetProcAddress')
      winapi::GetLastError(),LONG,PASCAL,NAME('GetLastError')
    END
    MODULE('UxTheme API')
      winapi::OpenThemeData(HWND hwnd,LONG pszClassList),HTHEME,PASCAL,NAME('fptr_OpenThemeData'),DLL
      winapi::CloseThemeData(HTHEME hTheme),HRESULT,PASCAL,NAME('fptr_CloseThemeData'),DLL
      winapi::GetThemeSysColorBrush(HTHEME hTheme,LONG iColorId),HBRUSH,PASCAL,NAME('fptr_GetThemeSysColorBrush'),DLL
      winapi::GetThemeSysFont(HTHEME hTheme,LONG iFontId,LONG plf),HRESULT,PASCAL,NAME('fptr_GetThemeSysFont'),DLL
      winapi::DrawThemeTextEx(HTHEME hTheme,HDC hdc,LONG iPartId,LONG iStateId,LONG pszText,LONG cchText, |
        UNSIGNED dwTextFlags,LONG pRect,LONG pOptions),HRESULT,PASCAL,NAME('fptr_DrawThemeTextEx'),DLL
      winapi::HitTestThemeBackground(HTHEME hTheme,HDC hdc,LONG iPartId,LONG iStateId,UNSIGNED dwOptions, |
        LONG pRect,HRGN hrgn,POINT ptTest,*USHORT pwHitTestCode),HRESULT,RAW,PASCAL,NAME('fptr_HitTestThemeBackground'),DLL
    END
  
    INCLUDE('printf.inc'), ONCE
  END

!- uxtheme APIs
UXTHEME_DLLNAME               CSTRING('UxTheme.dll'), STATIC

!https://docs.microsoft.com/en-us/windows/win32/api/uxtheme/

!- OpenThemeData
szOpenThemeData               CSTRING('OpenThemeData'), STATIC
paOpenThemeData               LONG, NAME('fptr_OpenThemeData')
!- CloseThemeData
szCloseThemeData              CSTRING('CloseThemeData'), STATIC
paCloseThemeData              LONG, NAME('fptr_CloseThemeData')
!- GetThemeSysColorBrush
szGetThemeSysColorBrush       CSTRING('GetThemeSysColorBrush'), STATIC
paGetThemeSysColorBrush       LONG, NAME('fptr_GetThemeSysColorBrush')
!- GetThemeSysFont
szGetThemeSysFont             CSTRING('GetThemeSysFont'), STATIC
paGetThemeSysFont             LONG, NAME('fptr_GetThemeSysFont')
!- DrawThemeTextEx
szDrawThemeTextEx             CSTRING('DrawThemeTextEx'), STATIC
paDrawThemeTextEx             LONG, NAME('fptr_DrawThemeTextEx')
!- HitTestThemeBackground
szHitTestThemeBackground      CSTRING('HitTestThemeBackground'), STATIC
paHitTestThemeBackground      LONG, NAME('fptr_HitTestThemeBackground')


 

TUxThemeInitializer           CLASS, TYPE
bInitialized                    BOOL
Construct                       PROCEDURE()
                              END

uxThemeInitializer            TUxThemeInitializer

!!!region TUxThemeInitializer
TUxThemeInitializer.Construct PROCEDURE()
hDll                            HINSTANCE, AUTO
  CODE
  hDll = winapi::LoadLibrary(UXTHEME_DLLNAME)
  IF hDll
    !- get procedure addresses
    paOpenThemeData = winapi::GetProcAddress(hDll, szOpenThemeData)
    paCloseThemeData = winapi::GetProcAddress(hDll, szCloseThemeData)
    paGetThemeSysColorBrush = winapi::GetProcAddress(hDll, szGetThemeSysColorBrush)
    paGetThemeSysFont = winapi::GetProcAddress(hDll, szGetThemeSysFont)
    paDrawThemeTextEx = winapi::GetProcAddress(hDll, szDrawThemeTextEx)
    paHitTestThemeBackground = winapi::GetProcAddress(hDll, szHitTestThemeBackground)

    winapi::FreeLibrary(hDll)
    
    IF paOpenThemeData AND paCloseThemeData |
      AND paGetThemeSysColorBrush AND paGetThemeSysFont |
        AND paHitTestThemeBackground AND paDrawThemeTextEx
      SELF.bInitialized = TRUE
    ELSE
      printd('TUxThemeInitializer.Construct: Cannot load UxTheme APIs.')
    END
    
  ELSE
    printd('TUxThemeInitializer.Construct: LoadLibrary(%Z) failed, error %i', UXTHEME_DLLNAME, winapi::GetLastError())
  END
!!!endregion


!!!region TUxTheme
TUxTheme.Construct            PROCEDURE()
  CODE
  
TUxTheme.Destruct             PROCEDURE()
  CODE
  
TUxTheme.OpenThemeData        PROCEDURE(TWnd wnd, STRING pClassList)
enc                             TStringEncoding
wClassList                      STRING(LEN(CLIP(pClassList))*2+2)
  CODE
  IF uxThemeInitializer.bInitialized
    wClassList = enc.ToUtf16(CLIP(pClassList)) &'<0,0>'
    SELF.hTheme = winapi::OpenThemeData(wnd.GetHandle(), ADDRESS(wClassList))
    RETURN SELF.hTheme
  ELSE
    printd('TUxTheme.OpenThemeData: uxtheme was not initialized')
    RETURN 0
  END
  
TUxTheme.CloseThemeData       PROCEDURE()
  CODE
  IF uxThemeInitializer.bInitialized
    RETURN winapi::CloseThemeData(SELF.hTheme)
  ELSE
    printd('TUxTheme.CloseThemeData: uxtheme was not initialized')
    RETURN E_NOTIMPL
  END
  
TUxTheme.GetThemeSysColorBrush    PROCEDURE(LONG iColorId)
  CODE
  IF uxThemeInitializer.bInitialized
    RETURN winapi::GetThemeSysColorBrush(SELF.hTheme, iColorId)
  ELSE
    printd('TUxTheme.GetThemeSysColorBrush: uxtheme was not initialized')
    RETURN E_NOTIMPL
  END
    
TUxTheme.GetThemeSysFont      PROCEDURE(LONG iFontId, *tagLOGFONTW plf)
  CODE
  IF uxThemeInitializer.bInitialized
    RETURN winapi::GetThemeSysFont(SELF.hTheme, iFontId, ADDRESS(plf))
  ELSE
    printd('TUxTheme.GetThemeSysFont: uxtheme was not initialized')
    RETURN E_NOTIMPL
  END
    
TUxTheme.DrawThemeTextEx      PROCEDURE(TDC dc, LONG iPartId, LONG iStateId, |
                                STRING pText, UNSIGNED dwTextFlags, TRect pRect, typDTTOPTS pOptions)
enc                             TStringEncoding
wText                           STRING(LEN(CLIP(pText))*2+2), AUTO
rc                              LIKE(_RECT_)
  CODE
  IF uxThemeInitializer.bInitialized
    wText = enc.ToUtf16(CLIP(pText)) &'<0,0>'
    pRect.AssignTo(rc)
    pOptions.dwSize = SIZE(typDTTOPTS)
    RETURN winapi::DrawThemeTextEx(SELF.hTheme, dc.GetHandle(), iPartId, iStateId, | 
      ADDRESS(wText), -1, dwTextFlags, rc, ADDRESS(pOptions))
  ELSE
    printd('TUxTheme.DrawThemeTextEx: uxtheme was not initialized')
    RETURN E_NOTIMPL
  END
  
TUxTheme.HitTestThemeBackground   PROCEDURE(TDC dc, LONG iPartId, LONG iStateId, UNSIGNED dwOptions, |
                                    TRect pRect, HRGN hrgn, POINT ptTest, *USHORT pwHitTestCode)
rc                                  LIKE(_RECT_)
  CODE
  IF uxThemeInitializer.bInitialized
    pRect.AssignTo(rc)
    RETURN winapi::HitTestThemeBackground(SELF.hTheme, dc.GetHandle(), iPartId, iStateId, dwOptions, | 
      ADDRESS(rc), hrgn, ptTest, pwHitTestCode)
  ELSE
    printd('TUxTheme.HitTestThemeBackground: uxtheme was not initialized')
    RETURN E_NOTIMPL
  END
!!!endregion