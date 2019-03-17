#ifndef STACK_H_
#define STACK_H_
# include "customer.h"
# include <iostream>


typedef Customer Item;


class Stack
{
private:
    enum {MAX=10};
    static double _totalPayment;//为什么static
    Item _items[MAX];
    int _top;
public:
    Stack():_top(0),_items(){};
    //如何在构造函数类初始化数组，
    // 写到大括号里就不是初始化了哦！且数组只能在初始化的使用初始化列表的形式
    // 像这样，直接在数组_items后面写个()，难道是调用了数组的构造函数吗？数组是一个对象吗？怎么还有构造函数。
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item &item);//if stack is full,return false.
    bool pop(Item &item);// if stack is empty,return false.
    void showTotalPayment(){std::cout<<"now the totalPayment is :"<<_totalPayment<<std::endl;}
    ~Stack(){};
};



#endif