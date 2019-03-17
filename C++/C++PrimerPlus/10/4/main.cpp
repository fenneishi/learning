# include "sale.h"



int main(int argc, char const *argv[])
{
    SALES::Sales markingTeam1;
    markingTeam1.setSales();
    markingTeam1.showSales();

    int num=3;
    double sales[3]={99.34,11.65,32.89};
    SALES::Sales markingTeam2(sales,num);

    // SALES::Sales markingTeam2({99.34,11.65,32.89},3); //形参是一个double 指针时候，无法接受这个初始化列表
    markingTeam1.showSales();

    
    
    return 0;
}
