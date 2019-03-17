
#include <iostream>
#include <string>
using namespace  std;

class BankAccount
{
private:
    string _name;
    string _id;
    double _balance;
public:
    BankAccount(const string &id,const string &name,double balance=0):_name(name),_id(id),_balance(balance){}
    BankAccount(){cout<<"this is wrong way!"<<endl;}
    void deposit(double saveCash){_balance+=saveCash;cout<<"save $"<<saveCash<<endl;}
    void withdraw(double needCash){_balance-=needCash;cout<<"out $"<<needCash<<endl;}
    void show(void)
    {
        cout<<"id:"<<_id<<";"<<"    "
            <<"name:"<<_name<<";"<<"    "
            <<"balance:"<<_balance<<endl;    
    }



};