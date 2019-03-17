# include"wine.h"
using namespace std;


Wine::Wine(const char *l,int kin,const int yr[],const int bot[])
    :name(l),kind(kin),PairArray(kin,yr,bot)
    {};


Wine::Wine(const char *nm,int kin)
    :name(nm),kind(kin),PairArray(kin)
    {};

void Wine::GetBottles()
{
    cout<<"Enter "+name+" for "<<kind<<" year(s): "<<endl;
    for(int i=0;i<kind;i++)
    {
        cout<<"enter year:";
        int year;
        (cin>>year).get();
        pushYear(i,year);
        cout<<"enter bottles for that year:";
        int bottles;
        cin>>bottles;
        pushBottle(i,bottles);
    }
}


void Wine::show()
{
    cout<<"year"<<"  "<<"Bottels"<<endl;
    PairArray::show();
}

string& Wine::label()
{
    return name;
}

int Wine::sum()
{
    return PairArray::sumBottles();
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


template<class T,class K>
Pair<T,K>::~Pair()
{

}


/*
继承
    1、内存角度含有父类成员，但是无法访问。
    2、函数角度：
        1、函数名称：类域名::函数名(必要时加上类域名）
        2、参数匹配：第1个参数是this指针，小心upcast。
模板
    1、模板是模板，类是类，模板实例化后就是类，模板具体化仍是模板。
    2、类继承的是类，可以作为模板的参数也是类，一般不是类。
    3、




*/