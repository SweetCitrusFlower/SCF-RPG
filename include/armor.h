#pragma once

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor final : public Item{
    int PlusDef;
    int PlusHP;
public:
    Armor(const char*, int, int, const char*);
    Armor();
    ~Armor() override;

    [[nodiscard]] int GetPlusDef() const& {return PlusDef;}
    [[nodiscard]] int GetPlusHP() const& {return PlusHP;}

};

inline auto Skin = Armor("Skin", 0, 1, "You're naked. Gross.");
inline auto SoulJacket = Armor("Soul Jacket", 200, 300, "The ultimate sacrifice: to live with your heart on your sleeve.");
inline auto LanaTShirt = Armor("Lana del Rey T-Shirt", 20, 500, "Given with love. Kinda want it back tho ngl");

#endif //ARMOR_H
