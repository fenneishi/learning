# include<stdio.h>
# include<math.h>



int main(void)
{
    int num[10][10];
    int i,j,n;
    

    
    
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            num[i][j]=i*j;
        }
    }

    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            if(i>=j)printf("%d*%d=%2d  ",i,j,num[i][j]);
        }
        printf("\n");
    }
    


    
    

 
    return 0;
}