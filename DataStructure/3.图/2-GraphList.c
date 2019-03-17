/*

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MaxVerSize 1000
#define ErrorVerdata -1
// #define VerError (Graph->num_V<1)
// #define EdgError (Graph->num_E>(Graph->num_V*Graph->num_V-Graph->V))
// #define DirError (Graph->direction!=0&&Graph->direction!=0)
// #define Graph_Check VerError&&EdgError&&DirError

typedef struct _Enode
{
    int end_v_data;
    int weight;
    struct _Enode *next_edge;
}Enode;

typedef struct _Vnode
{
    int data;
    struct _Enode *first_edge;
}Vnode;

typedef struct _Graph
{
    int num_V;
    int num_E;
    int direction;
    Vnode Vers[MaxVerSize];
}Lgraph;

int Graph_Check(Lgraph * GRaph);
Lgraph *Initialize_Graph();
Lgraph *Creat_V_by_user(Lgraph *Graph);
Lgraph *Creat_E_by_user(Lgraph *Graph);
Lgraph *Creat_Graph_by_user();
Vnode *find_V(Lgraph *Graph,int V_data);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

int Graph_Check(Lgraph * Graph)
{
if(Graph->num_V<1)return 0;
if(Graph->num_E>(Graph->num_V*Graph->num_V-Graph->num_V))return 0;
if(Graph->direction!=0&&Graph->direction!=0)return 0;
return 1;
}

// int Edge_Check(Lgraph * Graph,Edge)
// {
// if(Graph->num_V<1)return 0;
// if(Graph->num_E>(Graph->num_V*Graph->num_V-Graph->num_V))return 0;
// if(Graph->direction!=0&&Graph->direction!=0)return 0;
// return 1;
// }


Lgraph *Initialize_Graph()//初始化图
{
    Lgraph *Graph;
    int *a;
    Graph=(Lgraph *)malloc(sizeof(Lgraph));//为图申请空间(主要是节点和属性)。
    if(Graph==NULL){printf("no more memory for Graph List!\n");return NULL;}
    do
    {
        printf("input the number of Ver!");//确定节点的数量
        scanf("%d",&Graph->num_V);
        printf("input the number of Edg!");//确定边的数量
        scanf("%d",&Graph->num_E);
        printf("input the direction of the graph(0--Undirected graph，1--directed graph):");
        scanf("%d",&Graph->direction);// 确定是否有向
    }while(Graph_Check(Graph)==0);
    
    Graph->Vers[0].data=ErrorVerdata;//节点的第0个位置，设置一个哨兵，节点从数组序号1开始。
    return Graph;
}

Lgraph *Creat_V_by_user(Lgraph *Graph)
{
    int i;
    if(Graph==NULL){printf("the Graph is NULL!\n");return Graph;}
    if(Graph_Check(Graph)==0){printf("the parameter is Error!\n");return Graph;}
    for(i=1;i<=Graph->num_V;i++)
    {
        printf("input the %d V data:",i);
        scanf("%d",&Graph->Vers[i].data);//注意：数组里存的就是一个个节点，不是指针。
    }
    return Graph;
}

Lgraph *Creat_E_by_user(Lgraph *Graph)
{
    int i;
    int start_V_data,end_V_data,Edge_weight;
    Vnode *temp1;
    Enode *temp2,*e_node;
    
    if(Graph==NULL){printf("the Graph is NULL!\n");return Graph;}//基本的检查
    if(Graph_Check(Graph)==0){printf("the parameter is Error!\n");return Graph;}
    for(i=1;i<=Graph->num_E;i++)
    {
        //从用户处获取必要的边信息。
        do
        {
            printf("input the information of Edges,like:1(start E) 2(End E) 12(Edge_weight)!");
            scanf("%d%d%d",&start_V_data,&end_V_data,&Edge_weight);
        }while(start_V_data>Graph->num_V||end_V_data>Graph->num_V||Edge_weight<=0);
        //申请空间，生成节点。
        e_node=(Enode *)malloc(sizeof(Enode));
        if(e_node==NULL){printf("no more memory for Graph!\n");return Graph;}
        e_node->end_v_data=end_V_data;
        e_node->weight=Edge_weight;
        e_node->next_edge=NULL;
        //把节点挂到合适位置。
        temp1=find_V(Graph,start_V_data);//找到start_node节点。
        if(temp1->first_edge==NULL)temp1->first_edge=e_node;//如果start_node节点上面没有挂东西，直接挂上去。
        else//如果有挂东西，挨个找到没有挂东西地方，然后挂上。
        {
            for(temp2=temp1->first_edge;temp2->next_edge!=NULL;temp2=temp2->next_edge)
            temp2->next_edge=e_node;
        }
    }
    return Graph;
}

Lgraph *Creat_Graph_by_user()
{
    Lgraph * Graph;
    Graph=Initialize_Graph();
    Graph=Creat_V_by_user(Graph);
    Graph=Creat_E_by_user(Graph);
    return Graph;
}

Vnode *find_V(Lgraph *Graph,int V_data)
{
    Vnode *temp;
    int i;
    for(i=Graph->num_V;Graph->Vers[i].data!=V_data&&Graph->Vers[i].data!=ErrorVerdata;i--)
    if(Graph->Vers[i].data==ErrorVerdata){printf("can not find the V_data=%d",V_data);return NULL;}
    return &Graph->Vers[i];
}



