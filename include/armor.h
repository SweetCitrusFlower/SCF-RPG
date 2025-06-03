#pragma once

#include "item.h"

#ifndef ARMOR_H
#define ARMOR_H

class Armor : public Item{
    int PlusDef = 0;
    int PlusHP = 0;
public:
    explicit Armor(const char* name, const int plusDef = 0, const int plusHP = 0, const char* description = "-") :
        Item(name, description), PlusDef(plusDef), PlusHP(plusHP) {}
    Armor() : Armor("No Armor") {};
    ~Armor() override = default;

    [[nodiscard]] int& GetPlusDef() {return PlusDef;}
    [[nodiscard]] int& GetPlusHP(){return PlusHP;}

    friend std::ostream& operator<<(std::ostream &c, Armor* A){
        A->ShowItem();
        c << "DEF: ";
        if(A->GetPlusDef() < 0) c << "-" << -A->GetPlusDef();
        else if(A->GetPlusDef() == 0) c << "0";
        else c << "+" << A->GetPlusDef();

        c << std::endl << "HPMax: ";
        if(A->GetPlusHP() < 0) c << "-" << -A->GetPlusHP();
        else if(A->GetPlusHP() == 0) c << "0";
        else c << "+" << A->GetPlusHP();
        c << std::endl;

        return c;
    }


    void ShowItem() override {
        std::cout << this;
    }
};

class Skin final : public Armor {
public:
    Skin() : Armor("Skin", 0, 1, "You're naked. Gross.") {}
    ~Skin() override = default;
};

class SoulJacket final : public Armor {
public:
    SoulJacket() : Armor("Soul Jacket", 200, 300, "The ultimate sacrifice: to live with your heart on your sleeve.") {}
    ~SoulJacket() override = default;
};

class LanaTShirt final : public Armor {
public:
    LanaTShirt() : Armor("Lana del Rey T-Shirt", 20, 500, "Given with love. Kinda want it back tho ngl") {}
    ~LanaTShirt() override = default;
};

#endif //ARMOR_H