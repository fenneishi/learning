# include "sale.h"


namespace SALES
{
    
    Sales::Sales()
    {
        for(int i=0;i<Sales::QUARTER;i++)_sales[i]=0;
        _average=_max=_min=0;
    }

    Sales::Sales(const double sales[],int n)
    {
        if(n>Sales::QUARTER){cout<<"warning num>4"<<endl;n=(Sales::QUARTER);}
        double sum=0;
        _max=0;
        _min=100000000;
        for (int i = 0; i < n; i++)
        {
            _sales[i] = sales[i];
            sum += sales[i];
            if(sales[i]>=_max)_max=sales[i];
            if(sales[i]<=_min)_min=sales[i];
        }
        _average=sum/n;
    }

    // Sales::~Sales()
    // {
    //     cout<<"destruct sales object!"<<endl;
    // }

    void Sales::setSales()
    {
        double sum=0;
        _max=0;
        _min=100000000;
        for (int i = 0; i < Sales::QUARTER; i++)
        {
            cout<<"input the "<<i<<"sale";
            cin>>_sales[i];
            sum += _sales[i];
            if(_sales[i]>=_max)_max=_sales[i];
            if(_sales[i]<=_min)_min=_sales[i];
        }
        _average=sum/Sales::QUARTER;
    }
    void Sales::showSales()
    {
        for (int i = 0; i < Sales::QUARTER; i++)
        {
            cout<<_sales[i]<<"  "<<endl;
        }
    }

} // SALES
