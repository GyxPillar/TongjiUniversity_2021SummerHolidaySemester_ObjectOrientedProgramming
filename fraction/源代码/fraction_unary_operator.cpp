/***************************************************************************
*
	�ļ���:fraction_unary_operator.cpp
	����  :ʵ�ַ����൥Ŀ���������
*
****************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*���෴��*/
fraction fraction::Inverse()
{
	fraction temp (-1 * numerator, denomination, -1 * value);
	return temp;
}

/*����*/
fraction fraction::Reciprocal()
{
	if (fabs(value) < 1e-6)
		return FAIL;
	fraction temp(numerator < 0 ? -1 * denomination : denomination, abs(numerator), double(denomination) / double(numerator));
	return temp;
}

/*Լ��*/
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
	if (fabs(other) < 1e-6)//��0����
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
	bool sign_flag = other[0] == '-' ? 0 : 1;//�жϷ�������
	i = sign_flag ? 0 : 1;//����λ��ʼλ����
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

/*���������*/
LL gcd(LL a, LL b)
{
	return a ? (b ? gcd(b, a % b) : a) : 1;
}

