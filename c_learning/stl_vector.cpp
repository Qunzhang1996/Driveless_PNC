#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//head of standard algorithm
//vector container save the data type
void myPrint(int val)
{
    cout<<val<<endl;
}
void test01()
 {
    //create a vector container, array

    vector<int> v;
    //insert data in container
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    //using iteration to get the data
    vector<int>::iterator itBegin=v.begin();//initial iteration, point to the first one
    vector<int>::iterator itEnd=v.end();//end iteration, point to the next position of the last element
    // //ergodic
    while (itBegin !=itEnd)
    {
        /* code */
        cout<<*itBegin<<endl;
        itBegin++;
    }
    //second kinds of ergodic
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;

    }
    //third kind of ergodic, using iteration algorithm in STL
    for_each(v.begin(),v.end(),myPrint);


 }
 int main(){
    test01();
    return 0;
 }