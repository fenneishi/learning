# include"wine.h"
using namespace std;


Wine::Wine(const char *l,int kin,const int yr[],const int bot[])
    :name(l),kind(kin),info(kin,yr,bot)
    {};


Wine::Wine(const char *nm,int kin)
    :name(nm),kind(kin),info(kin)
    {};

void Wine::GetBottles()
{
    cout<<"Enter "+name+" for "<<kind<<" year(s): "<<endl;
    for(int i=0;i<kind;i++)
    {
        cout<<"enter year:";
        int year;
        (cin>>year).get();
        info.pushYear(i,year);
        cout<<"enter bottles for that year:";
        int bottles;
        cin>>bottles;
        info.pushBottle(i,bottles);
    }
}


void Wine::show()
{
    cout<<"year"<<"  "<<"Bottels"<<endl;
    info.show();
}

string& Wine::label()
{
    return name;
}

int Wine::sum()
{
    return info.sumBottles();
}

Wine::~Wine(){}



template<class T,class K>
Pair<T,K>::Pair(int kind)
    :years(kind),bottles(kind){}

template<class T,class K>
Pair<T,K>::Pair(int kind,const int *yr,const int *bot)
    :years(yr,kind),bottles(bot,kind){}

template<class T,class K>
void Pair<T,K>::pushYear(int i,int yr)
{
    years[i]=yr;
}

template<class T,class K>
void Pair<T,K>::pushBottle(int i,int bot)
{
    bottles[i]=bot;
}

template<class T,class K>
void Pair<T,K>::show()
{
    for(int i=0;i<years.size();i++)
    {
        cout<<years[i]<<"  "<<bottles[i]<<endl;
    }
}

template<class T,class K>
int Pair<T,K>::sumBottles()
{
    return bottles.sum();
}

// template <typename type> istream& operator>>(istream& is,type& info)
// {
    
// }

// template <typename type> ostream& operator<<(ostream& os,const type& info)
// {

// }

template<class T,class K>
Pair<T,K>::~Pair()
{

}
