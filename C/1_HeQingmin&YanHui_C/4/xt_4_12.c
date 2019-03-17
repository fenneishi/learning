# include<stdio.h>
# include<math.h>



int main(void)
{
    double s_down,s_up;
    int count_down,count_up;

    count_down=1;
    s_down = 10;
    printf    ("count_down:%2d   high:%.2f\n",count_down,s_down);
    count_up =0;
    while(s_down>0.01){
        count_up++;
        s_up = s_down/2;
        printf("count_up:%4d   high:%.2f\n",count_up,s_up);
        count_down++;
        s_down=s_up;
        printf("count_down:%2d   high:%.2f\n",count_down,s_down);
    }


    return 0;
}

