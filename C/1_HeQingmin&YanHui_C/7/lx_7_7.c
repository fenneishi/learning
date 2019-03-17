# include<stdio.h>
# include<math.h>


int main(void)
{
    int num[6][6];
    int i,j,n;
    int sum=0;

    printf("please intput n:");
    scanf("%d",&n);
    printf("please input the numbers:");


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&num[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i+j)!=(n-1)&&i!=(n-1)&&j!=(n-1))sum+=num[i][j];
        }
    }

    printf("the sum is %d\n",sum);
    


    
    

 
    return 0;
}