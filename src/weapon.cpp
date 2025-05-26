#include "../include/weapon.h"
#include "item.cpp"

Weapon::Weapon(const char *name, const int plusAD = 0, const char *description = nullptr)
    : Item(name, description) , PlusAD(plusAD) {}

Weapon::Weapon() : Weapon("No Weapon") {}

std::ostream& operator<<(std::ostream& c, Weapon*& W) {
    c << dynamic_cast<Item*>(W) << "AD: ";
    if(W->GetPlusAD() < 0) c << "-" << -W->GetPlusAD();
    else if (W->GetPlusAD() == 0) c << "0";
    else c << "+" << W->GetPlusAD() << std::endl;
    return c;
}

