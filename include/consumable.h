#pragma once

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <vector>

class Consumable final : public Item {
protected:
    int PlusHP = 0;

public:

    Consumable(const char*, int, const char*);
    Consumable();
    ~Consumable() override = default;

    [[nodiscard]] int GetPlusHP() const { return PlusHP;}


};

#endif //CONSUMABLE_H
