

#include <stdio.h>
#include <stdlib.h> 

#define MaxSize 3

struct book
{
    char name[100];
    int price;
}books[MaxSize],max,min;



int main(void)
{   
    int i;
    for(i=0;i<MaxSize;i++)
    {
        printf("input the number %d book name  :",i+1);
        scanf("%s",books[i].name);
        printf("input the number %d book price :",i+1);
        scanf("%d",&books[i].price);
    }

    min=max=books[0];
    for(i=0;i<MaxSize;i++)
    {
        if(max.price<books[i].price)max=books[i];
        if(min.price>books[i].price)min=books[i];
    }
    
    printf("max:name=%s,price=%d\n",max.name,max.price);
    printf("min:name=%s,price=%d\n",min.name,min.price);

    
    return 0;
}