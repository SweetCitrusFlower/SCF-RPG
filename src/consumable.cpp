#include "../include/consumable.h"
#include "item.cpp"

Consumable::Consumable(const char* name, const int plusHP = 0, const char* desc = "")
    : Item(name, desc) , PlusHP(plusHP) {}

Consumable::Consumable() : Consumable("") {}

std::ostream& operator<<(std::ostream& c, Consumable& C){
    c << static_cast<Item&>(C) << "HP: ";
    if(C.GetPlusHP() < 0) c << "-" << -C.GetPlusHP();
    else if(C.GetPlusHP() == 0) c << "0";
    else c << "+" << C.GetPlusHP();
    c << std::endl;
    return c;
}