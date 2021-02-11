//#include <windows.h> 
//#include <string.h> 
//#include <stdio.h> 
//
//LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
//
//char szWinName[] = "MyWin";   //   Имя класса окна 
//char str[255] = "";     //   Строка вывода 
//int  WINAPI  WinMain(HINSTANCE  hThisInst, HINSTANCE  hPrevInst, LPSTR lpszArgs, int nWinMode)
//{
//	HWND hwnd;    //  Дескриптор окна 
//	MSG msg;    //  Структура сообщения Windows 
//	WNDCLASSEX wcl;  //  Структура, определяющая класс окна 
//	/* Определение класса окна */
//	wcl.hInstance = hThisInst;    //  Работа с данным экземпляром 
//	wcl.lpszClassName = szWinName;  //  Имя класса окна 
//	wcl.lpfnWndProc = WindowFunc;  //  Оконная функция 
//	wcl.style = 0;   //  Использовать стиль окна по умолчанию 
//	wcl.cbSize = sizeof(WNDCLASSEX);  //  Установка размера 
//	// WNDCLASSEX 
//	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Большие иконки 
//	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO); //  Маленькие 
//	//  иконки 
//	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); // Стиль курсора 
//	wcl.lpszMenuName = NULL;      //  Меню нет 
//	wcl.cbClsExtra = 0;   //  Дополнительной информации нет 
//	wcl.cbWndExtra = 0;   //  Дополнительной информации нет 
//	wcl.hbrBackground = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //(GetStockObject не работает в codeblocks) без него работает
//		// Установка фона окна 
//	   /* Регистрация класса окна */
//	if (!RegisterClassEx(&wcl)) return 0;
//	/* Создаём само окно */
//	hwnd = CreateWindow(szWinName,  //  Имя класса окна 
//						"API application",      //  Заголовок 
//						WS_OVERLAPPEDWINDOW,  //  Стиль окна - нормальный пропущена запятая
//						CW_USEDEFAULT,  //  Координата X - выбирает Windows 
//						CW_USEDEFAULT,  //  Ширина - выбирает Windows 
//						CW_USEDEFAULT,  //  Высота - выбирает Windows 
//						CW_USEDEFAULT, //(не хватало этого параметра)
//						HWND_DESKTOP,  //  Нет родительского окна 
//						NULL,    //  Нет меню 
//						hThisInst, //  Работа с данным экземпляром программы 
//						NULL   //  Дополнительные аргументы отсутствуют 
//	);
//	/* Вывод окна */
//	ShowWindow(hwnd, nWinMode);
//	UpdateWindow(hwnd);
//
//	/* Создание цикла обработки сообщений */
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg); //Разрешить использование клавиатуры 
//		DispatchMessage(&msg);  //  Вернуть управление Windows 
//	}
//	return msg.wParam;
//}      // WinMain 
//
///*  Оконная функция обработки сообщений, полученных из очереди сообщений.  */
//
//LRESULT  CALLBACK  WindowFunc(HWND  hwnd, UINT  message,
//							  WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	switch (message)
//	{
//		case WM_CHAR:        //  Символьное сообщение от клавиатуры 
//			break;
//		case WM_LBUTTONDOWN:         // Обработчик нажатия левой кнопки мыши 
//			break;
//		case WM_RBUTTONDOWN:          // Обработчик нажатия правой кнопки мыши 
//			break;
//		case WM_DESTROY:     //  Завершение программы 
//			PostQuitMessage(0);
//			break;
//		default:
//			return  DefWindowProc(hwnd, message, wParam, lParam);
//	}
//	return 0;
//}
