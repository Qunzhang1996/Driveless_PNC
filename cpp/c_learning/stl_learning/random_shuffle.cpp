#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

void myPrint (int v)
{
    cout<<v<<endl;
};
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
}
int main()
{
    test01();
    return 0;
}