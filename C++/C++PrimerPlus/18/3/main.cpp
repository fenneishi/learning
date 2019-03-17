#include <iostream>
using namespace std;

long double sum_value()
{
    return 0;
}

template<typename T>
long double sum_value( T const value)
{
    return value;
}

template<typename T,typename ...Args>
long double sum_value(T const value,Args... args)
{
    return value+sum_value(args...);
}


int main(int argc, char const *argv[])
{   
    cout << sum_value(1, 2, 3) << endl;
    cout << sum_value('A', 123.456, 0, 10)<<endl;
    return 0;
}

