// 分别用数组和指针来计算10个整数的和

# include<stdio.h>
# include<math.h>


void reverse(int a[],int n);

int main(void)
{
    int i,a[10],n;

    printf("enter n:");
    scanf("%d",&n);

    printf("please %d numbers :",n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);

    reverse(a,n);

    for(i=0;i<n;i++)printf("%-3d",a[i]);
    printf("\n");
    return 0;
}


void reverse(int a[],int n)
{
    int i,j,temp;
    for(i=0,j=n-1;i<j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}