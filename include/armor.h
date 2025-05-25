#pragma once

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : public Item{
    int PlusDef = 0;
    int PlusHP = 0;
public:
    Armor(const char*, int, int, const char*);
    Armor();
    ~Armor() override = default;

    [[nodiscard]] int& GetPlusDef() {return PlusDef;}
    [[nodiscard]] int& GetPlusHP(){return PlusHP;}

    int& SetPlusDef(const int x) {PlusDef = x; return PlusDef;}
    int& SetPlusHP(const int x) {PlusHP = x; return PlusHP;}
};

class Skin : public Armor {
public:
    Skin() : Armor("Skin", 0, 1, "You're naked. Gross.") {}
    ~Skin() override = default;
};

class SoulJacket : public Armor {
public:
    SoulJacket() : Armor("Soul Jacket", 200, 300, "The ultimate sacrifice: to live with your heart on your sleeve.") {}
    ~SoulJacket() override = default;
};

class LanaTShirt : public Armor {
    public:
    LanaTShirt() : Armor("Lana del Rey T-Shirt", 20, 500, "Given with love. Kinda want it back tho ngl") {}
    ~LanaTShirt() override = default;
};

#endif //ARMOR_H
