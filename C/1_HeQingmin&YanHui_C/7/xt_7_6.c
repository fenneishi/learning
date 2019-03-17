
// 字符串逆序输出（回车结束的，来自用户输入）

# include<stdio.h>
# include<math.h>

int main(void)
{
    int i,j;
    char str[80];
    char temp;
    
    printf("please input the strings:");


    // 从用户处获得字符串(用回车结束标志的)
    i = 0;
    while((str[i++] = getchar( )) != '\n');
    str[--i] = '\0';

    j=i-1;
    for(i=0;i<j;(i++,j--))
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }

    for(i=0;str[i] !='\0';i++)putchar(str[i]);
    putchar('\n');
    return 0;
}




int way2(void)
{
    int i, k, temp;
    char str[80];

    printf("Input a string: ");
    i = 0;
    while ((str[i] = getchar()) != '\n')
        i++;
    str[i] = '\0';
    
    k = i - 1;
    for (i = 0; i < k; i++)
    {
        temp = str[i];
        str[i] = str[k];
        str[k] = temp;
        k--;
    }
    for (i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    return 0;
}
