/***************************************************************************
*
	文件名:fraction_out.cpp
	功能  :实现分数类输出运算符的重载
*
****************************************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*重载输出运算符*/
std::ostream& operator<<(std::ostream& _cout, const fraction& T)
{
	if (T.numerator == 0 && T.denomination == 1)
		_cout << "ERROR(0/1)";
	else if (fabs(T.value) < 1e-6)
		_cout << "0/2";//见Tips④
	else
		_cout << T.numerator << '/' << T.denomination;
	return _cout;
}