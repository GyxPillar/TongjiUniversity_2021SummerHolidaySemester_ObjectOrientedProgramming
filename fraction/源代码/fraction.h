#pragma once
/* 2053385 高逸轩 */
#ifndef FRACTION_H_
#define FRACTION_H_

/* 错误处理将fraction置为0/1 */
#define FAIL (0,1,0.0)
typedef long long LL;

/*求最大公因数*/
LL gcd(LL a, LL b);

class fraction
{
public:

	/*构造函数*/

    fraction(const LL& T1, const LL& T2, const double T3) :numerator(T1), denomination(T2), value(T3) {};
    fraction(const double other = 0.0);//隐式类类型转换DtoF;默认构造函数
    fraction(const char other[50]);//隐式类类型转换StoF


    /*单目运算*/

    fraction Inverse();//求相反数
    fraction Reciprocal();///求倒数
    fraction Reduction();//约分


    /*双目运算*/

    fraction operator+(const fraction& other);//重载加号
    fraction operator-(const fraction& other);//重载减号
    fraction operator*(const fraction& other);//重载乘号
    fraction operator/(const fraction& other);//重载除号
    bool operator>(const fraction& other);//重载大于号
    bool operator<(const fraction& other);//重载小于号
    bool operator>=(const fraction& other);//重载大于等于号
    bool operator<=(const fraction& other);//重载小于等于号
    bool operator!=(const fraction& other);//重载不等号
    bool operator==(const fraction& other);//重载等于号


	/*输出运算符重载*/

    friend std::ostream& operator<<(std::ostream& _cout, const fraction& T);

private:

	/*成员数据*/

    LL numerator;//分子
    LL denomination;//分母
    double value;//分数数值

};

#endif // !FRACTION_H_