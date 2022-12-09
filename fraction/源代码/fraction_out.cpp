/***************************************************************************
*
	�ļ���:fraction_out.cpp
	����  :ʵ�ַ�������������������
*
****************************************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
#include"fraction.h"

using namespace std;

/*������������*/
std::ostream& operator<<(std::ostream& _cout, const fraction& T)
{
	if (T.numerator == 0 && T.denomination == 1)
		_cout << "ERROR(0/1)";
	else if (fabs(T.value) < 1e-6)
		_cout << "0/2";//��Tips��
	else
		_cout << T.numerator << '/' << T.denomination;
	return _cout;
}