#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    char num='x';
    cout<<num<<endl;

    cout<<"input the num:";
    cin>>num;
    if(cin)
    {
        cout<<"cin is true"<<endl;
    }
    else
    {
        cout<<"cin is false"<<endl;
    }
    cout<<num<<endl;
    cout<<"------------"<<endl;
    return 0;
}
