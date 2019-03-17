
#include "point.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"point_1"<<endl;
    Point point_1;
    point_1.showPoint();
    point_1.resetPoint(0.1,0.2);
    point_1.showPoint();

    cout<<"point_2"<<endl;
    Point point_2(1,2);
    point_2.showPoint();
    point_2.resetPoint(1.1,2.1);
    point_2.showPoint();

    cout<<"point_3"<<endl;
    Point point_3=point_1.add(point_2);
    point_3.showPoint();
    point_3.resetPoint(3.1,3.1);
    point_3.showPoint();

    return 0;
}

