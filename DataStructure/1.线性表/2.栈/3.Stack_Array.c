


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MaxSize 10
#define Error -1

typedef struct  
{
    int Data[MaxSize];
    int top;
}stack;

stack *CreateStack();
void push(int x,stack *Ptrs);
int pop(stack *Ptrs);

int main(void)
{
    
    return 0;
}


stack *CreateStack()
{
    stack *Ptrs;
    Ptrs->top=0;
    return Ptrs;
}

void push(int x,stack *Ptrs)
{
    if(Ptrs->top==MaxSize)
    {printf("stack is full\n");return;}
    Ptrs->top++;
    Ptrs->Data[Ptrs->top]=x;
    return;
}

int pop(stack *Ptrs)
{
    if(Ptrs->top==0)
    {printf("stack is Empty\n");return Error;}
    return Ptrs->Data[Ptrs->top--];
}



