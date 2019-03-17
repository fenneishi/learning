// 冒泡排序法，利用动态内存分配；

# include<stdio.h>
# include<stdlib.h>


void bubble(int a[],int n);


int main(void)
{
    int n;
    int i;
    int *p;
    
    printf("please input n(<=8):");
    scanf("%d",&n);

    if(      ( p=(int *)malloc(n*sizeof(int)) ) ==NULL       )
    {
        printf("Not able to allocate memory.\n");
        exit(1);
    }


    printf("please input a[%d]",n);
    for(i=0;i<n;i++)scanf("%d",p+i);
    bubble(p,n);
    for(i=0;i<n;i++)printf("%3d",*(p+i));
    printf("\n");

    return 0;
}

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
