

# include "stock.h"

Stock::Stock()
{
    shares=0;
    shar_val=0;
    set_tot();
    company=new char[20];
    strcpy(company,"default company");
    cout<<"-------------------------------------"<<company<<": default construct!"<<endl;
}


Stock::Stock(const char *co,int n,double per)//一个注意点：explicit
{
    shares=n;
    shar_val=per;
    set_tot();
    company=new char[strlen(co)+1];
    strcpy(company,co);
    cout<<"-------------------------------------"<<company<<": copy construct!"<<endl;

}
Stock::Stock(const Stock &s)//只要一个注意点：深拷贝
{
    shares=s.shares;
    shar_val=s.shar_val;
    set_tot();
    company=new char[strlen(s.company)+1];
    strcpy(company,s.company);
}
void Stock::buy(int num,double price)
{
    shares+=num;
    shar_val=price;
    set_tot();
}
void Stock::sell(int num,double price)
{
    shares-=num;
    shar_val=price;
    set_tot();
}
void Stock::update(double price)
{
    shar_val=price;
    set_tot();
}

const Stock& Stock::topval(const Stock &s)const
{
    if(shar_val>=s.shar_val)
        return (*this);
    else 
        return (s);
}

// 只有要返回局部变量的时候，才会用非引用
Stock & Stock::operator=(const Stock &s)//深拷贝，delete,不能自己到自己
{
    if(this==&s) 
        return *this;
    
    shares=s.shares;
    shar_val=s.shar_val;
    set_tot();

    delete[] company;
    company=new char[strlen(s.company)+1];
    strcpy(company,s.company);

    return *this;
}

Stock & Stock::operator=(const char *ch)
{
    return *this;
}
ostream & operator<<(ostream & os,Stock const & s)
{
    os<<"company: "<<s.company<<endl;;
    os<<"shares: "<<s.shares<<endl;;
    os<<"shar_val: "<<s.shar_val<<endl;;
    os<<"tot_val: "<<s.total_val;//这里尽量不要加endl;
    return os;
}
istream & operator>>(istream & is,Stock & ss)
{
    cout<<"input the name of company: ";
    char temp[100];
    is.get(temp,100);
    if(is)
        ss=temp;
    while(cin&&is.get()!='\n')
        continue;
    
    cout<<"shares: ";
    is>>ss.shares;
    cout<<"shar_val:";
    is>>ss.shar_val;
    ss.set_tot();
    return is;
}


Stock::~Stock()
{
    delete [] company;
    cout<<"-------------------------------------"<<company<<": destruct!"<<endl;
}