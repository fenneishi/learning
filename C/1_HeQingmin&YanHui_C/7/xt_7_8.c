
// 字符串逆序输出（回车结束的，来自用户输入）

# include<stdio.h>
# include<math.h>




int main(void)
{
    /////////////////////////////////////////////
    const int magicNumber='A'+'Z';
    int i;
    char str[80];
    ////////从用户处获得字符串(用回车结束标志的)//////
    printf("please input the strings:");
    i = 0;
    while ((str[i++] = getchar()) != '\n');
    str[--i] = '\0';
    ///////////////////////////////////////////
    for (i = 0; str[i] != '\0'; i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=magicNumber-str[i];
        }
    }
    ///////////////////////////////////////////
    printf("%s\n",str);
    ///////////////////////////////////////////
    for (i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
    return 0;
}

