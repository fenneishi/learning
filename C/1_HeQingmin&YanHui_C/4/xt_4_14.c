# include<stdio.h>
# include<math.h>



int main(void)
{
    int i,s;
    
    s = 1;
    printf("第9天剩余： 1\n");
    for(i=8;i>=0;i--){
        s=2*(s+1);
        printf("第%d天剩余： %d\n",i,s);
    }
    return 0;
}

 