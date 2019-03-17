#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(!fin)
    {

    }
    while(fin)
    {
        string str;
        getline(fin,str);
        fout<<str<<endl;
    }
    return 0;
}
