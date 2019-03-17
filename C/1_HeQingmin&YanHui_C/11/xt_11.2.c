

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 



int main(void)
{  
    char *week[8]={NULL,"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    char today[10];
    int num;
    int i;
    printf("What day is it today:");
    scanf("%s",today);
    
    for(i=1;i<=7;i++)
    {
        if (!strcmp(week[i], today))
        {
            printf("%d\n", i);
            break;
        }
    }
    if(i==8)printf("Not found\n");


    return 0;
}





