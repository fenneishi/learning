# include<stdio.h>
# include<math.h>



int main(void)
{
    int count,num;
    double grade,total;

    num=total=count=0;

    printf("Enter grades:");
    scanf("%lf",&grade);

    while(grade>=0){
        total=total+grade;
        num++;
        if(grade<60)count++;
        scanf("%lf",&grade);
    }
    if(num!=0)printf("Grade average is %.2f\nNumber of failures is %d\n",total/num,count);
    else printf("Grade average is 0\n");

    return 0;
}

