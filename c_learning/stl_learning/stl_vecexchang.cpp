#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    cout<<endl;
}
void test01()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for(int i=10;i>0;i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"exchange"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
int main(){
    test01();
    return 0;
}
