# include<stdio.h>
# include<math.h>


int main(void)
{
    int prime(int m);
    int i,num,max;

    printf("please input a num:");
    scanf("%d",&num);

    i=1;                                    // 因为i++放到起始位置，所以i=1而非i=2;
    while(num>1){                           
        i++;                                // i++ 放在开始的原因：因为后面可能会重置i到起始值，所以要把i++放到开始，
        if((prime(i)==1)&&(num%i==0)){
            printf("%d*",i);
            num=num/i;
            i=1;                            //循环回到起始位置，从新来
        }

    }
    printf("\n");
    
    return 0;
}


int prime(int m){

    int i;
    if(m<=0)return 0;
    else{
        for(i=2;i<=m/2.0;i++)if(m%i==0)break;
        if(i>m/2&&m!=1)return 1;
        else return 0;
    }
    
    return 0;
}