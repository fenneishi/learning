# include<stdio.h>
# include<math.h>



int main(void)
{
    int i;
    char num,enter;

    


    for (i=1;i<=3;i++){
        num = '1';
        printf("[1]apples\n[2]pears\n[3]oranges\n[0]Exit\nplease input number:\n");
        
        num = getchar(); //getchar 是获取键盘的输入，所以当你输入一个字符并敲击回车时候，回车会被下一个getchar获取到。
        enter = getchar();
       
        if(num=='0'){break;}
        switch(num){
            case 'a': printf("the price is ￥1.00\n");break;
            case '2': printf("the price is ￥2.00\n");break;
            case '3': printf("the price is ￥3.00\n");break;
            case '4': printf("the price is ￥4.00\n");break;
            default:  printf("input wrong! \n");      break;
        } 
        printf("\n");
    }
    

    return 0;
}

