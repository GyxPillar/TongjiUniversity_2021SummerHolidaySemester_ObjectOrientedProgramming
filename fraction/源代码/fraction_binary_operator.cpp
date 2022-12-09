/***************************************************************************
*                                                                          
	�ļ���:fraction_binary_operator.cpp
	����  :ʵ�ַ�����˫Ŀ���������
*                                                                           
****************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*���ؼӺ�*/
fraction fraction::operator+(const fraction& other)
{
	fraction ret(numerator * other.denomination + denomination * other.numerator, denomination * other.denomination, value + other.value);
	ret = ret.Reduction();
	return ret;
}

/*���ؼ���*/
fraction fraction::operator-(const fraction& other)
{
	fraction ret(numerator * other.denomination - denomination * other.numerator, denomination * other.denomination, value - other.value);
	ret = ret.Reduction();
	return ret;
}

/*���س˺�*/
fraction fraction::operator*(const fraction& other)
{
	fraction ret(numerator * other.numerator, denomination * other.denomination, value * other.value);
	ret = ret.Reduction();
	return ret;
}

/*���س���*/
fraction fraction::operator/(const fraction& other)
{
	if (fabs(other.value) < 1e-6)//��ֹ����Ϊ0
	{
		fraction ret(0, 1, 0.0);
		return ret;
	}
	int sign_flag = value * other.value > 0 ? 1 : -1;
	fraction ret(abs(numerator * other.denomination) * sign_flag, abs(denomination * other.numerator), value / other.value);
	ret = ret.Reduction();
	return ret;
}

/*���ش��ں�*/
bool fraction::operator>(const fraction& other)
{
	return value > other.value;
}

/*����С�ں�*/
bool fraction::operator<(const fraction& other)
{
	return value < other.value;
}

/*���ش��ڵ��ں�*/
bool fraction::operator>=(const fraction& other)
{
	return value >= other.value;
}

/*����С�ڵ��ں�*/
bool fraction::operator<=(const fraction& other)
{
	return value <= other.value;
}

/*���ز��Ⱥ�*/
bool fraction::operator!=(const fraction& other)
{
	return fabs(value - other.value) >= 1e-6;
}

/*���ص��ں�*/
bool fraction::operator==(const fraction& other)
{
	return fabs(value - other.value) < 1e-6;
}
