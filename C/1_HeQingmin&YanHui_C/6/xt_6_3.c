# include<stdio.h>
# include<math.h>



int main(void)
{
    int res,num;
    char sym,ch;
   

    printf("please input the Expression :");


    res=getchar()-48;        //'1'的ASCII码是49。
    printf("%d\n",res);
    
    while((ch=getchar())!='='){
        printf("%c__",ch);
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')sym=ch;
        printf("%c__",sym);
        if(ch>='0'&&ch<='9'){ch-=48;
            if(sym=='+')res+=ch;
            if(sym=='-')res-=ch;
            if(sym=='*')res*=ch;
            if(sym=='/')res/=ch;
        }
        printf("%d\n",res);
    }


    printf("the res is :%d\n",res);

    return 0;
}

