//#include <windows.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "ScrollClass";
//char szTitle[] = "Window with scrollbar";
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdChow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, szTitle,
//		WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_VISIBLE,
//		194, 50, 246, 350, 0, 0, hInstance, NULL)))
//		return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))DispatchMessage(&msg);
//	return msg.wParam;
//}
//
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static unsigned int nyPos, nyMin, nyMax, nyPage;
//	static SCROLLINFO siy;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			nyPos = nyMin = 1; nyMax = 200; nyPage = 10;
//			siy.cbSize = sizeof(siy); siy.fMask = SIF_ALL;
//			siy.nMin = nyMin; siy.nMax = nyMax;
//			siy.nPage = nyPage; siy.nPos = nyPos;
//			SetScrollInfo(hwnd, SB_VERT, &siy, TRUE);
//			return 0;
//		}
//		case WM_VSCROLL:
//		{
//			switch (LOWORD(wParam))
//			{
//				case SB_PAGERIGHT:
//				{ nyPos += 10; break; }
//				case SB_LINERIGHT:
//				{ nyPos += 1; siy.nPage += 1; break; }
//				case SB_PAGELEFT:
//				{ nyPos -= 10; break; }
//				case SB_LINELEFT:
//				{ nyPos -= 1; siy.nPage -= 1; break; }
//				case SB_TOP:
//				{ nyPos = nyMin; break; }
//				case SB_BOTTOM:
//				{ nyPos = nyMax; break; }
//				case SB_THUMBPOSITION:
//				case SB_THUMBTRACK:
//				{ nyPos = HIWORD(wParam); break; }
//			}
//			if (nyPos > nyMax) nyPos = nyMax;
//			if (nyPos < nyMin) nyPos = nyMin;
//			siy.nPos = nyPos; siy.fMask = SIF_POS | SIF_PAGE;
//			if (siy.nPage < nyPage || siy.nPage > nyMax)
//				siy.nPage = nyPage;
//			SetScrollInfo(hwnd, SB_VERT, &siy, TRUE);
//			return 0;
//		}
//		case WM_KEYDOWN:
//		{
//			switch (wParam)
//			{
//				case VK_HOME:
//					if (HIBYTE(GetKeyState(VK_CONTROL)))
//						SendMessage(hwnd, WM_VSCROLL, SB_TOP, 0L);
//					break;
//				case VK_END:
//					if (HIBYTE(GetKeyState(VK_CONTROL)))
//						SendMessage(hwnd, WM_VSCROLL, SB_BOTTOM, 0L);
//					break;
//				case VK_UP:
//					SendMessage(hwnd, WM_VSCROLL, SB_LINELEFT, 0L);
//					break;
//				case VK_DOWN:
//					SendMessage(hwnd, WM_VSCROLL, SB_LINERIGHT, 0L);
//					break;
//				case VK_PRIOR:
//					SendMessage(hwnd, WM_VSCROLL, SB_PAGELEFT, 0L);
//					break;
//				case VK_NEXT:
//					SendMessage(hwnd, WM_VSCROLL, SB_PAGERIGHT, 0L);
//					break;
//			}
//			return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}