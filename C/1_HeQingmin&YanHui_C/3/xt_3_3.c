# include<stdio.h>
# include<math.h>



int main(void)
{
    int t;
    double s,fee;

    printf("please input s:");
    scanf("%lf",&s);
    printf("please input t:");
    scanf("%d",&t);

    s=s+t/5.0;


   if       (s<=3.0)           fee=10;
   else if  (3.0<s&&s<=10.0)   fee=10+(s-3)*2;
   else if  (10.0<s)           fee=10+(10-3)*2+(s-10)*3;


   printf("your tax fee  is %.0f\n",fee);

    return 0;
}

