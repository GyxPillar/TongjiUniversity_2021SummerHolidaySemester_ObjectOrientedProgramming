/* 2053385 ������ */


/***************************************************************************
  �ļ����ƣ�colorball_main.cpp
  ��    �ܣ�������
***************************************************************************/

#include<graphics.h>
#include<iostream>
#include"colorball_class.h"
#include"colorball_graph.h"

using namespace std;

int main()
{
	game GAME;           // ������Ϸ�ṹ��
	homepage();          // չʾ��Ϸ��ʼ����
	graph_init();        // չʾ��Ϸ���еĳ�ʼ����
	while (1)           
		GAME.function(); // ������Ϸ
	return 0;
}