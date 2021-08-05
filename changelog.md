02.08.2021
- TDC: ModifyWorldTransform added.

24.07.2021
- TGdiObj: GetStockObject method added.
- TDC: SetGraphicsMode, SetMapMode, SetWorldTransform, DPtoLP, PatBlt methods added.
- TBitmap: GetBits, SaveBitmap methods added.

13.07.2021
- TProcessEnvironment class, GetEnvironmentVariable and SetEnvironmentVariable methods.

18.05.2021
- TStringEncoding.ToCWStr does CLIP(pInput).

10.05.2021
- TWnd: IsZoomed.

07.05.2021
- TWnd: DestroyWindow.

03.05.2021
- TStringEncoding: ToCWStr returns null terminated string.

22.04.2021
- TLogicalFont: CreateFontIndirectW, GetPropertiesW.
- TBitmap: CreateDIBSection.
- TWnd: GetWindowTextLengthW, GetWindowText, GetWindowTextW, IsWindowVisible, GetDesktopWindow, GetWindowPlacement.

14.04.2021
- TDC: missing SetHandle method, overloaded FromHDC.

30.03.2021
- TSystemMetrics: DPI-aware support.

25.03.2021
- TWnd: FindWindowEx reported an error if a window was not found.

23.03.2021
- TDC: GetDeviceCaps.

22.03.2021
- TRect: AssignPtr.

17.03.2021
- TDC: FrameRect.

13.03.2021
- TIODevice: SetFilePointer.
- TDiskFile: AppendFile.

06.11.2020
- TDC: DrawText now can draw not clipped text.

10.10.2020
- TDC: new methods StretchDIBits, GetStretchBltMode, SetStretchBltMode;  
overloaded methods StretchBlt, BitBlt.

28.09.2020
- TWnd: FindWindow, FindWindowEx.

18.09.2020
- TWnd: RedrawWindow, ShowCaret, HideCaret.

17.09.2020
- TWnd: GetPropA, SetPropA, GetWindowTextLength, GetWindowSubclass, SetWindowSubclass, RemoveWindowSubclass, DefSubclassProc.
- TDC: overloaded GetDCEx(hwnd,hrgn,flags), GetCurrentObject, Arc, Pie, GetArcDirection, SetArcDirection.
- TLogicalFont: fixed CreateFontIndirect, new GetProperties.
- added winapi.lib for Clarion versions prior C10.

21.08.2020
- TWnd: new methods GetClassName, IsWindow, MoveWindow, SetHotKey, GetFocus, SetFocus, Focused.
- TDC: new methods GetDC(TWnd), GetDCEx(TWnd,ULONG), DrawTextW, Rectangle, DrawFocusRect.
- TLogicalFont: new method CreateFontIndirect.
- TSystemMetrics class.
- TStringEncoding class.

04.08.2020
- TWnd: EnableWindow(bool).
- TRect: Intersect method tests if 2 rectangles are intersecting.
- TDC: SetBkMode sets the background mix mode of the specified device context.

28.07.2020
- TWnd: restores relevant userData before CallWindowProc(), this fixes the issue with multiple window procedures bound to a window/control.  
- TWnd: call ResetWndProc in .dtor

26.07.2020
- TDC: Polygon added.
- TIODevice: some WriteXXX methods added.
- TRect: Width() and Height() are now writeables.
- Static COLORREF::ToClarion returned wrong color value.
