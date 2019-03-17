# include<stdio.h>
# include<math.h>


int main(void)
{
    int n,i,j;
    int prime(int m);
    for(n=10000;n<=10002;n+=2){
        for(i=2;i<n;i++){
            for(j=2;j<n;j++){
                if( i+j==n && prime(i) && prime(j) )printf("%03d=%02d+%02d \n",n,i,j);
            }
        }
    printf("\n");
    }
    


    return 0;
}


int prime(int m){

    int i;
    if(m<=0)return 0;
    else{
        for(i=2;i<=m/2.0;i++)if(m%i==0)break;
        if(i>m/2&&m!=1)return 1;
        else return 0;
    }
    
    return 0;
}