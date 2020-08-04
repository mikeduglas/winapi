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
