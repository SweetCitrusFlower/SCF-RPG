#pragma once

#include "entity.h"
#include "consumable.h"
#include <vector>
#include <cmath>

#include <fstream>
inline std::ifstream cin("../tastatura.txt");

#ifndef PLAYABLE_H
#define PLAYABLE_H

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

    void ShowEntity() const override {
        std::cout << this->GetName() << std::endl << this->GetDesc() << std::endl;
        std::cout << this->GetAD() << " AD, " << this->GetHPCurrent() << "/" << this->GetHPMAX() << " HP, " << this->GetDEF() << " DEF, " << this->GetSpeed() << " Speed" << std::endl;;
        std::cout << "Weapon: " << this->GetWeapon()->GetName() << std::endl;
        std::cout << "Armor: " << this->GetArmor()->GetName() << std::endl;
    }
};

class Weakling final : public Playable {
public:
    Weakling() : Playable("Weakling", 0, 0, 1, 0, 1, "-", new Fists, new Skin, {}) {}
    ~Weakling() override {
        SetWeapon(nullptr);
        SetArmor(nullptr);
    }
};

class Mera final: public Playable {
public:
    Mera() : Playable("Mera", 5, 2, 30, 46, 3, "He loves playing League", new Fists, new Skin, {new Vodka}) {}
    ~Mera() override {
        SetWeapon(nullptr);
        SetArmor(nullptr);
    }
};

class Dragos final: public Playable {
public:
    Dragos() : Playable("Dragos", 15, 1, 115, 5, 11, "A beautiful feller", new Cigarette, new LanaTShirt, {new Apple()}) {}
    ~Dragos() override {
        SetWeapon(nullptr);
        SetArmor(nullptr);
    }
};

class sans final : public Playable {
public:
    sans() : Playable("sans.", 1, 1, 1, 43, 1, "erererererer", new Fists, new Skin, {}) {}
    ~sans() override {
        SetWeapon(nullptr);
        SetArmor(nullptr);
    }
};

#endif //PLAYABLE_H

inline std::ostream& operator<<(std::ostream& c, const Playable& P){
    P.ShowEntity();
    const int LVL = ceil(log2(1 + P.GetXP()));
    c << "LVL: " << LVL << ", XP: " << P.GetXP() << std::endl;
    c << "Next LVL threshold at " << pow(2, LVL) << " XP" << std::endl;
    c << "Has " << P.GetGold() << " Gold to their name." << std::endl;
    return c;
}