/*
比较两文本文件的内容是否相同，并输出两文件内容首次出现不同的行号和字符位置
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

FILE *OpenFile(char *filename,char *model);
void CloseFile(FILE *);

int main(int argc, char const *argv[])
{
    FILE *fp1,*fp2;
    int enter_count=0,char_count=0;
    char temp1,temp2;
    fp1=OpenFile("xt-3-1.txt","r");
    fp2=OpenFile("xt-3-2.txt","r");
    while( (!feof(fp1)) && (!feof(fp2)) )
    {   
        temp1=fgetc(fp1);
        temp2=fgetc(fp2);
        if(temp1==temp2)
        {
            switch(temp1)
            {
                case '\n':enter_count++;break;
                default:char_count++;break;
            }
        }
        if(temp1!=temp2)
        {
            printf("the line is %d",enter_count+1);
            printf("the location is %d",char_count+1);
        }
    }
    CloseFile(fp1);
    CloseFile(fp2);
    

   
    return 0;
}


FILE *OpenFile(char *filename,char *model)
{
    FILE *fp;
    if((fp=fopen(filename,model))==NULL)
    {
        printf("can not open file!\n");
        exit(0);
    }
    return fp;
}
void CloseFile(FILE *fp)
{
    if(fclose(fp))
    {
        printf("can not close file!\n");
        exit(0);
    }
}

