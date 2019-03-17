# include<stdio.h>
# include<math.h>

int main(void)
{
    int i,n,tar;
    float  sum;             /*  must be float */
    sum=0 ;                   /*  一定要赋初值 */
    tar = 1;

    printf("Enter n:");
    scanf("%d",&n);
    
    printf("sum=");
    for(i=1;i<=n;i=i+3){
        sum = sum+tar*1.0/i;       /*  must be 1.0 */
        // printf("+(%d/%d)",tar,i);
        if(tar<0){printf("%d/%d",tar,i);}
        else if(i==1){printf("%d/%d",tar,i);}
        else{printf("+%d/%d",tar,i);}
        tar=-tar;
    }
    printf("\n");


    printf("n=%d  sum=%.2f\n",n,sum);   /*  must be sum=%f  */

    return 0;
}