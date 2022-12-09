/***************************************************************************
*
	文件名:fraction_menu.cpp
	功能  :在进行分数类功能测试时，展示菜单并控制测试模式
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

/*菜单供模式选择*/
bool menu()
{
	cout << "测试共两个模式:" << endl;
	cout << "1.无需输入，测试数据由程序本身提供，输出数据于控制台窗口和文件." << endl;
	cout << "2.模式二需要用户选择测试功能、输入测试数据，输出数据于控制台窗口和文件." << endl;
	cout << "[请选择模式]:";

	/*输入菜单模式，已进行输入异常处理*/
	while (1)
	{
		char ch = _getch();
		if (ch != '1' && ch != '2')
			continue;	
		cout << ch << endl << endl;
		return ch - '1';
	}
}