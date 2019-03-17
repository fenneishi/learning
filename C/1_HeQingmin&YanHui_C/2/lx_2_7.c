# include<stdio.h>
# include<math.h>

int main(void)
{
   int money,year;
   double rate,sum;

//    printf("please input money,year,rate\n");
   printf("please input money,rate,year\n");
//    scanf("%d%d%lf",&money,&year,&rate);
   scanf("%d%lf%d",&money,&rate,&year);

   sum = money*pow(1+rate,year);

   printf("sum=%.2f\n",sum);

}