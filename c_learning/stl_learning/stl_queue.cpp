#include<iostream>
#include<queue>
#include<string>
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
void test01()
{
    queue<Person>q;
    Person p1("tom",20);
    Person p2("jerry",30);
    Person p3("ally",40);
    Person p4("jason",50);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while (!q.empty())
    {
        cout<<"queue front name "<<q.front().m_Name<<" age "<<q.front().m_Age<<endl;
        cout<<"queue back name "<<q.back().m_Name<<" age "<<q.back().m_Age<<endl;
        q.pop();
    }
    cout<<"size of the queue  "<<q.size()<<endl;
    

}
int main()
{
    test01();
    return 0;
}