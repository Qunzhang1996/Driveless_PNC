#include<iostream>
#include<algorithm>
using namespace std;
const int weight[5]={0,2,3,4,5};
const int value[5]={0,3,4,5,6};
int dp[5][9]={0};
int object[5];
void dynamic()
{
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<9;j++)
        {   
            if(weight[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }
};
void Find(int i, int j)
{
    if(i==0)
    {
        for(int m=0;m<5;m++)
            cout<<object[m]<<" ";
        cout<<endl;
        return;
    }
    if(dp[i][j]==dp[i-1][j])
    {
        object[i]=0;
        Find(i-1,j);
    }else if(dp[i][j]==dp[i-1][j-weight[i]]+value[i])
    {
        object[i]=1;
        Find(i-1,j-weight[i]);
    }

}
int main()
{
    dynamic();
    Find(4, 8);
    return 0;

}