/*
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。
如果小数点后数值大于等于 0.5 ,向上取整；小于 0.5 ，则向下取整。
*/
#include <iostream>
using namespace std;

int main() {
    float num;
    scanf("%f",&num);
    float num1=num-static_cast<int>(num);
    if(num1>=0.5)
    {
        cout<<static_cast<int>(num)+1<<endl;

    }else{
        cout<<static_cast<int>(num)<<endl;
    }
    
}
