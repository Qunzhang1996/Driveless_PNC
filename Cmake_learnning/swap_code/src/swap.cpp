#include "swap.h"
using namespace std;
void swap::run()
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swap::printInfo()
{
    cout<<"  a=  "<<a<<endl;
    cout<<"  b=  "<<b<<endl;
}