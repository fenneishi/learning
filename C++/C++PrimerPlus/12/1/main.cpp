

# include "cow.h"

int main(int argc, char const *argv[])
{
    
    cout<<"cow1:"<<endl;
    Cow c1;
    c1.showCow();
    cout<<"-------------------------"<<endl;

    cout<<"cow2:"<<endl;
    Cow c2("cow2","grass2",3);
    c2.showCow();
    cout<<"-------------------------"<<endl;

    cout<<"cow3:"<<endl;
    Cow c3(c2);
    c3.showCow();
    cout<<"-------------------------"<<endl;

    cout<<"cow4:"<<endl;
    Cow c4=c3;//仅仅调用了copy构造函数
    c4.showCow();
    cout<<"-------------------------"<<endl;

    cout<<"cow4:"<<endl;
    Cow c5;
    c5=c4;//我的编译器并没有在这里创建临时对象。
    c5.showCow();
    cout<<"-------------------------"<<endl;
    return 0;
}
