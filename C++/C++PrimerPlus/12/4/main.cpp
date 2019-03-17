# include "stack.h"



int main(int argc, char const *argv[])
{
    Stack stack1;
    for(int i=0;i<10;i++)
    {
        stack1.push(i);
    }
    Stack stack2(stack1);
    Stack stack3=stack2;
    Stack stack4;
    stack4=stack3;
    cout<<stack1;
    cout<<stack2;
    cout<<stack3;
    cout<<stack4;
    cout<<"------------------------------"<<endl;





    Item temp;
    for(int i=0;i<3;i++)
    {
        stack1.pop(temp);
        stack2.pop(temp);
        stack3.pop(temp);
        stack4.pop(temp);
    }
    cout<<stack1;
    cout<<stack2;
    cout<<stack3;
    cout<<stack4;
    cout<<"------------------------------"<<endl;





    for(int i=0;i<3;i++)
    {
        stack1.pop(temp);
        stack2.pop(temp);
        stack3.pop(temp);
        stack4.pop(temp);
    }
    cout<<stack1;
    cout<<stack2;
    cout<<stack3;
    cout<<stack4;
    cout<<"------------------------------"<<endl;






    for(int i=0;i<3;i++)
    {
        stack1.pop(temp);
        stack2.pop(temp);
        stack3.pop(temp);
        stack4.pop(temp);
    }
    cout<<stack1;
    cout<<stack2;
    cout<<stack3;
    cout<<stack4;
    cout<<"------------------------------"<<endl;





    stack1.pop(temp);
    stack2.pop(temp);
    stack3.pop(temp);
    stack4.pop(temp);
    cout<<stack1;
    cout<<stack2;
    cout<<stack3;
    cout<<stack4;
    cout<<"------------------------------"<<endl;

    return 0;
}
