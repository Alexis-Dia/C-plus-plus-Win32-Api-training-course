//#include <windows.h>
//#include <math.h>
//#define PI 3.1415926535
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "LinesClass";
//int WINAPI WinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevInstance, LPSTR lpszCmdLine,
//				   int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "Эллиптическая диаграмма",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, 0, 0, hInstance, NULL);
//	if (!hwnd)
//		return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc;
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL;
//	return (RegisterClass(&wc) != 0);
//}
//BOOL DrawLine(HDC hdc, int x0, int y0, int x, int y)
//{
//	MoveToEx(hdc, x0, y0, NULL);
//	return LineTo(hdc, x, y);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM lParam)
//{
//	static short cx, cy;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{
//			cx = LOWORD(lParam);
//			cy = HIWORD(lParam);
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			//Задаем область для рисования эллипса
//			int i = cx / 10, //Левый край эллипса
//				r = cx - i, //Правый край эллипса
//				t = cy / 10, //Верxний край эллипса
//				b = cy - t, //Нижний край эллипса 
//				yc = cy / 2, //Центр эллипса по оси у
//				xc = cx / 2; //Центр эллипса по оси x
//				//Задаем координаты точек дуги
//			int x0 = (int)(xc + 0.5 * (r - i)),
//				у0 = yc,
//				x = (int)(xc + 0.5 * (r - i) * cos(2. * PI * 0.625)),
//				y = (int)(yc - 0.5 * (b - t) * sin(2. * PI * 0.625));
//			//Рисуем прямую линию
//			DrawLine(hdc, xc, yc, x0, у0);
//			//Рисуем дугу эллипса
//			Arc(hdc, i, t, r, b, x0, у0, x, y);
//			x0 = x; у0 = y; //Запоминаем координаты точки
//			//Выводим текст
//			x = (int)(xc + 0.4 * cx * cos(2. * PI * 0.3125));
//			y = (int)(yc - 0.4 * cy * sin(2. * PI * 0.3125));
//			TextOut(hdc, x, y, "62,5 %", 6);
//			//Рисуем прямую линию
//			DrawLine(hdc, xc, yc, x0, у0);
//			x = (int)(xc + 0.5 * (r - i) * cos(2. * PI * 0.75));
//			y = (int)(yc - 0.5 * (b - t) * sin(2. * PI * 0.75));
//			//Рисуем дугу эллипса
//			Arc(hdc, i, t, r, b, x0, у0, x, y);
//			x0 = x; у0 = y; //Запоминаем координаты точки
//			//Выводим текст
//			x = (int)(xc + 0.4 * cx * cos(2. * PI * 0.6875));
//			y = (int)(yc - 0.4 * cy * sin(2. * PI * 0.6875));
//			TextOut(hdc, x, y, "25 % ", 6);
//			//Рисуем прямую линию
//			DrawLine(hdc, xc, yc, x0, у0);
//			x = (int)(xc + 0.5 * (r - i) * cos(2. * PI));
//			y = (int)(yc - 0.5 * (b - t) * sin(2. * PI));
//			//Рисуем дугу эллипса
//			Arc(hdc, i, t, r, b, x0, у0, x, y);
//			//Выводим текст
//			x = (int)(xc + 0.4 * cx * cos(2. * PI * 0.875));
//			y = (int)(yc - 0.4 * cy * sin(2. * PI * 0.875));
//			TextOut(hdc, x, y, "25 %", 4);
//			EndPaint(hwnd, &ps); return 0;
//		}
//		case WM_DESTROY:
//		{
//			PostQuitMessage(0); return 0;
//		}
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}