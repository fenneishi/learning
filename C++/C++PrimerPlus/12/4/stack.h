


#if !defined(STACK_H_)
#define STACK_H_

#include<iostream>
#include<cstring>
using namespace std; 

typedef int Item;

class Stack
{
private:
    enum{MAX=10};
    Item *pitems;
    int size;
    int top;
public:
    Stack(int n=MAX);
    Stack(const Stack & st);
    bool isEmpty()const;
    bool isFull()const;
    bool push(Item const & item);
    bool pop(Item & item);


    Stack& operator=(Stack & st);
    friend ostream& operator<<(ostream &os,const Stack &st);

    ~Stack();
};




#endif // Stack_H_
