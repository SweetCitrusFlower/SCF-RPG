#pragma once

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

class Consumable final : public Item {
protected:
    int PlusHP = 0;

public:

    Consumable(const char*, int, const char*);
    Consumable();
    ~Consumable() override;

    [[nodiscard]] int GetPlusHP() const { return PlusHP;}

};

inline auto McPuisor = Consumable("McPuisor", -40, "This item makes you a bit fatter.");
inline auto Apple = Consumable("Apple", 5, "Keeps the doctors away!");
inline auto Vodka = Consumable("Vodka", 300, "Russian wisdom cyka blyat");


#endif //CONSUMABLE_H
