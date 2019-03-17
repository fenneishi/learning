# include<stdio.h>
# include<math.h>


int main(void)
{
    int n;
    //循环始值
    do{
        printf("please input the number(must≠0):");
        scanf("%d",&n);
    }
    while(n==0);
    if (n<0){n=-n;printf("-");}

    do { 
        printf("%d",n%10);//循环体
        n=n/10;//循环前进
    }
    while(n!=0);//循环条件
   
   printf("\n");
    
    return 0;
}


