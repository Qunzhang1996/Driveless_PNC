/*
描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串
*/
#include<iostream>
#include<string>
using namespace std;
void Seperate_Char(string &input)
{
    int len=input.length();
    int val=len%8;
    if(val!=0)
    {
        for(int i=0;i<8-val;i++)
        {
            input.append(1,'0');
        };
    }
    
    len=input.length();
    // cout<<len<<endl;
    // cout<<input<<endl;
    string temp;
    int count =0;
    for(int i=0;i<len;i++)
    {
        
        temp.append(1,input[i]);
         count++;
        if(count==8)
        {
            cout<<temp<<endl;
            temp.clear();
            count=0;
        }
       

    }
    


};
int main()
{
    string input;
    cin>>input;
    Seperate_Char(input);
}