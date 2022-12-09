#pragma once
/* 2053385 高逸轩 */


/***************************************************************************
  文件名称：colorball_class.h
  功    能：实现游戏类与彩球结构体
***************************************************************************/

// 球结构体，用以记录每个球的信息
struct ball
{
	int color = -1;           // 记录颜色（0-6）,-1为没有生成珠子
	bool mark[6] = { 0,0,0,0,0,0 };     // 记录遍历或搜索时是否被标记
	ball* son = NULL;         // 记录搜索时子节点
	int x, y;                 // 记录x，y坐标
};

// 游戏结构体，用以实现游戏的各个部分功能
class game
{
public:
	game();                                                                                      // 构造函数，进行初始优化
	~game() {};                                                                                  // 析构函数

	// 实现于colorball_graph.cpp
	void draw_move(const int start_x, const int start_y, const int end_x, const int end_y);      // 移动一个小球
	int draw_remove();                                                                           // 消除可以得分的小球

	// 实现于colorball_function.cpp
	void colorball_random_generation();                                                          // 随机生成三个彩球	
	bool bfs(const int start_x, const int start_y, const int end_x, const int end_y);            // 搜索起点是否可达终点
	void path_genaration(const int start_x,const int start_y);                                   // 生成最短移动路径并展示
	bool game_scores_calculate(const bool flag );                                                // 计算分数
	int  colorball_remove(const int direction);                                                  // 计算可得分的小球
	bool game_over_judge();                                                                      // 检验一局游戏是否结束
	void function();                                                                             // 游戏运行

private:
	ball colorball[9][9];                                                                        // 记录9*9棋盘
	int best_scores = 0;                                                                         // 记录最佳成绩
	int total_scores = 0;                                                                        // 记录本局成绩
};
