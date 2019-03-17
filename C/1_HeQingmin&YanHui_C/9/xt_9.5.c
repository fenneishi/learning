

#include <stdio.h>
#include <stdlib.h> 

#define MaxSize 3
struct birthday
{
    int year,month,day;
};

struct contact
{
    char name[100];
    struct birthday birthday;
    int phone;
    int address;
}contacts[MaxSize],temp;



int main(void)
{   
    int i;
    int j;
    for(i=0;i<MaxSize;i++)
    {
        printf("input the number %d people name  :",i+1);
        scanf("%s",contacts[i].name);
        printf("input the number %d people birth,like 1992-8-2 :",i+1);
        scanf("%d-%d-%d",&contacts[i].birthday.year,&contacts[i].birthday.month,&contacts[i].birthday.day);
        printf("input the number %d people phone  :",i+1);
        scanf("%d",&contacts[i].phone);
        printf("input the number %d people address  :",i+1);
        scanf("%d",&contacts[i].address);
    }

    
    for(i=MaxSize-1-1;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if
            (
                (contacts[j].birthday.year >  contacts[j+1].birthday.year)
                ||
                (contacts[j].birthday.year == contacts[j+1].birthday.year && contacts[j].birthday.month > contacts[j+1].birthday.month)
                ||
                (contacts[j].birthday.year == contacts[j+1].birthday.year && contacts[j].birthday.month == contacts[j+1].birthday.month && contacts[j].birthday.day > contacts[j+1].birthday.day)
            )
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;

            }
        }
    }

    for(i=0;i<MaxSize;i++)
    {
       printf
       (
        "%s-%d/%d/%d-%d-%d\n",
        contacts[i].name,
        contacts[i].birthday.year,contacts[i].birthday.month,contacts[i].birthday.day,
        contacts[i].phone,
        contacts[i].address
        );
    }
    

    
    return 0;
}