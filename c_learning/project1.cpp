#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name=name;
        this->m_Score=score;
    }
    string m_Name;
    int m_Score;
};
void createPerson(vector<Person>&v)
{
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name="member";
        name+=nameSeed[i];
        int socre =0;
        Person p(name, socre);
        
        v.push_back(p);
    }
}
void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            int score=rand() % 41+60;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for (deque<int>::iterator it1=d.begin();it1!=d.end();it1++)
        {
            sum+=*it1;
        }
        int avg=sum/d.size();
        it->m_Score=avg;
        // cout<<"name: "<<it->m_Name<<" "<<"score: "<<it->m_Score<<endl;
    }
}
void showScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"name: "<<it->m_Name<<" "<<"score: "<<it->m_Score<<endl;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    vector<Person>v;
    createPerson(v);
    // for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    // {
    //     cout<<"name: "<<it->m_Name<<" "<<"score: "<<it->m_Score<<endl;
    // }
    setScore(v);
    showScore(v);
    return 0;
}
