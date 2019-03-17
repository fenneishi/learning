#include<stdio.h>





int main(void)
{   
    class test
    {
    public:
        int a;
        test();
        virtual ~test();
        void print_test(int);
    };
    void print_test(int tt)
    {
        printf("%d\n",tt);
    }   
    test t;
    t.a=1;
    t.print_test(1);
    return 0;
}



/*

*/