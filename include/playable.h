#pragma once

#ifndef PLAYABLE_H
#define PLAYABLE_H

#include "entity.h"
#include "../src/consumable.cpp"
#include <vector>

class Playable final : public Entity {
protected:
    std::vector<Consumable> Inventory {};
    std::vector<Consumable>& UseConsumable(int);

public:

    Playable(const char*, int, int, int, int, int, const char*, Weapon*, Armor*, const std::vector<Consumable>&);
    Playable();
    ~Playable() override = default;

    std::vector<Consumable>& SetInventory(const std::vector<Consumable> &I) {Inventory = I; return Inventory;}
    [[nodiscard]] std::vector<Consumable> GetInventory() const {return Inventory;}

    Playable& ChangeWeapon(Weapon&);
    Playable& ChangeArmor(Armor&);
    void CheckInventory();
    std::vector<Consumable>& AddConsumableToInventory(const Consumable&);

    void ShowEntity() const override;

};

#endif //PLAYABLE_H
