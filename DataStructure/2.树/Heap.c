/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define max_data 1000
#define Error  -1
typedef int elment_type;


typedef struct heapsort
{
    elment_type *elements;
    int size;
    int capacity;
}max_heap;

max_heap *creat(int max_size);
void insert(elment_type x,max_heap *heap);
elment_type delete(max_heap *heap);
int is_full(max_heap *heap);

int main(void)
{
    
    return 0;
}

// 创建容量为max_size空的堆。
max_heap *creat(int max_size)
{
    max_heap *heap;
    heap=(max_heap*)malloc(sizeof(max_heap));
    heap->elements=(elment_type *)malloc(sizeof(elment_type)*(max_size+1));
    heap->size=0;
    heap->capacity=max_size;
    heap->elements[0]=max_data;
}



void insert(elment_type x,max_heap *heap)
{
    int i;
    if(heap==NULL||heap->elements==NULL){printf("is wrong,do not creat heap!\n");return;}
    if(heap->size==0){heap->elements[1]=x;return;}
    if(heap->size==heap->capacity-1){printf("the heap is full!\n");return;}
    heap->size++;i=heap->size;
    for(;heap->elements[i/2]<x;i=i/2)heap->elements[i]=heap->elements[i/2];
    heap->elements[i]=x;
}


elment_type delete(max_heap *heap)
{
    int i;
    elment_type res;
    elment_type temp;
    
    if(heap==NULL||heap->elements==NULL){printf("is wrong,do not creat heap!\n");return Error;}
    if(heap->size==0){printf("the heap is empty!\n");return Error;}
    
    
    //调整成max heap
    res=heap->elements[1];// 暂存首个元素。
    heap->size--;//整体的size减1.必须先减一才能进入循环。
    for(i=1;2*i<=heap->size;)//不断的指向孩子节点，直到没有孩子的节点退出。
    {
        if((2*i+1)>heap->size)
            i=2*i;//只有一个左孩子，则指向左孩子
        else 
            i=heap->elements[2*i]>heap->elements[2*i+1]?
                2*i:
                2*i+1;//有两个孩子，则指向最大的那个孩子
        heap->elements[i/2]=heap->elements[i];//父亲的值等于孩子的值。
    }
    heap->elements[i]=heap->elements[heap->size];//把最后一个节点复制循环退出的位置
    

    
    return res;
}

