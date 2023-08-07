#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int input;
    cin>>input;
    vector<int>container;
    if (input==0)
    {
        container.push_back(0);
    }
    while(input>0)
    {
        int num=input%10;
        container.push_back(num);
        input=input/10;
    }
    for(auto con:container)
    {
        cout<<con;
    }
    return 0;
}