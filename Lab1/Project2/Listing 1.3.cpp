//#define  _CRT_SECURE_NO_WARNINGS
//#include<windows.h>
//
////Объявление функции
//BOOL RegClass(WNDPROC, LPCSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK WndPopup(HWND, UINT, WPARAM, LPARAM);
//
//HINSTANCE hInstance;
//char szMainClass[] = "MainClass";
//char szPopupClass[] = "PopupClass";
//char szTitle[] = "Example 1.3";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance,
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	//Регистрируем класс окна приложения
//	//Выбираем стандартный цвет COLOR_WINDOW
//	if (!RegClass(WndProc, szMainClass, COLOR_WINDOW))
//		return FALSE;
//	// Регистрируем класс временных окон
//	// Выбираем цвет трехмерных элементов COLOR_BTNFACE
//	if (!RegClass(WndPopup, szPopupClass, COLOR_BTNFACE))
//		return FALSE;
//	// Создаем окно приложения
//	// Указываем стиль WS_OVERLAPPED | WS_VISIBLE 
//	// Координаты задаем по умолчанию.
//	hwnd = CreateWindow(szMainClass, szTitle,
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//	if (!hwnd)return FALSE;
//	// Активизируем цикл обработки сообщений
//	while (GetMessage(&msg, 0, 0, 0))DispatchMessage(&msg);
//	return msg.wParam;
//}
//// Сообщения из этого цикла попадают в две различные функции окон.
//// Функция окна приложения WndProc теперь содержит описания,
//// которые решают поставленную задачу.
//// А функция временных окон все сообщения возвращает операционной системе.
//// Даже сообщение о закрытии временного окна обрабатывает операционная система.
//
//// Все действия по созданию, отображению и расположению временных окон 
//// выполняет функция окна приложения при обработке кодов сообщений WM_MOVE, WM_SIZE и WM_LBUTTONDOWN.
//
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM lParam)
//{
//	static short cxClient, cyClient, yStep, xStep;
//	static short left, top, Width, Height;
//	//Описываем массив дескрипторов окно
//	static HWND hwnds[5];
//	switch (msg)
//	{
//		case WM_CREATE: {
//			//ШАГ СМЕЩЕНИЯ ОКНО ПО ВЕРТИКАЛИ
//			yStep = GetSystemMetrics(SM_CYCAPTION);
//			return 0;
//		}
//						//При обработке кода WM_MOVE нужно переместить существующие временные окна.
//						// При перемещении окна - владельца временные окна остаются на прежних позициях.
//						// Но по условию задачи они должны располагаться
//						// от правого нижнего до левого верхнего угла рабочей области окна - владельца.
//						// Поэтому запоминаем новые координаты левого верхнего угла рабочей области окна приложения :
//		case WM_MOVE: {
//			// Левый верхний угол рабочей области
//			left = LOWORD(lParam); top = HIWORD(lParam);
//			// Остается переместить существующие временные окна:
//			// К оордината левого края j - го временного окна отсчитывается 
//			// от правого края рабочей области(left + cxClient) и равна 
//			// величине : left + cxClient - Width - xStep * j.
//			// Аналогично отсчитывается координата верхнего края j-го временного окна.
//			for (short j = 0; j < 5; j++)
//				if (IsWindow(hwnds[j]))
//					MoveWindow(hwnds[j],
//							   left + cxClient - Width - xStep * j,
//							   top + cyClient - Height - yStep * j,
//							   Width, Height, TRUE);
//			return 0;
//		}
//					  // При поступлении кода WM_SIZE требуется пересчитать размеры временных окон. 
//					  // Для этого запоминаем новую ширину и высоту рабочей области окна приложения:
//		case WM_SIZE: {
//			cxClient = LOWORD(lParam); cyClient = HIWORD(lParam);
//			// Тогда ширину и высоту временных окон можно вычислить по выражениям 
//			Width = cxClient / 2; Height = cyClient - 4 * yStep;
//			// Временные окна должны быть смещены друг по отношению к другу. 
//			// Шаг смещения окон по горизонтали зависит от ширины рабочей области. 
//			// Поэтому величину шага также пересчитываем:
//			xStep = (cxClient - Width) / 4;
//			// Остается только переместить существующие временные окна.
//			// Эта часть обработки кода WM_SIZE полностью совпадает 
//			// с такой же частью обработки кода WM_MOVE:
//			// Здесь перебирают все элементы массива дескрипторов hwnds, 
//			// и, если для j - го элемента массива(дескриптора hwnds[j]) существует окно, 
//			// это окно перемещается в новые координаты.
//			for (short j = 0; j < 5; j++)
//				if (IsWindow(hwnds[j]))
//					MoveWindow(hwnds[j],
//							   left + cxClient - Width - xStep * j,
//							   top + cyClient - Height - yStep * j,
//							   Width, Height, TRUE);
//			return 0;
//		}
//					  // При обработке кода WM_LBUTTONDOWN(при нажатии левой клавиши мыши) 
//					  // перебирают элементы массива дескрипторов hwnds до тех пор, 
//					  // пока не обнаруживается, что для j - го элемента массива
//					  // (дескриптора hwnds[j]) не существует окна :
//		case WM_LBUTTONDOWN:
//		{// опечатка short в книге
//			short j;
//			for (j = 0; j < 5, IsWindow(hwnds[j]); j++);
//			if (j > 4) return 0;
//
//			char str[20]; _itoa(j + 1, str, 10); strcat(str, "-е окно");
//			//Если для всех дескрипторов массива существуют окна, 
//			//обработка сообщения завершается.
//			//Иначе для этого дескриптора в определенном условиями задачи месте создается окно :
//			hwnds[j] = CreateWindow(szPopupClass, str,
//									WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE,
//									left + cxClient - Width - xStep * j,
//									top + cyClient - Height - yStep * j,
//									Width, Height, hwnd, 0, hInstance, NULL);
//			// Следующее действие связано с изменением расположения только что созданного окна без перемещения:
//			if (j > 0)
//			{
//				SetWindowPos(hwnds[j], hwnds[j - 1], 0, 0, Width, Height, SWP_NOMOVE);
//				SetForegroundWindow(hwnds[0]);
//			}return 0;
//			// To есть функция SetWindowPos располагает окно hwnds[j] под предыдущим окном hwnds[j-1]. 
//			// А функция SetForegroundWindow выдвигает на передний план первое окно из массива дескрипторов. 
//			// Таким образом, при создании нового временного окна на переднем плане всегда окажется первое из них.
//			// Этим завершается обработка кода WM_LBUTTONDOWN.
//		}
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}
//LRESULT CALLBACK WndPopup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}
