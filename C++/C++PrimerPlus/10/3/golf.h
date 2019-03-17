# include <iostream>
# include <string>
using namespace std;

class Golf
{
private:
    string _name;
    int _handicap;
public:
    Golf():_name(""),_handicap(0){};
    Golf(const string& name,int handicap):_name(name),_handicap(handicap){};
    int setGolf();//return 1 if name is entered;return 0 if is not
    void setHandicap(int handicap);//reset handicap to new value.
    void show();
};