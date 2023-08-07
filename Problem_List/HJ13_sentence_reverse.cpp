#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    vector<string>vec;
    string ss;
    while (cin >> ss) {
        vec.push_back(ss);
    }
    reverse(vec.begin(), vec.end());
    for(auto v:vec)
        cout << v  << " ";
    cout << endl;
    return 0;
}