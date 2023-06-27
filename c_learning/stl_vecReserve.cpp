#include<iostream>
#include<vector>
using namespace std;
void test01(){
    vector<int>v;
    //using reserve to reserve space in advance
    v.reserve(100000);
    int num =0;
    int * p=NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
            /* code */
        }
        
    }
    cout<<"num="<< num <<endl;
}
int main(){
    test01();
    return 0;
}