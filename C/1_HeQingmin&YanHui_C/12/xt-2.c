/*
键盘输入一批实数，间隔用空格分隔，将这些数据写到一个文本文件中。
如果数据之间用逗号分隔，应该如何修改程序？
写入的文本文件内容又有什么不同？
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



int main(int argc, char const *argv[])
{
    FILE *fp;
    int count,i;
    double num;
    if((fp=fopen("xt-2.txt","w"))==NULL)
    {
        printf("can not open file!\n");
        exit(0);
    }
    printf("input the count of nums:");
    scanf("%d",&count);
    printf("input the nums:");
    for(i=1;i<=count;i++)
    {
        scanf("%lf",&num);
        fprintf(fp,"%.2f,",num);
    }
    if(fclose(fp))
    {
        printf("can not close file!\n");
        exit(0);
    }
    return 0;
}


