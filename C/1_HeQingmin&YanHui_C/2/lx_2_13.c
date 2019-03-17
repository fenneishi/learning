# include<stdio.h>
# include<math.h>

int main(void)
{
    int i,n;
    float  sum;             /*  must be float */
    sum=0 ;                   /*  一定要赋初值 */
    

    printf("Enter n:");
    scanf("%d",&n);
    

    for(i=1;i<=n;i++){
        sum = sum+1.0/i;       /*  must be 1.0 */
    }

    printf("n=%d  sum=%.2f\n",n,sum);   /*  must be sum=%f  */

    return 0;
}