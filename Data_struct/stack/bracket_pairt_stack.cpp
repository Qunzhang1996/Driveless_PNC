#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

bool bracket_check_func(char *exp, int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            S.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty())
            {
                cout << "top does  not pair!!!!";
                return false;
            }
            else
            {
                char top = S.top();
                S.pop();

                // Check if the current closing bracket matches the top of the stack
                if ((exp[i] == ')' && top != '(') || (exp[i] == '}' && top != '{') || (exp[i] == ']' && top != '['))
                {
                    cout << "Mismatched brackets!";
                    return false;
                }
            }
        }
    }
    return S.empty();
};
int main()
{
    char C[51];

    printf("Enter a string:  ");
    cin.getline(C, sizeof(C));
    if (bracket_check_func(C, strlen(C)))
    {
        cout<<" pair successfully"<<endl;
    }else{
        cout<<" pair failed"<<endl;
    }
    
    cout << endl;
}