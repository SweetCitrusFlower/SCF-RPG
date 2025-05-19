#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item {
protected:
    int PlusAD;
public:
    Weapon(const char*, int, const char*);
    Weapon();

    [[nodiscard]] int GetPlusAD() const {return PlusAD;}

    std::ostream& operator<<(const Weapon&) const;

    ~Weapon() override = default;
};

inline auto Plate = Weapon("Plate", 500, "Can hurt a lot, but is very fragile. Just like a betrayed heart.");
inline auto Cigarette = Weapon("Cigarette", 30, "It's gonna be put out on your skin.");

#endif //WEAPON_H
