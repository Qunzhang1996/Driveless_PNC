#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    string input;
    vector<string>data;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        data.push_back(input);

    }
    sort(data.begin(), data.end());
    for(auto d:data)
    {
        cout<<d<<endl;
    }
    
}
