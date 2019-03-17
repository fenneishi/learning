# include<stdio.h>
# include<math.h>



int main(void)
{
    int i;
    char cha;

    printf("please input a or b or c or d or e\n");
    cha = getchar();
    switch(cha){
        case 'a':case 'A': printf("the number is 90~100\n");break;
        case 'b':case 'B': printf("the number is 80~90\n");break;
        case 'c':case 'C': printf("the number is 70~80\n");break;
        case 'd':case 'D': printf("the number is 60~70\n");break;
        case 'e':case 'E': printf("the number is 0~60\n");break;
        default:         printf("input wrong! \n");break;
    }

    return 0;
}

