#pragma once

#include "../include/armor.h"
#include "item.cpp"

Armor::Armor(const char* name, const int plusDef = 0, const int plusHP = 0, const char* description = nullptr)
    : Item(name, description), PlusDef(plusDef), PlusHP(plusHP) {}

Armor::Armor() : Armor("No Armor") {}

std::ostream& Armor::operator<<(std::ostream &c) const{
    c << "DEF: ";
    if(GetPlusDef() < 0) c << "-" << -GetPlusDef();
    else if(GetPlusDef() == 0) c << "0";
    else c << "+" << GetPlusDef();

    c << std::endl << "HPMax: ";
    if(GetPlusHP() < 0) c << "-" << -GetPlusHP();
    else if(GetPlusHP() == 0) c << "0";
    else c << "+" << GetPlusHP();
    c << std::endl;

    return c;
}

Armor::~Armor() = default;