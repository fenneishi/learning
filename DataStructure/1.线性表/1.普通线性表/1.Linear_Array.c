


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
//define new struct :Link
#define MAXSIZE 100//the maxsize of the array;
typedef struct 
{
    int Data[MAXSIZE];
    int Last;
}List;
// Function declaration
List *MakeEmpty();//make an empty link list;
int FindKth(int K, List *PtrL);//Return the element contents according to the ordinal K; 
int Find(int X, List *PtrL);//find the first location of X 
void Insert(int X, int i, List *PtrL);//Insert a new element X between i-1 and i
void Add(int X,List *PtrL);//add a new element X at the end
void Delete(int i,List *PtrL);//delete the specifies element i
int Length(List *PtrL);//return the length of link list


//主函数
int main(void)
{
    
    return 0;
}

//初始化一个空线性表L;
List *MakeEmpty()
{
    List *PtrL;//定义指向List类型的指针，
    PtrL=(List *)malloc(sizeof(List));
    PtrL->Last=-1; // 没有元素，所以最后一个值为-1；
    return PtrL;
}
//根据位序K，返回相应元素 ; 找到返回元素值，没找到，返回-1。
int FindKth(int K, List *PtrL)
{
    int res,Max;
    K--;
    if(K>(Length(PtrL)-1))res=-1;// 超出范围，算作没有找到，返回-1；
    else res=PtrL->Data[K];
    return res;
}
//在线性表L中查找X的第一次出现位置，找到返回序号(存储位置)，没有，返回-1.
int Find(int X, List *PtrL )
{
   int i,res=-1;
   for(i=0;i<=PtrL->Last;i++)
   {
       if(PtrL->Data[i]==X){res=i;break;}
   }
   return res+1;//find return i;not return -1;
}
//返回线性表L的长度n
int Length(List *PtrL)
{
    return PtrL->Last+1;
}
//在位序i-1和i之间插入一个新元素X，首元素从0开始
void Insert(int X, int i, List *PtrL)
{
    int j;
    i--;
    //检查插入位置合法性
    if(i<0||i>PtrL->Last){printf("插入位置不合法！\n");return;}
    // 排除空间已经满了的情况。
    if(PtrL->Last==(MAXSIZE-1)){printf("空间已经满了，无法插入\n");return;}
    // 把i之后的元素移位
    for(j=PtrL->Last;j>=i;j--)PtrL->Data[j+1]=PtrL->Data[j];
    // 更新Last的值
    PtrL->Last++;
    // 插入元素x.
    PtrL->Data[i]=X;
}
//在末尾添加一个新元素X。
void Add(int X,List *PtrL)
{
    // 排除空间已经满了的情况。
    if(PtrL->Last>=(MAXSIZE-1)){printf("空间已经满了，无法插入\n");return;}
    // 更新Last的值
    PtrL->Last++;
    // 插入元素x.
    PtrL->Data[PtrL->Last]=X;

}
//删除指定位序i的元素;
void Delete(int i,List *PtrL)
{
    int j;
    i--;
    //排除空表，检查删除位置合法性
    if(i<0||i>(Length(PtrL)-1)){printf("超出范围\n");return;}
    //把i及其之后的 数据向前移位1，完成删除操作。
    for(j=i;j<=PtrL->Last-1;j++)PtrL->Data[j]=PtrL->Data[j+1];
    //更新last的值
    PtrL->Last--;
}


