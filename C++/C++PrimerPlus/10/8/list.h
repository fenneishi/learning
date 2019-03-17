
#ifndef LIST_H_
#define LIST_H_

#include "item.h"
#include <iostream>

class List
{
private:
    const static int MAX=10;
    Item _list[MAX];
    int _top;
public:
    List():_list(),_top(0){};
    bool isEmpty(){return _top==0;}
    bool isFull(){return _top==MAX;}

    bool add(const Item &addItem)
    {
        if(isFull())return false;
        _list[_top++]=addItem;
        return true;
    }
    //if list is full,return false

    bool del(Item &recvItem)
    {
        if(isEmpty())return false;
        recvItem=_list[--_top];
        return true;
    }
    //if list is empty,return false

    void visit(void (*pf)(Item &))
    {
        // std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
        for(int i=0;i<_top;i++)
        {
            (*pf)(_list[i]);
        }
        std::cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<std::endl;
    }

    ~List(){};
};

#endif
