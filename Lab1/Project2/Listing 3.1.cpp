//#include <windows.h>
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hlnstance;
//char szClass[] = "OutputClass";
//int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hlnstance = hlnstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "Вывод текста",
//						WS_OVERLAPPEDWINDOW,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hlnstance, NULL);
//	if (!hwnd) return FALSE;
//	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//
//BOOL RegClass(WNDPROC Ргос, LPCTSTR szName,
//			  UINT brBackground)
//{
//	WNDCLASS wc; wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0; wc.lpfnWndProc = Ргос;
//	wc.hInstance = hlnstance; wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM IParam)
//{
//	char szText[] = "Выводим какой-либо текст";
//	static short cx, cy;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{ cx = LOWORD(IParam); cy = HIWORD(IParam);
//		return 0;
//		}
//		case WM_PAINT:
//		{ PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hwnd, &ps);
//		//Настриваем атрибуты вывода текста
//		SetTextColor(hdc, RGB(255, 0, 0));
//		SetBkColor(hdc, RGB(0, 255, 255));
//		SetTextAlign(hdc, TA_CENTER);
//		//Выводим текст
//		TextOut(hdc, cx / 2, cy / 2, szText, strlen(szText));
//		EndPaint(hwnd, &ps);
//		return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}