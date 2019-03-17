# include "port.h"
# include <cstring>
using namespace std;

//共同方法：这些所有类都要设计的特殊函数，基本都不是const函数
// 四大金刚，都牵扯修改this内容，所以都不是const函

Port::Port(const char *br,const char *st,int bo)
{
    br=new char[strlen(br)+1];
    strcpy(brand,br);
    st=new char[strlen(st)+1];
    strcpy(style,st);
    bottles=bo;
}

Port::~Port()//析构函数不能搞成const
{
    delete[] brand;
    delete[] style;
}

Port::Port(const Port &p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    style=new char[strlen(p.style)+1];
    strcpy(style,p.style);
    bottles=p.bottles;//为了方便自动补全，起名字的时候开头尽量不同
}

Port& Port::operator=(const Port &p)
{
    if(this==&p)
        return *this;
    else    
        delete[] brand;
        delete[] style;
        brand=new char[strlen(p.brand)+1];
        strcpy(brand,p.brand);
        style=new char[strlen(p.style)+1];
        strcpy(style,p.style);
        bottles=p.bottles;//为了方便自动补全，起名字的时候开头尽量不同
        return *this;
}
//cout+cin
ostream& operator<<(ostream &os,const Port p)
{
    os<<p.brand<<" "<<p.style<<" "<<p.bottles;
    return os;
}
istream& operator>>(istream &is,Port p)
{
    cout<<"brand:";(is>>p.brand).get();
    cout<<"style:";(is>>p.style).get();
    cout<<"bottles:";(is>>p.bottles).get();
    return is;
}
//特有函数
Port& Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}
Port& Port::operator-=(int b)
{
    bottles-=b;
    return *this;
}
void Port::show()const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Kind: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
}


// 函数描述符：friend virtual static explicit 不会存在于实现文件中的。
// 参数默认值删掉
// 只有friend不加限定符号
