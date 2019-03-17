# include<stdio.h>
# include<math.h>



int main(void)
{
    int x,y;

    printf("please input x:");
    scanf("%d",&x);

    if(x<0){y=-1;}
    else if (x==0){y=0;}
    else{y=1;}

    printf("%d\n",y);    

    return 0;
}

