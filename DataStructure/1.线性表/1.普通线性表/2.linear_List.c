/*线性表用链表实现*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node 
{
    int data;
    struct Node *next;
}List;

#define LISTSIZE sizeof(List)

int length(List *head);//renturn the length of List
List *FindKth(int k,List *head);// Find number K,return location。
List *Find(int x,List *head);// Find value X,return location。
List *Join(int x,int k,List *head);//x join in number K,retrun new head;
List *Delete(int k,List *head);//delete number k,return new head;

//主函数
int main(void)
{
    
    return 0;
}

//renturn the length of List
int length(List *head)
{//这个head是可以移动的，不一定非得一直指向头结点
    int count;List *temp;
    // Empty List
    if(head==NULL)return 0;
    // Nomal Case
    for(count=1,temp=head;temp!=0;temp=temp->next,count++); 
    return count-1;
}
// return the location of element number K
List *FindKth(int k,List *head)
{//这个head是可以移动的，不一定非得一直指向头结点
    List *temp;int num;
    // Empty List
    if(head==NULL)return NULL;
    //illegal k 
    if(k<1)return NULL;
    //Nomal Case
    for(num=1,temp=head;num!=k&&temp!=NULL;temp=temp->next,num++);
    if(temp==NULL)return NULL;//k>len,not find
    return temp;//k<=len,find
}
// Find according value ,return location
List *Find(int x,List *head)
{//这个head是可以移动的，不一定非得一直指向头结点
    List *temp;
    // Empty List
    if(head==NULL)return NULL;
    // Nomal Case
    for(temp=head;temp->data!=x&&temp!=NULL;temp=temp->next);
    if(temp==NULL)return NULL; // not find 
    return temp;//find
}

//x in Join in list in k
List *Join(int x,int k,List *head) 
{
    List *temp,*node;
    int num;
    // creat node;
    node=(List *)malloc(LISTSIZE);
    node->data=x;
    node->next=NULL;
    // Empty List
    if(head==NULL)
    {
        if(k==1)return node;
        return head;
    }
    //illegal k
    if(k<1)return head;
    //illegal k-1
    if(k==1){node->next=head;return node;}//sure k-1>1    
    //find k-1
    for(temp=head,num=1;num<k-1&&temp!=NULL;temp=temp->next,num++);
    //k-1>len
    if(temp==NULL)return head;
    //1<=k-1<=len
    node->next=temp->next;
    temp->next=node;
    return head;
}

//delete number k,return new head;
List *Delete(int k,List *head)
{
    List *temp,*temp2;
    int num;
    // Empty list;
    if(head==NULL)return head;
    // illegal k;
    if(k<1)return head;
    // illegal k-1;
    if(k==1){temp2=head->next;free(head);return temp2;}
    //find k-1
    for(temp=head,num=1;num<k-1&&temp->next!=NULL;temp=temp->next,num++)
    //k-1>(len-1)
    if(temp->next==NULL)return head;
    //1<=k-1<=(len-1)
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return head;
}