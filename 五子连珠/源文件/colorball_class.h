#pragma once
/* 2053385 ������ */


/***************************************************************************
  �ļ����ƣ�colorball_class.h
  ��    �ܣ�ʵ����Ϸ�������ṹ��
***************************************************************************/

// ��ṹ�壬���Լ�¼ÿ�������Ϣ
struct ball
{
	int color = -1;           // ��¼��ɫ��0-6��,-1Ϊû����������
	bool mark[6] = { 0,0,0,0,0,0 };     // ��¼����������ʱ�Ƿ񱻱��
	ball* son = NULL;         // ��¼����ʱ�ӽڵ�
	int x, y;                 // ��¼x��y����
};

// ��Ϸ�ṹ�壬����ʵ����Ϸ�ĸ������ֹ���
class game
{
public:
	game();                                                                                      // ���캯�������г�ʼ�Ż�
	~game() {};                                                                                  // ��������

	// ʵ����colorball_graph.cpp
	void draw_move(const int start_x, const int start_y, const int end_x, const int end_y);      // �ƶ�һ��С��
	int draw_remove();                                                                           // �������Ե÷ֵ�С��

	// ʵ����colorball_function.cpp
	void colorball_random_generation();                                                          // ���������������	
	bool bfs(const int start_x, const int start_y, const int end_x, const int end_y);            // ��������Ƿ�ɴ��յ�
	void path_genaration(const int start_x,const int start_y);                                   // ��������ƶ�·����չʾ
	bool game_scores_calculate(const bool flag );                                                // �������
	int  colorball_remove(const int direction);                                                  // ����ɵ÷ֵ�С��
	bool game_over_judge();                                                                      // ����һ����Ϸ�Ƿ����
	void function();                                                                             // ��Ϸ����

private:
	ball colorball[9][9];                                                                        // ��¼9*9����
	int best_scores = 0;                                                                         // ��¼��ѳɼ�
	int total_scores = 0;                                                                        // ��¼���ֳɼ�
};
