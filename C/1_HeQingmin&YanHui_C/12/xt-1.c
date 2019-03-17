/*
统计文本文件中字母、数字、其他字符各有多少？
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int judge_num(char);
int judge_char(char);


int main(int argc, char const *argv[])
{
    FILE *fp;
    int ch;
    int count_num,count_char,count_other;
    count_num=count_char=count_other=0;
    if((fp=fopen("xt-1.txt","r"))==NULL)
    {
        printf("open file error!\n");
        exit(0);
    }
    while(!feof(fp))
    {
        ch=fgetc(fp);
        if(ch==-1)break;       // 这里面最大的问题是为什么最后结束的这个-1还是会被读取进来。
        printf("==%c:%d==",ch,ch);
        if(judge_num(ch)==1)count_num++;
        else if(judge_char(ch)==1)count_char++;
        else count_other++;
    }

    printf("the count of num is:%d\n",count_num);
    printf("the count of char is:%d\n",count_char);
    printf("the count of other is:%d\n",count_other);

    if(fclose(fp))
    {
        printf("close file error!\n");
        exit(0);
    }
    /* code */
    return 0;
}


int judge_num(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))return 1;
    return 0;
}
int judge_char(char ch)
{
    if(ch>='0'&&ch<='9')return 1;
    return 0;
}