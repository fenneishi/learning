#
#if !defined(REDUCE_H_)
#define REDUCE_H_

#include "common.h"

int zero(int n){return 0;}

template<class T>
int reduce(T s[],int n)
{
    // 通过集合进行排序和去重
    set<T> s_set(s,s+n);

    //返还到数组中d
    copy(s_set.begin(),s_set.end(),s);
    auto end=s+s_set.size();
    transform(end,s+n,end,zero);//多余元素置为0;

    // 返回新的字符串长度
    return s_set.size();
}

#endif // REDUCE_H_
