
// 任意进制转换

# include<stdio.h>
# include<math.h>




int main(void)
{
    /////////////////////////////////////////////
    int sys,num;
    int rem[100];
    int i,j,k;
    ////////////////////////////////////////////
    printf("please input the number:");
    scanf("%d",&num);
    printf("please input the system:");
    scanf("%d",&sys);
    ///////////////////////////////////////////
    for (i=0;num!=0;i++)
    {
        rem[i]=num%sys;    // 注意这俩的位置不能放反了。
        num/=sys;
    }
    i--;
    ///////////////////////////////////////////
    for (k=i;k>=0;k--)
    {
       printf("%d",rem[k]);
    }
    printf("\n");
    return 0;
}

