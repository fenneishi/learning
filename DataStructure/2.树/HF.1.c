/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define weight_max 10000;
#define MaxSize 100;

typedef int weight_type;

typedef struct HuffManTree
{
    weight_type weight;
    struct HuffManTree *left,*right;
}hf;

typedef struct Heap
{
    hf* *elements;
    ;
    int capacity;
}min_heap;



min_heap *initialize_min_heap();
min_heap *creat_min_heap();
min_heap *heap_insert(hf *node,min_heap *heap);
int main(void)
{
    int a;
    a=(int)malloc(10*sizeof(int));
    return 0;
}

min_heap *initialize_min_heap()
{
    min_heap *node;//申请一块指针大小的空间，命名node,node未来指向的地址的数据类型为min_heap
    node=(min_heap *)malloc(sizeof(min_heap));//申请一块能装下min_heap类型数据的空间，并让node指向这块空间。
        if(node==NULL){printf("no more memory for heap!\n");return  NULL;}
    node->elements=(hf **)malloc(sizeof(hf*)*(MaxSize+1));
        if(node->elements==NULL){printf("no more memory for heap!\n");return  NULL;}
    node->elements[0]=(hf *)malloc(sizeof(hf));
        if(node->elements[0]==NULL){printf("no more memory for heap!\n");return  NULL;}
    node->elements[0]->weight=weight_max;
    return node;
}


min_heap *creat_min_heap()
{
    min_heap *heap;
    int weight=1000,i=0;
    hf *node;
    heap=initialize_min_heap();
    do
    {
        i++;
        //creat a new node;
        node=(hf *)malloc(sizeof(hf));
        if(node==NULL){printf("no memory for heap!\n");return heap;}
        printf("input the %d weight,quite input 0!\n",i);
        scanf("%d",&weight);
        node->weight=weight;
        node->left=node->right=NULL;
        //insert the new node in the heap;
        heap=heap_insert(node,heap);
    }while(weight>0);
}

min_heap *heap_insert(hf *node,min_heap *heap)
{
    *((heap->elements+1))=(hf *)malloc(sizeof(hf));
    heap->size++;

}
