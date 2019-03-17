# include<stdio.h>
# include<math.h>



int main(void)
{
    int i,n,grade,sum,goodnumber;
    double aveg;

    printf("please input n:");
    scanf("%d",&n);

    sum = 0;
    goodnumber=0;
    for(i=1;i<=n;i++){
        printf("please input %d student grade:",i);
        scanf("%d",&grade);
        sum = sum +grade;
        if(grade>=60){goodnumber++;}

    }

    printf("the average grade of students is : %.2f \n",(sum*1.0)/n);
    printf("the good students number is : %d \n",goodnumber);

    

    return 0;
}

