#include<iostream>
#include<list>
#include<string>
using namespace std;
class Person
{
private:
    /* data */
public:
    Person(string name, int age, int height)
    {
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};

void printList(const list<int>&L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" "<<endl;
    }
    cout<<endl;
}
bool comparePerson(Person &p1, Person &p2)
{
    if(p1.m_Age==p2.m_Age)
        return p1.m_Height>p2.m_Height;
    else{
        return p1.m_Age<p2.m_Age;
    }
    
}
void test01()
{
    list<Person>L;
    Person p1("Jason1",35,115);
    Person p2("Jason2",45,185);
    Person p3("Jason3",35,165);
    Person p4("Jason4",25,175);
    Person p5("Jason5",65,200);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    for(list<Person>::iterator it1=L.begin();it1!=L.end();it1++)
    {
        cout<<"name: "<<(*it1).m_Name<<" age: "<<it1->m_Age<<" Height: "<<it1->m_Height<<endl;
    }
    //sort
    cout<<"__________result after sort__________________"<<endl;
    L.sort(comparePerson);
        for(list<Person>::iterator it1=L.begin();it1!=L.end();it1++)
    {
        cout<<"name: "<<(*it1).m_Name<<" age: "<<it1->m_Age<<" Height: "<<it1->m_Height<<endl;
    }
}
int main()
{
    test01();
    return 0;
}