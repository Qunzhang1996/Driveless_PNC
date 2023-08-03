#include<iostream>
using namespace std;
void Swap(int* a, int* b){
    int temp  = *a;
    *a = *b;
    *b = temp;
};

void Bubble_Sort(int Array[], int n)
{
    for(int k=1; k<n; k++)
    {
        for (int i=0; i<n-k; i++)
        {
            if (Array[i] > Array[i+1])
            {
                Swap(&Array[i], &Array[i+1]);
            }
        }
    }
    
};

int main()
{
    int Array_[]={2,4,1,5,3,7};
    int n = sizeof(Array_) /sizeof(Array_[0]);
    Bubble_Sort(Array_, n);
    for(int i=0;i<n;i++)
    {
        cout<<Array_[i]<<endl;
    }
    
}