#include <iostream>
#include<algorithm>
#include<string>
#include <vector>
using namespace std;

int main() {
    int input;
    cin>>input;
    vector<int>container;
    while(input>0)
    {
        int num=input%10;
        auto it=find(container.begin(),container.end(),num);
        if (it==container.end())
        {
            container.push_back(num);
        }
        input=input/10;
    }
    for(auto con:container)
    {
        cout<<con;
    };
    // Create a new integer value without duplicates
    int newValue = 0;
    for (int i : container) {
        newValue = newValue * 10 + i;
    }

}