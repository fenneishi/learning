
// 从用户处得到一个m*n行矩阵，然后求出各行元素之和，然后输出。


# include<stdio.h>
# include<math.h>

int main(void)
{
    int m,n;
    int matrix[6][6];
    int i,j;
    int sum=0;

    printf("please input the count of lines:");
    scanf("%d",&m);
    printf("please input the count of rows:");
    scanf("%d",&n);

    for(i=0;i<m;i++){
        printf("please input the number of %d line:",i+1);
        for(j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    for(i=0;i<m;i++){
        sum=0;
        for(j=0;j<n;j++)sum+=matrix[i][j];
        printf("the sum of %3d line is: %d\n",i+1,sum);
    }
    
    return 0;
}


