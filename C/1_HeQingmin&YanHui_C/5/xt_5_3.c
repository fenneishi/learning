# include<stdio.h>
# include<math.h>


double funcos(float x,float e);
double fact(int n);

int main(void)
{
    float x,e;

    printf("please input x:");
    scanf("%f",&x);
    printf("please input e:");
    scanf("%f",&e);

    printf("the resutl of cos(x) is:%.2f\n",funcos(x,e));
    
    return 0;
}

double funcos(float x,float e){     
    int i,flag;
    double item,sum;
    
    sum=0;
    flag =1;
    i=0;
    item = pow(x,i)/fact(i);
    while(item>=e){
        sum=sum+(flag*item);
        flag=-flag;
        i+=2;
        item = pow(x,i)/fact(i);
    }
    
    return sum;
}

double fact(int n){
    int res,i;
    
    res = 1;
    for(i=1;i<=n;i++){
        res=res*i;
    }

    return res;
}