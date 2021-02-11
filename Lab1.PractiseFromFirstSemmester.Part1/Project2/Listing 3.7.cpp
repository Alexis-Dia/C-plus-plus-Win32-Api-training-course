//#include <windows.h>
//#include <stdio.h>
//#include <math.h>
//#include <tchar.h>
//#define snprintf _snprintf
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "TableClass";
////��������� ������� ������
//typedef struct {
//	char str[15]; //���� ����� �������
//	double val[50]; //������ ������ �������
//}
//COLUMN; //��� ����
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "�������",
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
//{ //��������� ������ �� 10 ��������
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
//			//��������� ��������� ��������
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
//			//��������� ������� ������ ��������
//			for (int i = 0; i < 50; i++)
//			{ //� ������ ������� ����� ������ �����
//				cols[0].val[i] = i;
//				//� ��������� �������� ����� ������
//				for (int j = 1; j < 10; j++)
//					cols[j].val[i] = 10 * sin(i / 10 / j);
//			}
//			//���������� ������� ������ � ������ ��������
//			{
//				TEXTMETRIC tm;
//				HDC hdc = GetDC(hwnd);
//				//���������� ������� ������
//				GetTextMetrics(hdc, &tm);
//				ReleaseDC(hwnd, hdc);
//				//����� �������� � ������ �������
//				cyChar = tm.tmHeight + tm.tmExternalLeading;
//				//����� �������� � ������� ������
//				cxChar = tm.tmAveCharWidth + 1;
//			}
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			char str[20];
//			//��������� ��������� ��������� ��� ������
//			int left = cxChar, //����� ����
//				top = cyChar / 2, //����
//				dx = cxChar, //������ �� ��� X
//				dy = cyChar / 4, //������ �� ��� Y
//				hy = cyChar + dy + dy, //������ ��� ������
//				right = cx - cxChar, //������ ����
//				bottom = cy - cyChar, //���
//				bounds[10], //������ ����� ��������
//				i = 0, j = 0; //��������� ������ �������� ��������
//			while (j < 10)
//			{ //��� j-ro ������� �������� ������
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
//			//���������� ������������ ����� ��������,
//			//������� ���������� �� ������ ������� �������
//			int dd = left, maxcol = 0;
//			while (maxcol < 10)
//			{
//				if (dd + bounds[maxcol] > right) break;
//				dd += bounds[maxcol];
//				maxcol++;
//			}
//			//right ������ ��������� �� ������ ���� �������
//			right = dd;
//			//��������� ������ ���� � ����� ��������
//			{
//				RECT rc; GetWindowRect(hwnd, &rc);
//				MoveWindow(hwnd, rc.left, rc.top,
//						   //�������� ������ ������ ����
//						   rc.right - rc.left - (cx - right) + dx,
//						   rc.bottom - rc.top, TRUE);
//			}
//			//////������ ������ �������//////
//			//������������� ����� ������������
//			SetTextAlign(hdc, TA_RIGHT);
//			//////������ ������ ����� �������//////
//			int y = top; //������� ���������� �� ��� Y
//			//�������������� ����� �� ��� ������
//			DrawLine(hdc, left, y, right, y);
//			//��������� ��������
//			int x = left; //������� ���������� �� ��� X
//			//������������ ����� ����� �� �������
//			DrawLine(hdc, x, y, x, y + hy);
//			for (j = 0; j < maxcol; j++)
//			{ //������������� � �� ������ ������� �������
//				x += bounds[j];
//				TextOut(hdc, x - dx, y + dy, cols[j].str, strlen(cols[j].str));
//				//������������ ����� ������ �� �������
//				DrawLine(hdc, x, y, x, y + hy);
//			}
//			//�������������� ����� �� ��� ������
//			y += hy; DrawLine(hdc, left, y, right, y);
//			//////����� ������ ����� �������//////
//			//////������ ������ ������ �������//////
//			i = 0;//������� ������ ������ ������
//			while (i < 50 && y < bottom)
//			{ //������������ ����� ����� �� ������� x=left;
//				DrawLine(hdc, x, y, x, y + hy);
//				for (j = 0; j < maxcol; j++) {
//					x += bounds[j];
//					//����������� ����� ����� � ������
//					if (j == 0) _itoa_s((int)cols[0].val[i], str, 10);
//					//����������� ������������ ����� � ������
//					else _sntprintf_s(str, 7, _T("%f"), cols[j].val[i]);
//					//_gcvt( cols[j].val[i], 7, str);
//					TextOut(hdc, x - dx, y + dy, str, strlen(str));
//					//������������ ����� ������ �� �������
//					DrawLine(hdc, x, y, x, y + hy);
//				}
//				//�������������� ����� �� ��� ������
//				y += hy; DrawLine(hdc, left, y, right, y);
//				i++;
//			}
//			//////����� ������ ������ �������//////
//			EndPaint(hwnd, &ps);
//			return 0;
//		}
//		case WM_DESTROY:
//		{ PostQuitMessage(0); return 0; }
//	}
//	return
//		DefWindowProc(hwnd, msg, wParam, lParam);
//}