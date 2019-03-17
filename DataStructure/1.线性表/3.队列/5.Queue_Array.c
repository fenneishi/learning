/*
1、next one is :(front+1)%MaxSize or (end+1)%MaxSize<--------Cycle Queue
2、the max reaf content of queue is MaxSize-1
3、add function  make the number(end) +1
4、delete function make the numebr(front) +1
5、numer(front)=number(the first Node)-1
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define Error -1
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int end;
    int front;
}Queue;


Queue *CreatQueue();
void add(int x,Queue *que); 
int delete(Queue *que);


int main(void)
{
    
    return 0;
}

Queue *CreatQueue()
{
    Queue *que;
    que=(Queue *)malloc(sizeof(Queue));
    que->end=que->front=0;
    return que;
}


void add(int x,Queue *que)
{
    //Full
    if((que->end+1)%MaxSize==que->front){printf("Queue is Full\n");return;}
    //not full:add x
    que->data[que->end=(que->end+1)%MaxSize]=x;
}

int delete(Queue *que)
{
    //Empty
    if(que->front==que->end){printf("Queue is Empty!\n");return Error;}
    //not Empty:delete :
    return que->data[que->front=(que->front+1)%MaxSize];
    // be careful:numer(front)=number(the first Node)-1;
}