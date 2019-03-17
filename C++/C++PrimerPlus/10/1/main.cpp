
# include <iostream>
# include "BankAccount.h"
using namespace std;


int main(int argc, char const *argv[])
{
    BankAccount user1("001","user1",99.9);
    user1.show();
    user1.deposit(0.1);
    user1.show();
    user1.withdraw(0.1);
    user1.show();
    cout<<"==============="<<endl;

    BankAccount users[3]={
        BankAccount("001","user1",9.9),
        BankAccount("002","user2",19.9),
        BankAccount("003","user3",29.9),
    };
    
    for(int num=0;num<3;num++)
    {
        users[num].show();
        users[num].deposit(0.1);
        users[num].show();
        users[num].withdraw(0.1);
        users[num].show();
        cout<<"-------------"<<endl;
    }



    // // C++11 extension
    // for(BankAccount user:users)
    // {
    //     user.show();
    //     user.deposit(0.1);
    //     user.show();
    //     user.withdraw(0.1);
    //     user.show();
    // }





    
    return 0;
}
