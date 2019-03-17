

# include<iostream>
# include"cd.h"
# include "classic.h"
using namespace std;

void Report(const Cd & cd);

int main(int argc, char const *argv[])
{
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2=Classic("piano Sonata in B flat,Fantasia in C","Alfred Brendel","philips",2,57.17);
    
    

    cout<< "Using object directly:\n";
    c1.report();
    c2.report();

    cout<< "Using Cd * pointer to object:\n";
    Cd *pcd = &c1;
    pcd->report();
    pcd=&c2;
    pcd->report();

    
    cout<< "callint a function to Cd reference\n";
    Report(c1);
    Report(c2);

    cout<<"test assistent\n";
    Classic copy;
    copy=c2;
    copy.report();
    
    return 0;
}


void Report(const Cd & cd)
{
    cd.report();
}
