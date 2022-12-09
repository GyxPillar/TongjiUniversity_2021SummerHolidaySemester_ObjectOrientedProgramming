/***************************************************************************
*
	�ļ���:fraction_test_mode_2.cpp
	����  :ʵ�ַ����๦�ܵĲ���2ģʽ
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

/*�õ�������*/
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

/*�Ӳ˵�*/
const string in_tips[17] = {
	"��ѡ����Թ���:",
	"1. �෴��Inverse����",
	"2. ����Reciprocal����",
	"3. ��Լ��Reduction����",
	"4. DtoFС��ת��������",
	"5. StoF�ַ���ת��������",
	"6. ����� + ����" ,
	"7. ����� - ����" ,
	"8. ����� * ����",
	"9. ����� / ����",
	"10.��ϵ����� > ����" ,
	"11.��ϵ����� < ����",
	"12.��ϵ����� >= ����" ,
	"13.��ϵ����� <= ����" ,
	"14.��ϵ����� != ����" ,
	"15.��ϵ����� == ����",
	"** �������������������������Ѿ���ɣ����ٵ������� **"
};

/*��Ŀ����*/
void unary_test(int mode)
{
	fraction number;
	mode != 4 ? cout << "����������(�Է�����ʽ,�뱣֤�������ݷ���Ҫ��):" : cout<<"����������(��С����ʽ,�뱣֤�������ݷ���Ҫ��):";
	mode != 4 ? number = get_number_s() : number = get_number_d();
	cout << number << " " << &in_tips[mode][3] << "���Ϊ : ";
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

	ofstream fout;  //foutΪ������
	fout.open("test_mode_2.txt", ios::out);  //���ļ�
	if (!fout.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	fout << number << " " << &in_tips[mode][3] << "���Ϊ : ";
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

/*˫Ŀ����*/
void binary_test(int mode)
{
	fraction number1, number2;
	cout << "����������1(�Է�����ʽ,�뱣֤�������ݷ���Ҫ��):";
	number1 = get_number_s();
	cout << "����������2(�Է�����ʽ,�뱣֤�������ݷ���Ҫ��):";
	number2 = get_number_s();
	cout << &in_tips[mode][3] << "���Ϊ : ";
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

	ofstream fout;  //foutΪ������
	fout.open("test_mode_2.txt", ios::out);  //���ļ�
	if (!fout.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	fout << &in_tips[mode][3] << "���Ϊ : ";
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
	/* ģʽ�������û��Լ�ѡ����Թ��ܡ������������. */
	cout << "ģʽ������ (�˲�����������ڿ���̨���ļ�)" << endl << endl;

	/*�Ӳ˵�չʾ*/
	for (int i = 0; i < 17; i++)
		cout << in_tips[i] << endl;
	cout << "[��ѡ��ģʽ]:";

	/*�������ģʽ���ѽ��������쳣����*/
	int mode = 0;
	while (1)
	{
		cin >> mode;
		if (cin.fail())
		{
			cin.clear();//��������ǣ����´������������������������ɱ�����֮ǰ�Ĳ�ƥ�������
			cin.ignore(1024, '\n');//���cin�����������ݡ�
			continue;
		}
		if (mode >= 1 && mode <= 15)
			break;
	}
	cout << endl << "��ǰ���в���: " << in_tips[mode] << endl;
	mode <= 5 ? unary_test(mode) : binary_test(mode);
	cout << endl;
}