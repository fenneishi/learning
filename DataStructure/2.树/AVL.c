/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
    
}AVL;

AVL *creat();

int  height(AVL *avl);

AVL *find(int x,AVL *avl);
AVL *find_max(AVL *avl);
AVL *find_min(AVL *avl);

void travel_pre(AVL *avl);
void travel_in(AVL *avl);
void travel_post(AVL *avl);


AVL *insert(int x,AVL *avl);
AVL *delete(int x,AVL *avl);

AVL *balance_rotation_insert(int x,AVL *avl);
AVL *left_left_rotation(AVL *avl);
AVL *right_right_rotation(AVL *avl);
AVL *left_right_rotation(AVL *avl);
AVL *right_left_rotation(AVL *avl);
AVL *balance_rotation(AVL *avl);







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
int  height(AVL *avl)
{
    return avl->height;
}


void travel_pre(AVL *avl)
{
    if(avl==NULL)return;
    printf("%d\n",avl->data);
    travel_pre(avl->left);
    travel_pre(avl->right);
}
// 中序遍历=所有元素会从小到大顺序输出。
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


AVL *insert(int x,AVL *avl)
{
    if(avl==NULL)
    {
        AVL *Node=NULL;
        Node=(AVL *)malloc(sizeof(AVL));
        if(Node==NULL)printf("no memory for new node!\n");
        Node->data=x;
        Node->height=0;
        Node->left=Node->right=NULL;
        return Node;
    }
    if(x==avl->data){printf("can not insert the same node into the tree\n");return avl;}
    if(x<avl->data)avl->left=insert(x,avl->left);
    if(x>avl->data)avl->right=insert(x,avl->right);
    avl->height=height(avl->left)>height(avl->right)?height(avl->left)+1:height(avl->right)+1;
    return balance_rotation_insert(x,avl);
}

AVL *balance_rotation_insert(int x,AVL *avl)
{
    //进行调整
    if(avl==NULL)return NULL;
    if(height(avl->left)-height(avl->right)>=2)
        {
            if(x<avl->left->data)return left_left_rotation(avl);
            return left_right_rotation(avl);
        }
    if(height(avl->right)-height(avl->left)>=2)
        {
            if(x>avl->right->data)return right_right_rotation(avl);
            return right_left_rotation(avl);
        }
    return avl;
}


AVL *delete(int x,AVL *avl)
{   
    AVL *temp;
    if(avl==NULL){printf("the tree is empty!\n");return NULL;};
    if(x==avl->data)
    {
        if(avl->left==NULL&&avl->right==NULL){free(avl);return NULL;}
        if(avl->left!=NULL&&avl->right==NULL){temp=avl->left;free(avl);avl=temp;}
        if(avl->left==NULL&&avl->right!=NULL){temp=avl->right;free(avl);avl=temp;}
        if(avl->left!=NULL&&avl->right!=NULL)
        {
            if(height(avl->left)>=height(avl->right))
            {
                temp=find_max(avl->left);
                avl->data=temp->data;
                avl->left=delete(avl->data,avl->left);  
            }
            if(height(avl->left)<height(avl->right))
            {
                temp=find_min(avl->right);
                avl->data=temp->data;
                avl->right=delete(avl->data,avl->right);
            }
        }
    }
    if(x<avl->data){avl->left=delete(x,avl->left);}
    if(x>avl->data){avl->right=delete(x,avl->right);}
    avl->height=height(avl->left)>height(avl->right)?height(avl->left)+1:height(avl->right)+1;
    return balance_rotation(avl);
}


AVL *balance_rotation(AVL *avl)
{
    //进行调整
    if(avl==NULL)return NULL;
    if(height(avl->left)-height(avl->right)>=2)
        {
            if(height(avl->left->left)>height(avl->left->right))return left_left_rotation(avl);
            return left_right_rotation(avl);
        }
    if(height(avl->right)-height(avl->left)>=2)
        {
            if(height(avl->right->right)>height(avl->right->left))return right_right_rotation(avl);
            return right_left_rotation(avl);
        }
    return avl;
}
AVL *left_left_rotation(AVL *avl)
{
    AVL *temp;
    temp=avl->left;
    avl->left=temp->right;
    temp->right=avl;
    return temp;
}
AVL *right_right_rotation(AVL *avl)
{
    AVL *temp;
    temp=avl->right;
    avl->right=temp->left;
    temp->left=avl;
    return temp;
}
AVL *left_right_rotation(AVL *avl)
{
    AVL *A,*B,*C;
    A=avl;B=avl->left;
    C=B->right;
    B->right=C->left;
    A->left=C->right;
    C->left=B;
    C->right=A;
    return C;

}
AVL *right_left_rotation(AVL *avl)
{
    AVL *A,*B,*C;
    A=avl;
    B=avl->right;
    C=B->left;
    B->left=C->right;
    A->right=C->left;
    C->right=B;
    C->left=A;
    return C;
}



