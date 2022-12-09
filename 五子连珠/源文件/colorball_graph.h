#pragma once
/* 2053385 ������ */


/***************************************************************************
  �ļ����ƣ�colorball_graph.h
  ��    �ܣ�������Ϸ��ʵ��ͼ�λ����ܵĺ����������и������ܵĺ궨��
***************************************************************************/

#include<graphics.h>

// ͼƬλ�ö�λ 
#define ROW_0 77                            // ����ͼƬ��ʼ������
#define D_ROW 33                            // ����ͼƬ�м��
#define COL_0 8                             // ����ͼƬ��ʼ������
#define D_COL 33                            // ����ͼƬ�м��

// ���ú궨���ѭ��д��
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define	FOR(j,a,b) for(int j=(a);j<(b);j++)
#define FOR(k,a,b) for(int k=(a);k<(b);k++) 

// ���з�������ʱѰ����������ķ�����dx[] dy[]�����Ӧ
const int ROW = 3;                          // ��������
const int COL = 1;                          // ��������
const int LEFT_DIAGONAL = 4;                // �����ϵ����¶Խ�������
const int RIGHT_DIAGONAL = 5;               // �����ϵ����¶Խ�������

// �����ƶ�ʱ����仯�������飬dx[] dy[]����ʹ��
// 0 �����ƶ�
// 1 �����ƶ�
// 2 �����ƶ�
// 3 �����ƶ�
// 4 �����ƶ�
// 5 �������ƶ�
// 6 �������ƶ�
const int dx[] = { -1,1,0,0 ,1,1 };
const int dy[] = { 0,0,-1,1 ,1,-1 };


void homepage();                                                                 // չʾ��Ϸ��ʼ���� 
void graph_init();                                                               // չʾ��Ϸ���г�ʼ����
void draw_colorball(const int color, const int x, const int y);                  // չʾ����
void draw_cover(const int x, const int y);                                       // ��������
void draw_game_bar(const int best_scores, const int total_scores);               // չʾ��״̬��
void draw_temp_tips();                                                           // չʾ��״̬��                   
void draw_shining(const int color, const int x, const int y, ExMessage& MESSAGE);// չʾ������˸Ч��
