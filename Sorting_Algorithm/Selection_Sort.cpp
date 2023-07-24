#include<iostream>
using namespace std;
void Sort(int Array[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int i_min=i;
        for(int j=i+1;j<n;j++)
        {
            if(Array[j]<Array[i_min])
            {
                i_min=j;
            }
        }
        int temp = Array[i];
        Array[i] = Array[i_min];
        Array[i_min] = temp;
    }
};
int main()
{
    int Array_ []= {2,1,4,7,5,3};
    int n = sizeof(Array_ ) / sizeof(Array_ [0]);
    Sort(Array_, n);
    for(int i=0;i<n;i++)
    {
        cout<<Array_[i]<<endl;
    }
    return 0;
}