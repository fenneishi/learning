//有向图：w=-1(i==j)、0(不存在边)、(0,∞)(存在边，数值代表权重)
//无向图：w=-1(i==j)、0(不存在边)、(0,∞)(存在边，数值代表权重)


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MaxVertices 100

typedef struct
{
    int Vertices[MaxVertices];
    int Edges[MaxVertices][MaxVertices];
    int num_V;
    int num_E;
    int direction;
}AdjMatrix;


AdjMatrix *Creat_Graph();
void Print_Graph(AdjMatrix *Graph);
void Change_Vex(AdjMatrix *Graph,int i);
void Change_Ege(int StartVex,int EtartVex,int EdgeWeight,AdjMatrix *Graph);
int main(void)
{
    AdjMatrix *Graph;
    Graph=Creat_Graph();
    Print_Graph(Graph);
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
    for(i=1;i<=Graph->num_V;i++)printf("%8d",Graph->Vertices[i]);
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
{s
    printf("input the %d Vertice data:",i);
    scanf("%d",&Graph->Vertices[i]);
}
void Change_Ege(int j,int k,int w,AdjMatrix *Graph)
{
    switch(Graph->direction)
        {
            case 0:Graph->Edges[k][j]=Graph->Edges[j][k]=w;break;// 无向图利用对称性完成另一半。
            case 1:Graph->Edges[j][k]=w;break;
        }
}


