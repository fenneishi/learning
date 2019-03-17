# include<stdio.h>
# include<math.h>


int prime(int m);
int main(void)
{
    int i,j,k,count;
    count=0;
    for(i=6;i<=100;i+=2){
            for(k=3;k<=i/2;k+=2){
                if(prime(k)&&prime(i-k)){
                    printf("%3d=%2d+%2d  ",i,k,i-k);
                    count++;
                    if(count%5==0&&count!=0)printf("\n");
                }
            }
    }
    
    printf("\n");
}




int prime(int m){
    int i;
    for(i=2;i<=m/2;i++){
        if(m%i==0)return 0;
    }
    return 1;
}