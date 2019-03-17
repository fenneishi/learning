#include"wine.h"



int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;

    
    cout<<"enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout<<"enter kind of years: ";
    int kind;
    cin>>kind;
    Wine holding(lab,kind);
    holding.GetBottles();
    cout<<"-------------------------------------------"<<endl;
    holding.show();



    cout<<"-------------------------------------------"<<endl;
    const int YRS=3;
    int y[YRS]={1993,1995,1998};
    int b[YRS]={48,60,72};
    Wine more("Gushing Grape Red",YRS,y,b);
    more.show();
    cout<<"Total bottles for "<<more.label()
        <<": "<<more.sum()<<endl;
    cout<<"Bye\n";
    return 0;
}
