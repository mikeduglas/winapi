09.09.2025
- TWnd: GetTopWindow, BringWindowToTop, GetWindowThreadProcessId methods added.
- TWnd: GetWindowText fixed.

07.09.2025
- TWnd: GetClassLongA and GetClassLongW methods added.
- TWnd: ValidHandle method added.
- TMdiTabBarWnd class added (MDI Tabbar hwnd).

13.07.2025
- TRect.RectInRect added.
 
23.06.2025
- TToolbarWnd class added (toolbar hwnd).

19.06.2025
- TPoint methods Assign, AssignTo added.

05.05.2025
- TRgn class added (region GDI object).
- TWnd, TDC classes: new and overloaded methods that support the region objects:
TWnd.RedrawWindow, TDC.GetDCEx, TDC.SelectClipRgn, TDC.FillRgn, TDC.FrameRgn, TDC.InvertRgn, TDC.PaintRgn, TDC.PolyFillMode.

27.07.2023
- TWnd: ClientToScreen(*TPoint ppt) overloaded method.

18.04.2023
- TLogicalFont: EnumFontFamiliesEx method added.

17.04.2023
- TRectF class added.

09.04.2023
- TClipboard class added.
- TGlobalMemory class added.
- TDC: SetDIBits method added.
- TBitmap: CreateDIBitmap method added.

31.03.2023
- TWnd: Overloaded GetBitmap, SaveBitmap, CopyBitmap accept TRect.

19.03.2023
- TDiskFile: ReadFileHeader added.

31.12.2022
- TWnd: UpdateLayeredWindow methods added.
- winapi::WindowFromPoint missing PASCAL attribute.
- winapi.lib has been updated.

14.10.2022
- TResource: FindResourceEx, GetResourceEx, LoadBitmap, LoadIcon, LoadCursor, LoadString methods added.

22.09.2022
- TWnd: WindowFromPoint, DragDetect methods added.

13.08.2022
- TWnd: SetScrollInfo method added.
- TDC: LPtoDP method added.

29.07.2022
- TPaintDC class: a device-context class derived from TDC. It performs a BeginPaint in GetDC(hwnd) and EndPaint in ReleaseDC().


08.05.2022
- TToolHelp class.

30.03.2022
- Renamed BITMAPFILEHEADER to tagBITMAPFILEHEADER to fix "Duplicate symbol: TYPE$BITMAPFILEHEADER" error when FRB is used.

16.03.2022
- TWnd: ModifyStyle, ModifyStyleEx added: call these methods to modify a window's style or a window's extended style.
- TRect: SetRectEmpty, UnionRect, InflateRect.
- TDC: ExtTextOut, FillSolidRect, Draw3dRect.

01.11.2021
- TIODevice: GetFileSizeEx, SetFilePointerEx methods added.

06.10.2021
- TWnd: PrintWindow method added.

08.08.2021
- TRect: OffsetRect added.
- TDC: GetWindowDC, RoundRect added.

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
