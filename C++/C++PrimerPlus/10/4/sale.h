# include <iostream>
using  namespace std;


namespace SALES
{
    
    class Sales
    {
    private:
        static const int QUARTER=4;
        double _sales[QUARTER];//C++里面尽量不要用数组字符串太恶心了！
        double _average;
        double _max;
        double _min;       
    public:
        Sales();
        Sales(const double sales[],int n);
        void setSales();
        void showSales();
        ~Sales() { }
    };
    

} // SALES
