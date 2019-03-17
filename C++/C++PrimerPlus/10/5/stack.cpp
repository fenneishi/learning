
# include "stack.h"

double Stack::_totalPayment=0;

bool Stack::isEmpty() const
{
    return _top==0;
}
bool Stack::isFull() const
{
    return _top==MAX;//不同于const static变量，这里不用加域解析
}
bool Stack::push(const Item &item)//if stack is full,return false.
{
    if(_top==MAX)return false;
    _items[_top++]=item;//注意：这里发生了拷贝构造。
    return true;
}
bool Stack::pop(Item &item)// if stack is empty,return false.
{
    if(_top==0)return false;
    item=_items[--_top];
    _totalPayment+=item.getPayment();
    return true;
}



