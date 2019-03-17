/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define Error -1

typedef struct Node
{   
    int data;
    struct Node *next;
}Qnode;

typedef struct 
{
    Qnode *front;
    Qnode *end;
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
    que->front=NULL;
    que->end=NULL;
    return que;
}

void add(int x,Queue *que)
{
    Qnode *NewNode;
    NewNode=(Qnode *)malloc(sizeof(Qnode));
    NewNode->data=x;
    NewNode->next=NULL;
    // Empty
    if(que->front==NULL){que->front=que->end=NewNode;return;};
    // not empty
    que->front->next=NewNode;
    que->front=NewNode;//be careful: do not forget this step
}

int delete(Queue *que)
{
    int FirstNodeData;
    Qnode *SecondNode;
    //empty
    if(que->front==NULL){printf("the queue is empty!\n");return Error;}
    //count=1
    if(que->front==que->end)
    {
        FirstNodeData=que->front->data;
        free(que->front);
        que->front=que->end=NULL;
        return FirstNodeData;
    }
    // count>=2
    FirstNodeData=que->front->data;
    SecondNode=que->front->next;
    free(que->front);
    que->front=SecondNode;
    return FirstNodeData;
}