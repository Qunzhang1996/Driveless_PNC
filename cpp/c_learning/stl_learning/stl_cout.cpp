#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
class  Greater20
{
private:
    /* data */
public:
    bool operator()(const Person &p)
    {
        return p.m_Age>40;
    }
};


void test01(){
    vector<Person>v;
    Person p1("Jason1",35);
    Person p2("Jason2",45);
    Person p3("Jason3",35);
    Person p4("Jason4",25);
    Person p5("Jason5",65);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    int num =count_if(v.begin(),v.end(),Greater20());
    cout<<num<<endl;

}
int main(){
    test01();
    return 0;
}