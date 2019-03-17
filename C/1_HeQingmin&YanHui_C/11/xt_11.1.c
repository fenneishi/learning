

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int main(void)
{  
    char *month[13]={NULL,"Jan","Feb","Mar","Apr","May","Jun","Aug","Sep","Oct","Nov","Dec"};
    int num;
    printf("please input the number:");
    scanf("%d",&num);
    printf("it is : %s\n",month[num]);
    return 0;
}

