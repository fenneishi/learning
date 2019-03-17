

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 



int main(void)
{  
    char *week[5],*max;
    int num,i;
    
    
    for(i=0;i<=4;i++)
    {
        printf("input string:");
        week[i]=(char *)malloc(100*sizeof(char));
        scanf("%s",week[i]);
    }
    for(i=0,max=week[0],num=strlen(week[0]);i<=4;i++)
    {
        if(num<strlen(week[i]))
        {
            max=week[i];
            num=strlen(week[i]);
        }
    }
    printf("the max is : '%s' \n",max);


    return 0;
}





