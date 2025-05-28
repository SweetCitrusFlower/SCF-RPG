#pragma once

#include "item.h"

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Consumable : public Item {
protected:
    int PlusHP = 0;
public:
    explicit Consumable(const char* name, const int plusHP = 0, const char* desc = "-") :
        Item(name, desc) , PlusHP(plusHP) {}
    Consumable() : Consumable("") {}
    ~Consumable() override = default;

    [[nodiscard]] int& GetPlusHP() { return PlusHP;}

    void ShowItem() override {
        std::cout << this;
    }
};

class McPuisor final : public Consumable {
public:
    McPuisor() : Consumable("McPuisor", -40, "This item makes you a bit fatter.") {}
    ~McPuisor() override = default;
};

class Apple final : public Consumable {
public:
    Apple() : Consumable("Apple", 5, "Keeps the doctors away!") {}
    ~Apple() override = default;
};

class Vodka final : public Consumable {
public:
    Vodka() : Consumable("Vodka", 300, "Russian wisdom cyka blyat") {}
    ~Vodka() override = default;
};

class PlateOfSpaghetti final : public Consumable {
public:
    PlateOfSpaghetti() : Consumable("Plate of spaghetti", 300, "To forgetti your regretti.") {}
    ~PlateOfSpaghetti() override = default;
};
#endif //CONSUMABLE_H

inline std::ostream& operator<<(std::ostream& c, Consumable*& C){
    C->ShowItem();
    c << "HP: ";
    if(C->GetPlusHP() < 0) c << "-" << -C->GetPlusHP();
    else if(C->GetPlusHP() == 0) c << "0";
    else c << "+" << C->GetPlusHP();
    c << std::endl;
    return c;
}