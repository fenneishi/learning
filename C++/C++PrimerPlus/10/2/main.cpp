# include <iostream>
# include "person.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwidddy","Sam");

    one.show();
    one.FormalShow();
    cout<<endl;
    

    two.show();
    two.FormalShow();
    cout<<endl;

    three.show();
    three.FormalShow();
    cout<<endl;
    
    return 0;
}
