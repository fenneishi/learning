
# include "string2.h"

// 尽量在大括号前完成初始化（主要针对const类成员和引用类成员)

String2::String2()
{
    str=new char[10];
    strcpy(str,"default");
    // 不要把str指向nullptr,不方便统一的输出接口。
}
String2::String2(const char *s)
{
    str=new char[strlen(s)+1];
    strcpy(str,s);
}
String2::String2(const String2 & s)
{
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
}

String2 &String2::operator=(const String2 &s)
{
    if(this==&s)return *this;
    delete[] str;
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
    return *this;

}
String2& String2::operator=(const char ch[])
{
    delete[] str;
    str=new char[strlen(ch)+1];
    strcpy(str,ch);
    return *this;
}
const char String2::operator[](int num)const
{
    return str[num];
}
String2  operator+(const String2 &s1,const String2 &s2)
{
    String2 res;
    res.str=new char[strlen(s1.str)+strlen(s2.str)+1];
    strcpy(res.str,s1.str);
    strcpy(res.str+strlen(s1.str),s2.str);
    return  res;//返回时局部变量，又要对这个局部变量进行修改，所以返回不能const不能引用
}
bool operator==(const String2 &s1,const String2 &s2)
{
    return strcmp(s1.str,s2.str)==0;
}
bool operator<(const String2 &s1,const String2 &s2)
{
    return strcmp(s1.str,s2.str)<0;
}
bool operator>(const String2 &s1,const String2 &s2)
{
    return strcmp(s1.str,s2.str)>0;
}
ostream & operator<<(ostream & os,const String2 &s)
{
    os<<s.str;//不要加endl;
    return os;
}
istream & operator>>(istream & is,String2 &s)
{
    char temp[String2::CIN_MAX];
    is.get(temp,String2::CIN_MAX);
    if(is) s=temp;
    while(is&&is.get()!='\n')continue; //把多余的包括等号，全部吃掉。不给主调函数后面的cin留下问题。
    return is;
}
void String2::stringLow()
{
    for(int i=0;i<strlen(str);i++)
    {
        str[i]=tolower(str[i]);
    }
}
void String2::stringUpr()
{
    for(int i=0;i<strlen(str);i++)
    {
        str[i]=toupper(str[i]);
    }
}
int String2::countChar(char ch)const
{
    int count=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==ch)count++;
    }
    return count;
}
int String2::getlen()
{
    return strlen(str);
}
String2::~String2()
{
    cout<<"-----------------------------------------"<<"construct:"<<str<<endl;
    delete[] str;
};