/***************************************************************************
*
	文件名:fraction_test_mode_2.cpp
	功能  :实现分数类功能的测试2模式
*
****************************************************************************/

#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cmath>
#include<conio.h>
#include"fraction.h"

using namespace std;

/*得到分数类*/
fraction get_number_s()
{
	char number[50];
	cin >> number;
	fraction ret = number;
	return ret;
}
fraction get_number_d()
{
	double number;
	cin >> number;
	fraction ret = number;
	return ret;
}

/*子菜单*/
const string in_tips[17] = {
	"请选择测试功能:",
	"1. 相反数Inverse测试",
	"2. 求倒数Reciprocal测试",
	"3. 求约分Reduction测试",
	"4. DtoF小数转分数测试",
	"5. StoF字符串转分数测试",
	"6. 运算符 + 测试" ,
	"7. 运算符 - 测试" ,
	"8. 运算符 * 测试",
	"9. 运算符 / 测试",
	"10.关系运算符 > 测试" ,
	"11.关系运算符 < 测试",
	"12.关系运算符 >= 测试" ,
	"13.关系运算符 <= 测试" ,
	"14.关系运算符 != 测试" ,
	"15.关系运算符 == 测试",
	"** 输出运算符测试在上述测试中已经完成，不再单独测试 **"
};

/*单目测试*/
void unary_test(int mode)
{
	fraction number;
	mode != 4 ? cout << "请输入数据(以分数形式,请保证输入数据符合要求):" : cout<<"请输入数据(以小数形式,请保证输入数据符合要求):";
	mode != 4 ? number = get_number_s() : number = get_number_d();
	cout << number << " " << &in_tips[mode][3] << "结果为 : ";
	switch (mode)
	{
	case 1:
		cout << number.Inverse();
		break;
	case 2:
		cout << number.Reciprocal();
		break;
	case 3:
		cout << number.Reduction();
		break;
	case 4:
		cout << number;
		break;
	case 5:
		cout << number;
		break;
	}

	ofstream fout;  //fout为变量名
	fout.open("test_mode_2.txt", ios::out);  //打开文件
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	fout << number << " " << &in_tips[mode][3] << "结果为 : ";
	switch (mode)
	{
	case 1:
		fout << number.Inverse();
		break;
	case 2:
		fout << number.Reciprocal();
		break;
	case 3:
		cout << number.Reduction();
		break;
	case 4:
		fout << number;
		break;
	case 5:
		fout << number;
		break;
	}
}

/*双目测试*/
void binary_test(int mode)
{
	fraction number1, number2;
	cout << "请输入数据1(以分数形式,请保证输入数据符合要求):";
	number1 = get_number_s();
	cout << "请输入数据2(以分数形式,请保证输入数据符合要求):";
	number2 = get_number_s();
	cout << &in_tips[mode][3] << "结果为 : ";
	switch (mode)
	{
	case 6:
		cout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case 7:
		cout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case 8:
		cout << number1 << " * " << number2 << " = " << number1 * number2;
		break;
	case 9:
		cout << number1 << " / " << number2 << " = " << number1 / number2;
		break;
	case 10:
		cout << number1 << " > " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 > number2);
		break;
	case 11:
		cout << number1 << " < " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 < number2);
		break;
	case 12:
		cout << number1 << " >= " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 >= number2);
		break;
	case 13:
		cout << number1 << " <= " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 <= number2);
		break;
	case 14:
		cout << number1 << " != " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 != number2);
		break;
	case 15:
		cout << number1 << " == " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 == number2);
		break;
	}

	ofstream fout;  //fout为变量名
	fout.open("test_mode_2.txt", ios::out);  //打开文件
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	fout << &in_tips[mode][3] << "结果为 : ";
	switch (mode)
	{
	case 6:
		fout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case 7:
		fout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case 8:
		fout << number1 << " * " << number2 << " = " << number1 * number2;
		break;
	case 9:
		fout << number1 << " / " << number2 << " = " << number1 / number2;
		break;
	case 10:
		fout << number1 << " > " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 > number2);
		break;
	case 11:
		fout << number1 << " < " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 < number2);
		break;
	case 12:
		fout << number1 << " >= " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 >= number2);
		break;
	case 13:
		fout << number1 << " <= " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 <= number2);
		break;
	case 14:
		fout << number1 << " != " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 != number2);
		break;
	case 15:
		fout << number1 << " == " << number2 << " = " << setiosflags(ios::boolalpha) << (number1 == number2);
		break;
	}
}

void test_mode_2()
{
	/* 模式二：由用户自己选择测试功能、输入测试数据. */
	cout << "模式二测试 (此部分内容输出于控制台和文件)" << endl << endl;

	/*子菜单展示*/
	for (int i = 0; i < 17; i++)
		cout << in_tips[i] << endl;
	cout << "[请选择模式]:";

	/*输入测试模式，已进行输入异常处理*/
	int mode = 0;
	while (1)
	{
		cin >> mode;
		if (cin.fail())
		{
			cin.clear();//清除错误标记，重新打开输入流，但是输入流中依旧保留着之前的不匹配的类型
			cin.ignore(1024, '\n');//清楚cin缓存区的数据。
			continue;
		}
		if (mode >= 1 && mode <= 15)
			break;
	}
	cout << endl << "当前进行测试: " << in_tips[mode] << endl;
	mode <= 5 ? unary_test(mode) : binary_test(mode);
	cout << endl;
}