# ifndef POINT_H_
# define POINT_H_

# include<iostream>


class Point
{
private:
    double _x;
    double _y;
public:
    Point(double x=0,double y=0):_x(x),_y(y){};
    void showPoint()const{std::cout<<"x="<<_x<<"  "<<"y="<<_y<<std::endl;}
    void resetPoint(double x,double y){_x=x;_y=y;}
    Point add(Point &p){return Point(p._x,p._y);}
    //这里要注意，关键在于两点：找到和权限
    // 找到:通过p._x和p._y可以找到对象p的两个成员变量（this指针其实也是一个参数）
    // 权限:只要是“对象所属类”的“友元函数和成员函数”都是有权限访问“对象的私有成员”
    // 注意:其实add函数有两个参数，一个是this指针，另一个才是Point &p。
    // 总结:
    //     找到：取决于有没有合适的参数传递进来（包括this指针）
    //     权限：取决“对象所属类”和“函数”的关系。
    ~Point(){};
};

#endif
