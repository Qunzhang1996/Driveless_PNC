/*
描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围： 
1≤n≤1000
 
1≤n≤1000 
输入描述：
第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。

输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母


use toupper 将当前字符转换为大写形式

*/
#include<iostream>
#include<string>
using namespace std;
int check_num(string& input, char& target)
{
    int num=0;
    int len=input.length();
    char upperTarget = toupper(target);

    for(int i=0;i<len;i++)
    {
        char BigAim = toupper(input[i]);
        if (upperTarget==BigAim)
        {
            num++;
        }
    }
    
    return num;
}
int main()
{
    string input;
    char target;
    int num;
    getline(cin, input);
    cin>>target;
    num=check_num(input, target);
    cout<<num<<endl;
}