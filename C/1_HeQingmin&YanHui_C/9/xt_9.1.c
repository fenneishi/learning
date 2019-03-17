

#include <stdio.h>
#include <stdlib.h> 

#define MaxSize 10
int Count=0;

struct employee
{
    int num;
    char name[10];
    double base,salary,secure,real;
};

void new_employee(struct employee employees[]);
void output_employee(struct employee employees[]);

int main(void)
{
    int choice,num;
    struct employee employees[MaxSize];
    do
    {
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("choice: 1:new 2:output 0:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: new_employee(employees);break;
            case 2: output_employee(employees);break;
            case 0: break;
        }
    }
    while(choice!=0);
    return 0;
}


void new_employee(struct employee employees[])
{
    struct employee s;
    if(Count==MaxSize)
    {
        printf("this employees array is full \n");
        return;
    }
    printf("input employee's num:");scanf("%d",&s.num);
    printf("input employee's name:");scanf("%s",s.name);
    printf("input base:");scanf("%lf",&s.base);
    printf("input salary:");scanf("%lf",&s.salary);
    printf("input secure:");scanf("%lf",&s.secure);
    s.real=s.base+s.salary-s.secure;
    employees[Count]=s;
    Count++;
}



void output_employee(struct employee employees[])
{
    int i;
    if(Count==0)
    {
        printf("the count of employees is Zero:\n");
        return;
    }
    printf("------------------------------------------------------------------\n");
    printf("num\tname\t\t\tbase\t\tsalary\t\tsecure\t\treal\n");
    for(i=0;i<Count;i++)
    {
        printf("%d\t",employees[i].num);
        printf("%s\t\t\t",employees[i].name);
        printf("%-.0f\t\t",employees[i].base);
        printf("%-.0f\t\t",employees[i].salary);
        printf("%-.0f\t\t",employees[i].secure);
        printf("%-.0f\n",employees[i].real);
    }
    printf("------------------------------------------------------------------\n");
}