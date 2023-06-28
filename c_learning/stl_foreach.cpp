#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//function
void print01(int val)
{
    cout<<val<<"  ";
}
//functor
class print02
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
        
    }
    
};
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    cout<<"__________________________"<<endl;
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}
int main()
{
    test01();
    return 0;
}