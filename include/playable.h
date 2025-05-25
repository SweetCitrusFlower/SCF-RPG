#pragma once

#ifndef PLAYABLE_H
#define PLAYABLE_H

#include "entity.h"
#include "../src/consumable.cpp"
#include <vector>

class Playable : public Entity {
protected:
    std::vector<Consumable*> Inventory {};
    std::vector<Consumable*>& UseConsumable(int);

public:

    Playable(const char*, int, int, int, int, int, const char*, Weapon*, Armor*, const std::vector<Consumable*>&);
    Playable();
    ~Playable() override = default;

    std::vector<Consumable*>& SetInventory(const std::vector<Consumable*> &I) {Inventory = I; return Inventory;}
    [[nodiscard]] std::vector<Consumable*>& GetInventory() {return Inventory;}

    Playable& ChangeWeapon(Weapon&);
    Playable& ChangeArmor(Armor&);
    void CheckInventory();
    std::vector<Consumable*>& AddConsumableToInventory(Consumable&);

    void ShowEntity() const override;

};

class Weakling : public Playable {
public:
    Weakling() : Playable("Weakling", 0, 0, 1, 0, 1, "-", new Fists, new Skin, {}) {}
    ~Weakling() override {
        delete this->WeaponSlot;
        delete this->ArmorSlot;
    }
};

class Mera: public Playable {
public:
    Mera() : Playable("Mera", 5, 2, 30, 46, 3, "He loves playing League", new Fists, new Skin, {new Vodka}) {}
    ~Mera() override {
        delete this->WeaponSlot;
        delete this->ArmorSlot;
    }
};

class Dragos : public Playable {
public:
    Dragos() : Playable("Dragos", 15, 1, 115, 5, 11, "A beautiful feller", new Cigarette, new LanaTShirt, {new Apple()}) {}
    ~Dragos() override {
        delete this->WeaponSlot;
        delete this->ArmorSlot;
    }
};

class sans : public Playable {
public:
    sans() : Playable("sans.", 1, 1, 1, 43, 1, "erererererer", new Fists, new Skin, {}) {}
    ~sans() override {
        delete this->WeaponSlot;
        delete this->ArmorSlot;
    }
};


#endif //PLAYABLE_H
