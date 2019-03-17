// 明文加密：把前三个字母放到最后

# include<stdio.h>
# include<string.h>


int main(void)
{   
    char a[100],b[100],c[100];
    int i;

    printf("input:");
    scanf("%s",a);


    printf("%ld\n",strlen(a));
    for(i=0;i<=2;i++)b[i]=a[i];
    for(i=3;i<strlen(a);i++)c[i-3]=a[i];
    
    printf("the res is :%s \n",c);
    printf("the res is :%s \n",strcat(c,b));

    return 0;
}

