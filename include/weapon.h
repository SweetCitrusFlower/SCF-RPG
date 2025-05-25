#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon final : public Item {
protected:
    int PlusAD = 0;

public:
    Weapon(const char*, int, const char*);
    Weapon();
    ~Weapon() override = default;

    [[nodiscard]] int& GetPlusAD() {return PlusAD;}
    int& SetPlusAD(const int PAD) {PlusAD = PAD; return PlusAD;}
};

#endif //WEAPON_H
