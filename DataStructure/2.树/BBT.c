/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
}AVL;

AVL *creat();
AVL *insert(int x,AVL *avl);
AVL *delete(int x,AVL *avl);
AVL *find_max(AVL *avl);
AVL *find_min(AVL *avl);
AVL *find(int x,AVL *avl);
void travel_pre(AVL *avl);
void travel_in(AVL *avl);
void travel_post(AVL *avl);
AVL *delete_node(AVL *node,AVL *avl);


int main(void)
{
    
    return 0;
}

AVL *creat()
{
    AVL *avl=NULL;
    int x,n,count=0;
    printf("Please input the number of node:");
    scanf("%d",&n);
    for(count=0;count<n;count++)
    {
        avl=insert(x,avl);
    }
    return avl;
}

AVL *insert(int x,AVL *avl)
{
    if(avl==NULL)
    {
        AVL *Node=NULL;
        Node=(AVL *)malloc(sizeof(AVL));
        Node->data=x;
        Node->left=Node->right=NULL;
        return Node;
    }
    if(x<=avl->data){avl->left=insert(x,avl->left);return avl;}
    if(x>avl->data){avl->right=insert(x,avl->right);return avl;}   
}

AVL *delete(int x,AVL *avl)
{   
    if(avl==NULL) return NULL;
    if(avl->data==x)return delete_node(avl,avl);
    if(x<avl->data){avl->left=delete(x,avl->left);return avl;}
    if(x>avl->data){avl->right=delete(x,avl->right);return avl;}
}


AVL *delete_node(AVL *node,AVL *avl)
{
    AVL *temp;
    if(avl==NULL||node==NULL){printf("delete Error!\n");return NULL;}
    if(node->left==NULL&&node->right==NULL){free(node);return NULL;}
    if(node->left!=NULL)
    {
        temp=find_max(node->left);
        node->data=temp->data;
        node->left=delete_node(temp,avl);
        return avl;
    }
    if(node->right!=NULL)
    {   
        temp=find_min(node->right);
        node->data=temp->data;
        node->right=delete_node(temp,avl);
        return avl;
    }
}

AVL *find_max(AVL *avl)
{
    if(avl->right==NULL)return avl;
    return find_max(avl->right);
}

AVL *find_min(AVL *avl)
{
    if(avl->left==NULL)return avl;
    return find_min(avl->left);
}

AVL *find(int x,AVL *avl)
{
    if(avl==NULL)return NULL;
    if(avl->data==x)return avl;
    if(avl->data<x)return find(x,avl->left);
    if(avl->data>x)return find(x,avl->right);
}


void travel_pre(AVL *avl)
{
    if(avl==NULL)return;
    printf("%d\n",avl->data);
    travel_pre(avl->left);
    travel_pre(avl->right);
}
// 中序遍历，实际上所有元素会从小到大顺序输出。
void travel_in(AVL *avl)
{
    if(avl==NULL)return;
    travel_pre(avl->left);
    printf("%d\n",avl->data);
    travel_pre(avl->right);
}
void travel_post(AVL *avl)
{
    if(avl==NULL)return;
    travel_pre(avl->left);
    travel_pre(avl->right);
    printf("%d\n",avl->data);
}


