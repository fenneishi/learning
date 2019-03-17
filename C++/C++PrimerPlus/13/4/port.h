
#if !defined(PORT_H_)
#define PORT_H_

#include <iostream>
using namespace std;

class Port
{
  private:
    char *brand;
    char *style;
    int bottles;

  public:
//共同方法：这些所有类都要设计的特殊函数，基本都不是const函数
    // 四大金刚，都牵扯修改this内容，所以都不是const函数
    Port(const char *br="none",const char *st="none",int bo=0);//这种形式实际上把所有构造函数都给包含了，有时候不好，尤其无法对单参数进行explicit
    virtual ~Port();//析构函数不能搞成const哦
    Port(const Port &p);
    Port &operator=(const Port &p);

    //overload constructor
    // Port(const char *br, const char *st, int bo);
    // explicit Port(const char *br); //加explicit的，只有单元素构造函数和转换函数

    //cout+cin
    friend ostream& operator<<(ostream &os,const Port p);
    friend istream& operator>>(istream &is,Port p);

    //还有两个特殊的，一个是&重载，一个是类型转换函数，但是这两个函数只是部分情况下可能会被用到


//特有函数:
    Port& operator+=(int b);
    Port& operator-=(int b);
    int bottleCout()const{return bottles;} //只牵扯父类状态成员的不用子类重写，所以设计成非virtual.
    virtual void show()const;



};

#endif // PORT_H_
