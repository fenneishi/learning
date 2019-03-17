# include<stdio.h>
# include<math.h>


int even(int x);

int main(void)
{
    int x,sum;
    
    
    printf("please input x:");
    scanf("%d",&x);
    sum=0;
    while(x>0){
        if(even(x)==1)sum+=x;
        printf("please input x:");
        scanf("%d",&x);
    }
    


    printf("the sum is : %d\n",sum);
    return 0;
}

int even(int x){                  
    if(x%2==0)return 1;
    return 0;
}
