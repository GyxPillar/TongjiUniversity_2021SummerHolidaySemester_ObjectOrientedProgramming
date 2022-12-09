/* 2053385 ������ */


/***************************************************************************
  �ļ����ƣ�color_ball_graph.cpp
  ��    �ܣ�ʵ����Ϸ����ͼ�λ�
***************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<iostream>
#include<cstring>
#include"colorball_class.h"
#include"colorball_graph.h"

using namespace std;

IMAGE game_bar;   // ��״̬��ͼ       
IMAGE board_bg;   // ��Ϸ���б���ͼ
IMAGE _chess[7];  // ����ͼƬ
IMAGE shining[13];// չʾ������˸��13֡ͼƬ
IMAGE cover;      // �����������ڸ�ͼƬ

RECT BAR_FRONT = { 70,31,120,47 };               // ��ǰ״̬������
RECT BAR_BEHIND = { 252,33,292,49 };             // �Ϻ�״̬������
RECT BAR_DOWN = { 40,394,55,450 };               // ��״̬������
RECT START_COMMAND = { 58,90,58 + 194,90 + 72 }; // ��ʼ������

/***************************************************************************
  �������ƣ�homepage
  ��    �ܣ�չʾ��Ϸ��ʼ����
  ���������
  �� �� ֵ��
***************************************************************************/
void homepage()
{
	initgraph(315, 358 + 65);                             // ���ɴ���

	BeginBatchDraw();                                     // ��ͣͼƬ�ڴ��ڵ�����������ӻ���������������������ⲻͬͼƬ��ʱ������Ӿ���˸

	IMAGE homepage_bg;                                    // ��ʼ���汳��ͼ
	loadimage(&homepage_bg, _T("homepage_bg.png"));       // ���뿪ʼ���汳��ͼ
	putimage(0, 0, &homepage_bg);                         // չʾ��ʼ���汳��ͼ

	IMAGE tongji1, tongji2;                               // ��ʼ����У��ͼ
	loadimage(&tongji1, _T("tongji1.png"));               // ���뿪ʼ����У��ͼ(Ϊʵ��͸�����������úڵײ�ͼ1��׵׺�ͼ2��������ȡͼƬ�Ա�����λ������ʽ���)
	loadimage(&tongji2, _T("tongji2.png"));
	putimage(84, 220, &tongji2,SRCAND);                   // �׵׺�ͼ2�ͱ��� ������and��ʽ ���
	putimage(84, 220, &tongji1,SRCPAINT);                 // �ڵײ�ͼ1�ͱ��� ������ or��ʽ ���

	IMAGE start_command1, start_command2;                 // ��ʼ���水��ͼ 
	loadimage(&start_command1, _T("start_command1.png")); // ���뿪ʼ���水��ͼ(Ϊʵ��͸�����������úڵײ�ͼ1��׵׺�ͼ2��������ȡͼƬ�Ա�����λ������ʽ���)
	loadimage(&start_command2, _T("start_command2.png"));
	putimage(58, 90, &start_command2, SRCAND);            // �׵׺�ͼ2�ͱ��� ������and��ʽ ���
	putimage(58, 90, &start_command1, SRCPAINT);	      // �ڵײ�ͼ1�ͱ��� ������ or��ʽ ���
	
	FlushBatchDraw();                                     // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
	EndBatchDraw();                                       // ����BeginBatchDraw()����

	ExMessage MESSAGE;                                    // ������Ϣ���������Խ��������Ϣ
	while (1)
	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY);          // ��ȡ���򰴼���Ϣ
		if (MESSAGE.message == WM_LBUTTONDOWN)            // ����ȡ���������
		{
			if (MESSAGE.x <= 58 || MESSAGE.x >= 58 + 194 || MESSAGE.y <= 90 || MESSAGE.y >= 90 + 72) 
				continue;                                 // ����겻�ڿ�ʼ����Χ�ڣ����¶�ȡ�����Ϣ
			break;                                        // �����ж�Ϊ�û�������ʼ���̣���Ϸ��ʼ
		}
	}
}

/***************************************************************************
  �������ƣ�graph_init
  ��    �ܣ�������Ϸ���ӡ��ʼ��ͼ
  ���������					
  �� �� ֵ��
***************************************************************************/
void graph_init()
{
	setbkmode(TRANSPARENT);                         // ������䱳����Ϊ͸��
	LOGFONT f;                                      // �����������
	gettextstyle(&f);						        // ��ȡ��ǰ��������
	f.lfHeight = 21;						        // ��������߶�Ϊ 21
	_tcscpy(f.lfFaceName, _T("Calibri"));	        // ��������
	f.lfQuality = ANTIALIASED_QUALITY;		        // �������Ч��Ϊ�����  
	settextstyle(&f);						        // ����������ʽ

	loadimage(&game_bar, _T("game_bar.png"));       // ������״̬��ͼ
	putimage(0, 0, &game_bar);                      // �����״̬��ͼ

	loadimage(&board_bg, _T("board_bg.png"));       // ������Ϸ����ͼ
	putimage(0, 65, &board_bg);                     // �����Ϸ����ͼ

	loadimage(&_chess[0], _T("chess0.png"));        // ����0-6��ɫ����ͼ
	loadimage(&_chess[1], _T("chess1.png"));
	loadimage(&_chess[2], _T("chess2.png"));
	loadimage(&_chess[3], _T("chess3.png"));
	loadimage(&_chess[4], _T("chess4.png"));
	loadimage(&_chess[5], _T("chess5.png"));
	loadimage(&_chess[6], _T("chess6.png"));

	loadimage(&shining[0], _T("shining (0).png"));  // ����13֡��˸ͼ
	loadimage(&shining[1], _T("shining (1).png"));
	loadimage(&shining[2], _T("shining (2).png"));
	loadimage(&shining[3], _T("shining (3).png"));
	loadimage(&shining[4], _T("shining (4).png"));
	loadimage(&shining[5], _T("shining (5).png"));
	loadimage(&shining[6], _T("shining (6).png"));
	loadimage(&shining[7], _T("shining (7).png"));
	loadimage(&shining[8], _T("shining (8).png"));
	loadimage(&shining[9], _T("shining (9).png"));
	loadimage(&shining[10], _T("shining (10).png"));
	loadimage(&shining[11], _T("shining (11).png"));
	loadimage(&shining[12], _T("shining (12).png"));

	loadimage(&cover, _T("cover.png"));             // �����ڸ�ͼ
}

/***************************************************************************
  �������ƣ�draw_colorball
  ��    �ܣ���ӡС��
  ���������const int color   С����ɫ
			const int x       ������
			const int y       ������
  �� �� ֵ��
***************************************************************************/ 
void draw_colorball(const int color, const int x, const int y)
{
	putimage(COL_0 + y * D_COL, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT); // SRCPAINT Ŀ��ͼ�� = Ŀ��ͼ�� OR Դͼ�� ��ͼƬʵ�л����㣬ʵ��͸��
}

/***************************************************************************
  �������ƣ�draw_cover
  ��    �ܣ�����С��
  ���������const int x       ������
			const int y       ������
  �� �� ֵ��
***************************************************************************/
void draw_cover(const int x, const int y)
{
	putimage(COL_0 + y * D_ROW + 4, ROW_0 + x * D_ROW + 4, &cover);
}

/***************************************************************************
  �������ƣ�draw_game_bar
  ��    �ܣ���ӡ��״̬����Ϣ
  ���������const int best_scores  ��ѳɼ�  
			const int total_scores ��ǰ�ɼ�
  �� �� ֵ��
***************************************************************************/
void draw_game_bar(const int best_scores, const int total_scores)
{
	setbkcolor(RGB(132, 44, 23));          // ���ñ�����ɫ-ǰ״̬��
	clearrectangle(70, 31, 120, 47);       // ���ǰ״̬��
	setbkcolor(RGB(127, 47, 21));          // ���ñ�����ɫ-ǰ״̬��
	clearrectangle(252, 33, 292, 49);      // �����״̬��	

	TCHAR BEST_SCORES[10],TOTAL_SCORES[10];// ��Ŀ�ַ��� TCHAR
	_stprintf_s(BEST_SCORES, _T("%d"), best_scores), _stprintf_s(TOTAL_SCORES, _T("%d"), total_scores);// ���÷ִ�int��ת��Ϊ��Ŀ�ַ���TCHAR��

	drawtext(BEST_SCORES, &BAR_FRONT, DT_RIGHT);   // ��ӡǰ״̬��
	drawtext(TOTAL_SCORES, &BAR_BEHIND, DT_RIGHT); // ��ӡ��״̬��
}

/***************************************************************************
  �������ƣ�draw_temp_tips
  ��    �ܣ���ӡ��״̬����Ϣ����ʾ������һ����Ϸ
  ���������
  �� �� ֵ��
***************************************************************************/
void draw_temp_tips()
{
	LOGFONT f;                                                   // ��������
	gettextstyle(&f);					     	                 // ��ȡ��ǰ��������
	f.lfHeight = 15;						                     // ��������߶�Ϊ 12
	settextstyle(&f);					                         // ����������ʽ
	outtextxy(40, 394, L"������Ϸ����,�������⴦������ֱ���˳�");// ���������Ϸ�����������һ����ʾ

	ExMessage MESSAGE;                           // ������Ϣ���������Խ��������Ϣ 
	while (1)
	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY); // ��ȡ����밴����Ϣ
		if (MESSAGE.message == WM_LBUTTONDOWN)   // ����ȡ�����������£�������һ����Ϸ
			break;
	}

	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 21;						// ��������߶�Ϊ 21
	settextstyle(&f);						// ����������ʽ���ָ���״̬�����壩

	putimage(0, 65, &board_bg);             // ��ӡ��Ϸ���б���ͼ��������̣�
}

/***************************************************************************
  �������ƣ�draw_shining
  ��    �ܣ������ӱ�ѡ�������չʾ��˸Ч��������ȡ��һ�ε��������������Ϣ
  ���������const int color    С����ɫ
			const int x        ������
			const int y        ������
			ExMessage &MESSAGE ��Ϣ����
  �� �� ֵ��
***************************************************************************/
void draw_shining(const int color, const int x, const int y,ExMessage &MESSAGE)
{
	while (1)
	{
		FOR(i, 0, 13)   // ��13֡��˸ͼ                                  
		{
			putimage(COL_0 + y * D_ROW + 3,ROW_0 + x * D_ROW + 3, &shining[i], SRCPAINT);        // SRCPAINT Ŀ��ͼ�� = Ŀ��ͼ�� OR Դͼ�� ��ͼƬʵ�л����㣬ʵ��͸��
			FOR(j, 0, 3)                                                                         // ����˸ʱʵʱ��ȡ�����Ϣ��ÿһ֡ͼƬͣ��3ms
			{
				if (peekmessage(&MESSAGE, EM_MOUSE | EM_KEY, true))                              // ʵʱ��ȡ��갴����Ϣ
				{
					if (MESSAGE.message == WM_LBUTTONDOWN)                                       // ����ȡ��������� 
					{
						BeginBatchDraw();                                                        // ��ͣͼƬ�ڴ��ڵ�����������ӻ���������������������ⲻͬͼƬ��ʱ������Ӿ���˸
						putimage(COL_0 + y * D_ROW + 3, ROW_0 + x * D_ROW + 3, &cover);          // �ڸ���˸ͼ
						putimage(COL_0 + y * D_ROW, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT);// �ָ�ԭ����ͼ
						FlushBatchDraw();                                                        // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
						EndBatchDraw();                                                          // ����BeginBatchDraw()����
						return;                                                                  // ֹͣ��˸��������һ������
					}
				}
				Sleep(1);                                                                        // ֹͣ1ms,ÿһ֡ͼ��Լͣ��3ms
			}
			BeginBatchDraw();                                                                    // ��ͣͼƬ�ڴ��ڵ�����������ӻ���������������������ⲻͬͼƬ��ʱ������Ӿ���˸
			putimage(COL_0 + y * D_ROW + 4, ROW_0 + x * D_ROW + 4, &cover);                      // �ڸ���˸ͼ
			putimage(COL_0 + y * D_ROW, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT);            // �ָ�ԭ����ͼ��ͬʱ��ͼƬor����ʹ����͸��
			FlushBatchDraw();                                                                    // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
			EndBatchDraw();                                                                      // ����BeginBatchDraw()����
		}
	}
}

/***************************************************************************
  �������ƣ�draw_move
  ��    �ܣ�չʾ�����ƶ�����
  ���������const int start_x  ��������
			const int start_y  ���������
			const int end_x    �յ������
			const int end_y    �յ�������
  �� �� ֵ��
***************************************************************************/
void game::draw_move(const int start_x, const int start_y, const int end_x, const int end_y)
{
	BeginBatchDraw();                                                                                            // ��ͣͼƬ�ڴ��ڵ�����������ӻ���������������������ⲻͬͼƬ��ʱ������Ӿ���˸
	putimage(COL_0 + start_y * D_ROW + 4, ROW_0 + start_x * D_ROW + 4, &cover);                                  // ����������
	putimage(COL_0 + end_y * D_ROW, ROW_0 + end_x * D_ROW, &_chess[colorball[start_x][start_y].color], SRCPAINT);// ���յ�չʾ����ͬʱ��ͼƬor����ʹ����͸��
	FlushBatchDraw();                                                                                            // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
	EndBatchDraw();                                                                                              // ����BeginBatchDraw()����
	Sleep(50);                                                                                                   // ֹͣ50ms
	colorball[end_x][end_y].color = colorball[start_x][start_y].color;                                           // �յ�����¼Ϊ�����ɫ
	colorball[start_x][start_y].color = -1;                                                                      // ����¼Ϊ�޲���
}


/***************************************************************************
  �������ƣ�draw_remove
  ��    �ܣ�չʾ������÷ֱ������ƶ�����
  ���������
  �� �� ֵ���������Ĳ�������Ŀ��ȥ���ظ�����Ĳ���
***************************************************************************/
int game::draw_remove()
{
	int ret = 0;
	FOR(k, 0, 13)     // ��13֡��˸ͼ 
	{
		BeginBatchDraw();
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)
			{
				if (colorball[i][j].mark[0])
					putimage(COL_0 + j * D_ROW + 3, ROW_0 + i * D_ROW + 3, &shining[i], SRCPAINT);        // SRCPAINT Ŀ��ͼ�� = Ŀ��ͼ�� OR Դͼ�� ��ͼƬʵ�л����㣬ʵ��͸��
			}
		}
		FlushBatchDraw();                                                                                            // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
		EndBatchDraw();
		BeginBatchDraw();
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)
			{
				if (colorball[i][j].mark[0])
				{
					putimage(COL_0 + j * D_ROW + 4, ROW_0 + i * D_ROW + 4, &cover);                                      // �ڸ���˸ͼ
					putimage(COL_0 + j * D_ROW, ROW_0 + i * D_ROW, &_chess[colorball[i][j].color], SRCPAINT);            // �ָ�ԭ����ͼ��ͬʱ��ͼƬor����ʹ����͸��
				}
			}
		}		
		Sleep(20);
		FlushBatchDraw();                                                                                            // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
		EndBatchDraw();
		Sleep(3);
	}
	BeginBatchDraw();
	FOR(i, 0, 9)
	{
		FOR(j, 0, 9)
		{
			if (colorball[i][j].mark[0])
			{
				putimage(COL_0 + j * D_ROW + 4, ROW_0 + i * D_ROW + 4, &cover);                      // �ڸ���˸ͼ
				colorball[i][j].color = -1;
				ret++;
			}
		}
	}
	FlushBatchDraw();                                                                                            // ���ݴ��ڻ�������ͼƬ����ͬʱ��������ⲻͬͼƬ��ʱ������Ӿ���˸
	EndBatchDraw();
	return ret;
}