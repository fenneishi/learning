# include<stdio.h>
# include<math.h>


int fib(int n);

int main(void)
{
    int max,min;
    int i;

    printf("please input min:");
    scanf("%d",&min);
    printf("please input max:");
    scanf("%d",&max);

    i=1;
    while(fib(i)<=max){
        if(fib(i)>=min)printf("%d ",fib(i));
        i++;
    }

    printf("\n");
    
    return 0;
}

int fib(int n){     
    int i,fib_a,fib_b,fib_c;
    
    if(n<=2)return 1;

    fib_a=1;
    fib_b=1;
    for(i=3;i<=n;i++){
        fib_c = fib_a+fib_b;
        fib_a=fib_b;
        fib_b=fib_c;
    }

    return fib_c;
}
