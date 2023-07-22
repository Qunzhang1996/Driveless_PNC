#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
void Reverse(char *C, int n)
{
    stack<char>  S;
    for(int i=0;i<n;i++)
    {
        S.push(C[i]);
    }
    for(int i=0;i<n;i++)
    {
        C[i]=S.top();
        S.pop();
    }
}
int main()
{
    char C[51];
    printf("Enter a string:  ");
    cin.getline(C, sizeof(C));
    Reverse(C, strlen(C));
    printf("Output  = %s", C);
    cout<<endl;

}