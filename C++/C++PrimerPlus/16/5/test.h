


#if !defined(TEST_H_)
#define TEST_H_

#include "common.h"
#include "reduce.h"
template<class T>
void test(const initializer_list<T> &ril)
{
    
    T t[ril.size()];
    copy(ril.begin(),ril.e nd(),t);

    
    //原始情况显示
    cout<<"---------------------"<<endl;
    cout<<"Original:"<<endl;
    cout<<ril.size()<<endl;
    for(auto x:t)cout<<x;cout<<endl;

    //去重和排序
    int num=reduce(t,ril.size());

    //结果显示
    cout<<"Result:"<<endl;
    cout<<num<<endl;
    for(auto x:t)
    {
        if(0==x)break;
        cout<<x;
    }
    cout<<endl;


    

}


#endif // TEST_H_


