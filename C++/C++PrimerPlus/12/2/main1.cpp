
# include "string2.h"




int main(int argc, char const *argv[])
{
    String2 s1(" and I am C++ student.");
    String2 s2=String2("please inter your name:");//这里也没有临时变量，按理说应该有，但是应该被编译器给优化了
    String2 s3;

    cout<<s2;

    (cin>>s3).get();
    s2=String2("my name is ")+s3;//这里创建了两次临时变量，所以会发生析构
    // new的对象、局部对象、静态区对象、临时对象构造时间和析构时间

    cout<<s2<<endl;

    s2=s2+s1;//一个临时变量

    s2.stringUpr();

    cout<<"the string:  "<<s2<<"\ncontains "<<s2.countChar('A')
        << " 'A' characters in it .\n";

    s1=String2("red");//一个临时变量

    String2 rgb[3]={String2(s1),String2("green"),String2("blue")};//这里并没有临时变量
    cout<<"enter the name of a primary color for mixing light: ";
    String2 ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringLow();
        for(int i=0;i<3;i++)
        {
            if(ans==rgb[i])
            {
                cout<<"that is right! \n";
                success =true;
                break;
            }
        }
        if(success)
            break;
        else
            cout<<"try again:";
    }

    cout<<"Bye\n";
    
    return 0;
}


