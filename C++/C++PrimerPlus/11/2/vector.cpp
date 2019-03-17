
#include "vector.h"
#include <cmath>
#include <iostream>

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;


namespace VECTOR
{
    //computer degrees in one radian.
    const double  rad_to_deg=45.0/atan(1);//atan(1)=π/4

    double Vector::getmag()const{return sqrt(_x*_x+_y*_y);}
    double Vector::getang()const{return atan2(_y,_x);}

    void Vector::_set_x(double mag,double ang)  
    {
        _x=mag*cos(ang);
    }
    void Vector::_set_y(double mag,double ang)  
    {
        _y=mag*sin(ang);
    }
    // void Vector::_set_mag()
    // {
    //     _mag=sqrt(_x*_x+_y*_y);
    // }
    // void Vector::_set_ang()
    // {
    //     _ang=atan2(_y,_x);
    // }

    Vector::Vector(double a,double b,Mode mode)
    {
        if(mode==RECT)
        {
            _x=a;
            _y=b;
            _mode=mode;
        }   
        else if(mode==POL)
        {
            _set_x(a,b);
            _set_y(a,b);
            _mode=mode;
        }
        else
        {
            cout<<"Incorrect 3rd argument to Vector()--";
            cout<<"vector set to be 0"<<std::endl;
            _x=_y=0.0;
            _mode=RECT;
        }
    }

    void Vector::reset(double a,double b,Mode mode)
    {
        if(mode==RECT)
        {
            _x=a;
            _y=b;
            _mode=mode;
        }   
        else if(mode==POL)
        {
            _set_x(a,b);
            _set_y(a,b);
            _mode=mode;
        }
        else
        {
            cout<<"Incorrect 3rd argument to Vector()--";
            cout<<"vector set to be 0"<<std::endl;
            _x=_y=0.0;
            _mode=RECT;
        }
    }
    
    // overload operator
    std::ostream & operator<<(std::ostream & os,const Vector & v)
    {
        if(v._mode==Vector::RECT)
        {
            os<<"(x,y) = "
                <<"("<<v._x<<","<<v._y<<")";
        }
        else if(v._mode==Vector::POL)
        {
            os<<"(m,a) = "
                <<"("<<v.getmag()<<","<<v.getang()<<")";
        }
        else
        {
            os<<"vector object mode is invalid";
        }
        return os; 
    }

    std::ofstream & operator<<(std::ofstream & os,const Vector & v)
    {
        if(v._mode==Vector::RECT)
        {
            os<<"(x,y) = "
                <<"("<<v._x<<","<<v._y<<")";// 注意这里不要自带换行，要不然容易多换一行。
        }
        else if(v._mode==Vector::POL)
        {
            os<<"(m,a) = "
                <<"("<<v.getmag()<<","<<v.getang()<<")";
        }
        else
        {
            os<<"vector object mode is invalid";
        }
        return os; 
    }
    



    
} // VECTOR



