

#if !defined(STOCK_H_)
#define STOCK_H_

#include<iostream>
#include<cstring>
using namespace std; 


class Stock
{
private:
    char * company;
    int shares;
    double shar_val;
    double total_val;
public://为了cin>>重载
    void set_tot(){total_val=shar_val*shares;}
public:
    Stock(/* args */);
    explicit Stock(const char *co,int n=0,double per=0);
    Stock(const Stock &s);

    void buy(int num,double price);
    void sell(int num,double price);

    void update(double price);
    const Stock &topval(const Stock &s)const;

    Stock & operator=(const Stock &s);
    Stock & operator=(const char *ch);

    friend ostream & operator<<(ostream & os,Stock const & s);
    friend istream & operator>>(istream & os,Stock & s);

    ~Stock() ;
};



#endif // STOCK_H_
