# include<stdio.h>
# include<math.h>


int day_of_year(int year,int month,int day);
int main(void)
{
   
    int year,month,day;
    printf("please input year:");
    scanf("%d",&year);
    printf("please input month:");
    scanf("%d",&month);
    printf("please input day:");
    scanf("%d",&day);
    printf("是%d天\n",day_of_year(year,month,day));
    return 0;
}




// 计算某个日期对应该年的第几天
int day_of_year(int year,int month,int day){
    int k,leap;
    // 初始化数组
    int tab[2][13]={
        {0,31,28,30,30,31,30,31,31,30,31,30,31},
        {0,31,29,30,30,31,30,31,31,30,31,30,31}
    };
    // 判断闰年
    leap = ((year%4==0&&year%100!=0)||year%400==0);   //year闰年是，leap=1，反之，leap=0
    // 计算天数
    for(k=1;k<month;k++)day+=tab[leap][k];  
    return day;
}

