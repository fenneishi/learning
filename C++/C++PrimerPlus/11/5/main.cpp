


# include "stonewt.h"

int main(int argc, char const *argv[])
{
    Stonewt s1;
    Stonewt s2(11.11);
    Stonewt s3(22,22.22);

    cout<<"LBS"<<endl;
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    cout<<"s3:"<<s3<<endl;

    s1.tostn();
    s2.tostn();
    s3.tostn();

    cout<<"STN"<<endl;
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    cout<<"s3:"<<s3<<endl;


    return 0;
}
