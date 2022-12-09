/***************************************************************************
*
	文件名:fraction_test_mode_1.cpp
	功能  :实现分数类功能的测试1模式
*
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<conio.h>
#include<fstream>
#include"fraction.h"

using namespace std;

/*读取回车键*/
void wait_enter()
{
	cout << "请按回车键继续" << endl;
	while (_getch() != 13)
		;
	cout << endl;
}

void test_mode_1()
{
	/* 模式一：测试数据四类：①正数 ②负数 ③ 0 ④非最简分数（分子分母不互质） */
	cout << "模式一测试 (此部分内容输出于控制台和文件)" << endl << endl;

	fraction f1 = "1/10";
	fraction f2 = "-2/7";
	fraction f3 = "0/3";//避免输入0/1作为0
	fraction f4 = "2/6";

	cout << "一、单目运算测试" << endl << endl;

	cout << "相反数Inverse测试:" << endl;
	cout << "f1 = 1/10 , want : f1.Inverse() = -1/10 , out : f1.Inverse() = " << f1.Inverse() << endl;
	cout << "f2 = -2/7 , want : f2.Inverse() =   2/7 , out : f2.Inverse() = " << f2.Inverse() << endl;
	cout << "f3 =  0/3 , want : f3.Inverse() =   0/3 , out : f3.Inverse() = " << f3.Inverse() << endl;
	cout << "f4 =  2/6 , want : f4.Inverse() =  -6/2 , out : f4.Inverse() = " << f4.Inverse() << endl << endl;
	wait_enter();

	cout << "求倒数Reciprocal测试:" << endl;
	cout << "f1 = 1/10 , want : f1.Reciprocal() =      10/1 , out : f1.Reciprocal() = " << f1.Reciprocal() << endl;
	cout << "f2 = -2/7 , want : f2.Reciprocal() =      -7/2 , out : f2.Reciprocal() = " << f2.Reciprocal() << endl;
	cout << "f3 =  0/3 , want : f3.Reciprocal() = ERROR(0/1), out : f3.Reciprocal() = " << f3.Reciprocal() << endl;
	cout << "f4 =  2/6 , want : f4.Reciprocal() =       6/2 , out : f4.Reciprocal() = " << f4.Reciprocal() << endl << endl;
	wait_enter();

	cout << "求约分Reduction测试:" << endl;
	cout << "f1 = 1/10 , want : f1.Reduction() = 1/10 , out : f1.Reduction() = " << f1.Reduction() << endl;
	cout << "f2 = -2/7 , want : f2.Reduction() = -2/7 , out : f2.Reduction() = " << f2.Reduction() << endl;
	cout << "f3 =  0/3 , want : f3.Reduction() =  0/3 , out : f3.Reduction() = " << f3.Reduction() << endl;
	cout << "f4 =  2/6 , want : f4.Reduction() =  1/3 , out : f4.Reduction() = " << f4.Reduction() << endl << endl;
	wait_enter();

	cout << "DtoF小数转分数测试:" << endl;
	fraction ff1 = 0.1, ff2 = -0.5, ff3 = 0.0;//本部分测试构造函数，需要重新定义对象
	cout << "want : ff1 = 1/10 , out : ff1 = " << ff1 << endl;
	cout << "want : ff2 = -1/2 , out : ff2 = " << ff2 << endl;
	cout << "want : ff3 =  0/2 , out : ff3 = " << ff3 << endl << endl;//见Tips④
	wait_enter();

	cout << "StoF字符串转分数测试:" << endl;
	fraction ff4 = "1/10", ff5 = "-1/2", ff6 = "0/3";//本部分测试构造函数，需要重新定义对象
	cout << "want : ff4 = 1/10 , out : ff4 = " << ff4 << endl;
	cout << "want : ff5 = -1/2 , out : ff5 = " << ff5 << endl;
	cout << "want : ff6 =  0/3 , out : ff6 = " << ff6 << endl << endl;//见Tips③
	wait_enter();

	cout << "二、双目运算测试" << endl << endl;

	cout << "运算符 + 测试:" << endl;
	cout << "want : f1 + f2 = -13/70 ,out : f1 + f2 = " << f1 + f2 << endl;
	cout << "want : f1 + f3 =   1/10 ,out : f1 + f3 = " << f1 + f3 << endl;
	cout << "want : f1 + f4 =  13/30 ,out : f1 + f4 = " << f1 + f4 << endl << endl;
	wait_enter();

	cout << "运算符 - 测试:" << endl;
	cout << "want : f1 - f2 = 27/70 ,out : f1 - f2 = " << f1 - f2 << endl;
	cout << "want : f1 - f3 =  1/10 ,out : f1 - f3 = " << f1 - f3 << endl;
	cout << "want : f1 - f4 = -7/30 ,out : f1 - f4 = " << f1 - f4 << endl << endl;
	wait_enter();

	cout << "运算符 * 测试:" << endl;
	cout << "want : f1 * f2 = -1/35 ,out : f1 * f2 = " << f1 * f2 << endl;
	cout << "want : f1 * f3 =  0/2  ,out : f1 * f3 = " << f1 * f3 << endl;
	cout << "want : f1 * f4 =  1/30 ,out : f1 * f4 = " << f1 * f4 << endl << endl;
	wait_enter();

	cout << "运算符 / 测试:" << endl;
	cout << "want : f1 / f2 = -7/20 ,out : f1 / f2 = " << f1 / f2 << endl;
	cout << "want : f1 / f3 = ERROR ,out : f1 / f3 = " << f1 / f3 << endl;
	cout << "want : f1 / f4 =  3/10 ,out : f1 / f4 = " << f1 / f4 << endl << endl;
	wait_enter();

	cout << "关系运算符 > 测试" << endl;
	cout << "want : f1 > f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 > f2) << endl;
	cout << "want : f1 > f4 = false ,out : " << setiosflags(ios::boolalpha) << (f1 > f4) << endl << endl;
	wait_enter();

	cout << "关系运算符 < 测试" << endl;
	cout << "want : f1 < f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 < f2) << endl;
	cout << "want : f1 < f4 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 < f4) << endl << endl;
	wait_enter();

	cout << "关系运算符 >= 测试" << endl;
	cout << "want : f1 >= f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 >= f2) << endl;
	cout << "want : f1 >= f4 = false ,out : " << setiosflags(ios::boolalpha) << (f1 >= f4) << endl << endl;
	wait_enter();

	cout << "关系运算符 <= 测试" << endl;
	cout << "want : f1 <= f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 <= f2) << endl;
	cout << "want : f1 <= f4 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 <= f4) << endl << endl;
	wait_enter();

	cout << "关系运算符 != 测试" << endl;
	fraction ff7 = "1/10";
	cout << "want : f1 != f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 != f2) << endl;
	cout << "want : f1 != ff7= false ,out : " << setiosflags(ios::boolalpha) << (f1 != ff7) << endl << endl;
	wait_enter();

	cout << "关系运算符 == 测试" << endl;
	cout << "want : f1 == f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 == f2) << endl;
	cout << "want : f1 == ff7 = true ,out : " << setiosflags(ios::boolalpha) << (f1 == ff7) << endl << endl;
	wait_enter();

	cout << "输出运算符测试已在上述程序中完成." << endl << endl;
	wait_enter();

	/*输出到文件*/
	ofstream fout;  //fout为变量名
	fout.open("test_mode_1.txt", ios::out);  //打开文件
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	fout << "模式一测试 (此部分内容输出于控制台和文件)" << endl << endl;

	fout << "一、单目运算测试" << endl << endl;

	fout << "相反数Inverse测试:" << endl;
	fout << "f1 = 1/10 , want : f1.Inverse() = -1/10 , out : f1.Inverse() = " << f1.Inverse() << endl;
	fout << "f2 = -2/7 , want : f2.Inverse() =   2/7 , out : f2.Inverse() = " << f2.Inverse() << endl;
	fout << "f3 =  0/3 , want : f3.Inverse() =   0/3 , out : f3.Inverse() = " << f3.Inverse() << endl;
	fout << "f4 =  2/6 , want : f4.Inverse() =  -6/2 , out : f4.Inverse() = " << f4.Inverse() << endl << endl;

	fout << "求倒数Reciprocal测试:" << endl;
	fout << "f1 = 1/10 , want : f1.Reciprocal() =      10/1 , out : f1.Reciprocal() = " << f1.Reciprocal() << endl;
	fout << "f2 = -2/7 , want : f2.Reciprocal() =      -7/2 , out : f2.Reciprocal() = " << f2.Reciprocal() << endl;
	fout << "f3 =  0/3 , want : f3.Reciprocal() = ERROR(0/1), out : f3.Reciprocal() = " << f3.Reciprocal() << endl;
	fout << "f4 =  2/6 , want : f4.Reciprocal() =       6/2 , out : f4.Reciprocal() = " << f4.Reciprocal() << endl << endl;

	fout << "求约分Reduction测试:" << endl;
	fout << "f1 = 1/10 , want : f1.Reduction() = 1/10 , out : f1.Reduction() = " << f1.Reduction() << endl;
	fout << "f2 = -2/7 , want : f2.Reduction() = -2/7 , out : f2.Reduction() = " << f2.Reduction() << endl;
	fout << "f3 =  0/3 , want : f3.Reduction() =  0/3 , out : f3.Reduction() = " << f3.Reduction() << endl;
	fout << "f4 =  2/6 , want : f4.Reduction() =  1/3 , out : f4.Reduction() = " << f4.Reduction() << endl << endl;

	fout << "DtoF小数转分数测试:" << endl;
	fout << "want : ff1 = 1/10 , out : ff1 = " << ff1 << endl;
	fout << "want : ff2 = -1/2 , out : ff2 = " << ff2 << endl;
	fout << "want : ff3 =  0/2 , out : ff3 = " << ff3 << endl << endl;//见Tips④

	fout << "StoF字符串转分数测试:" << endl;
	fout << "want : ff4 = 1/10 , out : ff4 = " << ff4 << endl;
	fout << "want : ff5 = -1/2 , out : ff5 = " << ff5 << endl;
	fout << "want : ff6 =  0/3 , out : ff6 = " << ff6 << endl << endl;//见Tips③

	fout << "二、双目运算测试" << endl << endl;

	fout << "运算符 + 测试:" << endl;
	fout << "want : f1 + f2 = -13/70 ,out : f1 + f2 = " << f1 + f2 << endl;
	fout << "want : f1 + f3 =   1/10 ,out : f1 + f3 = " << f1 + f3 << endl;
	fout << "want : f1 + f4 =  13/30 ,out : f1 + f4 = " << f1 + f4 << endl << endl;

	fout << "运算符 - 测试:" << endl;
	fout << "want : f1 - f2 = 27/70 ,out : f1 - f2 = " << f1 - f2 << endl;
	fout << "want : f1 - f3 =  1/10 ,out : f1 - f3 = " << f1 - f3 << endl;
	fout << "want : f1 - f4 = -7/30 ,out : f1 - f4 = " << f1 - f4 << endl << endl;

	fout << "运算符 * 测试:" << endl;
	fout << "want : f1 * f2 = -1/35 ,out : f1 * f2 = " << f1 * f2 << endl;
	fout << "want : f1 * f3 =  0/2  ,out : f1 * f3 = " << f1 * f3 << endl;
	fout << "want : f1 * f4 =  1/30 ,out : f1 * f4 = " << f1 * f4 << endl << endl;

	fout << "运算符 / 测试:" << endl;
	fout << "want : f1 / f2 = -7/20 ,out : f1 / f2 = " << f1 / f2 << endl;
	fout << "want : f1 / f3 = ERROR ,out : f1 / f3 = " << f1 / f3 << endl;
	fout << "want : f1 / f4 =  3/10 ,out : f1 / f4 = " << f1 / f4 << endl << endl;

	fout << "关系运算符 > 测试" << endl;
	fout << "want : f1 > f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 > f2) << endl;
	fout << "want : f1 > f4 = false ,out : " << setiosflags(ios::boolalpha) << (f1 > f4) << endl << endl;

	fout << "关系运算符 < 测试" << endl;
	fout << "want : f1 < f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 < f2) << endl;
	fout << "want : f1 < f4 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 < f4) << endl << endl;

	fout << "关系运算符 >= 测试" << endl;
	fout << "want : f1 >= f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 >= f2) << endl;
	fout << "want : f1 >= f4 = false ,out : " << setiosflags(ios::boolalpha) << (f1 >= f4) << endl << endl;

	fout << "关系运算符 <= 测试" << endl;
	fout << "want : f1 <= f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 <= f2) << endl;
	fout << "want : f1 <= f4 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 <= f4) << endl << endl;

	fout << "关系运算符 != 测试" << endl;
	fout << "want : f1 != f2 = true  ,out : " << setiosflags(ios::boolalpha) << (f1 != f2) << endl;
	fout << "want : f1 != ff7= false ,out : " << setiosflags(ios::boolalpha) << (f1 != ff7) << endl << endl;

	fout << "关系运算符 == 测试" << endl;
	fout << "want : f1 == f2 = false ,out : " << setiosflags(ios::boolalpha) << (f1 == f2) << endl;
	fout << "want : f1 == ff7 = true ,out : " << setiosflags(ios::boolalpha) << (f1 == ff7) << endl << endl;

	fout << "输出运算符测试已在上述程序中完成." << endl ;
}