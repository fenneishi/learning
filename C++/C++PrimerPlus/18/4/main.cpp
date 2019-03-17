#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

// 函数对象
template<class T>  // functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) { }
	bool operator()(const T & v) { return v > cutoff; }
};



void outInt(int n){cout<<n<<" ";}
int main(int argc, char const *argv[])
{
    

	list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> etcetera = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "Original lists:\n";
    auto outint=[](int n){cout<<n<<" ";};
    for_each(yadayada.begin(),yadayada.end(),outInt);
    cout<<endl;
    for_each(etcetera.begin(),etcetera.end(),outInt);
    cout<<endl;
    
    
    yadayada.remove_if([](int n){ return n > 100; }); 
    etcetera.remove_if(TooBig<int>(200)); //模板类实例化的时候，必须指明模板参数类型。
    cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(),[](int n){cout<<n<<" ";});
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(),[](int n){cout<<n<<" ";});
	cout << endl;

    return 0;
}
