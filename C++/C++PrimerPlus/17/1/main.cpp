#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"please input:";
    char *ch=new char[100];
    cin.get(ch,100,'$');
    int num;
    num=strlen(ch);
    cout<<ch<<endl;
    cout<<"the num is :"<<num<<endl;
    delete[] ch;
    return 0;
}
