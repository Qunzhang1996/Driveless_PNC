#pragma once
#include <string>
#include "Gun.h"

class Solider
{
public:
    Solider(std::string name);
    void addBulletToGun(const int bullet_num);
    void addGun(Gun *ptr_gun);
    bool fire();
    ~Solider();

private:
    std::string _name;
    Gun *_ptr_gun;
};