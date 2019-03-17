# include<stdio.h>
# include<math.h>


int main(void)
{
    int num,count,sum;
    printf("please input a int number: ");
    scanf("%d",&num);

    sum =0;
    count=0;
    if(num<0)num=-num;

    while(num>0){
        sum = sum + num%10;
        num= num/10;
        count++;
    }
   
    printf("the count of number is %d\nand the sum of number is %d\n",count,sum);

    return 0;
}
