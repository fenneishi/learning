// 输入年份和天数，输出对应的年月日

# include<stdio.h>
# include<math.h>

void month_day(int year,int yeardy,int *pmonth, int *pday);



int main(void)
{
    int year,yeardy,month,day;
    int *pmonth=&month,*pday=&day;


    printf("please input the year of today :");
    scanf("%d",&year);
    printf("please input the day of this month for today :");
    scanf("%d",&yeardy);
    month_day(year,yeardy,pmonth,pday);
    printf("today is %d-%d-%d\n",year,month,day);

    return 0;
}

void month_day(int year,int yeardy,int *pmonth, int *pday)
{
    int k,leap;
    int tab[2][13]=
    {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31},
    };

    // 闰年判别条件： 
    leap = ( (year%400==0)||(year%4==0&&year%100!=0) );

    for(k=1;yeardy>tab[leap][k];k++) yeardy-=tab[leap][k];

    *pmonth=k;
    *pday=yeardy;
}
