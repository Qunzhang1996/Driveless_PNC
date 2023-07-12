#include<iostream>
using namespace std;
#include<stack>
void test01()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    while (!s.empty())
    {
        //check stack top element
        cout<<"stack top element  "<<s.top()<<endl;
        //stack pop
        s.pop();
    }
    cout<<"size of the stack  "<<s.size()<<endl;
    
}
int main()
{
    test01();
    return 0;
}