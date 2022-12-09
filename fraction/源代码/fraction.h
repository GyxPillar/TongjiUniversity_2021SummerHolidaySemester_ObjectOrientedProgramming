#pragma once
/* 2053385 ������ */
#ifndef FRACTION_H_
#define FRACTION_H_

/* ������fraction��Ϊ0/1 */
#define FAIL (0,1,0.0)
typedef long long LL;

/*���������*/
LL gcd(LL a, LL b);

class fraction
{
public:

	/*���캯��*/

    fraction(const LL& T1, const LL& T2, const double T3) :numerator(T1), denomination(T2), value(T3) {};
    fraction(const double other = 0.0);//��ʽ������ת��DtoF;Ĭ�Ϲ��캯��
    fraction(const char other[50]);//��ʽ������ת��StoF


    /*��Ŀ����*/

    fraction Inverse();//���෴��
    fraction Reciprocal();///����
    fraction Reduction();//Լ��


    /*˫Ŀ����*/

    fraction operator+(const fraction& other);//���ؼӺ�
    fraction operator-(const fraction& other);//���ؼ���
    fraction operator*(const fraction& other);//���س˺�
    fraction operator/(const fraction& other);//���س���
    bool operator>(const fraction& other);//���ش��ں�
    bool operator<(const fraction& other);//����С�ں�
    bool operator>=(const fraction& other);//���ش��ڵ��ں�
    bool operator<=(const fraction& other);//����С�ڵ��ں�
    bool operator!=(const fraction& other);//���ز��Ⱥ�
    bool operator==(const fraction& other);//���ص��ں�


	/*������������*/

    friend std::ostream& operator<<(std::ostream& _cout, const fraction& T);

private:

	/*��Ա����*/

    LL numerator;//����
    LL denomination;//��ĸ
    double value;//������ֵ

};

#endif // !FRACTION_H_