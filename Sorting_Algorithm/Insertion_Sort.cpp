#include<iostream>
using namespace std;
void Insertion_Sort(int  array[], int n)
{
    for(int i=1;i<n;i++)
    {
        int value=array[i];
        int hole =i;
        while(hole>0&&array[hole-1]<value)
        {
            array[hole]=array[hole-1];
            hole=hole-1;
        }
        array[hole]=value;
    }
};
int main(){
    int array[]={7,2,4,1,5,3};
    int n= sizeof(array)/sizeof(array[0]);
    Insertion_Sort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
    return 0;
}