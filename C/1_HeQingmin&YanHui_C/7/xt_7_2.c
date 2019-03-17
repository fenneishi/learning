// 从大到小排序

# include<stdio.h>
# include<math.h>

void sort(int *nums,int count);
int getnumbers(int *nums,int count);
void resprint(int *nums,int count);

int main(void)
{
    int count,i;
    int nums[10];
    
    count=getnumbers(nums,count);
    sort(nums,count);
    resprint(nums,count);
    
    return 0;
}


int getnumbers(int *nums,int count){
    int i;
    printf("please input the count(1<cont<=10) of numbers:");
    scanf("%d",&count);
    printf("please input %d numbers:",count);
    for(i=0;i<count;i++)scanf("%d",&nums[i]);
    return count;
}


void resprint(int *nums,int count){
    int i;
    printf("the result after sort:");
    for(i=0;i<count;i++)printf("%d ",nums[i]);
    printf("\n");
}

// 冒泡排序
void sort(int *nums,int count){
    int i,j,temp;
    for(i=0;i<=count-1-1;i++){          // i=1 不行，因为后面有count-1-i,另外，count-1 就是最后一个元素了，因为是第一个是0
        for(j=0;j<=count-1-1-i;j++){   // j=1 不行，因为不能把第一个元素漏掉了。
            if(nums[j]>nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}





