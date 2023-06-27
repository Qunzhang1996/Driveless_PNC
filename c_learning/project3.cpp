#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#define art 0
#define PD  1
#define manuf 2
class Worker{
    public:
    string m_Name;
    int m_Salary;

};
void createWorker(vector<Worker> &v)
{
    string nameSeed ="ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        Worker worker;
        worker.m_Name="member: ";
        worker.m_Name+=nameSeed[i];
        worker.m_Salary=rand()%10000+10000;//
        v.push_back(worker);
    }
}
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
    {
        //create  number of the department
        int deptId=rand()%3; //0,1,2
        m.insert(make_pair(deptId, *it));
    }
}
void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout<<"ART Department: "<<endl;
    multimap<int, Worker>::iterator pos=m.find(art);
    int count=m.count(art);
    int index=0;
    for(;pos!=m.end()&&index<count;pos++, index++)
    {
        cout<<"name: "<<pos->second.m_Name<<"   salary: "<<pos->second.m_Salary<<endl;
    }
    cout<<"______________________________"<<endl;
    cout<<"PD Department"<<endl;

    pos=m.find(PD);
    count=m.count(PD);
    index=0;
    for(;pos!=m.end()&&index<count;pos++, index++)
    {
        cout<<"name: "<<pos->second.m_Name<<"   salary: "<<pos->second.m_Salary<<endl;
    }
    cout<<"______________________________"<<endl;
    cout<<"manuf Department"<<endl;
    
    pos=m.find(manuf);
    count=m.count(manuf);
    index=0;
    for(;pos!=m.end()&&index<count;pos++, index++)
    {
        cout<<"name: "<<pos->second.m_Name<<"   salary: "<<pos->second.m_Salary<<endl;
    }
}
int main(){
    //create member
    vector<Worker>vWorker;
    createWorker(vWorker);
    //test
    // for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++)
    // {
    //     cout<<"name: "<<it->m_Name<<"   salary: "<<it->m_Salary<<endl;
    // }
    //assign group
    multimap<int, Worker>mworker;
    setGroup(vWorker, mworker);
    showWorkerByGroup(mworker);
    return 0;
}