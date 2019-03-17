# include<stdio.h>
# include<math.h>



int main(void)
{
    int year; 
    
    printf("please input year:");
    scanf("%d",&year);
   
    if(year<0){printf("input wrong,year must >0\n");}
    else if((year%4==0&&year%100!=0)||(year%400==0)){printf("%d is run year\n",year);}
    else{printf("%d is not run year\n",year);}
    
    return 0;
}

