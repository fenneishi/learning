#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>


class Customer
{
    std::string _name;
    double _payment;
public:
    Customer():_name(),_payment(){};
    Customer(const std::string &name, double payment):_name(name),_payment(payment){}
    double getPayment(){return _payment;}
};


#endif