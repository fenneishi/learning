// 从大到小排序


# include<stdio.h>
# include<math.h>

int get_Matrix(int (*nums)[6],int order);
int if_UpperTriangularMatrix(int (*nums)[6],int order);


int main(void)
{
    int order;
    int nums[6][6];
    int res;
    
    order=get_Matrix(nums,order);
    
    switch (if_UpperTriangularMatrix(nums,order)){
        case 1:printf("Yes\n");break;
        case 0:printf("NO\n");break;
    }
    
    return 0;
}


int get_Matrix(int (*nums)[6],int order){
    int i,j;
    printf("please input the order of square matrix:");
    scanf("%d",&order);
    for(i=0;i<order;i++){
        printf("please input the %d lins :",i+1);
        for(j=0;j<order;j++){
            scanf("%d",&nums[i][j]);
        }  
    }
    return order;
}



// 判断是否我上三角矩阵
int if_UpperTriangularMatrix(int (*nums)[6],int order){
    int i,j,sign=1;
    for(i=0;i<order;i++){    
        for(j=0;j<i;j++){
            if(nums[i][j]!=0){sign=0;break;}
        }
        if(sign==0)break;
    }
    return sign;
}



