

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

struct student * copy(struct student *);

int main(void)
{  

    struct student *stu1,*stu2,*temp;
    int count1;
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


    // 复制；
    stu2=copy(stu1);
    
    // 输出结果；
    printf("the result is :\n");
    for(temp=stu2;temp!=NULL;temp=temp->next)
    {
        printf("====");
        printf("%d:%s\n",temp->num,temp->name);
    }
    free(stu1);
    free(stu2);
    return 0;
}


struct student * copy(struct student * stu1)
{
    struct student *new,*temp1,*temp2;

    new=(struct student *)malloc(sizeof(struct student));
    *new=*stu1;

    for(temp1=stu1,temp2=new;temp1->next!=NULL;)
    {
        temp2->next=(struct student *)malloc(sizeof(struct student));
        temp2=temp2->next;
        temp1=temp1->next;
        *temp2=*temp1;
    }
    return new;
}
