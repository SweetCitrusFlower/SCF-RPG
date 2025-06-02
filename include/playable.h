#pragma once

#include "entity.h"
#include "consumable.h"
#include <vector>
#include <cmath>

#ifndef PLAYABLE_H
#define PLAYABLE_H

class Playable : public Entity {
protected:
    std::vector<Consumable*> *Inventory = {};
    std::vector<Consumable*>& UseConsumable(int);

public:

    Playable(const char*, int, int, int, int, int, const char*, Weapon*, Armor*, std::vector<Consumable*>*);
    Playable();
    ~Playable() override {
        if (!Inventory->empty())
            for (const auto i : *Inventory) {
                delete i;
            }
        Inventory->clear();
    }

    std::vector<Consumable*>* SetInventory(std::vector<Consumable*> *&I) {Inventory = I; return Inventory;}
    [[nodiscard]] std::vector<Consumable*>* GetInventory() const {return Inventory;}

    Playable &ChangeWeapon(Weapon *&);

    Playable &ChangeArmor(Armor *&);
    void CheckInventory();
    std::vector<Consumable*>& AddConsumableToInventory(Consumable&) const;

    void ShowEntity() const override {
        std::cout << this->GetName() << std::endl << this->GetDesc() << std::endl;
        std::cout << this->GetAD() << " AD, " << this->GetHPCurrent() << "/" << this->GetHPMAX() << " HP, " << this->GetDEF() << " DEF, " << this->GetSpeed() << " Speed" << std::endl;;
        std::cout << "Weapon: " << this->GetWeapon()->GetName() << std::endl;
        std::cout << "Armor: " << this->GetArmor()->GetName() << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& c, const Playable& P){
        P.ShowEntity();
        const int LVL = ceil(log2(1 + P.GetXP()));
        c << "LVL: " << LVL << ", XP: " << P.GetXP() << std::endl;
        c << "Next LVL threshold at " << pow(2, LVL) << " XP" << std::endl;
        c << "Has " << P.GetGold() << " Gold to their name." << std::endl;
        return c;
    }
};

class Weakling final : public Playable {
public:
    Weakling() : Playable("Weakling", 0, 0, 1, 0, 1, "-", new Fists, new Skin, new std::vector<Consumable*> {}) {}
    ~Weakling() override = default;
};

class Mera final: public Playable {
public:
    Mera() : Playable("Mera", 5, 2, 30, 46, 3, "He loves playing League", new Fists, new Skin, new std::vector<Consumable*> {}) {}
    ~Mera() override = default;
};

class Dragos final: public Playable {
public:
    Dragos() : Playable("Dragos", 15, 1, 115, 5, 11, "A beautiful feller", new Cigarette, new LanaTShirt, new std::vector<Consumable*> {new Apple}) {}
    ~Dragos() override = default;
};

class sans final : public Playable {
public:
    sans() : Playable("sans.", 1, 1, 1, 43, 1, "erererererer", new Fists, new Skin, new std::vector<Consumable*> {new PlateOfSpaghetti}) {}
    ~sans() override = default;
};

class GOD final : public Playable {
public:
    GOD() : Playable("GOD", 99999, 999999, 99999, 99999, 99999, "god", new Fists, new Skin, new std::vector<Consumable*> {}) {}
    ~GOD() override = default;
};

#endif //PLAYABLE_H