#include <iostream>
#include <string>
using namespace std;

class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv);
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj) const;
	void Display()const;
};


int main(int argc, char const *argv[])
{
    
	Cpmv cpmv1 = Cpmv("112233", "445566");
    /* 
    理论上:  Cpmv("112233", "445566")调用Cpmv(string q, string z)
	        构造函数创建一个临时对象，它属于一个右值，因在定义时用'='，则首选
            调用Cpmv(Cpmv && mv)移动构造函数将临时对象赋给cpmv1对象。 
    实际上:  string, string constructor called.编译器做了智能优化，压根就没有创建一个临时右值对象。
            直接把“Cpmv cpmv1 = Cpmv("112233", "445566");” 转化成“Cpmv cpmv1("112233", "445566")”
    */
    cout<<"-----------cpmv1-----------------\n";

	Cpmv cpmv2("1234", "5678");
    cout<<"-----------cpmv2-----------------\n";

	Cpmv cpmv3 = cpmv1;
    cout<<"-----------cpmv3-----------------\n";

	Cpmv cpmv4;
    cout<<"-----------cpmv4-----------------\n";

	cpmv4 = cpmv2;
    cout<<"-----------cpmv4-----------------\n";

    Cpmv cpmv5;
    cout<<"-----------cpmv5-----------------\n";
	
	cpmv5 = cpmv3 + cpmv4;
    /* 
    理论上:  cpmv3 + cpmv4首先调用cpmv3.operator+(cpmv4)创建一个临时
	        对象，它是一个右值(return返回temp对象右值)，然后调用
	        cpmv5.operator=(cpmv3 + cpmv4的返回值)移动赋值运算符。
    实际上:  于理论基本一致,确实创建了一个临时对象。
            default constructor called.
            add assignment operator called.
            move assignment operator called.
            destructor called.
    */
    cout<<"-----------cpmv5-----------------\n";

    cout<<"                            \n";
    cout<<"                            \n";
    cout<<"                            \n";  
	std::cout << "cpmv1 contents:\n";
	cpmv1.Display();
	std::cout << "cpmv2 contents:\n";
	cpmv2.Display();
	std::cout << "cpmv3 contents:\n";
	cpmv3.Display();
	std::cout << "cpmv4 contents:\n";
	cpmv4.Display();
	std::cout << "cpmv5 contents:\n";
	cpmv5.Display();
 
	return 0;


}




Cpmv::Cpmv()
{
    pi=new Info;
    cout << "default constructor called.\n";
}
Cpmv::Cpmv(string q, string z)
{
    pi=new Info;
    pi->qcode=q;
    pi->zcode=z;
    std::cout << "string, string constructor called.\n";
}
Cpmv::Cpmv(const Cpmv& cp)
{
    pi=new Info;
    pi->qcode=cp.pi->qcode;
    pi->zcode=cp.pi->zcode;
    std::cout << "copy constructor called.\n";
}
Cpmv::Cpmv(Cpmv&& mv)
{
    pi=mv.pi;
    mv.pi=nullptr;
    cout << "move constructor called.\n";
}
Cpmv::~Cpmv()
{
    delete pi;
    cout << "destructor called.\n";
}
Cpmv& Cpmv::operator=(const Cpmv& cp)
{
    if(this==&cp)return *this;
    pi=new Info;
    pi->qcode=cp.pi->qcode;
    pi->zcode=cp.pi->zcode;
    cout << "copy assignment operator called.\n";
    return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& mv)
{
    if(this==&mv)return *this;
    pi=mv.pi;
    mv.pi=nullptr;
    cout << "move assignment operator called.\n";
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj) const
{
    Cpmv temp;
    temp.pi->qcode=pi->qcode+obj.pi->qcode;
    temp.pi->zcode=pi->zcode+obj.pi->zcode;
    cout << "add assignment operator called.\n";
    return temp;
}
void Cpmv::Display()const
{
    cout << "pi->qcode: " << pi->qcode << endl;
	cout << "pi->zcode: " << pi->zcode << endl;
}
