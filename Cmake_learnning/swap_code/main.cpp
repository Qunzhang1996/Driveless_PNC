#include"swap.h"
int main()
{
    int val1=10;
    int val2=20;
    swap swapp(val1,val2);
    swapp.printInfo();
    swapp.run();
    swapp.printInfo();
    return 0;
}