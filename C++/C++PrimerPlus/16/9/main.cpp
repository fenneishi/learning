#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

#define size 10000000

int main(int argc, char const *argv[])
{
    vector<int> o(size);
    for(int i=0;i<size;i++)
    {
        o.push_back(rand()/10);
    }
    vector<int> ov(o);
    list<int>   ol(size);
    copy(o.begin(),o.end(),ol.begin());

    clock_t start=clock();
        sort(ov.begin(),ov.end());
    clock_t end=clock();
    cout<<"vector sort time:"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    

    start=clock(); 
         ol.sort();
    end=clock();
    cout<<"  list sort time:"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    

    return 0;
}
