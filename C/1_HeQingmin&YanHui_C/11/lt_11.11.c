#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>


// 有些函数没有定义必要，例如遍历，用它还得再定义一个函数，把函数当成参数传递进去，整体会比较复杂，还不如直接for循环。
// 定义工具，根据为的规模和需要来，虽然整体结构最好要有，但是不一定所有的都要。
// 链表里面，单独给一个节点的地址，实际上一种比较无效的信息，因为你什么事情都不敢做，你不知道他的上家在哪里。
// 链表里面的遍历常见的是两个指针的遍历，引文很多操作都必须要知道上下家才能做，要不然链表就会断掉。

struct students
{
    int num;
    char name[30];
    int score;
    struct students *next;
};

// 链表层面函数：
// add:must return new head(except "creat_node").
struct students *creat_node           (                                                 );//创建一个节点
struct students *creat_link_head      (                                                 );// 创建一个空的链表表头
struct students *insert_node          (struct students *head,struct students *node      );// insert a node
struct students *Creat_Link           (                                                 );// creat a new full link by User with shell.
//delete:must return new head(or NULL)
struct students *delete_node_byPosi   (struct students *head,struct students *position  );//delete by position；first one
struct students *delete_node_byNumb   (struct students *head,int num                    );//delete by num;first one
struct students *delete_node_byName   (struct students *head,char name[]                );//delete by name;first one
struct students *Delete_Part_Link     (struct students *head,struct students *start,struct students *end);//change a part of link's content by user with shell;
struct students *Delete_Full_Link     (struct students *head                            );// Delete a linked list completely and free memory.
//change:  
void             change_node_byPosi   (struct students *head,struct students *position  );//change by position；first one
void             change_node_byNumb   (struct students *head,int num                    );//change by num;first one
void             change_node_byName   (struct students *head,char *name                 );//change by name;first one
void             Change_Part_Link     (struct students *head,struct students *start,struct students *end);//change a part of link's content by user with shell;
void             Change_Full_Link     (struct students *head                            );//change full of link's content by user with shell;
//find:must return the position(first one)
struct students *find_node_byNumb     (struct students *head,int num                    );//find by num;
struct students *find_node_byName     (struct students *head,char *name                 );//find by name;
//print:（traver）
void             Traver_Full_link     (struct students *head,struct students (*function) (struct students *p));// Prints the contents of the specified location member.
void             print_by_posi        (struct students *head,struct students *position  );// Prints the contents of the specified location member.
void             print_by_numb        (struct students *head,int num                    );// Print the member contents of all whos have teh specified number.(first one)
void             print_by_name        (struct students *head,char *name                 );// Print the member contents of all whos have teh specified name.(first one)
void             Print_Part_Link      (struct students *head,struct students *start,struct students *end);//print a part of link's content by user with shell;
void             Print_Full_Link      (struct students *head                            );//print full of link's content by user with shell


//交互层面函数
struct students *CreatClass           (                                                 );
struct students *DeleteClass          (struct students *head                            );//must return NULL.
void             PrintClass           (struct students *head                            );
struct students *InsertStudent        (struct students *head                            );//must return new head.
struct students *DeleteStudentByNumber(struct students *head                            );//must return new head.
struct students *DeleteStudentByName  (struct students *head                            );//must return new head.
void             ChangeStudentByNumber(struct students *head                            );
void             ChangeStudentByName  (struct students *head                            );
void             PrintStudentByNumber (struct students *head                            );
void             PrintStudentByName   (struct students *head                            );




int main(void)
{  
    int choice;
    struct students *head;
    do
    {
        printf("===========================================================\n");
        printf("===========================================================\n");
        printf("===========================================================\n");
        printf
        (
            "1---Creat a class list\n"
            "2---Delete the class list\n"
            "3---Print all students' information in the class\n"
            "4---Add students according to schoor number\n"
            "5---Delete a student from class list(search by number)\n"
            "6---Delete a student from class list(search by name)\n"
            "7---Change a student's information(search bt number)\n"
            "8---Change a student's information(search bt name)\n"
            "9---Print a student information(search bt number)\n"
            "10--Print a student information(search bt name)\n"
            "0---quit the system\n"
        );
        printf("------------------------------------------------------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  :head=CreatClass           (    );break;
            case 2  :head=DeleteClass          (head);break;
            case 3  :     PrintClass           (head);break;
            case 4  :head=InsertStudent        (head);break;
            case 5  :head=DeleteStudentByNumber(head);break;
            case 6  :head=DeleteStudentByName  (head);break;
            case 7  :     ChangeStudentByNumber(head);break;
            case 8  :     ChangeStudentByName  (head);break;
            case 9  :     PrintStudentByNumber (head);break;
            case 10 :     PrintStudentByName   (head);break;
            case 0  :                                 break;
            default :                                 break;
        }
    }while(choice!=0);
    return 0;// 返回0，表明main函数正常执行。
}






 //创建一个学生节点:
struct students *creat_node() 
{
    struct students *code;
    code=(struct students *)malloc(sizeof(struct students));
    code->next=NULL;
    return code;
}
// 往链表里插入一个节点：must return new head.
struct students *insert_node          (struct students *head,struct students *node      )// insert a node
{
    struct students *temp1,*temp2;
    if(head==NULL)head=node;
    else
    {//把链表分成多个区间，一个个区间去比较，根据比较结果，确定插入位置。
        for(temp1=head,temp2=head->next;temp2!=NULL;temp1=temp2,temp2=temp2->next)
        {
            if(temp1->num<=node->num&&node->num<=temp2->num)
            {
                node->next=temp2;
                temp1->next=node;
                break;
            }
        }
        if(temp1->num<node->num){temp1->next=node;}
        if(node->num<head->num){node->next=head->next;head=node;}
    }
    return  head;
}
//删除第一个学号匹配的学生信息从链表中:return head
struct students *delete_node_byNumb   (struct students *head,int num                    )//delete by num;first one
{
    struct students *temp1,*temp2;
    if(head==NULL)printf("can not find the one with numer:%d",num);
    else
    {//把链表分成多个区间，一个个区间去比较，根据比较结果，确定插入位置。
        if(head->num==num){head=head->next;free(head);}
        else
        {
            for (temp1 = head, temp2 = head->next; temp2 != NULL; temp1 = temp2, temp2 = temp2->next)
            {   if (temp2->num == num){temp1->next = temp2->next;free(temp2);break;}                }
            if(temp2==NULL)printf("can not find the one with numer:%d",num);
        }
    }
    return head;
}
//删除第一个姓名匹配的学生信息从链表中:return head
struct students *delete_node_byName   (struct students *head,char name[]                )//delete by name;first one
{
    struct students *temp1,*temp2;
    if(head==NULL)printf("can not find the one with numer:%s",name);
    else
    {//把链表分成多个区间，一个个区间去比较，根据比较结果，确定插入位置。
        if(strcmp(head->name,name)==0){head=head->next;free(head);}
        else
        {
            for (temp1 = head, temp2 = head->next; temp2 != NULL; temp1 = temp2, temp2 = temp2->next)
            {   if (strcmp(temp2->name,name)==0){temp1->next = temp2->next;free(temp2);break;}                }
            if(temp2==NULL)printf("can not find the one with numer:%s",name);
        }
    }
    return head;
}

struct students *Delete_Full_Link     (struct students *head                            );// Delete a linked list completely and free memory.
//change:  
void             change_node_byPosi   (struct students *head,struct students *position  );//change by position；first one
void             change_node_byNumb   (struct students *head,int num                    );//change by num;first one
void             change_node_byName   (struct students *head,char *name                 );//change by name;first one
void             Change_Part_Link     (struct students *head,struct students *start,struct students *end);//change a part of link's content by user with shell;
void             Change_Full_Link     (struct students *head                            );//change full of link's content by user with shell;
//find:must return the position(first one)
struct students *find_node_byNumb     (struct students *head,int num                    );//find by num;
struct students *find_node_byName     (struct students *head,char *name                 );//find by name;
//print:（traver）
void             Traver_Full_link     (struct students *head,struct students (*function) (struct students *p));// Prints the contents of the specified location member.
void             print_by_posi        (struct students *head,struct students *position  );// Prints the contents of the specified location member.
void             print_by_numb        (struct students *head,int num                    );// Print the member contents of all whos have teh specified number.(first one)
void             print_by_name        (struct students *head,char *name                 );// Print the member contents of all whos have teh specified name.(first one)
void             Print_Part_Link      (struct students *head,struct students *start,struct students *end);//print a part of link's content by user with shell;
void             Print_Full_Link      (struct students *head                            );//print full of link's content by user with shell




struct students *CreatClass           (                                                 )
{
    struct students *head=NULL;
    int num,i;
    printf("please input the numbers of students");
    scanf("%d",&num);
    for(i=0;i<=(num-1);i++)InsertStudent(head);
    return head;
}

//一次性删除整个链表：return NULL,并释放内存
struct students *DeleteClass          (struct students *head                            )
{
    struct students *temp1=NULL,*temp2=NULL;
    if(head!=NULL)
    {
        for(temp1=head,temp2=head->next;temp2!=NULL;temp1=temp2,temp2=temp2->next)
        {
            free(temp1);
        }
        head=NULL;
    }
    return head;
}
//return nothing ;
void             PrintClass           (struct students *head                            )
{
    struct students *temp1=NULL;
    if(head!=NULL)
        for(temp1=head;temp1!=NULL;temp1=temp1->next)
            printf("num:%d,name:%s,score：%d",temp1->num,temp1->name,temp1->score);
    else printf("there is no student in zhe class.");
}
// must return no head;
struct students *InsertStudent        (struct students *head                            )
{
    struct students *stu;
    stu=(struct students *)malloc(sizeof(struct students *));
    printf("please input the student num:");
    scanf("%d",&stu->num);
    printf("please input the student name:");
    scanf("%s",stu->name);
    printf("please input the student score:");
    scanf("%d",&stu->score);
    stu->next=NULL;
    return insert_node(head,stu);
}
//must return new head.
struct students *DeleteStudentByNumber(struct students *head                            )
{
    return head;
}
//must return new head.
struct students *DeleteStudentByName  (struct students *head                            )
{
    return head;
}
//must return new head.
void             ChangeStudentByNumber(struct students *head                            )
{
    return head;
}

void             ChangeStudentByName  (struct students *head                            )
{
    return head;
}

void             PrintStudentByNumber (struct students *head                            )
{
    return head;
}

void             PrintStudentByName   (struct students *head                            )
{
    return head;
}



