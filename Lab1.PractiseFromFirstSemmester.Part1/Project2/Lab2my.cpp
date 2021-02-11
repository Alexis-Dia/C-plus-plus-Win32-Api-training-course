//#include <windows.h>
//#include <stdio.h>
//
//#define ID_EDITRED 1
//#define ID_EDITGREEN 2
//#define ID_EDITBLUE 3
//#define ID_EXIT 4
//#define ID_EDITHEX 5
//#define ID_EDIT 1000
//#define ID_LISTBOX 1001
//#define ID_BUTTON 1002
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "ListDir";
//char szTitle[] = "Работа со списком";
//
//char string[] = "Установка цвета"; //текст в окне
//char string1[] = "Ваш цвет: ";
//char string2[] = "16-ричный код цвета:";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, szTitle,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 50, 1000, 360, 0, 0, hInstance, NULL))) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))
//	{
//		TranslateMessage(&msg); DispatchMessage(&msg);
//	}
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hRedScroll, hGreenScroll, hBlueScroll, hyScroll, hyStatic;
//
//	static HWND hRedStatic, hGreenStatic, hBlueStatic;
//	static int nxPos, nxMin, nxMax, nyPos, nyMin, nyMax;
//
//	static HWND hEditRed, hEditBlue, hEditGreen, hEditHex;
//	int red = 128, green = 128, blue = 128; //значения цветов
//	static HWND hListВox, hEdit, hButton, hStatic;
//	int uItem, i; char Buf[80];
//
//	HDC hDC;
//	HBRUSH hBrush; //кисть для рисования эллипса
//	PAINTSTRUCT PaintStruct;
//	RECT Rect, Client; //области отрисовки
//
//	switch (msg)
//	{
//		case WM_CREATE:
//			nxPos = 128; //Среднее положение движка
//			nxMin = 0; //Минимальное положение движка
//			nxMax = 255; //Максимальное положение движка
//			{
//				//Создание трёх полос для каждого цвета
//				hRedScroll = CreateWindow("scrollbar", NULL,
//										  WS_CHILD | WS_VISIBLE | SBS_HORZ,
//										  20, 120, 200, 25, hWnd, (HMENU)-1,
//										  hInstance, NULL);
//				hGreenScroll = CreateWindow("scrollbar", NULL,
//											WS_CHILD | WS_VISIBLE | SBS_HORZ,
//											20, 180, 200, 25, hWnd, (HMENU)-1,
//											hInstance, NULL);
//				hBlueScroll = CreateWindow("scrollbar", NULL,
//										   WS_CHILD | WS_VISIBLE | SBS_HORZ,
//										   20, 240, 200, 25, hWnd, (HMENU)-1,
//										   hInstance, NULL);
//				//Установка диапазона полосы прокрутки
//				//nxMin, nxMax - максимальные значения, TRUE - необходимость перерисовки
//				SetScrollRange(hRedScroll, SB_CTL, nxMin, nxMax, TRUE);
//				SetScrollRange(hGreenScroll, SB_CTL, nxMin, nxMax, TRUE);
//				SetScrollRange(hBlueScroll, SB_CTL, nxMin, nxMax, TRUE);
//				// Cледующая функция устанавливает ползунок в нужное положение
//				//nxPos - новое положение ползунка. TRUE - необходимость перерисовки
//				SetScrollPos(hRedScroll, SB_CTL, nxPos, TRUE);
//				SetScrollPos(hGreenScroll, SB_CTL, nxPos, TRUE);
//				SetScrollPos(hBlueScroll, SB_CTL, nxPos, TRUE);
//
//				hRedStatic = CreateWindow("static", NULL,
//										  WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//										  20, 100, nxPos, 15, hWnd, (HMENU)-1,
//										  hInstance, NULL);
//				hGreenStatic = CreateWindow("static", NULL,
//											WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//											20, 160, nxPos, 15, hWnd, (HMENU)-1,
//											hInstance, NULL);
//				hBlueStatic = CreateWindow("static", NULL,
//										   WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//										   20, 220, nxPos, 15, hWnd, (HMENU)-1,
//										   hInstance, NULL);
//
//				//Создание полей ввода со значениями цветов
//				hEditRed = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//										  WS_CHILD | WS_VISIBLE | WS_BORDER,
//										  240, 120, 30, 25, hWnd, (HMENU)ID_EDITRED,
//										  hInstance, NULL);
//
//				hEditGreen = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//											WS_CHILD | WS_VISIBLE | WS_BORDER,
//											240, 180, 30, 25, hWnd, (HMENU)ID_EDITGREEN,
//											hInstance, NULL);
//
//				hEditBlue = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//										   WS_CHILD | WS_VISIBLE | WS_BORDER,
//										   240, 240, 30, 25, hWnd, (HMENU)ID_EDITBLUE,
//										   hInstance, NULL);
//
//				//Поле ввода с 16-ричным кодом цвета
//				hEditHex = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "7F7F7F",
//										  WS_CHILD | WS_VISIBLE | WS_BORDER,
//										  320, 260, 60, 25, hWnd, (HMENU)ID_EDITHEX,
//										  hInstance, NULL);
//				/*hyScroll = CreateWindow("scrollbar", NULL,
//										WS_CHILD | WS_VISIBLE | SBS_VERT,
//										20, 100, 90, 200, hwnd, (HMENU)-1,
//										hInstance, NULL);
//				nyPos = 100; nyMin = 1; nyMax = 255;
//
//				SetScrollRange(hyScroll, SB_CTL, nyMin, nyMax, TRUE);
//				SetScrollPos(hyScroll, SB_CTL, nyPos, TRUE);
//				hyStatic = CreateWindow("static", NULL,
//										WS_CHILD | WS_VISIBLE | SS_GRAYRECT,
//										130, 100, 90, nyPos, hwnd, (HMENU)-1,
//										hInstance, NULL);*/
//
//				hStatic = CreateWindow("static",
//									   "Введите строку для ввода в список",
//									   WS_CHILD | WS_VISIBLE | SS_CENTER,
//									   600, 10, 300, 20, hWnd, (HMENU)0, hInstance,
//									   NULL);
//
//				hEdit = CreateWindow("edit", NULL,
//									 WS_CHILD | WS_VISIBLE | WS_BORDER |
//									 ES_LEFT | ES_AUTOHSCROLL, 600, 40, 300, 30,
//									 hWnd, (HMENU)ID_EDIT, hInstance, NULL);
//
//				hListВox = CreateWindow("listbox", NULL,
//										WS_CHILD | WS_VISIBLE | LBS_STANDARD,
//										600, 80, 300, 200, hWnd,
//										(HMENU)ID_LISTBOX, hInstance, NULL);
//
//				hButton = CreateWindow("button", "Добавить",
//									   WS_CHILD | WS_VISIBLE |
//									   BS_PUSHBUTTON, 650, 290, 100, 30, hWnd,
//									   (HMENU)ID_BUTTON, hInstance, NULL);
//				SetFocus(hEdit);
//				return 0;
//			}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				case ID_LISTBOX:
//				{
//					switch (HIWORD(wParam))
//					{
//						case LBN_ERRSPACE:
//						{
//							MessageBox(hWnd, "Мало памяти", szTitle, MB_OK);
//							return 0;
//						}
//						case LBN_DBLCLK:
//						{
//							uItem = (int)SendMessage(hListВox, LB_GETCURSEL, 0, 0L);
//							if (uItem != LB_ERR)
//							{
//								SendMessage(hListВox, LB_GETTEXT, uItem, (LPARAM)Buf);
//								MessageBox(hWnd, Buf, szTitle, MB_OK);
//
//							}
//							return 0;
//						}
//						default: return 0;
//					}
//					return 0;
//				}
//				case ID_BUTTON:
//				{
//
//					SendMessage(hEdit, EM_GETLINE, 0, (LPARAM)Buf);
//					SendMessage(hListВox, LB_ADDSTRING, 0, (LPARAM)Buf);
//					SetWindowText(hEdit, "\0");
//					SetFocus(hEdit);
//					return 0;
//				}
//				default:return 0;
//			}
//		}
//		case WM_HSCROLL:
//		{
//
//			if (hRedScroll == (HWND)lParam)i = 0;
//			if (hGreenScroll == (HWND)lParam)i = 1;
//			if (hBlueScroll == (HWND)lParam)i = 2;
//			switch (LOWORD(wParam))
//
//			{
//				case SB_PAGERIGHT://На страницу вправо
//				{
//					nxPos += 10;
//					break;
//				}
//				case SB_LINERIGHT://На одну линию вправо
//				{
//					nxPos += 1;
//					break;
//				}
//				case SB_PAGELEFT://На страницу влево
//				{
//					nxPos -= 10;
//					break;
//				}
//				case SB_LINELEFT://На линию влево
//				{
//					nxPos -= 1;
//					break;
//				}
//				case SB_TOP://Максимальное значение
//				{
//					nxPos = nxMin;
//					break;
//				}
//				case SB_BOTTOM: //Минимальное значение
//				{
//					nxPos = nxMax;
//					break;
//				}
//				case SB_THUMBPOSITION://Любое перемещение
//				case SB_THUMBTRACK:
//				{
//					nxPos = HIWORD(wParam);
//					break;
//				}
//				default: break;
//			}
//			//Если позиция больше максимальной
//			if (nxPos > nxMax) nxPos = nxMax;//Устанавливаем на граничную максимальную
//			//Если позиция меньше минимальной
//			if (nxPos < nxMin) nxPos = nxMin; //Устанавливаем на граничную минимальную
//			if (nxPos == nxMax)
//				//Если положение движка достигло максимума, блокировать его
//				switch (i) {
//					case 0:
//						EnableScrollBar(hRedScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//					case 1:
//						EnableScrollBar(hGreenScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//					case 2:
//						EnableScrollBar(hBlueScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//				}
//
//			//Вспоминаем, какая полоса была сдвинута
//			switch (i) {
//				case 0:
//					SetScrollPos(hRedScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITRED, nxPos, 0);
//					MoveWindow(hRedStatic, 20, 100, nxPos, 15, TRUE);
//					break;
//				case 1:
//					SetScrollPos(hGreenScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITGREEN, nxPos, 0);
//					MoveWindow(hGreenStatic, 20, 160, nxPos, 15, TRUE);
//					break;
//				case 2:
//					SetScrollPos(hBlueScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITBLUE, nxPos, 0);
//					MoveWindow(hBlueStatic, 20, 220, nxPos, 15, TRUE);
//					break;
//			}
//
//			//Новые значения переменных цвета получены из полей ввода
//			red = GetDlgItemInt(hWnd, ID_EDITRED, NULL, 0);
//			green = GetDlgItemInt(hWnd, ID_EDITGREEN, NULL, 0);
//			blue = GetDlgItemInt(hWnd, ID_EDITBLUE, NULL, 0);
//
//			//Задаём границы области перерисовки по эллипсу
//			Client.left = 330;
//			Client.top = 60;
//			Client.right = 480;
//			Client.bottom = 220;
//			//Вызываем сообщение WM_PAINT по перерисовке области
//			//эллипса
//			InvalidateRect(hWnd, &Client, 1);
//			//Записываем в буфер 16-ричные эквиваленты цветов
//			sprintf_s(Buf, "%X%X%X", red, green, blue);
//			//Выводим буфер в поле 16-ричного вывода
//			SetDlgItemText(hWnd, ID_EDITHEX, Buf);
//			//Сообщшение рисования
//		case WM_PAINT:
//			hDC = BeginPaint(hWnd, &PaintStruct);
//			GetClientRect(hWnd, &Rect);
//			//Прозрачный режим фона
//			SetBkMode(hDC, TRANSPARENT);
//			//Белый прямоугольник под эллипсом
//			Rectangle(hDC, 330, 60, 480, 220);
//			//Создаём кисть с новыми цветами
//			hBrush = CreateSolidBrush(RGB(red, green, blue));
//			//Делаем её активной
//			SelectObject(hDC, hBrush);
//			//Рисуем эллипс
//			Ellipse(hDC, 350, 80, 460, 200);
//
//			//Выводим текст в окно
//			TextOut(hDC, 60, 20, string, strlen(string));
//			TextOut(hDC, 370, 20, string1, strlen(string1));
//			TextOut(hDC, 325, 234, string2, strlen(string2));
//
//			//Выводим текст над полями ввода разного цвета
//			SetTextColor(hDC, RGB(255, 0, 0));
//			TextOut(hDC, 240, 100, "Red:", 4);
//			SetTextColor(hDC, RGB(0, 255, 0));
//			TextOut(hDC, 234, 160, "Green:", 6);
//			SetTextColor(hDC, RGB(0, 0, 255));
//			TextOut(hDC, 240, 200, "Blue:", 5);
//
//			EndPaint(hWnd, &PaintStruct);
//			break;
//			return 0;
//
//		}
//		/*case WM_VSCROLL:
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
//		}*/
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}#include <windows.h>
//#include <stdio.h>
//
//#define ID_EDITRED 1
//#define ID_EDITGREEN 2
//#define ID_EDITBLUE 3
//#define ID_EXIT 4
//#define ID_EDITHEX 5
//#define ID_EDIT 1000
//#define ID_LISTBOX 1001
//#define ID_BUTTON 1002
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "ListDir";
//char szTitle[] = "Работа со списком";
//
//char string[] = "Установка цвета"; //текст в окне
//char string1[] = "Ваш цвет: ";
//char string2[] = "16-ричный код цвета:";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, szTitle,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 50, 1000, 360, 0, 0, hInstance, NULL))) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))
//	{
//		TranslateMessage(&msg); DispatchMessage(&msg);
//	}
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hRedScroll, hGreenScroll, hBlueScroll, hyScroll, hyStatic;
//
//	static HWND hRedStatic, hGreenStatic, hBlueStatic;
//	static int nxPos, nxMin, nxMax, nyPos, nyMin, nyMax;
//
//	static HWND hEditRed, hEditBlue, hEditGreen, hEditHex;
//	int red = 128, green = 128, blue = 128; //значения цветов
//	static HWND hListВox, hEdit, hButton, hStatic;
//	int uItem, i; char Buf[80];
//
//	HDC hDC;
//	HBRUSH hBrush; //кисть для рисования эллипса
//	PAINTSTRUCT PaintStruct;
//	RECT Rect, Client; //области отрисовки
//
//	switch (msg)
//	{
//		case WM_CREATE:
//			nxPos = 128; //Среднее положение движка
//			nxMin = 0; //Минимальное положение движка
//			nxMax = 255; //Максимальное положение движка
//			{
//				//Создание трёх полос для каждого цвета
//				hRedScroll = CreateWindow("scrollbar", NULL,
//										  WS_CHILD | WS_VISIBLE | SBS_HORZ,
//										  20, 120, 200, 25, hWnd, (HMENU)-1,
//										  hInstance, NULL);
//				hGreenScroll = CreateWindow("scrollbar", NULL,
//											WS_CHILD | WS_VISIBLE | SBS_HORZ,
//											20, 180, 200, 25, hWnd, (HMENU)-1,
//											hInstance, NULL);
//				hBlueScroll = CreateWindow("scrollbar", NULL,
//										   WS_CHILD | WS_VISIBLE | SBS_HORZ,
//										   20, 240, 200, 25, hWnd, (HMENU)-1,
//										   hInstance, NULL);
//				//Установка диапазона полосы прокрутки
//				//nxMin, nxMax - максимальные значения, TRUE - необходимость перерисовки
//				SetScrollRange(hRedScroll, SB_CTL, nxMin, nxMax, TRUE);
//				SetScrollRange(hGreenScroll, SB_CTL, nxMin, nxMax, TRUE);
//				SetScrollRange(hBlueScroll, SB_CTL, nxMin, nxMax, TRUE);
//				// Cледующая функция устанавливает ползунок в нужное положение
//				//nxPos - новое положение ползунка. TRUE - необходимость перерисовки
//				SetScrollPos(hRedScroll, SB_CTL, nxPos, TRUE);
//				SetScrollPos(hGreenScroll, SB_CTL, nxPos, TRUE);
//				SetScrollPos(hBlueScroll, SB_CTL, nxPos, TRUE);
//
//				hRedStatic = CreateWindow("static", NULL,
//										  WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//										  20, 100, nxPos, 15, hWnd, (HMENU)-1,
//										  hInstance, NULL);
//				hGreenStatic = CreateWindow("static", NULL,
//											WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//											20, 160, nxPos, 15, hWnd, (HMENU)-1,
//											hInstance, NULL);
//				hBlueStatic = CreateWindow("static", NULL,
//										   WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
//										   20, 220, nxPos, 15, hWnd, (HMENU)-1,
//										   hInstance, NULL);
//
//				//Создание полей ввода со значениями цветов
//				hEditRed = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//										  WS_CHILD | WS_VISIBLE | WS_BORDER,
//										  240, 120, 30, 25, hWnd, (HMENU)ID_EDITRED,
//										  hInstance, NULL);
//
//				hEditGreen = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//											WS_CHILD | WS_VISIBLE | WS_BORDER,
//											240, 180, 30, 25, hWnd, (HMENU)ID_EDITGREEN,
//											hInstance, NULL);
//
//				hEditBlue = CreateWindowEx(WS_EX_STATICEDGE, "edit", "127",
//										   WS_CHILD | WS_VISIBLE | WS_BORDER,
//										   240, 240, 30, 25, hWnd, (HMENU)ID_EDITBLUE,
//										   hInstance, NULL);
//
//				//Поле ввода с 16-ричным кодом цвета
//				hEditHex = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "7F7F7F",
//										  WS_CHILD | WS_VISIBLE | WS_BORDER,
//										  320, 260, 60, 25, hWnd, (HMENU)ID_EDITHEX,
//										  hInstance, NULL);
//				/*hyScroll = CreateWindow("scrollbar", NULL,
//										WS_CHILD | WS_VISIBLE | SBS_VERT,
//										20, 100, 90, 200, hwnd, (HMENU)-1,
//										hInstance, NULL);
//				nyPos = 100; nyMin = 1; nyMax = 255;
//
//				SetScrollRange(hyScroll, SB_CTL, nyMin, nyMax, TRUE);
//				SetScrollPos(hyScroll, SB_CTL, nyPos, TRUE);
//				hyStatic = CreateWindow("static", NULL,
//										WS_CHILD | WS_VISIBLE | SS_GRAYRECT,
//										130, 100, 90, nyPos, hwnd, (HMENU)-1,
//										hInstance, NULL);*/
//
//				hStatic = CreateWindow("static",
//									   "Введите строку для ввода в список",
//									   WS_CHILD | WS_VISIBLE | SS_CENTER,
//									   600, 10, 300, 20, hWnd, (HMENU)0, hInstance,
//									   NULL);
//
//				hEdit = CreateWindow("edit", NULL,
//									 WS_CHILD | WS_VISIBLE | WS_BORDER |
//									 ES_LEFT | ES_AUTOHSCROLL, 600, 40, 300, 30,
//									 hWnd, (HMENU)ID_EDIT, hInstance, NULL);
//
//				hListВox = CreateWindow("listbox", NULL,
//										WS_CHILD | WS_VISIBLE | LBS_STANDARD,
//										600, 80, 300, 200, hWnd,
//										(HMENU)ID_LISTBOX, hInstance, NULL);
//
//				hButton = CreateWindow("button", "Добавить",
//									   WS_CHILD | WS_VISIBLE |
//									   BS_PUSHBUTTON, 650, 290, 100, 30, hWnd,
//									   (HMENU)ID_BUTTON, hInstance, NULL);
//				SetFocus(hEdit);
//				return 0;
//			}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				case ID_LISTBOX:
//				{
//					switch (HIWORD(wParam))
//					{
//						case LBN_ERRSPACE:
//						{
//							MessageBox(hWnd, "Мало памяти", szTitle, MB_OK);
//							return 0;
//						}
//						case LBN_DBLCLK:
//						{
//							uItem = (int)SendMessage(hListВox, LB_GETCURSEL, 0, 0L);
//							if (uItem != LB_ERR)
//							{
//								SendMessage(hListВox, LB_GETTEXT, uItem, (LPARAM)Buf);
//								MessageBox(hWnd, Buf, szTitle, MB_OK);
//
//							}
//							return 0;
//						}
//						default: return 0;
//					}
//					return 0;
//				}
//				case ID_BUTTON:
//				{
//
//					SendMessage(hEdit, EM_GETLINE, 0, (LPARAM)Buf);
//					SendMessage(hListВox, LB_ADDSTRING, 0, (LPARAM)Buf);
//					SetWindowText(hEdit, "\0");
//					SetFocus(hEdit);
//					return 0;
//				}
//				default:return 0;
//			}
//		}
//		case WM_HSCROLL:
//		{
//
//			if (hRedScroll == (HWND)lParam)i = 0;
//			if (hGreenScroll == (HWND)lParam)i = 1;
//			if (hBlueScroll == (HWND)lParam)i = 2;
//			switch (LOWORD(wParam))
//
//			{
//				case SB_PAGERIGHT://На страницу вправо
//				{
//					nxPos += 10;
//					break;
//				}
//				case SB_LINERIGHT://На одну линию вправо
//				{
//					nxPos += 1;
//					break;
//				}
//				case SB_PAGELEFT://На страницу влево
//				{
//					nxPos -= 10;
//					break;
//				}
//				case SB_LINELEFT://На линию влево
//				{
//					nxPos -= 1;
//					break;
//				}
//				case SB_TOP://Максимальное значение
//				{
//					nxPos = nxMin;
//					break;
//				}
//				case SB_BOTTOM: //Минимальное значение
//				{
//					nxPos = nxMax;
//					break;
//				}
//				case SB_THUMBPOSITION://Любое перемещение
//				case SB_THUMBTRACK:
//				{
//					nxPos = HIWORD(wParam);
//					break;
//				}
//				default: break;
//			}
//			//Если позиция больше максимальной
//			if (nxPos > nxMax) nxPos = nxMax;//Устанавливаем на граничную максимальную
//			//Если позиция меньше минимальной
//			if (nxPos < nxMin) nxPos = nxMin; //Устанавливаем на граничную минимальную
//			if (nxPos == nxMax)
//				//Если положение движка достигло максимума, блокировать его
//				switch (i) {
//					case 0:
//						EnableScrollBar(hRedScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//					case 1:
//						EnableScrollBar(hGreenScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//					case 2:
//						EnableScrollBar(hBlueScroll, SB_CTL, ESB_DISABLE_RIGHT);
//						break;
//				}
//
//			//Вспоминаем, какая полоса была сдвинута
//			switch (i) {
//				case 0:
//					SetScrollPos(hRedScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITRED, nxPos, 0);
//					MoveWindow(hRedStatic, 20, 100, nxPos, 15, TRUE);
//					break;
//				case 1:
//					SetScrollPos(hGreenScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITGREEN, nxPos, 0);
//					MoveWindow(hGreenStatic, 20, 160, nxPos, 15, TRUE);
//					break;
//				case 2:
//					SetScrollPos(hBlueScroll, SB_CTL, nxPos, TRUE);
//					SetDlgItemInt(hWnd, ID_EDITBLUE, nxPos, 0);
//					MoveWindow(hBlueStatic, 20, 220, nxPos, 15, TRUE);
//					break;
//			}
//
//			//Новые значения переменных цвета получены из полей ввода
//			red = GetDlgItemInt(hWnd, ID_EDITRED, NULL, 0);
//			green = GetDlgItemInt(hWnd, ID_EDITGREEN, NULL, 0);
//			blue = GetDlgItemInt(hWnd, ID_EDITBLUE, NULL, 0);
//
//			//Задаём границы области перерисовки по эллипсу
//			Client.left = 330;
//			Client.top = 60;
//			Client.right = 480;
//			Client.bottom = 220;
//			//Вызываем сообщение WM_PAINT по перерисовке области
//			//эллипса
//			InvalidateRect(hWnd, &Client, 1);
//			//Записываем в буфер 16-ричные эквиваленты цветов
//			sprintf_s(Buf, "%X%X%X", red, green, blue);
//			//Выводим буфер в поле 16-ричного вывода
//			SetDlgItemText(hWnd, ID_EDITHEX, Buf);
//			//Сообщшение рисования
//		case WM_PAINT:
//			hDC = BeginPaint(hWnd, &PaintStruct);
//			GetClientRect(hWnd, &Rect);
//			//Прозрачный режим фона
//			SetBkMode(hDC, TRANSPARENT);
//			//Белый прямоугольник под эллипсом
//			Rectangle(hDC, 330, 60, 480, 220);
//			//Создаём кисть с новыми цветами
//			hBrush = CreateSolidBrush(RGB(red, green, blue));
//			//Делаем её активной
//			SelectObject(hDC, hBrush);
//			//Рисуем эллипс
//			Ellipse(hDC, 350, 80, 460, 200);
//
//			//Выводим текст в окно
//			TextOut(hDC, 60, 20, string, strlen(string));
//			TextOut(hDC, 370, 20, string1, strlen(string1));
//			TextOut(hDC, 325, 234, string2, strlen(string2));
//
//			//Выводим текст над полями ввода разного цвета
//			SetTextColor(hDC, RGB(255, 0, 0));
//			TextOut(hDC, 240, 100, "Red:", 4);
//			SetTextColor(hDC, RGB(0, 255, 0));
//			TextOut(hDC, 234, 160, "Green:", 6);
//			SetTextColor(hDC, RGB(0, 0, 255));
//			TextOut(hDC, 240, 200, "Blue:", 5);
//
//			EndPaint(hWnd, &PaintStruct);
//			break;
//			return 0;
//
//		}
//		/*case WM_VSCROLL:
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
//		}*/
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}