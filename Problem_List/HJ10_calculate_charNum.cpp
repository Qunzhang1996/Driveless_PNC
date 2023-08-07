#include <iostream>
#include<set>
#include <string>
using namespace std;

int main() {
    string input;
    cin>>input;
    set<char>container;
    for(auto inp:input)
    {
        container.insert(inp);
    };
    cout<<container.size();
}