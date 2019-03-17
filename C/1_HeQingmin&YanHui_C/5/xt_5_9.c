# include<stdio.h>
# include<math.h>

int is(int n);
int main(void)
{
    int max,min;
    int i;

    printf("please input min:");
    scanf("%d",&min);
    printf("please input max:");
    scanf("%d",&max);

    for(i=min;i<=max;i++){
        if(is(i)==i)printf("%d ",i);
    }
    printf("\n");
    
    return 0;
}

int is(int n){     
   int sum;
   sum = 0;
   while(n>0){
       sum+=pow(n%10,3);
       n=n/10;
   }
   return sum;
}
