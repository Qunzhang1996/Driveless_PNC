#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Point{
    int x,y;
    Point(int x, int y):x(x),y(y){};
};
bool areAllDigits(const std::string& str) {
    if(str.empty()) {
        return false; // If empty
    }
    for(char c : str) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}
void calculate_point(const char& direction, const int& value, Point& result)
{
    switch (direction) {
        case 'A':
            result.x-=value;
            break;
        case 'D':
            result.x+=value;
            break;
        case 'S':
            result.y-=value;
            break;
        case 'W':
            result.y+=value;
            break;
    
    }
};

int main(){
    string input;
    cin>>input;
    string temp;
    Point result={0,0};
    int len=input.size();
    for(int i=0;i<len;i++)
    {
        temp+=input[i];
        if(input[i]==';')
        {
            int length=temp.size();
            char direction=temp[0];
            temp.erase(temp.begin());
            temp.pop_back();
            if((direction == 'A' || direction == 'D' || direction == 'S' || direction == 'W') && areAllDigits(temp)) {
                calculate_point(direction, stoi(temp), result);
            }
            temp.clear();
        }
    }
    cout<<result.x<<","<<result.y;
    return 0;
}