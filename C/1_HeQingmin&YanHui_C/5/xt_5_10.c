# include<stdio.h>
# include<math.h>

int reverse(int number);
int main(void)
{
    int number;

    printf("please input the number:");
    scanf("%d",&number);
    
    printf("%d",reverse(number));
  

    printf("\n");
    return 0;
}

int reverse(int number){     
   int number_back;
   
   number_back = 0;
   while(number>0){
       number_back=number_back*10+number%10;
       number=number/10;
   }

   return number_back;
}


