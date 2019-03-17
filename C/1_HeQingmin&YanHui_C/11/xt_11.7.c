

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 


struct student
{
    int num;
    char name[100];
    struct student *next;
};

struct student * cat(struct student *,struct student *);

int main(void)
{  

    struct student *stu1,*stu2,*temp;
    int count1,count2;
    int i;

    //建立第一个班级的链表；
    printf("please input the count of first class :");
    scanf("%d",&count1);
    // 建立stu1的第一个节点；
    stu1=(struct student *)malloc(sizeof(struct student));
    stu1->num=1;
    printf("input %d student's name:",1);
    scanf("%s",stu1->name);
    stu1->next=NULL;
    temp=stu1;
    // 建立stu1后面的节点，完成链表。
    for(i=2;i<=count1;i++)
    {
        temp->next=(struct student *)malloc(sizeof(struct student));
        temp=temp->next;
        temp->num=i;
        printf("input %d student's name:",i);
        scanf("%s",temp->name);
    }
    temp->next=NULL;

    // 建立第二个班级的链表；
    printf("please input the count of second class :");
    scanf("%d",&count2);
    // 建立stu2的第一个节点；
    stu2=(struct student *)malloc(sizeof(struct student));
    stu2->num=1;
    printf("input %d student's name:",1);
    scanf("%s",stu2->name);
    stu2->next=NULL;
    temp=stu2;
    // 建立stu2后面的节点，完成链表。
    for(i=2;i<=count2;i++)
    {
        temp->next=(struct student *)malloc(sizeof(struct student));
        temp=temp->next;
        temp->num=i;
        printf("input %d student's name:",i);
        scanf("%s",temp->name);
    }
    temp->next=NULL;
    
    for(temp=stu1;temp!=NULL;temp=temp->next)
    {
        printf("====");
        printf("%d:%s\n",temp->num,temp->name);
    }
    printf("==================\n");
    for(temp=stu2;temp!=NULL;temp=temp->next)
    {
        printf("====");
        printf("%d:%s\n",temp->num,temp->name);
    }


    // 把stu2链到stu1后面；
    cat(stu1,stu2);
    
    // 输出结果；
    printf("the result is :\n");
    for(temp=stu1;temp!=NULL;temp=temp->next)
    {
        printf("====");
        printf("%d:%s\n",temp->num,temp->name);
    }
    free(stu1);
    free(stu2);
    return 0;
}


struct student * cat(struct student * stu1,struct student *stu2)
{
    struct student *temp1;
    for(temp1=stu1;temp1->next!=NULL;temp1=temp1->next);
    temp1->next=stu2;
    return stu1;
}
