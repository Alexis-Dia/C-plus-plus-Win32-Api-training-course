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
//	hwnd = CreateWindow(szClassName, "�������",
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
//			//������ ������� ��� ��������� �������
//			int �0 = cx / 10, //����� ���� �������
//				�r = cx - �0, //������ ���� �������
//				�0 = cy / 10, //������� ���� �������
//				�� = cy / 2, //�������� ������� �� ��� �
//				amp = �� - �0; //��������� ������� �� ������
//			float ymax = 0., //�������� �������
//				ymin = 0.; //������� �������
//				//������� �������� �������
//			TextOut(hdc, �0 + 4, �0 / 3,
//					myfunc.name, strlen(myfunc.name));
//			//������� �������� ����������
//			TextOut(hdc, �r + �0 / 2, �� + �0 / 10, "T", 1);
//			//������ ��� �������
//			MoveToEx(hdc, �0, cy - �0 + �0 / 2, NULL);
//			LineTo(hdc, �0, �0 - �0 / 2); //������ ��� �������
//			MoveToEx(hdc, �0, ��, NULL);
//			LineTo(hdc, �r + �0 / 2, ��);
//			//���������� �������� � ������� �������
//			for (int i = 0; i < 100; i++)
//			{
//				float ycurr = myfunc.y[i];
//				if (ymax < ycurr) ymax = ycurr;
//				else if (ymin > ycurr) ymin = ycurr;
//			}
//			if (ymax < fabs(ymin)) ymax = (float)fabs(ymin);
//			//������������� ������� �� ��� �
//			float dy = (float)amp / ymax;
//			//������������� ������� �� ��� �
//			float dx = (float)(�r - �0) / (myfunc.x[99] - myfunc.x[0]);
//			//��� ��������� ������� ���� ������ �����
//			HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//			HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
//			//������������� ������ � ������ ����� �������
//			MoveToEx(hdc, �0, (int)(�� - dy * myfunc.y[0]), NULL);
//			//������� ����� �� ���������� ����� � �������
//			for (int i = 1; i < 100; i++)
//			{
//				//��������� ���������� ������� �����
//				int xcurr = (int)(dx * (myfunc.x[i] - myfunc.x[0]) + �0),
//					ycurr = (int)(�� - dy * myfunc.y[i]);
//				//������ ������ �� ������� �����
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