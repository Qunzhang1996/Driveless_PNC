#include<iostream>
#include<cstdio>
using namespace std;
int Factorial(int n)
{
    cout<<"I am calculating F("<<n<<")\n";
    if(n==0)
    {
        return 1;}
    int F = n*Factorial(n-1);
    
    return F;
    
}
int main()
{
    int n;
    cout<<"give me an n:";
    cin>>n;
    int result = Factorial(n);
    cout<<result<<endl;
    return 0;
}