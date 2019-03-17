
#include "common.h"
#include "test.h"
#include "reduce.h"






int main(int argc, char const *argv[])
{
    
    //程序缺陷，不能有0;
    test<char>({'h','e','l','l','o','w','o','r','l','d'});
    test<int>({1,7,6,1,1,2,7,1,8,2,2});
    test<long>({1,3,7,5,9,7,3,1,6,1,1});
    cout<<"============="<<endl;

    return 0;
}






/*

// std::ostream_iterator<char,char>couter(cout," ");
// copy(s_set.begin(),s_set.end(),couter);
    // // 显示集合内部情况
    

// T t=ril;
    // // array initializer must be an initializer list
    // // 猜测：数组的初始化虽然是可以用初始化列表，但是这是语法层面的，并非数组真的有一个形参是std::initializer_list的构造函数
    // // 而vectordeng容器，是有个构造函数是std::initializer_list，所以数组你只能用初始化列表字面量去初始化，而不能用std::initializer_list对象去初始化。
  



*/