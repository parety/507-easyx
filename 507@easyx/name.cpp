#include <name.h>

//#define DEBUG


int name_loop(int SCREEN_W, int SCREEN_H)
{
	int pos = 0;
	wchar_t ch;
	wchar_t *name;
	name = (wchar_t*)calloc(BUFFSIZE, sizeof(wchar_t));
	settextcolor(BLACK);
	settextstyle(72, 0, _T("SYSTEM"));
	RECT title_rect = { 0, 0, SCREEN_W, 3*SCREEN_H/4};
	RECT name_rect = { 0,SCREEN_H/2,SCREEN_W,SCREEN_H };
	while (1)
	{
		clearcliprgn();
		Sleep(50);
		BeginBatchDraw();
		drawtext(_T("WHAT IS YOUR NAME?"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(name, &name_rect, DT_CENTER | DT_WORDBREAK);
		FlushBatchDraw();

		if (_kbhit())
		{
			ch = _getch();
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				//��ջ��������ַ�
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				//��ջ��������ַ�
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				//��ջ��������ַ�
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				//��ջ��������ַ�
				_getch();
				continue;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Returned!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				Sleep(200);
				return 1;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) & 1)
			{
				clearcliprgn();
				BeginBatchDraw();
				drawtext(_T("Escaped!"), &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				FlushBatchDraw();
				Sleep(200);
				return 1;
			}
			else if (GetAsyncKeyState(VK_BACK) & 1)
			{
			}
			else if(ch >=33 && ch <= 126)
			{
				if(pos<BUFFSIZE-1) name[pos++] = ch;
			}
		}
	}
}
