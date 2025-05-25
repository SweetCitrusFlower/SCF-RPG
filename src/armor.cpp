#include "../include/armor.h"
#include "item.cpp"

Armor::Armor(const char* name, const int plusDef = 0, const int plusHP = 0, const char* description = nullptr) :
    Item(name, description) {
    SetPlusDef(plusDef);
    SetPlusHP(plusHP);
}

Armor::Armor() : Armor("No Armor") {}

std::ostream& operator<<(std::ostream &c, Armor& A){
    c << static_cast<Item&>(A) << "DEF: ";
    if(A.GetPlusDef() < 0) c << "-" << -A.GetPlusDef();
    else if(A.GetPlusDef() == 0) c << "0";
    else c << "+" << A.GetPlusDef();

    c << std::endl << "HPMax: ";
    if(A.GetPlusHP() < 0) c << "-" << -A.GetPlusHP();
    else if(A.GetPlusHP() == 0) c << "0";
    else c << "+" << A.GetPlusHP();
    c << std::endl;

    return c;
}

