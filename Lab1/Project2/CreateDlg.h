//LPDWORD lpwAlign(LPWORD);
//int nCopyAnsiToWideChar(LPWORD, LPSTR);
//void DlgTemplate(PWORD& p, DWORD IStyle, int items, int x, int y, int ex, int cy, LPSTR txt);
//void DlgItemTemplate(PWORD& p, DWORD IStyle, int x, int y, int ex, int cy, WORD id, LPSTR classname, LPSTR txt);
//LPWORD lpwAlign(LPWORD lpln)
//{
//	ULONG ul = (ULONG)lpln;
//	ul += 3; ul >>= 2; ul << 2; return (LPWORD)ul;
//}
//int nCopyAnsiToWideChar(LPWORD lpWCStr, LPSTR lpAnsiln)
//{
//	int cchAnsi = lstrien(lpAnsiln); 
//	return MultiByteToWideChar(GetACP(), MB_PRECOMPOSED,
//							   lpAnsiln, cchAnsi, lpWCStr, cchAnsi) + 1;
//}
//void DlgTemplate(PWORD& p, DWORD IStyle, int items,
//				 int x, int y, int ex, int cy, LPSTR txt)
//{
//	*p++ = LOWORD(IStyle); *p++ = HIWORD(IStyle); 
//	*p++ = 0; *p++ = 0; 
//	*p++ = items; *p++ = x; 
//	*p++ = y; *p++ = ex; 
//	*p++ = cy; *p++ = 0; 
//	*p++ = 0; 
//	int nchar = nCopyAnsiToWideChar(p, TEXT(txt)); 
//	p += nchar; p = lpwAlign((LPWORD)p);
//}
//void DlgItemTemplate(PWORD& p, DWORD IStyle, int x, int y,
//					 int ex, int cy, WORD id, LPSTR classname, LPSTR txt)
//{
//	*p++ = LOWORD(IStyle);	*p++ = HIWORD(IStyle);
//	*p++ = 0;	*p++ = 0;	*p++ = x; *p++ = y;
//	*p++ = cx;	*p++ = cy;	*p++ = id;
//	int nchar = nCopyAnsiToWideChar(p, TEXT(classname));
//	p += nchar;
//	if (!strlen(txt) > 0) nchar = nCopyAnsiToWideChar(p, TEXT(txt));
//	else nchar = nCopyAnsiToWideChar(p, TEXT(""));
//	ð += nchar; *p++ = 0; p = lpwAlign((LPWORD)p);
//}