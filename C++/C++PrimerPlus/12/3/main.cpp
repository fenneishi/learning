# include "stock.h"


const int STKS=4;


int main(int argc, char const *argv[])
{
    Stock stocks[STKS] =
    {
        Stock("name1",12,20.0),
        Stock("name2",200,2),
        Stock("name3",130,3.25),
        Stock("name4",60,6.5),
    };

    cout<<"stock holdings:\n";
    int st;
    for(st=0;st<STKS;st++)
        cout<<stocks[st]<<endl;

    const Stock *top = &stocks[0];
        top=&(top->topval(stocks[st]));

    std::cout<<"\nMost valuable holding:\n";
    cout<<(*top)<<endl;;


    return 0;
}
