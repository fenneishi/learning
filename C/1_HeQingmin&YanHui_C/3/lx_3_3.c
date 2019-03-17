# include<stdio.h>
# include<math.h>



int main(void)
{
    int eng,num,space,enter,other,i;
    char ch;

    printf("please input 10 char:");

    eng=0;
    num=0;
    space=0;
    enter=0;
    other=0;

    for(i=1;i<=10;i++){
        ch=getchar();
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){eng++;}
        else if(ch>='0'&&ch<='9'){num++;}
        else if(ch==' '){space++;}
        else if(ch=='\n'){enter++;}
        else{other++;}
    } 

    printf("eng=%d,num=%d,spcae=%d,enter=%d,other=%d \n",eng,num,space,enter,other);
    
    

    return 0;
}

