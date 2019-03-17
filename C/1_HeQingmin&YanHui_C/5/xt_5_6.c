# include<stdio.h>
# include<math.h>


int countdigit(int number,int digit);

int main(void)
{
    int number,digit;
    int i;
    long double sum;

    printf("please input number:");
    scanf("%d",&number);
    printf("please input digit:");
    scanf("%d",&digit);

    printf(" the count of %d in %d is :%d\n",digit,number,countdigit(number,digit));

    return 0;
}

int countdigit(int number,int digit){     
    int i,count;
    count = 0;
    while(number>0){
        if(number%10==digit)count++;
        number=number/10;
    }
    return count;
}
