/***************************************************************************
*
	�ļ���:fraction_menu.cpp
	����  :�ڽ��з����๦�ܲ���ʱ��չʾ�˵������Ʋ���ģʽ
*
****************************************************************************/

#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<conio.h>
#include"fraction.h"

using namespace std;

/*�˵���ģʽѡ��*/
bool menu()
{
	cout << "���Թ�����ģʽ:" << endl;
	cout << "1.�������룬���������ɳ������ṩ����������ڿ���̨���ں��ļ�." << endl;
	cout << "2.ģʽ����Ҫ�û�ѡ����Թ��ܡ�����������ݣ���������ڿ���̨���ں��ļ�." << endl;
	cout << "[��ѡ��ģʽ]:";

	/*����˵�ģʽ���ѽ��������쳣����*/
	while (1)
	{
		char ch = _getch();
		if (ch != '1' && ch != '2')
			continue;	
		cout << ch << endl << endl;
		return ch - '1';
	}
}