/* 2053385 高逸轩 */


/***************************************************************************
  文件名称：color_ball_function.cpp
  功    能：实现游戏内部功能
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
  函数名称：game
  功    能：game构造函数，对其中colorball数组进行初始化
  输入参数：
  返 回 值：
***************************************************************************/
game::game()
{
	total_scores = 0;                                                 // 本局总分置0
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{
			colorball[i][j].color = -1, colorball[i][j].mark[0] = false; // 记录无彩球，未访问 
			colorball[i][j].x = i, colorball[i][j].y = j;             // 记录x,y坐标
			colorball[i][j].son = NULL;                               // 记录无子节点
		}
}

/***************************************************************************
  函数名称：colorball_random_generation
  功    能：随机生成三颗珠子
  输入参数：
  返 回 值：
***************************************************************************/
void game::colorball_random_generation()
{
	srand((unsigned int)(time(0)));	                     // 设置随机数种子
	int counter = 0;                                     // 计数器
	while (counter - 3)                                  // 生成3个彩球
	{
		if (game_over_judge())break;                     // 若在生成过程中发现棋盘已满则结束
		int x = rand() % 9, y = rand() % 9;              // 记录随机生成的x，y坐标 
		if (colorball[x][y].color == -1)	             // 当前位置未生成过珠子
		{
			colorball[x][y].color = rand() % 7;          // 随机生成颜色
			counter++;                                   // 本次生成彩球数量+1
			draw_colorball(colorball[x][y].color, x, y); // 显示新生成的珠子
		}
	}
}

/***************************************************************************
  函数名称：game_over_judge
  功    能：判断游戏是否结束
  输入参数：
  返 回 值：0  游戏继续
			1  游戏中止
***************************************************************************/
bool game::game_over_judge()
{
	FOR(i, 0, 9)
		FOR(j, 0, 9)
			if (colorball[i][j].color == -1) return 0; // 有格子未生成珠子，游戏继续
	return 1;                                          // 全部格子生成珠子，游戏中止
}

/***************************************************************************
  函数名称：getxy
  功    能：读取当前光标位置并判断是否合法
  输入参数：short &x                 读取返回的x坐标
			short &y				 读取返回的y坐标
			const ExMessage &MESSAGE 消息变量
  返 回 值：true                     坐标位置合法
			false                    坐标位置非法
***************************************************************************/
bool getxy(short& x, short& y, const ExMessage& MESSAGE)
{
	x = MESSAGE.y, y = MESSAGE.x;                                                     // 注意行列与电脑像素坐标x,y顺序颠倒
	if (y >= COL_0 && y <= COL_0 + D_COL * 9 && x >= ROW_0 && x <= ROW_0 + D_ROW * 9) // 光标位置合法
	{
		y = (y - COL_0) / D_COL, x = (x - ROW_0) / D_ROW;                             // 计算得到起始对应格子坐标
		return true;                                                                  // 坐标合法
	}
	else
		return false;                                                                 // 坐标非法
}

/***************************************************************************
  函数名称：bfs
  功    能：判断起点是否可以移动到终点
  输入参数：const int start_x   起点横坐标
			const int start_y   起点纵坐标
			const int end_x     终点横坐标
			const int end_y     终点纵坐标
  返 回 值：true                可移动
			false               不可移动  
***************************************************************************/
bool game::bfs(const int start_x, const int start_y, const int end_x, const int end_y)
{
	if (start_x == end_x && start_y == end_y)  // 起点终点重合特判为失败
		return false;

	colorball[end_x][end_y].mark[0] = true;    // 标记终点已搜过，从终点向起点进行搜索，同时记录各个点子节点，可方便后续path_generation()函数从起点开始，生成移动路径动画
	queue<ball>Q;                              // 定义搜索所需队列
	Q.push(colorball[end_x][end_y]);           // 加入终点

	int now_x, now_y;                          // 记录新点坐标
	while (!Q.empty())                         // 若队列非空
	{
		ball TOP = Q.front();                  // 以TOP变量记录队列顶部元素
		Q.pop();                               // 弹出队列顶部元素
		FOR(i, 0, 4)                           // 上下左右共四个方向可行   
		{ 
			now_x = TOP.x + dx[i], now_y = TOP.y + dy[i];               // 记录新点坐标
			if (now_x == start_x && now_y == start_y)                   // 若新点为起点，则搜索结束，可移动
			{
				colorball[now_x][now_y].son = &colorball[TOP.x][TOP.y]; // 记录新点的子节点为TOP
				return true;                                            // 可移动
			}
			if (now_x < 0 || now_y < 0 || now_x >= 9 || now_y >= 9)     // 出界则不加入队列
				continue;
			if (colorball[now_x][now_y].mark[0] || colorball[now_x][now_y].color != -1) // 新点已经被标记过 or 此处有球则不加入队列
				continue;
			colorball[now_x][now_y].mark[0] = true;                     // 新点记录为已经搜索过
			colorball[now_x][now_y].son = &colorball[TOP.x][TOP.y];     // 记录新点的子节点为TOP
			Q.push(colorball[now_x][now_y]);                            // 新点加入队列
		}
	}
	return false;                                                       // 若整个队列搜索完仍不能到达起点，则不可移动  
}

/***************************************************************************
  函数名称：path_generation
  功    能：绘制从起点到终点的移动路径
  输入参数：const int start_x   起点横坐标
			const int start_y   起点纵坐标
  返 回 值：
***************************************************************************/
void game::path_genaration(const int start_x, const int start_y)
{
	ball now = colorball[start_x][start_y], next;                     // 用now变量记录目前访问的节点
	while (now.son != NULL)                                           // 若节点有子节点，则路径未生成结束
	{ 
		next = *(now.son);                                            // 用next变量记录now的子节点
		draw_move(now.x, now.y, next.x, next.y);                      // 将now处的球移至next处
		now = next;                                                   // 将next赋值给now，下一次循环的节点更替

	}
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		colorball[i][j].son = NULL, colorball[i][j].mark[0] = false;  // 生成路径后，将各节点的子节点和访问标记重置
}

/***************************************************************************
  函数名称：game_scores_calculate
  功    能：计算可消除彩球分数
  输入参数：const bool flag   
			默认为0，计算分数  
			输入为1，不计算分数
  返 回 值：true   有可消除彩球
            false  无可消除彩球
***************************************************************************/
bool game::game_scores_calculate(const bool flag = false)
{
	int counter = 0;                             // 记录可消除彩球个数
	counter += colorball_remove(ROW);            // 记录横向可消除
	counter += colorball_remove(COL);            // 记录纵向可消除
	counter += colorball_remove(LEFT_DIAGONAL);  // 记录左上到右下可消除
	counter += colorball_remove(RIGHT_DIAGONAL); // 记录右上到左下可消除

	if (!counter || flag)                        // 可消除彩球个数为0或自动生成不计分数
	{
		bool judge = false;                      // 记录为可消除
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)                         
			{
				if (colorball[i][j].mark[0] && !judge)     // 若发现有可消除彩球则消除
				{
					judge = true;
					draw_remove();
				}
				colorball[i][j].mark[0] = false;  // 访问标记重置 
				colorball[i][j].mark[ROW] = false;
				colorball[i][j].mark[COL] = false;
				colorball[i][j].mark[LEFT_DIAGONAL] = false;
				colorball[i][j].mark[RIGHT_DIAGONAL] = false;
			}
		}
		return false;
	}

	counter = draw_remove();                     // 记录去除重复后的可消除彩球个数
	total_scores += counter * 2;                 // 本局游戏分数增加，一个彩球2分
	best_scores = best_scores > total_scores ? best_scores : total_scores; // 最佳成绩=max(最佳成绩，本局分数)
	draw_game_bar(best_scores, total_scores);    // 更新上状态栏显示的分数
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{                                        // 访问标记重置
			colorball[i][j].mark[0] = false;
			colorball[i][j].mark[ROW] = false;
			colorball[i][j].mark[COL] = false;
			colorball[i][j].mark[LEFT_DIAGONAL] = false;
			colorball[i][j].mark[RIGHT_DIAGONAL] = false;
		}

	return true;                                // 存在可消除的彩球
}

/***************************************************************************
  函数名称：colorball_remove
  功    能：计算可消除彩球的个数
  输入参数：
  返 回 值：int ret    可消除彩球的个数 ( >= 5 )
***************************************************************************/
int game::colorball_remove(const int direction)
{
	int ret = 0, counter = 0;                                                  // ret为本次遍历可消除彩球总个数，counter记录与当前选中点在指定方向上颜色相同彩球的个数
	FOR(i, 0, 9)                                                              
	{
		FOR(j, 0, 9)
		{
			if (colorball[i][j].mark[direction] || colorball[i][j].color == -1) continue; // 已经遍历过 or 此处无彩球则不会进行消除
			colorball[i][j].mark[direction] = true;                                       // 记录此点已经遍历
			counter = 0;                                                       // 与此点颜色相同珠子数量置0
			FOR(k, 1, 5)                                                       // 在direction方向上寻找与选中点颜色相同的彩球
			{
				if (i + k * dx[direction] >= 9 || j + k * dy[direction] >= 9 || j + k * dy[direction] < 0) break; // 若出界，则不会进行消除
				if (colorball[i + k * dx[direction]][j + k * dy[direction]].color != colorball[i][j].color || colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction]) break; // 若有彩球与初始选定颜色不同或此处已经被搜过，则跳出循环，无法进行消除
				else
				{
					colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction] = true;               // 此处珠子标记为已经遍历到
					counter++;                                                 // 与选中点颜色相同彩球个数+1
				}
			}
			if (counter == 4)                                                  // 与选中点颜色相同彩球个数至少为4，此处可消除
			{
				FOR(k, 5, 9)
				{
					if (i + k * dx[direction] >= 9 || j + k * dy[direction] >= 9 || j + k * dy[direction] < 0) break;// 若出界，则不会进行消除
					if (colorball[i][j].color != colorball[i + k * dx[direction]][j + k * dy[direction]].color || colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction]) break; // 若有珠子与初始选定颜色不同或此处已经被搜过，则跳出循环
					else
					{
						colorball[i + k * dx[direction]][j + k * dy[direction]].mark[direction] = true;                     // 此处彩球标记为已经遍历到
						counter++;                                             // 与选中点颜色相同彩球个数+1，此处可消除
					}
				}
				ret += counter + 1;                                            // 本次遍历可消除彩球总个数增加
				FOR(k, 0, counter+1)
					colorball[i + k * dx[direction]][j + k * dy[direction]].mark[0] = true; // 记录为可消除
			}
		}
	}
	return ret;
}

/***************************************************************************
  函数名称：function
  功    能：进行一局游戏
  输入参数：
  返 回 值：
***************************************************************************/
void game::function()
{
	total_scores = 0;                         // 本局游戏得分置0
	FOR(i, 0, 9)
		FOR(j, 0, 9)
		{
			colorball[i][j].color = -1, colorball[i][j].mark[0] = false; // 记录无彩球，未访问 
			colorball[i][j].x = i, colorball[i][j].y = j;                // 记录x,y坐标
			colorball[i][j].son = NULL;                                  // 记录无子节点
		}

	ExMessage MESSAGE;		                  // 定义消息变量，用以接收鼠标或键盘消息
	short start_x, start_y, end_x, end_y;     // 读取起始点、终止点坐标
	draw_game_bar(best_scores, total_scores); // 打印状态栏
	colorball_random_generation();            // 随机生成三个彩球

	while (!game_over_judge())                // 若游戏未结束，则持续进行
 	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY);    // 获取一条鼠标或按键消息
		if (MESSAGE.message == WM_LBUTTONDOWN)      // 读取到左键按下           
		{
			if (getxy(start_x, start_y, MESSAGE))   // 读取起点坐标，若合法则继续进行
			{
				if (colorball[start_x][start_y].color != -1)                                    // 若起始点有生成的珠子，则继续进行
				{
					draw_shining(colorball[start_x][start_y].color, start_x, start_y, MESSAGE); // 在起始点生成闪烁效果并读取下一次鼠标左键单击操作
					if (getxy(end_x, end_y, MESSAGE))                                           // 读取终点坐标，若合法则继续进行
					{
						if (colorball[end_x][end_y].color == -1)                                // 若终止点无珠子，则继续进行
						{
							if (bfs(start_x, start_y, end_x, end_y))                            // 若起点可以到达终点，则继续进行
							{
								path_genaration(start_x, start_y);                              // 绘制从起点移动到终点的路径
								if (game_scores_calculate())                                    // 若成功消除则不生成新彩球
									draw_game_bar(best_scores, total_scores);                   // 更新分数状态栏
								else                                                            // 如果本次操作无法消除彩球，则需要生成新彩球
								{
									colorball_random_generation();                              // 生成新彩球
									game_scores_calculate(1);                                   // 若生成新彩球后可以消除，则不计算入分数
								}
							}
						}
					}
				}
			}
		}
	}
	draw_temp_tips();   // 一局游戏结束后进行提示
}

