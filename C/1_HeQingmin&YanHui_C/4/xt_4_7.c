# include<stdio.h>
# include<math.h>


int main(void)
{
    int n,sum,i,count,reset;
    count = 0;
    for(n=1;n<=1000000;n++){

        sum=0;
        reset = n;
        while(n>0){
            sum = sum +pow(n%10,3);
            n=n/10;
        }
        n= reset;

        
        if(sum==n){
            count++;
            printf("%d:%d\n",count,n);
        
        }
    }

    
    


    return 0;
}
