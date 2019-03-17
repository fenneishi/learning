# include<stdio.h>
# include<math.h>


int main(void)
{
    int num[10];
    int i,n;
    int max=0;
    

    printf("please intput n:");
    scanf("%d",&n);
    printf("please intput the numbers:");
    for(i=0;i<n;i++){scanf("%d",&num[i]);}

    for(i=1;i<n;i++){
        if(num[i]>num[max])max=i;
    }

    printf("最大值下标=%d，值=%d",max,num[max]);
    printf("\n");

    num[max]^=num[n-1]^=num[max]^=num[n-1];

    for(i=0;i<n;i++){printf("%d ",num[i]);}
    printf("\n");  
    
    return 0;
}

