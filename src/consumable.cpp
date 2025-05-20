#pragma once

#include "../include/consumable.h"
#include "item.cpp"

Consumable::Consumable(const char* name, const int plusHP = 0, const char* desc = "")
    : Item(name, desc) , PlusHP(plusHP) {}

Consumable::Consumable() : Consumable("") {}

std::ostream& Consumable::operator<<(std::ostream& c) const{
    c << "HP: ";
    if(GetPlusHP() < 0) c << "-" << -GetPlusHP();
    else if(GetPlusHP() == 0) c << "0";
    else c << "+" << GetPlusHP() << std::endl;
    return c;
}

Consumable::~Consumable() = default;
