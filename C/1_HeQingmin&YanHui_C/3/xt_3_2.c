# include<stdio.h>
# include<math.h>



int main(void)
{
   int salary;
   double tax,rate,deduction;

   printf("please input your salary:");
   scanf("%d",&salary);

   if       (salary<=3500)                {rate=0;deduction=0;}
   else if  (3500<salary&&salary<=5000)   {rate=3.0/100;deduction=0;}
   else if  (5000<salary&&salary<=8000)   {rate=10.0/100;deduction=105;}
   else if  (8000<salary&&salary<=12500)  {rate=20.0/100;deduction=555;}
   else if  (12500<salary&&salary<=38500) {rate=25.0/100;deduction=1005;}
   else if  (38500<salary&&salary<=58500) {rate=30.0/100;deduction=2755;}
   else if  (58500<salary&&salary<=83500) {rate=35.0/100;deduction=5505;}
   else if  (83500<salary)                {rate=45.0/100;deduction=13505;}
   
   tax=rate*(salary-3500)-deduction;

   printf("your tax is %.2f\n",tax);

    return 0;
}

