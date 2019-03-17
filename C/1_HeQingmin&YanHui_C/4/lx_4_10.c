# include<stdio.h>
# include<math.h>


int main(void)
{
    int n,i,num,min;
    //获得循环次数
    do{
        printf("please input the count(must>0) of number :");
        scanf("%d",&n);
    }
    while(n<=0);
    
    
    //赋初始值
    printf("please input the 1 number:");
    scanf("%d",&num);
    min = num;
    i=2;

    do { 
        printf("please input the %d number:",i);
        scanf("%d",&num);
        if (num<min) min=num;
        i++;
        }
    while(i<=n);
   
    printf("the min number is %d\n",min);
    
    return 0;
}

