#pragma once

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

class Consumable : public Item {
protected:
    int PlusHP = 0;
public:
    Consumable(const char*, int, const char*);
    Consumable();
    ~Consumable() override = default;

    [[nodiscard]] int& GetPlusHP() { return PlusHP;}
};

class McPuisor : public Consumable {
public:
    McPuisor() : Consumable("McPuisor", -40, "This item makes you a bit fatter.") {}
    ~McPuisor() override = default;
};

class Apple : public Consumable {
public:
    Apple() : Consumable("Apple", 5, "Keeps the doctors away!") {}
    ~Apple() override = default;
};

class Vodka : public Consumable {
public:
    Vodka() : Consumable("Vodka", 300, "Russian wisdom cyka blyat") {}
    ~Vodka() override = default;
};

class PlateOfSpaghetti : public Consumable {
public:
    PlateOfSpaghetti() : Consumable("Plate of spaghetti", 300, "To forgetti your regretti.") {}
    ~PlateOfSpaghetti() override = default;
};
#endif //CONSUMABLE_H
