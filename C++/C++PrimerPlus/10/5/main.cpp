
# include "stack.h"
# include <iostream>

int main(int argc, char const *argv[])
{
    Stack oldCusStack;
    Stack newCusStack;

    oldCusStack.push(Customer("customer_1",10));
    oldCusStack.push(Customer("customer_2",20));
    oldCusStack.push(Customer("customer_3",30));
    
    for(int i=1;i<=3;i++)
    {
        Customer temp;
        oldCusStack.pop(temp);
        newCusStack.push(temp);
    }

    oldCusStack.showTotalPayment();


    return 0;
}
