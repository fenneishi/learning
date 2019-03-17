

#if !defined(COW_H_)
#define COW_H_

# include<iostream>
# include<cstring> //构造函数无法真正初始化数组，所以必须借助scp()函数，在构造函数中第一时间给数组赋值


using namespace std;


class Cow
{
private:
    char name[20];
    char *hobby;
    double weight;
public:
    Cow(/* args */);
    Cow(const char *nm, const char *ho,double weight);
    Cow(const Cow &c);
    Cow & operator=(const Cow &c);//因为*this不是const，所以返回值（引用*const）也不能是const;
    void showCow()const;
    ~Cow();
};







#endif // COW_H_
