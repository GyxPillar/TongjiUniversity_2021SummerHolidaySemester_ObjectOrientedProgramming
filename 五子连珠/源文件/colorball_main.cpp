/* 2053385 高逸轩 */


/***************************************************************************
  文件名称：colorball_main.cpp
  功    能：主函数
***************************************************************************/

#include<graphics.h>
#include<iostream>
#include"colorball_class.h"
#include"colorball_graph.h"

using namespace std;

int main()
{
	game GAME;           // 定义游戏结构体
	homepage();          // 展示游戏开始界面
	graph_init();        // 展示游戏进行的初始界面
	while (1)           
		GAME.function(); // 进行游戏
	return 0;
}