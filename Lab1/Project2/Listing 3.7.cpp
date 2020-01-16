//#include <windows.h>
//#include <stdio.h>
//#include <math.h>
//#include <tchar.h>
//#define snprintf _snprintf
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "TableClass";
////Структура столбца данных
//typedef struct {
//	char str[15]; //Поле имени столбца
//	double val[50]; //Массив данных столбца
//}
//COLUMN; //Имя типа
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "ТАБЛИЦА",
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{ //Описываем массив из 10 столбцов
//	static COLUMN cols[10];
//	static int cx, cy, cxChar, cyChar;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{
//			cx = LOWORD(lParam);
//			cy = HIWORD(lParam);
//			return 0;
//
//		}
//		case WM_CREATE:
//		{
//			//Заполняем заголовки столбцов
//			strcpy_s(cols[0].str, "i");
//			strcpy_s(cols[1].str, "10*sin(i/10.)");
//			strcpy_s(cols[2].str, "20*sin(i/20.)");
//			strcpy_s(cols[3].str, "30*sin(i/30.)");
//			strcpy_s(cols[4].str, "40*sin(i/40.)");
//			strcpy_s(cols[5].str, "50*sin(i/50.)");
//			strcpy_s(cols[6].str, "60*sin(i/60.)");
//			strcpy_s(cols[7].str, "70*sin(i/70.)");
//			strcpy_s(cols[8].str, "80*sin(i/80.)");
//			strcpy_s(cols[9].str, "90*sin(i/90.)");
//			//Заполняем массивы данных столбцов
//			for (int i = 0; i < 50; i++)
//			{ //В первом столбце будут номера строк
//				cols[0].val[i] = i;
//				//В остальных столбцах будут данные
//				for (int j = 1; j < 10; j++)
//					cols[j].val[i] = 10 * sin(i / 10 / j);
//			}
//			//Определяем средние высоту и ширину символов
//			{
//				TEXTMETRIC tm;
//				HDC hdc = GetDC(hwnd);
//				//Определяем метрики текста
//				GetTextMetrics(hdc, &tm);
//				ReleaseDC(hwnd, hdc);
//				//Число пикселей в высоте символа
//				cyChar = tm.tmHeight + tm.tmExternalLeading;
//				//Число пикселей в средней ширине
//				cxChar = tm.tmAveCharWidth + 1;
//			}
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			char str[20];
//			//Установим начальные параметры для вывода
//			int left = cxChar, //Левый край
//				top = cyChar / 2, //Верх
//				dx = cxChar, //Пробел по оси X
//				dy = cyChar / 4, //Пробел по оси Y
//				hy = cyChar + dy + dy, //Высота для строки
//				right = cx - cxChar, //Правый край
//				bottom = cy - cyChar, //Низ
//				bounds[10], //Массив ширин столбцов
//				i = 0, j = 0; //Заполняем массив ширинами столбцов
//			while (j < 10)
//			{ //Для j-ro столбца выбираем ширину
//				bounds[j] = _tcslen(cols[j].str);
//				for (i = 0; i < 50; i++)
//				{
//					_sntprintf_s(str, 7, _T("%f"), cols[j].val[i]);
//					//_gcvt( cols[j].val[i], 7, str );
//					int ss = _tcslen(str);
//					if (bounds[j] < ss) bounds[j] = ss;
//				}
//				if (bounds[j] <= 3) bounds[j] = 4;
//				if (bounds[j] > 10) bounds[j] -= 2;
//				bounds[j] = cxChar * (bounds[j]);
//				j++;
//			}
//			//Определяем максимальное число столбцов,
//			//которое помещается на ширине рабочей области
//			int dd = left, maxcol = 0;
//			while (maxcol < 10)
//			{
//				if (dd + bounds[maxcol] > right) break;
//				dd += bounds[maxcol];
//				maxcol++;
//			}
//			//right теперь указывает на правый край таблицы
//			right = dd;
//			//Подгоняем ширину окна к числу столбцов
//			{
//				RECT rc; GetWindowRect(hwnd, &rc);
//				MoveWindow(hwnd, rc.left, rc.top,
//						   //Изменяем только ширину окна
//						   rc.right - rc.left - (cx - right) + dx,
//						   rc.bottom - rc.top, TRUE);
//			}
//			//////НАЧАЛО ВЫВОДА ТАБЛИЦЫ//////
//			//Устанавливаем режим выравнивания
//			SetTextAlign(hdc, TA_RIGHT);
//			//////Начало вывода шапки таблицы//////
//			int y = top; //Текущая координата по оси Y
//			//Горизонтальная линия на всю ширину
//			DrawLine(hdc, left, y, right, y);
//			//Заголовки столбцов
//			int x = left; //Текущая координата по оси X
//			//Вертикальная линия слева от столбца
//			DrawLine(hdc, x, y, x, y + hy);
//			for (j = 0; j < maxcol; j++)
//			{ //Устанавливаем х на правой границе столбца
//				x += bounds[j];
//				TextOut(hdc, x - dx, y + dy, cols[j].str, strlen(cols[j].str));
//				//Вертикальная линия справа от столбца
//				DrawLine(hdc, x, y, x, y + hy);
//			}
//			//Горизонтальная линия на всю ширину
//			y += hy; DrawLine(hdc, left, y, right, y);
//			//////Конец вывода шапки таблицы//////
//			//////Начало вывода данных таблицы//////
//			i = 0;//Счетчик номера строки данных
//			while (i < 50 && y < bottom)
//			{ //Вертикальная линия слева от столбца x=left;
//				DrawLine(hdc, x, y, x, y + hy);
//				for (j = 0; j < maxcol; j++) {
//					x += bounds[j];
//					//Преобразуем целое число в строку
//					if (j == 0) _itoa_s((int)cols[0].val[i], str, 10);
//					//Преобразуем вещественное число в строку
//					else _sntprintf_s(str, 7, _T("%f"), cols[j].val[i]);
//					//_gcvt( cols[j].val[i], 7, str);
//					TextOut(hdc, x - dx, y + dy, str, strlen(str));
//					//Вертикальная линия справа от столбца
//					DrawLine(hdc, x, y, x, y + hy);
//				}
//				//Горизонтальная линия на всю ширину
//				y += hy; DrawLine(hdc, left, y, right, y);
//				i++;
//			}
//			//////Конец вывода данных таблицы//////
//			EndPaint(hwnd, &ps);
//			return 0;
//		}
//		case WM_DESTROY:
//		{ PostQuitMessage(0); return 0; }
//	}
//	return
//		DefWindowProc(hwnd, msg, wParam, lParam);
//}