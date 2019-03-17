
#include "comp.h"

int main(int argc, char const *argv[])
{
    Comp a(3.0,4.0);
    Comp c;

    cout<<"Enter a comples number (q to quit)"<<endl;
    while(cin>>c)
    {
        cout<<"c is "<<c<<endl;
        cout<<"c conjugate is "<<~c<<endl;

        cout<<"a is "<<a<<endl;
        cout<<"a+c="<<a+c<<endl;
        cout<<"a-c="<<a-c<<endl;
        cout<<"a*c="<<a*c<<endl;
        cout<<"2*c="<<2*c<<endl;
        cout<<"Enter a comples number (q to quit)"<<endl;
    }

    cout<<"Done!"<<endl;
    return 0;
}
