


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define Error -1

typedef struct Node
{
    int Data;
    struct Node *next;
}stack;

stack *CreateStack();
void push(int x,stack *top);
int pop(stack *top);

int main(void)
{
    
    return 0;
}


stack *CreateStack()
{
    return NULL;
}

void push(int x,stack *top)
{
    stack *Node;
    //Creat a Node
    Node=(stack *)malloc(sizeof(stack));
    Node->Data=x;
    Node->next=NULL;
    //push the Node
    Node->next=top;
    top=Node;
}

int pop(stack *top)
{   
    stack *SecondNode;
    int TopData;
    //Stack is Empty----return Error;
    if(top==NULL){printf("stack is Empty\n");return Error;}
    //Stack is not Empty--->pop first Node;
    TopData=top->Data;
    SecondNode=top;
    free(top);
    top=SecondNode;
    return TopData;
}



