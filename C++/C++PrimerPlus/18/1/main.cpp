#include <iostream>
#include <initializer_list>
using namespace std;

// 方案1:
template<typename T=double> //C++11可以带默认值
T  average_list(const initializer_list<T> &numList);

// // 方案2：
// template<typename T>
// T average_list(const T& value);
// template<typename... Args>
// T average_list(Args... args);


int main(int argc, char const *argv[])
{
    auto q=average_list({15.4,10.7,9.0});
    cout<<q<<endl;
    cout<<average_list({20,30,19,17,45,38})<<endl;
    auto ad=average_list<double>({'A',70,65.33});
    cout<<ad<<endl;
    return 0;
    return 0;
}


// 方案1:
// 优点:丰富的成员函数(迭代器、size())可以简化编程。
// 缺点：list里的元素类型必须是一致的。
template<class T>
T  average_list(const initializer_list<T> &numList)
{
    T sum=0;
    for(auto num:numList)
    {
        sum+=num;
    }
    return (numList.size()==0?sum:sum/numList.size());
}


// // 方案2：因为递归带来的逻辑复杂，所以没有必要再去实现了。
// // 优点：实参{}中的类型不必强行一致。
// // 缺点：
// // 递归耗内存，效率低
// // 有些逻辑不适合用递归来实现，用递归实现会带来逻辑的复杂性。
// // 没有必要的库函数，如size(),迭代器等等,这会让解决问题变得复杂，这也是必须要用递归来解决的原因。

// template<typename T>
// T average_list(const T& value)
// {

// }
// template<typename T,typename... Args>
// T average_list(T value,Args... args)
// {
//     static int count=0;
//     static int sum=0;
//     sum+=value;
//     count++;
//     return average_list(args);
// }




