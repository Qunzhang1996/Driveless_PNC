#include <iostream>
#include <iterator>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    cin>>input;
    stack<char>container;
    for(auto inp:input)
    {
        container.push(inp);
    }
    while(!container.empty())
    {
        char result=container.top();
        cout<<result;
        container.pop();
    }

    
}