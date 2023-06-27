#include<iostream>
#include<list>
using namespace std;
void printList(const list<int>&L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" "<<endl;
    }
    cout<<endl;
}
void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
}
int main()
{
    test01();
    return 0;
}