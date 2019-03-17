# include "stack.h"

Stack::Stack(int n)
{
    pitems=new Item[MAX];
    size=0;
    top=-1;
}
//强调空间概念，内存上的样子，逻辑上的样子，例如整个栈的样子
Stack::Stack(const Stack & st)//脑中要有那种内存的构建概念，构造函数大括号执行前，就已经给*this分配了空间，然后你要做的是，符合合理的在这些空间上填充合适的值。
{
    pitems=new Item[st.size];
    for(int i=0;i<st.size;i++)
        pitems[i]=st.pitems[i];
    size=st.size;
    top=st.top;
}
bool Stack::isEmpty()const
{
    return size==0;
}
bool Stack::isFull()const
{
    return size==MAX;
}
bool Stack::push(Item const & item)
{
    if(isFull())
        return false;
    else
    {
        pitems[++top]=item;
        size++;
        return true;
    }
}
bool Stack::pop(Item & item)
{
    if(isEmpty())
        return false;
    else
    {
        item=pitems[top--];
        size--;
        return true;
    }
}
Stack& Stack::operator=(Stack & st) //拷贝构造一定不能emplicit
{
    if(this==&st)
        return *this;
    else
    {
        delete[] pitems;
        pitems=new Item[st.size];
        for(int i=0;i<st.size;i++)
            pitems[i]=st.pitems[i];
        size=st.size;
        top=st.top;
        return *this;
    }
}

ostream & operator<<(ostream & os,Stack const  &st)
{
    for(int i=0;i<10;i++)
        os<<st.pitems[i]<<"-";
    os<<endl;
    return os;
}

Stack::~Stack()
{
    delete[] pitems;
}


//脑中要有空间感，内存，代码逻辑，这个空间感要完善，当然代码基本东西要熟悉，这时候代码就像是在说话打字一样自然。