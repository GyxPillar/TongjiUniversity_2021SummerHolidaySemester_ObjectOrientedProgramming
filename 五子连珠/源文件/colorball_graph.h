#pragma once
/* 2053385 高逸轩 */


/***************************************************************************
  文件名称：colorball_graph.h
  功    能：声明游戏中实现图形化功能的函数，并进行辅助功能的宏定义
***************************************************************************/

#include<graphics.h>

// 图片位置定位 
#define ROW_0 77                            // 彩球图片起始横坐标
#define D_ROW 33                            // 彩球图片行间隔
#define COL_0 8                             // 彩球图片起始纵坐标
#define D_COL 33                            // 彩球图片列间隔

// 采用宏定义简化循环写法
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define	FOR(j,a,b) for(int j=(a);j<(b);j++)
#define FOR(k,a,b) for(int k=(a);k<(b);k++) 

// 进行分数计算时寻找五子连珠的方向，与dx[] dy[]数组对应
const int ROW = 3;                          // 横向消除
const int COL = 1;                          // 纵向消除
const int LEFT_DIAGONAL = 4;                // 从左上到右下对角线消除
const int RIGHT_DIAGONAL = 5;               // 从右上到左下对角线消除

// 彩球移动时坐标变化辅助数组，dx[] dy[]搭配使用
// 0 向上移动
// 1 向下移动
// 2 向左移动
// 3 向左移动
// 4 向右移动
// 5 向右下移动
// 6 向左下移动
const int dx[] = { -1,1,0,0 ,1,1 };
const int dy[] = { 0,0,-1,1 ,1,-1 };


void homepage();                                                                 // 展示游戏开始界面 
void graph_init();                                                               // 展示游戏进行初始界面
void draw_colorball(const int color, const int x, const int y);                  // 展示彩球
void draw_cover(const int x, const int y);                                       // 消除彩球
void draw_game_bar(const int best_scores, const int total_scores);               // 展示上状态栏
void draw_temp_tips();                                                           // 展示下状态栏                   
void draw_shining(const int color, const int x, const int y, ExMessage& MESSAGE);// 展示彩球闪烁效果
