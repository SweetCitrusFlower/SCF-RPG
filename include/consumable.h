#pragma once

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <cstring>

class Consumable : public Item {
protected:
    int PlusHP = 0;
    void UseConsumable();

public:
    explicit Consumable(const char* name, const int plusHP = 0, const char* desc = "") : Item(name, desc) , PlusHP(plusHP) {}
    Consumable() : Consumable("McPuisor", 1, "This item makes you a bit fatter.") {}

};

#endif //CONSUMABLE_H
