// 你会发现函数之间传递的参数类型：要么是具体的节点Data,要么就是地址，很少有传递节点本身的。


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MaxVertices 100



typedef struct _Vnode
{
    int data;
    int visited;
    struct _Vnode *Q_next;
}Vnode;

typedef struct
{
    Vnode Vertices[MaxVertices];
    int Edges[MaxVertices][MaxVertices];
    int num_V;
    int num_E;
    int direction;
}AdjMatrix;



typedef struct
{
    Vnode *start;
    Vnode *end;
}Queue;

// 函数声明；
AdjMatrix *Creat_Graph();
void Print_Graph(AdjMatrix *Graph);
void Change_Vex(AdjMatrix *Graph,int i);
void Change_Ege(int StartVex,int EtartVex,int EdgeWeight,AdjMatrix *Graph);
void DFS(AdjMatrix *Graph,int V_i);
void dfs(AdjMatrix *Graph,int V_i);
void visite(AdjMatrix *Graph, int V_i);
void BFS(AdjMatrix *Graph,int V_i);

Queue *Initia_Queue(AdjMatrix *);
void En_Queue(Queue *,Vnode *);
Vnode *De_Queue(Queue *s);





int main(void)
{
    AdjMatrix *Graph;
    int start_V;
    Graph=Creat_Graph();
    Print_Graph(Graph);
    do
    {
        printf("input the start Ver(-1--->quit):");
        scanf("%d",&start_V);
        if(start_V<=0)break;
        DFS(Graph,start_V);
    }while(1);
    
    return 0;
}


AdjMatrix *Creat_Graph()
{
    AdjMatrix *Graph;
    int i,j,k;
    //apply the memory for the Graph;
    Graph=(AdjMatrix *)malloc(sizeof(AdjMatrix));
    if(Graph==NULL){printf("no more memory for the Graph!\n");return NULL;}
    //Initialize the Graph
    printf("input the numer Vertices:");scanf("%d",&Graph->num_V);
    printf("input the numer Edges:");scanf("%d",&Graph->num_E);
    printf("input the direction of the graph(0--Undirected graph，1--directed graph):");
    scanf("%d",&Graph->direction);
    for(i=1;i<=Graph->num_V;i++)
    {
        for(j=1;j<=Graph->num_V;j++)
            {if(i==j)Graph->Edges[i][j]=0;else Graph->Edges[i][j]=-1;}
    }
    printf("===============Initialize====================\n");
    Print_Graph(Graph);
    printf("===============Initialize====================\n");
    //add the data of Vertices
    for(i=1;i<=Graph->num_V;i++)Change_Vex(Graph,i);
    //add the data of Edges
    for(i=1;i<=Graph->num_E;i++)
    {
        int w;
        printf("input the %d Edges data(eg:1 2 10):",i);
        scanf("%d%d%d",&j,&k,&w);
        Change_Ege(j,k,w,Graph);
    }
    return Graph;
}



void Print_Graph(AdjMatrix *Graph)
{
    int i,j;
    printf("print the Vertices :\n");
    for(i=1;i<=Graph->num_V;i++)printf("%8d",Graph->Vertices[i].data);
    printf("\nprint the AdjMatrix:\n");
    printf("\t");
    for(i=1;i<=Graph->num_V;i++)printf("%8d",i);
    printf("\n");
    //printf the AdjMatrix
    for(i=1;i<=Graph->num_V;i++)
    {
        printf("%8d",i);
        for(j=1;j<=Graph->num_V;j++)
        {
            printf("%8d",Graph->Edges[i][j]);
        }
        printf("\n");
    }
}

void Change_Vex(AdjMatrix *Graph,int i)
{
    printf("input the %d Vertice data:",i);
    scanf("%d",&Graph->Vertices[i].data);
}
void Change_Ege(int j,int k,int w,AdjMatrix *Graph)
{
    switch(Graph->direction)
        {
            case 0:Graph->Edges[k][j]=Graph->Edges[j][k]=w;break;// 无向图利用对称性完成另一半。
            case 1:Graph->Edges[j][k]=w;break;
        }
}

//整体上的调用
void DFS(AdjMatrix *Graph,int V_i)
{
    //初始化：
    int i;
    for(i=1;i<=Graph->num_V;i++)Graph->Vertices[i].visited=0;
    //调用主体函数：
    dfs(Graph,V_i);
}
void dfs(AdjMatrix *Graph,int V_i)
{
    int V_j;
    if(V_i<=0||V_i>Graph->num_V){printf("can not find Ver!\n");return;}//检查节点取值范围，不要越界
    visite(Graph,V_i);
    for(V_j=1;V_j<=Graph->num_V;V_j++)
    {
        if(Graph->Edges[V_i][V_j]!=0&&Graph->Edges[V_i][V_j]!=-1&&Graph->Vertices[V_j].visited==0)
            dfs(Graph,V_j);
    }
}

void visite(AdjMatrix *Graph, int V_i)
{
    // printf("====================================================================\n");
    // printf("before visiting,the par-visited is %d\n",Graph->Vertices[V_i].visited);
    Graph->Vertices[V_i].visited=1;
    printf("Now visiting the %d Ver.data is :%d\n",V_i,Graph->Vertices[V_i].data);
    // printf("after visiting,the par-visited is %d\n",Graph->Vertices[V_i].visited);
}


void BFS(AdjMatrix *Graph,int V_start)
{
    int V_neighbor;
    Vnode *temp;
    //初始化：
    for(i=1;i<=Graph->num_V;i++)Graph->Vertices[i].visited=0;//初始化：所有元素都没有访问过。
    Queue *Q;
    Q= Initia_Queue(Graph);//初始化：初始化建立队列，同时所有节点的next分量一定置为NULL;
    visite(Graph,V_start);
    En_Queue(Q,&Graph->Vertices[V_start]);//初始化：先visit开始元素，然后把这个元素扔进队列里。
    //BFS循环主体：
    temp=De_Queue(Q);
    visite(Graph,V_start);
    for(V_neighbor=1;V_neighbor<=Graph->num_V;V_neighbor++)
    {
        if(Graph->Edges[V_i][V_neighbor]!=0&&Graph->Edges[V_i][V_neighbor]!=-1&&Graph->Vertices[V_neighbor].visited==0)
            dfs(Graph,V_j);
    }
}

Queue *Initia_Queue(AdjMatrix *Graph)
{
    int i;
    Queue *Q;//给队列申请空间
    Q=(Queue *)malloc(sizeof(Queue));
    if(Q==NULL){printf("no more memory for queue!\n");return NULL;}
    Q->start=Q->end=NULL;//队列中两个指针初始化
    for(i=1;i<=Graph->num_V;i++)Graph->Vertices[i].Q_next=NULL;//初始化：每个节点的Q_next分量全部变成NULL;
    return Q;
}
void En_Queue(Queue *Q,Vnode *V)
{
    if(Q==NULL){printf("can not find the q!\n");return;}
    if(Q->start==NULL&&Q->end==NULL)
    {
        Q->start=Q->end=V;
        return;
    }
    Q->end->Q_next=V;
    Q->end=V;
}
Vnode *De_Queue(Queue *Q)
{
    if(Q==NULL){printf("can not find the q!\n");return NULL;}
    if(Q->start==NULL&&Q->end==NULL){printf("the queue is empty!\n");return NULL;}
    Vnode *temp;
    Q->start=temp->Q_next;
    return temp;
}


//viste 函数可以修改，整个代码的函数可以更多的传递参数，而不是传递int型的data；
//还需要解决一个问题，就是知道地址，求节点的下标的问题，其实就是相对地址的问题。