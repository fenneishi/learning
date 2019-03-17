#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct students
{
    int num;
    char name[30];
    int score;
    struct students *next;
};

// 函数声明：
// 初始层面工具：
struct students *creat_node();  //创建一个节点
struct students *creat_link_head();// 创建一个链表表头


// 元素层面工具：
// add:return new head
struct students *insert_node(struct students *head,struct students *node); // insert a node
//delete:return new head
struct students *delete_node_byPosi(struct students *head,struct students *position); //delete by position；first one
struct students *delete_node_byNumb(struct students *head,int num); //delete by num;first one
struct students *delete_node_byName(struct students *head,char name[]);  //delete by name;first one
//change:return new head
struct students *change_node_byPosi(struct students *head,struct students *position); //change by position；first one
struct students *change_node_byNumb(struct students *head,int num); //change by num;first one
struct students *change_node_byName(struct students *head,char *name);  //change by name;first one
//find:return the position(first one)
struct students *find_node_byNumb(struct students *head,int num); //find by num;
struct students *find_node_byName(struct students *head,char *name);  //find by name;
//show:return void;
void show_by_posi(struct students *head,struct students *position);// Prints the contents of the specified location member.
void show_by_num(struct students *head,int num);// Print the member contents of all whos have teh specified number.
void show_by_name(struct students *head,char *name);// Print the member contents of all whos have teh specified name.


// 链表层面工具：
//add:return new head
struct students *Creat_Link(struct students *head);// creat a new full link by User with shell.
//delete:return new head
struct students *Delete_Link(struct students *head);// Delete a linked list completely and free memory.
//change:return new head
struct students *Change_Part_Link(struct students *head); //change a part of link's content by user with shell;
struct students *Change_Full_Link(struct students *head); //change full of link's content by user with shell;
//show:return void;
struct students *Show_Part_Link(struct students *head); //Show a part of link's content by user with shell;
struct students *Show_Full_Link(struct students *head); //Show full of link's content by user with shell;


//交互层面工具：
//Level 0 menu:
void menu_0(struct students *head);
//Level 1 menu:
int menu_add(struct students *head);
int menu_del(struct students *head);
int menu_cha(struct students *head);
int menu_fin(struct students *head);
int menu_sho(struct students *head);



int main(void)
{  
    struct students *head;head=creat_link_head();// 创建一个链表表头,表头指向NULL.
    menu_0(head);// 调用菜单函数，进入交互.
    return 0;// 返回0，表明main函数正常执行。
}


// 函数声明：
// 初始层面工具：
struct students *creat_node();  //创建一个节点
struct students *creat_link_head();// 创建一个链表表头




// 元素层面工具：
// add:return new head
struct students *insert_node(struct students *head,struct students *node); // insert a node
//delete:return new head
struct students *delete_node_byPosi(struct students *head,struct students *position); //delete by position；first one
struct students *delete_node_byNumb(struct students *head,int num); //delete by num;first one
struct students *delete_node_byName(struct students *head,char name[]);  //delete by name;first one
//change:return new head
struct students *change_node_byPosi(struct students *head,struct students *position); //change by position；first one
struct students *change_node_byNumb(struct students *head,int num); //change by num;first one
struct students *change_node_byName(struct students *head,char *name);  //change by name;first one
//find:return the position(first one)
struct students *find_node_byNumb(struct students *head,int num); //find by num;
struct students *find_node_byName(struct students *head,char *name);  //find by name;
//show:return void;
void show_by_posi(struct students *head,struct students *position);// Prints the contents of the specified location member.
void show_by_num(struct students *head,int num);// Print the member contents of all whos have teh specified number.
void show_by_name(struct students *head,char *name);// Print the member contents of all whos have teh specified name.




// 链表层面工具：
//add:
struct students *Creat_Link();// creat a new full link by User with shell.
struct students *Insert_node(struct students *head); // insert a node
//delete:
struct students *Delete_Link(struct students *head);// Delete a linked list completely and free memory.
struct students *Delete_node_byNumb(struct students *head); //delete by num;first one
struct students *Delete_node_byName(struct students *head);  //delete by name;first one
//change:
struct students *Change_Part_Link(struct students *head); //change a part of link's content by user with shell;
struct students *Change_Full_Link(struct students *head); //change full of link's content by user with shell;
//show:return void;
struct students *Show_Part_Link(struct students *head); //Show a part of link's content by user with shell;
struct students *Show_Full_Link(struct students *head); //Show full of link's content by user with shell;


//交互层面工具：
//Level 0 menu:
void menu_0(struct students *head)
{
    int choice=0;
    do 
    {
        printf("1-add,2-del,3-cha,4-fin,5-sho,0-quit:");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:choice=menu_add(head);break;
           case 2:choice=menu_del(head);break;
           case 3:choice=menu_cha(head);break;
           case 4:choice=menu_fin(head);break;
           case 5:choice=menu_sho(head);break;
           case 0:break;
           default:break;
        }
    }while(choice!=0);
}
//Level 1 menu:
int menu_add(struct students *head)
{
    int choice=1;
    do
    {
        printf("1-begin Creat chass,2-insert a student,3-,4-,5-,0-quit,-1=return:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Creat_Link(head);break;
            case 2:Insert_node(head);break;
            case 0:break;
            case -1:break;
            default:break;
        }
    }while(choice!=0&&choice!=-1);
    return choice;
}

struct students *Delete_Link(struct students *head);// Delete a linked list completely and free memory.
struct students *Delete_node_byNumb(struct students *head); //delete by num;first one
struct students *Delete_node_byName(struct students *head);  //delete by name;first one

int menu_del(struct students *head)
{
    int choice=1;
    do
    {
        printf("1-delete full class,2-delete by num,3-delete by name,0-quit,-1=return:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Delete_Link(head);break;
            case 2:Delete_node_byNumb(head);break;
            case 3:Delete_node_byName(head);break;
            case 0:break;
            case -1:break;
            default:break;
        }
    }while(choice!=0&&choice!=-1);
    return choice;
}
int menu_cha(struct students *head)
{
    int choice=1;
    do
    {
        printf("1-,2-,3-,4-,5-,0-quit,-1=return:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:;break;
            case 2:;break;
            case 3:;break;
            case 4:;break;
            case 5:;break;
            case 0:break;
            case -1:break;
            default:break;
        }
    }while(choice!=0&&choice!=-1);
    return choice;
}
int menu_fin(struct students *head)
{
    int choice=1;
    do
    {
        printf("1-,2-,3-,4-,5-,0-quit,-1=return:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:;break;
            case 2:;break;
            case 3:;break;
            case 4:;break;
            case 5:;break;
            case 0:break;
            case -1:break;
            default:break;
        }
    }while(choice!=0&&choice!=-1);
    return choice;
}
int menu_sho(struct students *head)
{
    int choice=1;
    do
    {
        printf("1-,2-,3-,4-,5-,0-quit,-1=return:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:;break;
            case 2:;break;
            case 3:;break;
            case 4:;break;
            case 5:;break;
            case 0:break;
            case -1:break;
            default:break;
        }
    }while(choice!=0&&choice!=-1);
    return choice;
}
