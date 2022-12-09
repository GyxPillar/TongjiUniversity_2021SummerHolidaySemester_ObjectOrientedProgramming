/* 2053385 高逸轩 */


/***************************************************************************
  文件名称：color_ball_graph.cpp
  功    能：实现游戏可视图形化
***************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<iostream>
#include<cstring>
#include"colorball_class.h"
#include"colorball_graph.h"

using namespace std;

IMAGE game_bar;   // 上状态栏图       
IMAGE board_bg;   // 游戏进行背景图
IMAGE _chess[7];  // 彩球图片
IMAGE shining[13];// 展示棋子闪烁的13帧图片
IMAGE cover;      // 用以消除的遮盖图片

RECT BAR_FRONT = { 70,31,120,47 };               // 上前状态栏矩形
RECT BAR_BEHIND = { 252,33,292,49 };             // 上后状态栏矩形
RECT BAR_DOWN = { 40,394,55,450 };               // 下状态栏矩形
RECT START_COMMAND = { 58,90,58 + 194,90 + 72 }; // 开始键矩形

/***************************************************************************
  函数名称：homepage
  功    能：展示游戏开始界面
  输入参数：
  返 回 值：
***************************************************************************/
void homepage()
{
	initgraph(315, 358 + 65);                             // 生成窗口

	BeginBatchDraw();                                     // 暂停图片在窗口的输出，后续从缓冲区进行批量输出，避免不同图片错时输出的视觉闪烁

	IMAGE homepage_bg;                                    // 开始界面背景图
	loadimage(&homepage_bg, _T("homepage_bg.png"));       // 载入开始界面背景图
	putimage(0, 0, &homepage_bg);                         // 展示开始界面背景图

	IMAGE tongji1, tongji2;                               // 开始界面校徽图
	loadimage(&tongji1, _T("tongji1.png"));               // 载入开始界面校徽图(为实现透明背景，采用黑底彩图1与白底黑图2，后续采取图片对背景的位运算形式输出)
	loadimage(&tongji2, _T("tongji2.png"));
	putimage(84, 220, &tongji2,SRCAND);                   // 白底黑图2和背景 与运算and形式 输出
	putimage(84, 220, &tongji1,SRCPAINT);                 // 黑底彩图1和背景 或运算 or形式 输出

	IMAGE start_command1, start_command2;                 // 开始界面按键图 
	loadimage(&start_command1, _T("start_command1.png")); // 载入开始界面按键图(为实现透明背景，采用黑底彩图1与白底黑图2，后续采取图片对背景的位运算形式输出)
	loadimage(&start_command2, _T("start_command2.png"));
	putimage(58, 90, &start_command2, SRCAND);            // 白底黑图2和背景 与运算and形式 输出
	putimage(58, 90, &start_command1, SRCPAINT);	      // 黑底彩图1和背景 或运算 or形式 输出
	
	FlushBatchDraw();                                     // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
	EndBatchDraw();                                       // 结束BeginBatchDraw()函数

	ExMessage MESSAGE;                                    // 定义消息变量，用以接受鼠标信息
	while (1)
	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY);          // 读取鼠标或按键信息
		if (MESSAGE.message == WM_LBUTTONDOWN)            // 若读取到左键按下
		{
			if (MESSAGE.x <= 58 || MESSAGE.x >= 58 + 194 || MESSAGE.y <= 90 || MESSAGE.y >= 90 + 72) 
				continue;                                 // 若光标不在开始键范围内，重新读取鼠标信息
			break;                                        // 否则判断为用户单击开始键盘，游戏开始
		}
	}
}

/***************************************************************************
  函数名称：graph_init
  功    能：进入游戏后打印初始地图
  输入参数：					
  返 回 值：
***************************************************************************/
void graph_init()
{
	setbkmode(TRANSPARENT);                         // 文字填充背景设为透明
	LOGFONT f;                                      // 定义字体变量
	gettextstyle(&f);						        // 获取当前字体设置
	f.lfHeight = 21;						        // 设置字体高度为 21
	_tcscpy(f.lfFaceName, _T("Calibri"));	        // 设置字体
	f.lfQuality = ANTIALIASED_QUALITY;		        // 设置输出效果为抗锯齿  
	settextstyle(&f);						        // 设置字体样式

	loadimage(&game_bar, _T("game_bar.png"));       // 载入上状态栏图
	putimage(0, 0, &game_bar);                      // 输出上状态栏图

	loadimage(&board_bg, _T("board_bg.png"));       // 载入游戏背景图
	putimage(0, 65, &board_bg);                     // 输出游戏背景图

	loadimage(&_chess[0], _T("chess0.png"));        // 载入0-6七色彩球图
	loadimage(&_chess[1], _T("chess1.png"));
	loadimage(&_chess[2], _T("chess2.png"));
	loadimage(&_chess[3], _T("chess3.png"));
	loadimage(&_chess[4], _T("chess4.png"));
	loadimage(&_chess[5], _T("chess5.png"));
	loadimage(&_chess[6], _T("chess6.png"));

	loadimage(&shining[0], _T("shining (0).png"));  // 载入13帧闪烁图
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

	loadimage(&cover, _T("cover.png"));             // 载入遮盖图
}

/***************************************************************************
  函数名称：draw_colorball
  功    能：打印小球
  输入参数：const int color   小球颜色
			const int x       横坐标
			const int y       纵坐标
  返 回 值：
***************************************************************************/ 
void draw_colorball(const int color, const int x, const int y)
{
	putimage(COL_0 + y * D_COL, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT); // SRCPAINT 目标图像 = 目标图像 OR 源图像 对图片实行或运算，实现透明
}

/***************************************************************************
  函数名称：draw_cover
  功    能：消除小球
  输入参数：const int x       横坐标
			const int y       纵坐标
  返 回 值：
***************************************************************************/
void draw_cover(const int x, const int y)
{
	putimage(COL_0 + y * D_ROW + 4, ROW_0 + x * D_ROW + 4, &cover);
}

/***************************************************************************
  函数名称：draw_game_bar
  功    能：打印上状态栏信息
  输入参数：const int best_scores  最佳成绩  
			const int total_scores 当前成绩
  返 回 值：
***************************************************************************/
void draw_game_bar(const int best_scores, const int total_scores)
{
	setbkcolor(RGB(132, 44, 23));          // 设置背景颜色-前状态栏
	clearrectangle(70, 31, 120, 47);       // 清除前状态栏
	setbkcolor(RGB(127, 47, 21));          // 设置背景颜色-前状态栏
	clearrectangle(252, 33, 292, 49);      // 清除后状态栏	

	TCHAR BEST_SCORES[10],TOTAL_SCORES[10];// 项目字符集 TCHAR
	_stprintf_s(BEST_SCORES, _T("%d"), best_scores), _stprintf_s(TOTAL_SCORES, _T("%d"), total_scores);// 将得分从int型转换为项目字符集TCHAR型

	drawtext(BEST_SCORES, &BAR_FRONT, DT_RIGHT);   // 打印前状态栏
	drawtext(TOTAL_SCORES, &BAR_BEHIND, DT_RIGHT); // 打印后状态栏
}

/***************************************************************************
  函数名称：draw_temp_tips
  功    能：打印下状态栏信息并提示进入下一局游戏
  输入参数：
  返 回 值：
***************************************************************************/
void draw_temp_tips()
{
	LOGFONT f;                                                   // 定义字体
	gettextstyle(&f);					     	                 // 获取当前字体设置
	f.lfHeight = 15;						                     // 设置字体高度为 12
	settextstyle(&f);					                         // 设置字体样式
	outtextxy(40, 394, L"本局游戏结束,单击任意处继续或直接退出");// 输出本局游戏结束与进入下一局提示

	ExMessage MESSAGE;                           // 定义消息变量，用以接受鼠标信息 
	while (1)
	{
		MESSAGE = getmessage(EM_MOUSE | EM_KEY); // 读取鼠标与按键信息
		if (MESSAGE.message == WM_LBUTTONDOWN)   // 若读取到鼠标左键按下，进入下一局游戏
			break;
	}

	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 21;						// 设置字体高度为 21
	settextstyle(&f);						// 设置字体样式（恢复上状态栏字体）

	putimage(0, 65, &board_bg);             // 打印游戏进行背景图（清除棋盘）
}

/***************************************************************************
  函数名称：draw_shining
  功    能：在珠子被选中情况下展示闪烁效果，并读取下一次单机左键后的鼠标信息
  输入参数：const int color    小球颜色
			const int x        横坐标
			const int y        纵坐标
			ExMessage &MESSAGE 信息变量
  返 回 值：
***************************************************************************/
void draw_shining(const int color, const int x, const int y,ExMessage &MESSAGE)
{
	while (1)
	{
		FOR(i, 0, 13)   // 共13帧闪烁图                                  
		{
			putimage(COL_0 + y * D_ROW + 3,ROW_0 + x * D_ROW + 3, &shining[i], SRCPAINT);        // SRCPAINT 目标图像 = 目标图像 OR 源图像 对图片实行或运算，实现透明
			FOR(j, 0, 3)                                                                         // 在闪烁时实时读取鼠标信息，每一帧图片停留3ms
			{
				if (peekmessage(&MESSAGE, EM_MOUSE | EM_KEY, true))                              // 实时读取鼠标按键信息
				{
					if (MESSAGE.message == WM_LBUTTONDOWN)                                       // 若读取到左键按下 
					{
						BeginBatchDraw();                                                        // 暂停图片在窗口的输出，后续从缓冲区进行批量输出，避免不同图片错时输出的视觉闪烁
						putimage(COL_0 + y * D_ROW + 3, ROW_0 + x * D_ROW + 3, &cover);          // 遮盖闪烁图
						putimage(COL_0 + y * D_ROW, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT);// 恢复原彩球图
						FlushBatchDraw();                                                        // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
						EndBatchDraw();                                                          // 结束BeginBatchDraw()函数
						return;                                                                  // 停止闪烁，进行下一步操作
					}
				}
				Sleep(1);                                                                        // 停止1ms,每一帧图大约停留3ms
			}
			BeginBatchDraw();                                                                    // 暂停图片在窗口的输出，后续从缓冲区进行批量输出，避免不同图片错时输出的视觉闪烁
			putimage(COL_0 + y * D_ROW + 4, ROW_0 + x * D_ROW + 4, &cover);                      // 遮盖闪烁图
			putimage(COL_0 + y * D_ROW, ROW_0 + x * D_ROW, &_chess[color], SRCPAINT);            // 恢复原彩球图，同时对图片or运算使背景透明
			FlushBatchDraw();                                                                    // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
			EndBatchDraw();                                                                      // 结束BeginBatchDraw()函数
		}
	}
}

/***************************************************************************
  函数名称：draw_move
  功    能：展示彩球移动动画
  输入参数：const int start_x  起点横坐标
			const int start_y  起点纵坐标
			const int end_x    终点横坐标
			const int end_y    终点纵坐标
  返 回 值：
***************************************************************************/
void game::draw_move(const int start_x, const int start_y, const int end_x, const int end_y)
{
	BeginBatchDraw();                                                                                            // 暂停图片在窗口的输出，后续从缓冲区进行批量输出，避免不同图片错时输出的视觉闪烁
	putimage(COL_0 + start_y * D_ROW + 4, ROW_0 + start_x * D_ROW + 4, &cover);                                  // 消除起点彩球
	putimage(COL_0 + end_y * D_ROW, ROW_0 + end_x * D_ROW, &_chess[colorball[start_x][start_y].color], SRCPAINT);// 在终点展示彩球，同时对图片or运算使背景透明
	FlushBatchDraw();                                                                                            // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
	EndBatchDraw();                                                                                              // 结束BeginBatchDraw()函数
	Sleep(50);                                                                                                   // 停止50ms
	colorball[end_x][end_y].color = colorball[start_x][start_y].color;                                           // 终点彩球记录为起点颜色
	colorball[start_x][start_y].color = -1;                                                                      // 起点记录为无彩球
}


/***************************************************************************
  函数名称：draw_remove
  功    能：展示彩球因得分被消除移动动画
  输入参数：
  返 回 值：可消除的彩球总数目（去除重复计算的彩球）
***************************************************************************/
int game::draw_remove()
{
	int ret = 0;
	FOR(k, 0, 13)     // 共13帧闪烁图 
	{
		BeginBatchDraw();
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)
			{
				if (colorball[i][j].mark[0])
					putimage(COL_0 + j * D_ROW + 3, ROW_0 + i * D_ROW + 3, &shining[i], SRCPAINT);        // SRCPAINT 目标图像 = 目标图像 OR 源图像 对图片实行或运算，实现透明
			}
		}
		FlushBatchDraw();                                                                                            // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
		EndBatchDraw();
		BeginBatchDraw();
		FOR(i, 0, 9)
		{
			FOR(j, 0, 9)
			{
				if (colorball[i][j].mark[0])
				{
					putimage(COL_0 + j * D_ROW + 4, ROW_0 + i * D_ROW + 4, &cover);                                      // 遮盖闪烁图
					putimage(COL_0 + j * D_ROW, ROW_0 + i * D_ROW, &_chess[colorball[i][j].color], SRCPAINT);            // 恢复原彩球图，同时对图片or运算使背景透明
				}
			}
		}		
		Sleep(20);
		FlushBatchDraw();                                                                                            // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
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
				putimage(COL_0 + j * D_ROW + 4, ROW_0 + i * D_ROW + 4, &cover);                      // 遮盖闪烁图
				colorball[i][j].color = -1;
				ret++;
			}
		}
	}
	FlushBatchDraw();                                                                                            // 将暂存在缓存区的图片批量同时输出，避免不同图片错时输出的视觉闪烁
	EndBatchDraw();
	return ret;
}