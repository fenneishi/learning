#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <fstream>

namespace VECTOR
{
    
    class Vector
    {
    public:
        enum Mode{RECT,POL};//RECT for rectangle,POL for Polar modes;
    private:
        Mode _mode;//RECT or POL
        double _x;
        double _y;
        // double _mag;//length
        // double _ang;//direction in degrees

        //private methods for setting values
        void _set_x(double mag,double ang);
        void _set_y(double mag,double ang);
        // void _set_mag();
        // void _set_ang();

    public:
        // construct
        Vector():_x(0),_y(0),_mode(RECT){};
        Vector(double a,double b,Mode mode=RECT);
        

        void reset(double a,double b,Mode mode=RECT);

        // get Value
        double getX()const{return _x;}
        double getY()const{return _y;}
        double getmag()const;
        double getang()const;
        // change mode
        void toPOL(){_mode=POL;}
        void toRECT(){_mode=RECT;}
        // overload operator
        Vector operator+(const Vector & v) const{return Vector(_x+v._x,_y+v._y);}
        Vector operator-(const Vector & v) const{return Vector(_x-v._x,_y+v._y);}
        Vector operator-() const{return Vector(-_x,-_y);};
        Vector operator*(int num) const{return Vector(_x*num,_y*num);};
        friend Vector operator*(int num,const Vector &v){return Vector(v._x*num,v._y*num);};
        friend std::ostream & operator<<(std::ostream & os,const Vector & v);
        friend std::ofstream & operator<<(std::ofstream & os,const Vector & v);

        // destruct
        ~Vector(){};
        
    };
} // VECTOR


# endif