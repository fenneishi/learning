
// 字符串逆序输出（回车结束的，来自用户输入）

# include<stdio.h>
# include<math.h>

int main(void)
{
    /////////////////////////////////////////////
    int i, count;
    char str[80];
    ////////从用户处获得字符串(用回车结束标志的)//////
    printf("please input the strings:");
    i = 0;
    while ((str[i++] = getchar()) != '\n');
    str[--i] = '\0';
    ///////////////////////////////////////////
    count=0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            switch(str[i])
            {
                case 'A':break;
                case 'E':break;
                case 'I':break;
                case 'O':break;
                case 'U':break;
                default:count++;
            }
        }
    }
    ///////////////////////////////////////////
    printf("the count is %d",count);
    // putchar((char)count);
    putchar('\n');
    return 0;
}


int way2(void)
{
    int count, i;
    char ch, str[80];
    printf("Input a string: ");
    i = 0;
    while ((ch = getchar()) != '\n')
    {
        str[i++] = ch;
    }
    str[i] = '\0';
    count = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] <= 'Z' && str[i] > 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
            count++;
    printf("count = %d\n", count);
    return 0;
}
