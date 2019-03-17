

# ifndef TIME_H_
# define TIME_H_

# include<iostream>

class Time
{
private:
    int _h;
    int _m;
public:
    Time():_h(0),_m(0){};
    Time(int h,int m):_h(h),_m(m){};

    void reset(int h,int m);

    void addHour(int h);
    void addMine(int m);


    friend Time operator+(const Time &c1,const Time &c2);
    friend Time operator-(const Time &c1,const Time &c2);
    friend std::istream & operator>>(std::istream &is, Time &c); //cin 和 cout 在各种形式的<<>>重载中，都没有使用const,所以不要再加const了给cin和cout
    friend std::ostream & operator<<(std::ostream &os, const Time &c);
    void test(){std::cin>>_h;}


    ~Time(){};
};


#endif