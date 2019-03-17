# 
#if !defined(VINTAGEPORT_H_)
#define VINTAGEPORT_H_
# include "port.h"
class Vintageport:public Port
{
private:
    char *nickname;
    int year;
public:
// 需要重写:
    // 四大金刚逃不掉,
    Vintageport();
    ~Vintageport();
    Vintageport(const Vintageport & vp);
    Vintageport& operator=(const Vintageport &vp);
    // 重载构造逃不掉
    explicit Vintageport(char *nn);
    Vintageport(char *nn,int y);
    Vintageport(char *nn,int y,const char *br,const char *st,int bo);
    // 输入输出是友元逃不掉
    friend ostream& operator<<(ostream &os,const Vintageport p);
    friend istream& operator>>(istream &is,Vintageport p);
    // virtual上面要求，
    virtual void show()const;
    // 其他友元也是逃不掉的


    
};


#endif // VINTAGEPORT_H_
