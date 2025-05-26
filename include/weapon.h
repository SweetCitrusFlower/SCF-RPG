#pragma once

#include "item.h"
#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon : public Item {
protected:
    int PlusAD = 0;

public:
    explicit Weapon(const char* name, const int plusAD = 0, const char* description = "-") : Item(name, description) , PlusAD(plusAD) {};
    Weapon() : Weapon("No Weapon") {};
    ~Weapon() override = default;

    [[nodiscard]] int& GetPlusAD() {return PlusAD;}

};

class Fists final : public Weapon {
public:
    Fists() : Weapon("Fists", 0, "Ye Ole Reliable.") {}
    ~Fists() override = default;
};

class Plate final : public Weapon {
public:
    Plate() : Weapon("Plate", 100, "Can hurt a lot, but is very fragile. Just like a betrayed heart.") {}
    ~Plate() override = default;
};

class Cigarette final : public Weapon {
public:
    Cigarette() : Weapon("Cigarette", 30, "It's gonna be put out on your skin.") {}
    ~Cigarette() override = default;
};

class FlipPhone final : public Weapon {
public:
    FlipPhone() : Weapon("Flip Phone", 150, "Single use. But you keep using it.") {}
    ~FlipPhone() override = default;
};

#endif //WEAPON_H

inline std::ostream& operator<<(std::ostream& c, Weapon*& W) {
    c << dynamic_cast<Item*>(W) << "AD: ";
    if(W->GetPlusAD() < 0) c << "-" << -W->GetPlusAD();
    else if (W->GetPlusAD() == 0) c << "0";
    else c << "+" << W->GetPlusAD() << std::endl;
    return c;
}

