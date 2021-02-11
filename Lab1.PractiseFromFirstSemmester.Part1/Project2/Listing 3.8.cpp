//#include <windows.h> 
//#include <tchar.h>
//#include <math.h>
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "GraphClass";
//typedef struct {
//	char name[10];
//	float x[100];
//	float y[100];
//} FUNC;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClassName, "ТАБЛИЦА",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc;
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0; wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance; wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL;
//	return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static short cx, cy;
//	static FUNC myfunc;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{
//			cx = LOWORD(lParam);
//			cy = HIWORD(lParam); return 0;
//		}
//		case WM_CREATE:
//		{
//			strcpy(myfunc.name, "25*cos(x)");
//			for (int i = 0; i < 100; i++)
//			{
//				myfunc.x[i] = (float)(0.314159265354);
//				myfunc.y[i] = (float)(25 * cos(myfunc.x[i]));
//			} return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			//Задаем область для рисования графика
//			int х0 = cx / 10, //Левый край графика
//				хr = cx - х0, //Правый край графика
//				у0 = cy / 10, //Верхний край графика
//				ус = cy / 2, //Середина графика по оси у
//				amp = ус - у0; //Амплитуда графика на экране
//			float ymax = 0., //Максимум функции
//				ymin = 0.; //Минимум функции
//				//Выводим название функции
//			TextOut(hdc, х0 + 4, у0 / 3,
//					myfunc.name, strlen(myfunc.name));
//			//Выводим название переменной
//			TextOut(hdc, хr + х0 / 2, ус + у0 / 10, "T", 1);
//			//Рисуем ось ординат
//			MoveToEx(hdc, х0, cy - у0 + у0 / 2, NULL);
//			LineTo(hdc, х0, у0 - у0 / 2); //Рисуем ось абсцисс
//			MoveToEx(hdc, х0, ус, NULL);
//			LineTo(hdc, хr + х0 / 2, ус);
//			//Определяем максимум и минимум функции
//			for (int i = 0; i < 100; i++)
//			{
//				float ycurr = myfunc.y[i];
//				if (ymax < ycurr) ymax = ycurr;
//				else if (ymin > ycurr) ymin = ycurr;
//			}
//			if (ymax < fabs(ymin)) ymax = (float)fabs(ymin);
//			//Устанавливаем масштаб по оси у
//			float dy = (float)amp / ymax;
//			//Устанавливаем масштаб по оси х
//			float dx = (float)(хr - х0) / (myfunc.x[99] - myfunc.x[0]);
//			//Для рисования создаем перо синего цвета
//			HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//			HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
//			//Устанавливаем курсор в первую точку графика
//			MoveToEx(hdc, х0, (int)(ус - dy * myfunc.y[0]), NULL);
//			//Выводим линии от предыдущей точки к текущей
//			for (int i = 1; i < 100; i++)
//			{
//				//Вычисляем координаты текущей точки
//				int xcurr = (int)(dx * (myfunc.x[i] - myfunc.x[0]) + х0),
//					ycurr = (int)(ус - dy * myfunc.y[i]);
//				//Рисуем прямую до текущей точки
//				LineTo(hdc, xcurr, ycurr);
//			}
//			SelectObject(hdc, hOldPen); DeleteObject(hPen);
//			EndPaint(hwnd, &ps); return 0;
//		}
//		case WM_DESTROY:
//		{PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}