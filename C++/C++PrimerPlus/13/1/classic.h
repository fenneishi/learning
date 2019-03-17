
#if !defined(CLASSIC_H_)
#define CLASSIC_H_

#include"cd.h"

class Classic : public Cd
{
private:
    char *str;
public:
    Classic();
    Classic(const char *s,const char* per,const char *lab,int sel,double plti);
    virtual ~Classic();
    Classic &operator=(const Classic &d);
    virtual void report() const;
};


#endif // CLASSIC_H_


// 经验:
// 非继承问题：
//     默认default:构造、析构、=函数、&函数
//     友元函数
// virtual函数实现


// 干扰：
//     子类new(深拷贝、delete)

