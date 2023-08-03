#include<iostream>
#include<list>
#include<set>
using namespace std;
void printList(const set<int>&s)
{
    for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" "<<endl;
    }
    cout<<endl;
}
void test01()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    printList(s1);
}
int main()
{
    test01();
    return 0;
}