

# include "stonewt.h"



Stonewt::Stonewt():stone(0),pds_left(0),pounds(0),state(LBS){}

Stonewt::Stonewt(double lbs,State st)
{
    stone = int(lbs)/Lbs_per_stn;
    pds_left=int(lbs)%Lbs_per_stn+lbs-int(lbs);
    pounds=lbs;
}

Stonewt::Stonewt(int stn,double lbs,State st)
{
    stone=stn;
    pds_left=lbs;
    pounds=stn*Lbs_per_stn+lbs;
}

void Stonewt::toLbs()
{
    state=LBS;
}

void Stonewt::tostn()
{
    state=STN;
}

ostream & operator<<(ostream& os,const Stonewt & S)
{
    if(S.state==Stonewt::LBS)
    {
        os<<S.pounds<<"pounds";
    }
    else if(S.state==Stonewt::STN)
    {
        os<<S.stone<<"stone, "<<S.pds_left<<" pounds";
    }
    else
    {
        os<<"error";
    }
    return os;
}

Stonewt::~Stonewt(){}