
/*
数字排序
*/

#include <stdio.h> 


int search(int list[],int n,int x);
void bubble(int a[],int n);

int main(void)
{
    int i;
    int list[10] ;
    int x;
    int res;

    printf("input 10 numbers :");
    for(i=0;i<=9;i++)scanf("%d",&list[i]);
    printf("input x:");
    scanf("%d",&x);

    bubble(list,10);
    res=search(list,10,x);
    switch(res)
    {
        case -1:printf("can not find %d in list\n",x);break;
        default :printf("the i is :%d\n",res);break;
    }

    return 0;
}

// 折半查找;
int search(int list[],int n,int x)
{
    int j;
    int i;
    int right=n-1,left=0;
    int mid=(left+right)/2;
    

    while (left<right && list[mid] != x)
    {
        if(list[mid]<x) left = mid+1;
        if(list[mid]>x) right= mid;
        mid = (left+right)/2;
    }

    if(list[mid]== x) i=mid;
    else if(left<right) i= -1;

    return i;
}

// 冒泡排序
void bubble(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

}



// int binary(int *a, int key, int n)
// {
//     int left = 0, right = n - 1, mid = 0;
//     mid = (left + right) / 2;
//     while (left < right && a[mid] != key)
//     {
//         if (a[mid] < key)
//         {
//             left = mid + 1;
//         }
//         else if (a[mid] > key)
//         {
//             right = mid;
//         }
//         mid = (left + right) / 2;
//     }
//     if (a[mid] == key)
//         return mid;
//     return -1;
// }