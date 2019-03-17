# include<stdio.h>
# include<math.h>


int sign(float x);

int main(void)
{
    float x;
    printf("please input x:");
    scanf("%f",&x);
    printf("the y is : %d\n",sign(x));
    return 0;
}

int sign(float x){                  
    if(x>0)return 1;
    if(x==0)return 0;
    return -1;
}
