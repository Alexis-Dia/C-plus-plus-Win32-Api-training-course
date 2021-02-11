//#include <windows.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "ScrollClass";
//char szTitle[] = "Полоса прокрутки - орган. управления";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, szTitle, WS_OVERLAPPEDWINDOW,
//		194, 50, 246, 350, 0, 0, hInstance, NULL)))
//		return FALSE;
//	ShowWindow(hwnd, SW_SHOWNORMAL);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Ргос, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Ргос; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	static HWND hxScroll, hxStatic, hyScroll, hyStatic;
//	static int nxPos, nxMin, nxMax, nyPos, nyMin, nyMax;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			hxScroll = CreateWindow("scrollbar", NULL,
//									WS_CHILD | WS_VISIBLE | SBS_HORZ,
//									20, 60, 200, 25, hwnd, (HMENU)-1,
//									hInstance, NULL);
//			nxPos = 100; nxMin = 1; nxMax = 200;
//			SetScrollRange(hxScroll, SB_CTL, nxMin, nxMax, TRUE);
//			SetScrollPos(hxScroll, SB_CTL, nxPos, TRUE);
//			hxStatic = CreateWindow("static", NULL,
//									WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//									20, 40, nxPos, 15, hwnd, (HMENU)-1,
//									hInstance, NULL);
//			hyScroll = CreateWindow("scrollbar", NULL,
//									WS_CHILD | WS_VISIBLE | SBS_VERT,
//									20, 100, 90, 200, hwnd, (HMENU)-1,
//									hInstance, NULL);
//			nyPos = 100; nyMin = 1; nyMax = 200;
//
//			SetScrollRange(hyScroll, SB_CTL, nyMin, nyMax, TRUE);
//			SetScrollPos(hyScroll, SB_CTL, nyPos, TRUE);
//			hyStatic = CreateWindow("static", NULL,
//									WS_CHILD | WS_VISIBLE | SS_GRAYRECT,
//									130, 100, 90, nyPos, hwnd, (HMENU)-1,
//									hInstance, NULL);
//			return 0;
//		}
//		case WM_HSCROLL:
//		{
//			switch (LOWORD(wParam))
//
//			{
//				case SB_PAGERIGHT:
//				{ nxPos += 10; break; }
//				case SB_LINERIGHT:
//				{ nxPos += 1; break; }
//				case SB_PAGELEFT:
//				{ nxPos -= 10; break; }
//				case SB_LINELEFT:
//				{ nxPos -= 1; break; }
//				case SB_TOP:
//				{ nxPos = nxMin; break; }
//				case SB_BOTTOM:
//				{ nxPos = nxMax; break; }
//				case SB_THUMBPOSITION:
//				case SB_THUMBTRACK:
//				{ nxPos = HIWORD(wParam); break; }
//				default: break;
//			}
//			if (nxPos > nxMax) nxPos = nxMax;
//			if (nxPos < nxMin) nxPos = nxMin;
//			SetScrollPos(hxScroll, SB_CTL, nxPos, TRUE);
//			if (nxPos == nxMax)
//				EnableScrollBar(hxScroll, SB_CTL,
//								ESB_DISABLE_RIGHT);
//			MoveWindow(hxStatic, 20, 40, nxPos, 15, TRUE);
//			return 0;
//		}
//		case WM_VSCROLL:
//		{
//			switch (LOWORD(wParam))
//			{
//				case SB_PAGERIGHT:
//				{ nyPos += 10; break; }
//				case SB_LINERIGHT:
//				{ nyPos += 1; break; }
//				case SB_PAGELEFT:
//				{ nyPos -= 10; break; }
//				case SB_LINELEFT:
//				{ nyPos -= 1; break; }
//				case SB_TOP:
//				{ nyPos = nyMin; break; }
//				case SB_BOTTOM:
//				{ nyPos = nyMax; break; }
//				case SB_THUMBPOSITION:
//				case SB_THUMBTRACK:
//				{ nyPos = HIWORD(wParam); break; }
//				default: break;
//			}
//			if (nyPos > nyMax) nyPos = nyMax;
//			if (nyPos < nyMin) nyPos = nyMin;
//			SetScrollPos(hyScroll, SB_CTL, nyPos, TRUE);
//			MoveWindow(hyStatic, 130, 100, 90, nyPos, TRUE);
//			return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}