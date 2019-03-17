# include<stdio.h>
# include<math.h>


int main(void)
{
    int num,back;
    printf("please input the number:");
    scanf("%d",&num);

    back = 0;

    while(num>0){
        back=back*10+num%10;
        num=num/10;
    } 
    

    while(back>0){
        printf("%d ",back%10);
        back=back/10;
    }

    printf("\n");

    return 0;
}


