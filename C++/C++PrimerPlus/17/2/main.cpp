#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char const *argv[])
{
    fstream fout(argv[1]);

    while(cin)
    {
        string str;
        getline(cin,str);
        fout<<str<<endl;
    }


    return 0;
}


