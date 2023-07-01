#include"Gun.h"
#include"Solder.h"
void test()
{
    Solider TOM("TOM");
    TOM.addGun(new Gun("AK47"));
    TOM.addBulletToGun(20);
    TOM.fire();

}
int main()
{   
    test();
    return 0;
}