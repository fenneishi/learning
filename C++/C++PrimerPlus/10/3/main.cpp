# include "golf.h"

int main(int argc, char const *argv[])
{
    Golf play1("jack",10);
    Golf play2;//Golf play2():empty parentheses interpreted as a function declaration
    if(play2.setGolf()==0)cout<<"name can not be empty!"<<endl;

    play1.show();
    play2.show();

    play1.setHandicap(0);
    play2.setHandicap(0);

    play1.show();
    play2.show();
    
    return 0;
}
