// 输入元素个数n和各个元素，最小值放到第一个，最大值放到最后一个，然后输出结果


# include<stdio.h>
# include<math.h>

void change(int *nums,int count);
int getnumbers(int *nums,int count);
void resprint(int *nums,int count);

int main(void)
{
    int count,i;
    int nums[10];
    
    count=getnumbers(nums,count);
    change(nums,count);
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

// 找到最大值和最小值坐标，然后最大值换到最后一个，最小值换到第一个
void change(int *nums,int count){
    int i,max_n,min_n,temp;
    max_n=min_n=0;
    for(i=1;i<count;i++){
        if(nums[i]>nums[max_n]){max_n=i;}
        if(nums[i]<nums[min_n]){min_n=i;}
    }
    
    temp=nums[0];
    nums[0]=nums[min_n];
    nums[min_n]=temp;

    temp=nums[count-1];
    nums[count-1]=nums[max_n];
    nums[max_n]=temp;

}





