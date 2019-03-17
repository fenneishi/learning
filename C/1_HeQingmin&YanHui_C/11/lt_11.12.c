// 有些函数没有定义必要，例如遍历，用它还得再定义一个函数，把函数当成参数传递进去，整体会比较复杂，还不如直接for循环。
// 定义工具，根据为的规模和需要来，虽然整体结构最好要有，但是不一定所有的都要。
// 链表里面，单独给一个节点的地址，实际上一种比较无效的信息，因为你什么事情都不敢做，你不知道他的上家在哪里。
// 链表里面的遍历常见的是两个指针的遍历，引文很多操作都必须要知道上下家才能做，要不然链表就会断掉。
// 刚开始，每个函数不要设置的太细化，稍微粗一点，如果整体需求逐渐增多，代码量上去，复购上去了，再去细化函数
// 先把主体框架搭好，再不断的补充函数，补充功能。
#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>
// 定义数据结构和宏
struct student
{
    int number,score;
    char name[30];
    struct student *next;
};
#define size sizeof(struct student)
// 函数声明
struct student * Creat_Class();
struct student * Add_Student(struct student * head);
struct student * Delete_Student(struct student * head);
void Count_Class(struct student * head);
void Print_Class(struct student * head);
void Change_Student(struct student *head);
//主函数
int main(void)
{
    struct student *class;
    int choice;
    do
    {
        printf("1-Creat class,2-Add student,3-Dellete student,4-Print_Class,5-count class,6-Change student,0-quit:");
        scanf("%d",&choice);
        if(choice==1)class=Creat_Class();
        else printf("must Creat the class first!\n");
    }while(choice!=1);
    
    do
    {
        printf("2-Add student,3-Dellete student,4-Print_Class,5-count class,6-Change student,0-quit:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:break;
            case 1:class=Creat_Class();break;
            case 2:class=Add_Student(class);break;
            case 3:class=Delete_Student(class);break;
            case 4:Print_Class(class);break;
            case 5:Count_Class(class);break;
            case 6:Change_Student(class);break;
            default:break;
        }
    }while(choice!=0);
    
    return 0;
}

// 注意：必须先creat,然后才能干起太的




struct student * Creat_Class()
{
    struct student *head=NULL;
    int max,i;
    printf("input the count of students in class:");
    scanf("%d",&max);
    for(i=1;i<=max;i++){head=Add_Student(head);}
    return head;
}

struct student * Add_Student(struct student * head)
{
    struct student *stu,*temp1,*temp2;
    // 创建一个学生；
    stu=(struct student *)malloc(size);
    printf("input name:");
    scanf("%s",stu->name);
    printf("input num,score:");
    scanf("%d,%d",&stu->number,&stu->score);
    stu->next=NULL;
    // 插入一个学生；
    if(head==NULL)head=stu; // 成为第一个
    else if(stu->number<=head->number){stu->next=head;head=stu;} //add到第一个
    else
    {
        for(temp1=head,temp2=head->next;temp2!=NULL;temp1=temp2,temp2=temp2->next)
        {
            if(temp1->number<=stu->number&&stu->number<=temp2->number){stu->next=temp2;temp1->next=stu;} // add到中间
        }
        if(temp1->number<stu->number)temp1->next=stu; // add到最后一个
    }
    return head;
}

struct student * Delete_Student(struct student *head)
{
    struct student *temp1,*temp2;
    int num;
    // 获得number：
    printf("input the student number who must delete:");
    scanf("%d",&num);
    // 删除学生：
    if(head==NULL)printf("no student in class\n");
    else if(head->number==num){head=head->next;free(head);}
    else
    {
        for(temp1=head,temp2=head->next;temp2!=NULL;temp1=temp2,temp2=temp2->next)
            { if(temp2->number==num){temp1->next=temp2->next;free(temp2);} }
        if(temp2==NULL)printf("can not find the student in class:\n");
    } 
    return head;
}

void Print_Class(struct student * head)
{
    struct student *temp1;
    for(temp1=head;temp1!=NULL;temp1=temp1->next)
        printf("num:%d,name:%s,score:%d\n",temp1->number,temp1->name,temp1->score);
}

void Count_Class(struct student * head)
{
    struct student *temp1;
    int count=0;
    for(temp1=head;temp1!=NULL;temp1=temp1->next)
        count++;
    printf("the full count of this class is :%d\n",count);
}

void Change_Student(struct student *head)
{
    int num;
    struct student *temp1;
    printf("input the student num:");
    scanf("%d",&num);
    for(temp1=head;temp1!=NULL;temp1=temp1->next)
    {
        if(temp1->number==num)
        {
            printf("input new name:");
            scanf("%s",temp1->name);
            printf("input new score:");
            scanf("%d",&temp1->score);
        }
    }
    if(temp1==NULL)printf("student not in the class:\n");
}