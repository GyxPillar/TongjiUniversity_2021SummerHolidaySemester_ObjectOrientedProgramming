/***************************************************************************
*                                                                          
	文件名:fraction_binary_operator.cpp
	功能  :实现分数类双目运算符重载
*                                                                           
****************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*重载加号*/
fraction fraction::operator+(const fraction& other)
{
	fraction ret(numerator * other.denomination + denomination * other.numerator, denomination * other.denomination, value + other.value);
	ret = ret.Reduction();
	return ret;
}

/*重载减号*/
fraction fraction::operator-(const fraction& other)
{
	fraction ret(numerator * other.denomination - denomination * other.numerator, denomination * other.denomination, value - other.value);
	ret = ret.Reduction();
	return ret;
}

/*重载乘号*/
fraction fraction::operator*(const fraction& other)
{
	fraction ret(numerator * other.numerator, denomination * other.denomination, value * other.value);
	ret = ret.Reduction();
	return ret;
}

/*重载除号*/
fraction fraction::operator/(const fraction& other)
{
	if (fabs(other.value) < 1e-6)//防止除数为0
	{
		fraction ret(0, 1, 0.0);
		return ret;
	}
	int sign_flag = value * other.value > 0 ? 1 : -1;
	fraction ret(abs(numerator * other.denomination) * sign_flag, abs(denomination * other.numerator), value / other.value);
	ret = ret.Reduction();
	return ret;
}

/*重载大于号*/
bool fraction::operator>(const fraction& other)
{
	return value > other.value;
}

/*重载小于号*/
bool fraction::operator<(const fraction& other)
{
	return value < other.value;
}

/*重载大于等于号*/
bool fraction::operator>=(const fraction& other)
{
	return value >= other.value;
}

/*重载小于等于号*/
bool fraction::operator<=(const fraction& other)
{
	return value <= other.value;
}

/*重载不等号*/
bool fraction::operator!=(const fraction& other)
{
	return fabs(value - other.value) >= 1e-6;
}

/*重载等于号*/
bool fraction::operator==(const fraction& other)
{
	return fabs(value - other.value) < 1e-6;
}
