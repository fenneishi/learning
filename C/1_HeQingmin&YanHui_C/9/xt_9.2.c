

#include <stdio.h>
#include <stdlib.h> 

#define MaxSize 10
int Count=0;

struct date
{
    int year,month,day;
};

int computer_diff(struct date,struct date);
int computer_year_diff(int Start_year,int End_year);
int computer_month_diff(int start_year,int start_month,int end_year,int end_month);
int computer_day_diff(int Start_day,int End_day); 
int leep(int year);

int main(void)
{   
    struct date StartDate,EndDate;
    struct date *P_StartDate,*P_EndDate;
    P_StartDate = &StartDate;
    P_EndDate   = &EndDate;
    StartDate.year=1990;
    StartDate.month=1;
    StartDate.day=1;
    printf("input the year-month-day: ");
    scanf("%d-%d-%d",&EndDate.year,&EndDate.month,&EndDate.day);
    printf("the days between is : %d\n",computer_diff(StartDate,EndDate));
    return 0;
}
int computer_diff(struct date StartDate ,struct date EndDate)
{
    int res=0;
    int i,j,k;
    if(EndDate.year<StartDate.year)return 0;
    else if(EndDate.year==StartDate.year&&EndDate.month<StartDate.month)return 0;
    else if(EndDate.year==StartDate.year&&EndDate.month==StartDate.month&&EndDate.day<=StartDate.day)return 0;
    res+=computer_year_diff(StartDate.year,EndDate.year);
    res+=computer_month_diff(StartDate.year,StartDate.month,EndDate.year,EndDate.month);
    res+=computer_day_diff(StartDate.day,EndDate.day);
    return res;
}
int computer_year_diff(int start_year,int end_year)
{
    int res=0;
    int year=start_year;
    for(year=start_year;year<end_year;year++)
    {
        switch(leep(year))
        {
            case 1:res+=366;printf("%d year is leap\n",year);break;
            case 0:res+=365;break;
        };
    };
    return res;
}
int computer_month_diff(int start_year,int start_month,int end_year,int end_month)
{
    int leap_year[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int nomal_year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int count_start=0;
    int count_end=0;
    int i;
    for(i=0;i<=start_month;i++)
    {
        switch(leep(start_year))
        {
            case 1:count_start+=leap_year[i] ;break;
            case 0:count_start+=nomal_year[i];break;
        };
        
    }
    for(i=0;i<=end_month;i++)
    {
        switch(leep(start_year))
        {
            case 1:count_end+=leap_year[i] ;break;
            case 0:count_end+=nomal_year[i];break;
        };
        
    }
    return count_end-count_start;
}
int computer_day_diff(int Start_day,int End_day)
{
    return End_day-Start_day;
}
int leep(int year)
{   
    return year%400==0||(year%4==0&&year%100!=0);
}