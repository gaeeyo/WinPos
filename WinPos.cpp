// WinPos.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


DWORD parseStyleText(LPCTSTR src)
{
	static struct {
		LPCTSTR name;
		DWORD	flag;
	} names[]= {
		{_T("WS_OVERLAPPED")       ,WS_OVERLAPPED      },
		{_T("WS_POPUP")            ,WS_POPUP           },
		{_T("WS_CHILD")            ,WS_CHILD           },
		{_T("WS_MINIMIZE")         ,WS_MINIMIZE        },
		{_T("WS_VISIBLE")          ,WS_VISIBLE         },
		{_T("WS_DISABLED")         ,WS_DISABLED        },
		{_T("WS_CLIPSIBLINGS")     ,WS_CLIPSIBLINGS    },
		{_T("WS_CLIPCHILDREN")     ,WS_CLIPCHILDREN    },
		{_T("WS_MAXIMIZE")         ,WS_MAXIMIZE        },
		{_T("WS_CAPTION")          ,WS_CAPTION         },     /* WS_BORDER | WS_DLGFRAME  */
		{_T("WS_BORDER")           ,WS_BORDER          },
		{_T("WS_DLGFRAME")         ,WS_DLGFRAME        },
		{_T("WS_VSCROLL")          ,WS_VSCROLL         },
		{_T("WS_HSCROLL")          ,WS_HSCROLL         },
		{_T("WS_SYSMENU")          ,WS_SYSMENU         },
		{_T("WS_THICKFRAME")       ,WS_THICKFRAME      },
		{_T("WS_GROUP")            ,WS_GROUP           },
		{_T("WS_TABSTOP")          ,WS_TABSTOP         },
		{_T("WS_MINIMIZEBOX")      ,WS_MINIMIZEBOX     },
		{_T("WS_MAXIMIZEBOX")      ,WS_MAXIMIZEBOX     },
		{NULL, 0 },
	};
	DWORD	flag = 0;
	CString	text(src);
	CString	token;
	int pos = 0;
	while(1) {
		token = text.Tokenize(_T("|+/"), pos);
		if(pos == -1) {
			break;
		}
		int j= 0;
		for(j=0; names[j].name != NULL; j++) {
			if(token.CompareNoCase(names[j].name) == 0) {
				flag |= names[j].flag;
				break;
			}
		}
		if(names[j].name == NULL) {
			DWORD v = 0;
			if( _stscanf_s(token, _T("0x%x"), &v) == 1) {
				flag |= v;
			}
			else if( _stscanf_s(token, _T("%d"), &v) == 1) {
				flag |= v;
			}
			else {
				_tprintf(_T("スタイル \"%s\" は未知のフラグです\r\n"), token);
			}
		}
	}
	return flag;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LPCTSTR  findClassName = NULL;
	LPCTSTR  findTitle = NULL;
	LPCTSTR  setRect = NULL;
	LPCTSTR  setStyle = NULL;
	for(int j=0; j<argc; j++) {
		if(_tcscmp(argv[j], _T("-title")) == 0 && j+1 < argc) {
			findTitle = argv[++j];
		}
		if(_tcscmp(argv[j], _T("-rect")) == 0 && j+1 < argc) {
			setRect = argv[++j];
		}
		if(_tcscmp(argv[j], _T("-style")) == 0 && j+1 < argc) {
			setStyle = argv[++j];
		}
	}

	if(findTitle == NULL) {
		_tprintf(
			_T("WinPos [-t TITLE] [-rect RECT] [-style MASK,STYLE]\r\n")

			);
	}
	else {
		CWindow wnd = FindWindow(findClassName, findTitle);
		if(wnd) {
			CRect rc;
			wnd.GetWindowRect(&rc);
			_tprintf(_T("%d,%d,%d,%d\r\n"), rc.left, rc.top, rc.right, rc.bottom);

			BOOL bModStyle = false;
			if(setStyle) {
				TCHAR	strMask[100] = {};
				TCHAR	strStyle[100] = {};
				int e = _stscanf_s(setStyle, _T("%[^,],%[^,]"),
						strMask, _countof(strMask), 
						strStyle, _countof(strStyle));

				DWORD dwStyle = wnd.GetWindowLong(GWL_STYLE);
				DWORD dwMask = parseStyleText(strMask);
				DWORD dwNewStyle = (dwStyle & ~dwMask) | parseStyleText(strStyle);
				if(dwNewStyle != dwStyle) {
					wnd.SetWindowLong(GWL_STYLE, dwNewStyle);
					bModStyle = true;
				}
			}
			
			CRect	newRect;
			if(setRect) {
				_stscanf_s(setRect, _T("%d,%d,%d,%d"), &newRect.left, &newRect.top, &newRect.right, &newRect.bottom);
			}

			if(bModStyle || setRect) {
				wnd.SetWindowPos(0, newRect, 
					(setRect ? 0 : (SWP_NOMOVE | SWP_NOSIZE)) 
					| (bModStyle ? SWP_FRAMECHANGED : 0)
					| SWP_NOACTIVATE | SWP_NOZORDER
					);
			}
		}
		else {
			_tprintf(_T("ウィンドウが見つかりませんでした\n"));
		}
	}

	return 0;
}

