#include <iostream>
using namespace std;
double sum_value()
{
    return 0;
}

template <typename T>
double sum_value(T value)
{
    return value;
}

template<typename T,typename ...Args>
double sum_value(T value,Args... args)
{
    return value+sum_value(args...);
}


int main(int argc, char const *argv[])
{   
    cout << sum_value(1, 2, 3) << endl;
    cout << sum_value('A', 123.456, 0, 10)<<endl;
    return 0;
}

