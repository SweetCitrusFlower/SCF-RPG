#pragma once

#include "../include/weapon.h"
#include "item.cpp"

Weapon::Weapon(const char *name, const int plusAD = 0, const char *description = nullptr)
    : Item(name, description) , PlusAD(plusAD) {}

Weapon::Weapon() : Weapon("No Weapon") {}

std::ostream& operator<<(std::ostream& c, const Weapon& W) {
    c << static_cast<Item>(W) << "AD: ";
    if(W.GetPlusAD() < 0) c << "-" << -W.GetPlusAD();
    else if (W.GetPlusAD() == 0) c << "0";
    else c << "+" << W.GetPlusAD() << std::endl;
    return c;
}

inline auto Fists = Weapon("Fists", 0, "Ye Ole Reliable.");
inline auto Plate = Weapon("Plate", 100, "Can hurt a lot, but is very fragile. Just like a betrayed heart.");
inline auto Cigarette = Weapon("Cigarette", 30, "It's gonna be put out on your skin.");
inline auto FlipPhone = Weapon("Flip Phone", 150, "Single use. But you keep using it.");
inline std::vector AllWeapons = {Plate, Cigarette, FlipPhone};
