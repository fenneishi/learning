
/*
有n个人围成一圈，按照顺序从1到n做好编号。从第一个人开始报数，报道m的人退出圈子.如此下去，知道最后一个人。编写程序，输入整数n和m,
并按照退出顺序输出退出圈子人编号。

这个程序充分体现了指针的一些思想，同时也牵扯到数据结构与算法设计的一些东西，程序本身还要很多优化空间。
*/

#include <stdio.h> 


int *move_p(int *p,int size,int m,int arry[]);
int *del_one(int *p,int size,int array[]);

int main(void)
{

    int array[100];
    int size;
    int m,n; 
    int i;
    int *p=array;


    printf("input n:");
    scanf("%d",&n);
    printf("input m:");
    scanf("%d",&m);


    for(i=0;i<n;i++)array[i]=i+1;

    


    for(size=n;size>0;size--)
    {
        for(i=0;i<size;i++)printf("%-3d",array[i]);
        printf("size is %4d   ",size);
        p=move_p(p,size,m,array);
        printf("the point is %d   ",*p);
        p=del_one(p,size,array);
        printf("the point(after dellect) is %d   \n",*p);
    }
    
    return 0;
}



int *move_p(int *p,int size,int m,int arry[])
{
    int *arry_star_addr=arry;
    int *arry_end_addr=arry+(size-1);

    if(size<=1)p=p;
    else
    {
        if(p+(m-1)<=arry_end_addr)p+=m-1;
        else p=p+(m-1)-size;
    }
    
    return p;
}


int *del_one(int *p,int size,int arry[])
{
    int *arry_star_addr=arry;
    int *arry_end_addr=arry+(size-1);
    
    int *i=p;
    printf("dellect one is : %d \n",*i);

    if(size<=2)
    {
        p--;
    }
    else
    {
        for(i=p;i<=(arry_end_addr-1);i++)
        {
            *i=*(i+1);
        }
    }

    return p;
    
}
