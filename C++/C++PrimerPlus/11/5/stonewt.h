# ifndef STONEWT_H_
# define STONEWT_H_

# include<iostream>
# include<string>
using namespace std;



class Stonewt
{
private:
    const static int Lbs_per_stn=14;
    enum State{LBS,STN};
    State state;
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt();
    Stonewt(double lbs,State st=LBS);
    Stonewt(int stn,double lbs,State st=LBS);

    void toLbs();
    void tostn();

    friend ostream & operator<<(ostream&,const Stonewt &);
    ~Stonewt();
};






# endif