# include<stdio.h>
# include<math.h>



int main(void)
{
   int eng,spa,num,other;
   char ch;
   
   
   eng=spa=num=other=0;

   printf("please input the some word:");


   while((ch=getchar())!='&'){
       if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')eng++;
       else if(ch==' ')spa++;
       else if(ch>='0'&&ch<='9')num++;
       else other++;
   }

   printf("eng=%d,spa=%d,num=%d,other=%d\n",eng,spa,num,other);

    return 0;
}

