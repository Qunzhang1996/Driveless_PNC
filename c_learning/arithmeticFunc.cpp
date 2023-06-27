#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
void test01(){
    negate<int>n;
    cout<<n(50)<<endl;
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
}
int main(){
    test01();
    return 0;
}