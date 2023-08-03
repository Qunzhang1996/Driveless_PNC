#pragma once
#include <iostream>
class swap
{
public:
    swap(int value1, int value2)
    {
        this->a = value1;
        this->b = value2;
    };
    void run();
    void printInfo();

private:
    int a;
    int b;
};