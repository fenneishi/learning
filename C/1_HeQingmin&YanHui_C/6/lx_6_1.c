# include<stdio.h>
# include<math.h>

int eight(int num);
int sixteen(int num);

int main(void)
{
    int num;

    printf("please input a num:");
    scanf("%d",&num);
    printf("eight is : %o\n",num);
    printf("sixteen is : %x\n",num);
    return 0;

}


// int eight(int num){
//     int res;
//     res = 0;
//     while(num>0){
//         res= res
//     }

//     return res;
// }

// int sixteen(int num){
//     int res;
//     return res;
// }