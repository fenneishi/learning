

# include "time.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Time t1;
    Time t2(3,40);

    cout<<"t1:"<<t1<<endl;
    cout<<"t2:"<<t2<<endl;

    t1.addHour(1);
    cout<<"t1.addHour(1)"<<endl;
    t2.addMine(30);
    cout<<"t2.addMine(30)"<<endl;

    cout<<"t1:"<<t1<<endl;
    cout<<"t2:"<<t2<<endl;

    Time t3=t1+t2;
    cout<<"t3=t1+t2"<<endl;
    cout<<"t3:"<<t3<<endl;


    Time t4=t2-t1;
    cout<<"t4=t2-t1"<<endl;
    cout<<"t4:"<<t4<<endl;


    Time t5;

    cout<<"t5:"<<t5<<endl;
    cin>>t5;
    cout<<"t5:"<<t5<<endl;
    return 0;
}
