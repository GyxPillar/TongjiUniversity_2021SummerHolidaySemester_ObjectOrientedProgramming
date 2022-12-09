/* 2053385 ������ */


/***************************************************************************
  �ļ����ƣ�color_ball_function.cpp
  ��    �ܣ�ʵ����Ϸ�ڲ�����
***************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<ctime>
#include"colorball_class.h"
#include"colorball_graph.h"

using namespace std;

/***************************************************************************
  �������ƣ�game
  ��    �ܣ�game���캯����������colorball������г�ʼ��
  ���������
  �� �� ֵ��
***************************************************************************/
game::game()
{
	total_scores = 0;                                                 // �����ܷ���0
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{
			colorball[i][j].color = -1, colorball[i][j].mark[0] = false; // ��¼�޲���δ���� 
			colorball[i][j].x = i, colorball[i][j].y = j;             // ��¼x,y����
			colorball[i][j].son = NULL;                               // ��¼���ӽڵ�
		}
}

/***************************************************************************
  �������ƣ�colorball_random_generation
  ��    �ܣ����������������
  ���������
  �� �� ֵ��
***************************************************************************/
void game::colorball_random_generation()
{
	srand((unsigned int)(time(0)));	                     // �������������
	int counter = 0;                                     // ������
	while (counter - 3)                                  // ����3������
	{
		if (game_over_judge())break;                     // �������ɹ����з����������������
		int x = rand() % 9, y = rand() % 9;              // ��¼������ɵ�x��y���� 
		if (colorball[x][y].color == -1)	             // ��ǰλ��δ���ɹ�����
		{
			colorball[x][y].color = rand() % 7;          // ���������ɫ
			counter++;                                   // �������ɲ�������+1
			draw_colorball(colorball[x][y].color, x, y); // ��ʾ�����ɵ�����
		}
	}
}

/***************************************************************************
  �������ƣ�game_over_judge
  ��    �ܣ��ж���Ϸ�Ƿ����
  ���������
  �� �� ֵ��0  ��Ϸ����
			1  ��Ϸ��ֹ
***************************************************************************/
bool game::game_over_judge()
{
	FOR(i, 0, 9)
		FOR(j, 0, 9)
			if (colorball[i][j].color == -1) return 0; // �и���δ�������ӣ���Ϸ����
	return 1;                                          // ȫ�������������ӣ���Ϸ��ֹ
}

/***************************************************************************
  �������ƣ�getxy
  ��    �ܣ���ȡ��ǰ���λ�ò��ж��Ƿ�Ϸ�
  ���������short &x                 ��ȡ���ص�x����
			short &y				 ��ȡ���ص�y����
			const ExMessage &MESSAGE ��Ϣ����
  �� �� ֵ��true                     ����λ�úϷ�
			false                    ����λ�÷Ƿ�
***************************************************************************/
bool getxy(short& x, short& y, const ExMessage& MESSAGE)
{
	x = MESSAGE.y, y = MESSAGE.x;                                                     // ע�������������������x,y˳��ߵ�
	if (y >= COL_0 && y <= COL_0 + D_COL * 9 && x >= ROW_0 && x <= ROW_0 + D_ROW * 9) // ���λ�úϷ�
	{
		y = (y - COL_0) / D_COL, x = (x - ROW_0) / D_ROW;                             // ����õ���ʼ��Ӧ��������
		return true;                                                                  // ����Ϸ�
	}
	else
		return false;                                                                 // ����Ƿ�
}

/***************************************************************************
  �������ƣ�bfs
  ��    �ܣ��ж�����Ƿ�����ƶ����յ�
  ���������const int start_x   ��������
			const int start_y   ���������
			const int end_x     �յ������
			const int end_y     �յ�������
  �� �� ֵ��true                ���ƶ�
			false               �����ƶ�  
***************************************************************************/
bool game::bfs(const int start_x, const int start_y, const int end_x, const int end_y)
{
	if (start_x == end_x && start_y == end_y)  // ����յ��غ�����Ϊʧ��
		return false;

	colorball[end_x][end_y].mark[0] = true;    // ����յ����ѹ������յ���������������ͬʱ��¼�������ӽڵ㣬�ɷ������path_generation()��������㿪ʼ�������ƶ�·������
	queue<ball>Q;                              // ���������������
	Q.push(colorball[end_x][end_y]);           // �����յ�

	int now_x, now_y;                          // ��¼�µ�����
	while (!Q.empty())                         // �����зǿ�
	{
		ball TOP = Q.front();                  // ��TOP������¼���ж���Ԫ��
		Q.pop();                               // �������ж���Ԫ��
		FOR(i, 0, 4)                           // �������ҹ��ĸ��������   
		{ 
			now_x = TOP.x + dx[i], now_y = TOP.y + dy[i];               // ��¼�µ�����
			if (now_x == start_x && now_y == start_y)                   // ���µ�Ϊ��㣬���������������ƶ�
			{
				colorball[now_x][now_y].son = &colorball[TOP.x][TOP.y]; // ��¼�µ���ӽڵ�ΪTOP
				return true;                                            // ���ƶ�
			}
			if (now_x < 0 || now_y < 0 || now_x >= 9 || now_y >= 9)     // �����򲻼������
				continue;
			if (colorball[now_x][now_y].mark[0] || colorball[now_x][now_y].color != -1) // �µ��Ѿ�����ǹ� or �˴������򲻼������
				continue;
			colorball[now_x][now_y].mark[0] = true;                     // �µ��¼Ϊ�Ѿ�������
			colorball[now_x][now_y].son = &colorball[TOP.x][TOP.y];     // ��¼�µ���ӽڵ�ΪTOP
			Q.push(colorball[now_x][now_y]);                            // �µ�������
		}
	}
	return false;                                                       // �����������������Բ��ܵ�����㣬�򲻿��ƶ�  
}

/***************************************************************************
  �������ƣ�path_generation
  ��    �ܣ����ƴ���㵽�յ���ƶ�·��
  ���������const int start_x   ��������
			const int start_y   ���������
  �� �� ֵ��
***************************************************************************/
void game::path_genaration(const int start_x, const int start_y)
{
	ball now = colorball[start_x][start_y], next;                     // ��now������¼Ŀǰ���ʵĽڵ�
	while (now.son != NULL)                                           // ���ڵ����ӽڵ㣬��·��δ���ɽ���
	{ 
		next = *(now.son);                                            // ��next������¼now���ӽڵ�
		draw_move(now.x, now.y, next.x, next.y);                      // ��now����������next��
		now = next;                                                   // ��next��ֵ��now����һ��ѭ���Ľڵ����

	}
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		colorball[i][j].son = NULL, colorball[i][j].mark[0] = false;  // ����·���󣬽����ڵ���ӽڵ�ͷ��ʱ������
}

/***************************************************************************
  �������ƣ�game_scores_calculate
  ��    �ܣ�����������������
  ���������const bool flag   
			Ĭ��Ϊ0���������  
			����Ϊ1�����������
  �� �� ֵ��true   �п���������
            false  �޿���������
***************************************************************************/
bool game::game_scores_calculate(const bool flag = false)
{
	int counter = 0;                             // ��¼�������������
	counter += colorball_remove(ROW);            // ��¼���������
	counter += colorball_remove(COL);            // ��¼���������
	counter += colorball_remove(LEFT_DIAGONAL);  // ��¼���ϵ����¿�����
	counter += colorball_remove(RIGHT_DIAGONAL); // ��¼���ϵ����¿�����

	if (!counter || flag)                        // �������������Ϊ0���Զ����ɲ��Ʒ���
	{
		bool judge = false;                      // ��¼Ϊ������
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)                         
			{
				if (colorball[i][j].mark[0] && !judge)     // �������п���������������
				{
					judge = true;
					draw_remove();
				}
				colorball[i][j].mark[0] = false;  // ���ʱ������ 
				colorball[i][j].mark[ROW] = false;
				colorball[i][j].mark[COL] = false;
				colorball[i][j].mark[LEFT_DIAGONAL] = false;
				colorball[i][j].mark[RIGHT_DIAGONAL] = false;
			}
		}
		return false;
	}

	counter = draw_remove();                     // ��¼ȥ���ظ���Ŀ������������
	total_scores += counter * 2;                 // ������Ϸ�������ӣ�һ������2��
	best_scores = best_scores > total_scores ? best_scores : total_scores; // ��ѳɼ�=max(��ѳɼ������ַ���)
	draw_game_bar(best_scores, total_scores);    // ������״̬����ʾ�ķ���
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{                                        // ���ʱ������
			colorball[i][j].mark[0] = false;
			colorball[i][j].mark[ROW] = false;
			colorball[i][j].mark[COL] = false;
			colorball[i][j].mark[LEFT_DIAGONAL] = false;
			colorball[i][j].mark[RIGHT_DIAGONAL] = false;
		}

	return true;                                // ���ڿ������Ĳ���
}

/***************************************************************************
  �������ƣ�colorball_remove
  ��    �ܣ��������������ĸ���
  ���������
  �� �� ֵ��int ret    ����������ĸ��� ( >= 5 )
***************************************************************************/
int game::colorball_remove(const int direction)
{
	int ret = 0, counter = 0;                                                  // retΪ���α��������������ܸ�����counter��¼�뵱ǰѡ�е���ָ����������ɫ��ͬ����ĸ���
	FOR(i, 0, 9)                                                              
	{
		FOR(j, 0, 9)
		{
			if (colorball[i][j].mark[direction] || colorball[i][j].color == -1) continue; // �Ѿ������� or �˴��޲����򲻻��������
			colorball[i][j].mark[direction] = true;                                       // ��¼�˵��Ѿ�����
			counter = 0;                                                       // ��˵���ɫ��ͬ����������0
			FOR(k, 1, 5)                                                       // ��direction������Ѱ����ѡ�е���ɫ��ͬ�Ĳ���
			{
				if (i + k * dx[direction] >= 9 || j + k * dy[direction] >= 9 || j + k * dy[direction] < 0) break; // �����磬�򲻻��������
				if (colorball[i + k * dx[direction]][j + k * dy[direction]].color != colorball[i][j].color || colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction]) break; // ���в������ʼѡ����ɫ��ͬ��˴��Ѿ����ѹ���������ѭ�����޷���������
				else
				{
					colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction] = true;               // �˴����ӱ��Ϊ�Ѿ�������
					counter++;                                                 // ��ѡ�е���ɫ��ͬ�������+1
				}
			}
			if (counter == 4)                                                  // ��ѡ�е���ɫ��ͬ�����������Ϊ4���˴�������
			{
				FOR(k, 5, 9)
				{
					if (i + k * dx[direction] >= 9 || j + k * dy[direction] >= 9 || j + k * dy[direction] < 0) break;// �����磬�򲻻��������
					if (colorball[i][j].color != colorball[i + k * dx[direction]][j + k * dy[direction]].color || colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction]) break; // �����������ʼѡ����ɫ��ͬ��˴��Ѿ����ѹ���������ѭ��
					else
					{
						colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction] = true;                     // �˴�������Ϊ�Ѿ�������
						counter++;                                             // ��ѡ�е���ɫ��ͬ�������+1���˴�������
					}
				}
				ret += counter + 1;                                            // ���α��������������ܸ�������
				FOR(k, 0, counter+1)
					colorball[i + k * dx[direction]][j + k * dy[direction]].mark[0] = true; // ��¼Ϊ������
			}
		}
	}
	return ret;
}

/***************************************************************************
  �������ƣ�function
  ��    �ܣ�����һ����Ϸ
  ���������
  �� �� ֵ��
***************************************************************************/
void game::function()
{
	total_scores = 0;                         // ������Ϸ�÷���0
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{
			colorball[i][j].color = -1, colorball[i][j].mark[0] = false; // ��¼�޲���δ���� 
			colorball[i][j].x = i, colorball[i][j].y = j;                // ��¼x,y����
			colorball[i][j].son = NULL;                                  // ��¼���ӽڵ�
		}

	ExMessage MESSAGE;		                  // ������Ϣ���������Խ������������Ϣ
	short start_x, start_y, end_x, end_y;     // ��ȡ��ʼ�㡢��ֹ������
	draw_game_bar(best_scores, total_scores); // ��ӡ״̬��
	colorball_random_generation();            // ���������������

	while (!game_over_judge())                // ����Ϸδ���������������
 	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY);    // ��ȡһ�����򰴼���Ϣ
		if (MESSAGE.message == WM_LBUTTONDOWN)      // ��ȡ���������           
		{
			if (getxy(start_x, start_y, MESSAGE))   // ��ȡ������꣬���Ϸ����������
			{
				if (colorball[start_x][start_y].color != -1)                                    // ����ʼ�������ɵ����ӣ����������
				{
					draw_shining(colorball[start_x][start_y].color, start_x, start_y, MESSAGE); // ����ʼ��������˸Ч������ȡ��һ����������������
					if (getxy(end_x, end_y, MESSAGE))                                           // ��ȡ�յ����꣬���Ϸ����������
					{
						if (colorball[end_x][end_y].color == -1)                                // ����ֹ�������ӣ����������
						{
							if (bfs(start_x, start_y, end_x, end_y))                            // �������Ե����յ㣬���������
							{
								path_genaration(start_x, start_y);                              // ���ƴ�����ƶ����յ��·��
								if (game_scores_calculate())                                    // ���ɹ������������²���
									draw_game_bar(best_scores, total_scores);                   // ���·���״̬��
								else                                                            // ������β����޷�������������Ҫ�����²���
								{
									colorball_random_generation();                              // �����²���
									game_scores_calculate(1);                                   // �������²��������������򲻼��������
								}
							}
						}
					}
				}
			}
		}
	}
	draw_temp_tips();   // һ����Ϸ�����������ʾ
}

