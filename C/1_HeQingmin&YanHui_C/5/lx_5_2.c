# include<stdio.h>
# include<math.h>



int main(void)
{
    int m,n;
    int max(int m,int n);
    int res;

    printf("please input first number:");
    scanf("%d",&m);
    printf("please input second number:");
    scanf("%d",&n);
    printf("the bigger one is : %d\n",max(m,n));

    return 0;
}

int max(int m,int n){                  // 不写int 编译器会给出警告，但是不会出错，可以正常运行，因为不写就会默认为int类型。    
        int res;
        if(m>=n)return m;
        else return n;     
}
