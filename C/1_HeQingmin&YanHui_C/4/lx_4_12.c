# include<stdio.h>
# include<math.h>


int main(void)
{
    int min,max;
    int count,res,i;  // 外层循环涉及变量
    int j;              // 内存循环涉及变量

    printf("please input the min number :");
    scanf("%d",&min);
    printf("please input the max number :");
    scanf("%d",&max);
    printf("================================================================\n");

    count=0;
    for(i=min;i<=max;i++){

        //内层循环判断是否为质数，是的话，res=1,否则，res=0
        if(i<=0)res=0;
        else{
            for(j=2;j<=i/2.0;j++)if(i%j==0)break;
            if(j>i/2&&i!=1)res=1;
            else res=0;
        }


        if(res==1){count++;printf("%d ",i);if(count%8==0)printf("\n");}
    }
    printf("\n");

    
    return 0;
}
