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
    ~Weapon() override;

    [[nodiscard]] int GetPlusAD() const {return PlusAD;}
};

inline auto Fists = Weapon("Fists", 0, "Ye Ole Reliable.");
inline auto Plate = Weapon("Plate", 500, "Can hurt a lot, but is very fragile. Just like a betrayed heart.");
inline auto Cigarette = Weapon("Cigarette", 30, "It's gonna be put out on your skin.");

#endif //WEAPON_H
