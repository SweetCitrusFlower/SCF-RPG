#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item {
protected:
    int PlusAD = 0;

public:
    Weapon(const char*, int, const char*);
    Weapon();
    ~Weapon() override = default;

    [[nodiscard]] int& GetPlusAD() {return PlusAD;}
    int& SetPlusAD(const int PAD) {PlusAD = PAD; return PlusAD;}
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
