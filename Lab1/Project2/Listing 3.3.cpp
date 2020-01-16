//#include <windows.h>
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstabce;
//char szClass[] = "OutputClass";
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstabce = hInstabce;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "Вывод текста",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstabce, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0; wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstabce; wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	static short cx, cy;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{
//			cx = LOWORD(IParam); cy = HIWORD(IParam);
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			char szText[] = "Вывод при обработке сообщения WM_PAINT";
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			//Цветом вывода символов выбираем малиновый
//			SetTextColor(hdc, RGB(255, 0, 255));
//			//Цветом фона вывода символов выбираем кремовый
//			SetBkColor(hdc, RGB(255, 251, 240));
//			SetTextAlign(hdc, TA_CENTER);
//			TextOut(hdc, cx / 2, cy / 2, szText, strlen(szText));
//			EndPaint(hwnd, &ps); return 0;
//		}
//
//		case WM_LBUTTONDOWN:
//		{
//			char szText[] = "Вывод при обработке сообщения WM_LВUПONDOWN";
//			HDC hdc = GetDC(hwnd);
//			//Цветом вывода символов выбираем синий
//			SetTextColor(hdc, RGB(0, 0, 255));
//			//Цветом фона вывода символов выбираем желтый
//			SetBkColor(hdc, RGB(255, 255, 0));
//			SetTextAlign(hdc, TA_CENTER);
//			TextOut(hdc, cx / 2, cy / 2 - 60, szText, strlen(szText));
//			ReleaseDC(hwnd, hdc); return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}