#include <iostream>
#include <set>


using std::cout;
using std::endl;
using std::cin;
using std::set;
using std::copy;




int reduce(char s[],int n);

int main(int argc, char const *argv[])
{
    char s[]="helloworld";
    cout<<s<<endl;
    int num=reduce(s,10);
    cout<<s<<endl;
    cout<<num<<endl;
    return 0;
}


int reduce(char s[],int n)
{
    // 通过集合进行排序和去重
    set<char> s_set(s,s+n);

    // // 显示集合内部情况
    // std::ostream_iterator<char,char>couter(cout," ");
    // copy(s_set.begin(),s_set.end(),couter);

 


    //返还到数组中
    copy(s_set.begin(),s_set.end(),s);
    *(s+s_set.size())=0;//

    // 返回新的字符串长度
    return s_set.size();
}