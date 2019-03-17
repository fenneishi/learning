# include<stdio.h>
# include<math.h>

int factorsum(int n);
int main(void)
{
    int max,min;
    int i;

    printf("please input min:");
    scanf("%d",&min);
    printf("please input max:");
    scanf("%d",&max);

    for(i=min;i<=max;i++){
        if(factorsum(i)==i)printf("%d ",i);
    }
    printf("\n");
    
    return 0;
}

int factorsum(int n){     
   int i,sum;

   sum = 0;

   for(i=1;i<=n/2;i++){
       if(n%i==0)sum+=i;
   }

   return sum;
}
