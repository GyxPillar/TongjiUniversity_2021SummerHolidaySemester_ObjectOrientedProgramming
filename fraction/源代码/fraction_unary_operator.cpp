/***************************************************************************
*
	文件名:fraction_unary_operator.cpp
	功能  :实现分数类单目运算符重载
*
****************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*求相反数*/
fraction fraction::Inverse()
{
	fraction temp (-1 * numerator, denomination, -1 * value);
	return temp;
}

/*求倒数*/
fraction fraction::Reciprocal()
{
	if (fabs(value) < 1e-6)
		return FAIL;
	fraction temp(numerator < 0 ? -1 * denomination : denomination, abs(numerator), double(denomination) / double(numerator));
	return temp;
}

/*约分*/
fraction fraction::Reduction()
{	
	if (fabs(value) < 1e-6)
		return *this;
	fraction ret(numerator / gcd(denomination, abs(numerator)), denomination / gcd(denomination, abs(numerator)), value);
	return ret;
}

/*double to fraction*/
fraction::fraction(const double other)
{
	if (fabs(other) < 1e-6)//置0处理
	{
		numerator = 0, denomination = 2, value = 0.0;
		return;
	}
	numerator = static_cast <LL>(other * 1e15) / gcd(abs(static_cast <LL>(other * 1e15)), 1e15);
	denomination = 1e15 / gcd(abs(static_cast <LL>(other * 1e15)), 1e15);
	value = other;
}

/*string to fraction*/
fraction::fraction(const char other[50])
{
	int i = 0;
	LL temp_numerator = 0, temp_denomination = 0;
	bool sign_flag = other[0] == '-' ? 0 : 1;//判断分子正负
	i = sign_flag ? 0 : 1;//数字位起始位控制
	for (; other[i] != '/'; i++)
	{
		temp_numerator *= 10;
		temp_numerator +=LL(other[i]) - LL('0');
	}
	for (i++; other[i] != '\0'; i++)
	{
		temp_denomination *= 10;
		temp_denomination += LL(other[i]) - LL('0');
	}
	numerator = sign_flag ? temp_numerator : -1 * temp_numerator;
	denomination = temp_denomination;
	value = double(numerator)/double(denomination);
}

/*求最大公因数*/
LL gcd(LL a, LL b)
{
	return a ? (b ? gcd(b, a % b) : a) : 1;
}

