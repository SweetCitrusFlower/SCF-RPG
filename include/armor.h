#pragma once

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor final : public Item{
    int PlusDef = 0;
    int PlusHP = 0;
public:
    Armor(const char*, int, int, const char*);
    Armor();
    ~Armor() override = default;

    [[nodiscard]] int GetPlusDef() const {return PlusDef;}
    [[nodiscard]] int GetPlusHP() const {return PlusHP;}

    int& SetPlusDef(const int x) {PlusDef = x; return PlusDef;}
    int& SetPlusHP(const int x) {PlusHP = x; return PlusHP;}

};

#endif //ARMOR_H
