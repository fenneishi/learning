#
#if !defined(STRINGTWO_H_)
#define STRINGTWO_H_
# include<iostream>
# include<cstring>
# include<cctype>
using namespace std;

// 尽量私有化
// 尽量explicit.
// 尽量const.
// 尽量friend.
// 尽量不要用default
// 尽量用引用
// 遇到问题，再根据具体问题去修改。

class String2
{
private:
    char *str;
    const static int CIN_MAX=100;
public:
    // construct
    String2();
    explicit String2(const char *s);
    // explicit String2(const String2 & s);若写成explicit则参数传递和函数返回中都无法使用拷贝构造了
    String2(const String2 & s);

    String2& operator=(const String2 &s);
    String2& operator=(const char ch[]);
    const char operator[](int num)const;

    friend String2 operator+(const String2 &s1,const String2 &s2);
    
    friend bool operator==(const String2 &s1,const String2 &s2);
    friend bool operator<(const String2 &s1,const String2 &s2);
    friend bool operator>(const String2 &s1,const String2 &s2);

    friend ostream & operator<<(ostream & os,const String2 &s2);
    friend istream & operator>>(istream & is,String2 &s);


    void stringLow();
    void stringUpr();

    int countChar(char ch)const;

    int getlen();

    // destruct
    ~String2();
};





#endif // STRINGTWO_H_
