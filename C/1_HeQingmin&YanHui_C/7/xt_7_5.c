
// 找出方阵的一个鞍点（该行最大，该列最小),找到输出下标，否则输出NO.


# include<stdio.h>
# include<math.h>

int main(void)
{
    int n;  // 矩阵的阶数
    int matrix[6][6];
    int i,j;
    int line_max[3],row_min[3];
    int Saddle[3]={0,0,0};
    // 获得方阵的阶数
    printf("please input the order of matrix:");
    scanf("%d",&n);
    // 获得方阵
    for(i=0;i<n;i++)
    {
        printf("please input the number of %d line:",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    //找出每一行最大值,每一列最小值。
    for(i=0;i<n;i++)
    {
        line_max[i]=matrix[i][0];
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]>line_max[i])line_max[i]=matrix[i][j];
        }
        row_min[i]=matrix[0][i];
        for(j=0;j<n;j++)
        {
            if(matrix[j][i]<row_min[i] )row_min[i] =matrix[j][i];
        }
    }

    // 遍历判断每个点，是不是鞍点。
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==line_max[i]&&matrix[i][j]==row_min[j])
            {
                Saddle[0]=matrix[i][j];
                Saddle[1]=i+1;
                Saddle[2]=j+1;  
            }
        }
    }

    // 输出结果
    if(Saddle[1]==0)printf("NO\n");
    else printf("the saddle point is x=%d,y=%d,value=%d\n",Saddle[1],Saddle[2],Saddle[0]);

    return 0;
}


