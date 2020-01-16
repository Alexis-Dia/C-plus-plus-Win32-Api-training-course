//#include <windows.h> 
//#include <stdlib.h> 
//#include <string.h> 
//#include <tchar.h> 
//
//static TCHAR szWindowClass[] = _T("MyWin");
////static TCHAR szTitle[] = _T("API Application"); 
//
//LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgs, int nWinMode) {
//
//	WNDCLASSEX wcl;
//	wcl.hInstance = hThisInstance;
//	wcl.lpszClassName = szWindowClass;
//	wcl.lpfnWndProc = WindowFunc;
//	wcl.style = 0;
//	wcl.cbSize = sizeof(WNDCLASSEX);
//	wcl.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
//	wcl.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_WINLOGO));
//	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wcl.lpszMenuName = NULL;
//	wcl.cbClsExtra = 0;
//	wcl.cbWndExtra = 0;
//	wcl.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//
//	if (!RegisterClassEx(&wcl)) {
//		return 0;
//	}
//
//	HWND hWnd = CreateWindow(
//
//		szWindowClass,			// имя класса окна
//		_T("API Application"),  // заголовок
//		WS_OVERLAPPEDWINDOW,	// стиль окна
//		CW_USEDEFAULT,			// координата Х - выбирает windows
//		CW_USEDEFAULT,			// координата У - выбирает windows
//		600,			// ширина - выбирает windows
//		600,			// высота - выбирает windows
//		HWND_DESKTOP,			// нет родительского окна
//		NULL,					// нет меню
//		hThisInstance,			// работа с данным экземпляром программы
//		NULL					// доп. аргументов нет
//	);
//
//	if (!hWnd) {
//		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
//		return 1;
//	}
//
//	ShowWindow(hWnd, nWinMode);
//	UpdateWindow(hWnd);
//
//	MSG msg;
//	while (GetMessage(&msg, NULL, 0, 0)) {
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return (int)msg.wParam;
//}
////  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM) 
////  PURPOSE:  Processes messages for the main window. 
////  WM_PAINT    - Paint the main window  
////  WM_DESTROY  - post a quit message and return 
//LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	PAINTSTRUCT ps;
//	HDC hdc;
//	switch (message) {
//		case WM_PAINT:
//			hdc = BeginPaint(hWnd, &ps);
//			RECT rt;
//			GetClientRect(hWnd, &rt);
//			EndPaint(hWnd, &ps);
//			break;
//		case WM_CHAR:
//			// символьное сообщение с клавиатуры
//			break;
//		case WM_LBUTTONDOWN:
//			// обработчик ЛКМ
//			break;
//		case WM_RBUTTONDOWN:
//			// обработчик ПКМ
//			break;
//		case WM_DESTROY:
//			PostQuitMessage(0);
//			break;
//		default:
//			return DefWindowProc(hWnd, message, wParam, lParam);
//			break;
//	}
//	return 0;
//}
//
