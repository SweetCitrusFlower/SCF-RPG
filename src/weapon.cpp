#pragma once

#include "../include/weapon.h"
#include "item.cpp"

Weapon::Weapon(const char *name, const int plusAD = 0, const char *description = nullptr)
    : Item(name, description) , PlusAD(plusAD) {}

Weapon::Weapon() : Weapon("No Weapon") {}

std::ostream& Weapon::operator<<(std::ostream& c) const{
    c << "AD: ";
    if(GetPlusAD() < 0) c << "-" << -GetPlusAD();
    else if (GetPlusAD() == 0) c << "0";
    else c << "+" << GetPlusAD() << std::endl;
    return c;
}
Weapon::~Weapon() = default;