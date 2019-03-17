
#if !defined(WINE_H)
#define WINE_H

#include<iostream>
#include<valarray>
#include<string>
using namespace std;


// template <typename type>  istream& operator>>(istream& is,type& info);
// template <typename type> ostream& operator<<(ostream& os,const type& info);
template<class T,class K>
class Pair
{
private:
    T years;
    K bottles;
public:
    Pair(int kind);
    Pair(int kind,const int *yr,const int *bot);
    void pushYear(int i,int year);
    void pushBottle(int i,int bottle);
    void show();
    int sumBottles();
    // friend istream& operator>> <Pair<T,K> > (istream& is,Pair<T,K>& info);
    // friend ostream& operator<< <Pair<T,K> >(ostream& os,const Pair<T,K>& info);
    ~Pair();
};

class Wine
{
private:
    typedef valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt> PairArray;
    string name;
    PairArray info;
    int kind;
public:
    Wine(const char *l,int y,const int yr[],const int bot[]);
    Wine(const char *l,int y);
    void GetBottles();
    void show();
    string &label();
    int sum();
    virtual ~Wine();
};



# endif // WINE_H
