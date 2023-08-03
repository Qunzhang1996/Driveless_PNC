#include<iostream>
using namespace std;
#include<list>
void printList(const list<int>&L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
};
bool myCompare(int v1, int v2)
{
    return v1>v2;
}
void test01()
{
    list<int>L;
    L.push_back(30);
    L.push_back(130);
    L.push_back(10);
    L.push_back(20);
    L.push_back(40);
    printList(L);
    L.sort();
    printList(L);
    L.sort(myCompare);
    printList(L);
}
int main(){
    test01();
    return 0;
}