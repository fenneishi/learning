# include<stdio.h>
# include<math.h>



int main(void)
{
    int i,n,grade,a_n,b_n,c_n,d_n,e_n;
    double sum,aver;

    printf("please input the amount of student:");
    scanf("%d",&n);

    sum=aver=a_n=b_n=c_n=d_n=e_n=0;

    for(i=1;i<=n;i++){

        printf("please input the %d student grade:",i);
        scanf("%d",&grade);

        if (grade>=0&&grade<=100){
            if      (90<=grade&&grade<=100) a_n++;
            else if (80<=grade&&grade<90)   b_n++;
            else if (70<=grade&&grade<80)   c_n++;
            else if (60<=grade&&grade<70)   d_n++;
            else if (0<=grade&&grade<60)    e_n++;
            sum = sum + grade;
        }
        else{printf("input wrong,please input again:\n");i--;}
    }

    printf("the average of students grade is %.2f\n",sum/n);
    
   
    printf("the amount of rank A is %d\n",a_n);
    printf("the amount of rank B is %d\n",b_n);
    printf("the amount of rank C is %d\n",c_n);
    printf("the amount of rank D is %d\n",d_n);
    printf("the amount of rank E is %d\n",e_n);


    return 0;
}

