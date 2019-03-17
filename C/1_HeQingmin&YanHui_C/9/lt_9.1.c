
/*
构建学生信息库，实现建立、查询、输出功能
*/

#include <stdio.h>
#include <stdlib.h> 
#define MaxSize 50

struct student
{
    int num;
    char name[10];
    int computer,english,math;
    double average;
};

int Count=0;

void new_student(struct student students[]);
void search_student(struct student students[],int num);
void output_student(struct student students[]);

int main(void)
{
    int choice,num;
    struct student students[MaxSize];
    do
    {
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("choice: 1:new 2:search 3:output 0:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: new_student(students);break;
            case 2: printf("Please intput the student's number:");
                    scanf("%d",&num);
                    search_student(students,num);
                    break;
            case 3: output_student(students);break;
            case 0: break;
        }
    }
    while(choice!=0);
    return 0;
}


void new_student(struct student students[])
{
    struct student s;
    if(Count==MaxSize)
    {
        printf("this students array is full \n");
        return;
    }
    printf("input student's num:");scanf("%d",&s.num);
    printf("input student's name:");scanf("%s",s.name);
    printf("input Math score:");scanf("%d",&s.math);
    printf("input English score:");scanf("%d",&s.english);
    printf("input Computer score:");scanf("%d",&s.computer);
    s.average=(s.math+s.english+s.computer)/3.0;
    students[Count]=s;
    Count++;
}

void search_student(struct student students[],int num)
{
    int i;
    int res=-1;
    if(Count==0)
    {
        printf("the count of students is Zero:\n");
        return;
    }
    for(i=0;i<Count;i++)
    {
        if(students[i].num==num)
        {
            res=i;
            break;
        }
    }

    if(res!=-1)
    {
        printf("num:%d\n",students[i].num);
        printf("name:%s\n",students[i].name);
        printf("Math score:%d\n",students[i].math);
        printf("English score:%d\n",students[i].english);
        printf("Computer score:%d\n",students[i].computer);
    }
    else 
        printf("Not Found!");

}

void output_student(struct student students[])
{
    int i;
    if(Count==0)
    {
        printf("the count of students is Zero:\n");
        return;
    }
    printf("------------------------------------------------------------------\n");
    printf("num\tname\tmath\tenglish\tcomputer\taverage\n");
    for(i=0;i<Count;i++)
    {
        printf("%d\t",students[i].num);
        printf("%s\t",students[i].name);
        printf("%d\t",students[i].math);
        printf("%d\t",students[i].english);
        printf("%d\t\t",students[i].computer);
        printf("%.2lf\n",students[i].average);
    }
    printf("------------------------------------------------------------------\n");
}