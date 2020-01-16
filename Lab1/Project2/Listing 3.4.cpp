//#include <windows.h>
//#include <tchar.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//void ContAttr(HWND hwnd);
//HINSTANCE hInstance;
//TCHAR szClass[] = TEXT("ClassContext");
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg;
//	HWND hwnd1, hwnd2;
//	hInstance = hInst;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd1 = CreateWindow(szClass, TEXT("Первое окно"),
//						 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//						 0, 0, hInstance, NULL);
//	if (!hwnd1) return FALSE;
//	hwnd2 = CreateWindow(szClass, TEXT("Второе окно"),
//						 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//						 0, 0, hInstance, NULL);
//	if (!hwnd2) return FALSE;
//	//Устанавливаем исходные атрибуты контекста
//	ContAttr(hwnd1);
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc;
//	wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.style = CS_HREDRAW | CS_VREDRAW | CS_CLASSDC;
//	wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//
//	static short cx, cy;
//
//	switch (msg)
//	{
//		case WM_SIZE:
//		{ cx = LOWORD(lParam); cy = HIWORD(lParam); return 0; }
//
//		case WM_PAINT:
//		{
//			TCHAR szText[] = TEXT("Вывод с атрибутами контекста класса");
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			TextOut(hdc, cx / 2, cy / 2, szText, _tcslen(szText));
//			EndPaint(hwnd, &ps);
//			return 0;
//		}
//
//		case WM_LBUTTONDOWN:
//
//		{
//			TCHAR szText[] = TEXT("Изменяем атрибуты контекста класса и выводим");
//			HDC hdc = GetDC(hwnd);
//			//Цветом вывода символов выбираем малиновый
//			SetTextColor(hdc, RGB(255, 0, 255));
//			//Цветом фона вывода символов выбираем кремовый
//			SetBkColor(hdc, RGB(255, 251, 240));
//			TextOut(hdc, cx / 2, cy / 2 - 60, szText, strlen(szText));
//			ReleaseDC(hwnd, hdc);
//			return 0;
//		}
//
//		case WM_RBUTTONDOWN:
//		{
//			//Восстанавливаем атрибуты контекста
//			ContAttr(hwnd);
//			TCHAR szText[] = TEXT("Восстанавливаем атрибуты контекста класса и выводим");
//			HDC hdc = GetDC(hwnd);
//			TextOut(hdc, cx / 2, cy / 2 + 60, szText, _tcslen(szText));
//			ReleaseDC(hwnd, hdc);
//			return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//
//}
//
//void ContAttr(HWND hwnd)
//
//{
//
//	HDC hdc = GetDC(hwnd);
//	//Цветом вывода символов устанавливаем синий
//	SetTextColor(hdc, RGB(0, 0, 255));
//	//Цветом фона вывода символов устанавливаем желтый
//	SetBkColor(hdc, RGB(255, 255, 0));
//	SetTextAlign(hdc, TA_CENTER);
//	ReleaseDC(hwnd, hdc);
//
//}