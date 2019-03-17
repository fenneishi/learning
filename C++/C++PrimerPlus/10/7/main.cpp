

#include "plorg.h"

int main(int argc, char const *argv[])
{
    std::cout<<"11111111"<<std::endl;
    Plorg plorg_1;
    plorg_1.show();
    plorg_1.changeID(51);
    plorg_1.show();
    

    std::cout<<"22222222"<<std::endl;
    Plorg plorg_2((char *)"jack",22);
    plorg_2.show();
    plorg_2.changeID(51);
    plorg_2.show();



    return 0;
}
