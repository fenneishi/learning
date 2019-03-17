# include<stdio.h>
# include<math.h>


int main(void)
{
    int count,n_1,n_2,n_5,i,j;

    count = 0;
    for(n_5=1;n_5<=20;n_5++){
        for(n_2=1;n_2<=50;n_2++){
            for(n_1=1;n_1<=100;n_1++){
                if(1*n_1+2*n_2+5*n_5==100){
                    count++;
                    printf("%03d: 1分=%2d个  2分=%2d个  5分=%2d个\n",count,n_1,n_2,n_5);
                }
            }
        }
    }
    


    return 0;
}
