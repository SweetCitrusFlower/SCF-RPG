#pragma once

#ifndef PLAYABLE_H
#define PLAYABLE_H

#include "entity.h"
#include "consumable.h"
#include <vector>

class Playable final : public Entity {
protected:
    int XP = 0;
    std::vector<Consumable> Inventory {};
    void Death() const;
    void UseConsumable(int);

public:
    Playable(const char*, int, int, int, int, int, int, const char*, const Weapon*, const Armor*, const std::vector<Consumable>&);
    Playable();
    ~Playable() override = default;

    [[nodiscard]] int GetXP() const {return XP;}
    [[nodiscard]] std::vector<Consumable> GetInventory() const& {return Inventory;}

    void ChangeWeapon(const Weapon&);
    void ChangeArmor(const Armor&);
    void CheckInventory();
    void AddConsumableToInventory(const Consumable&);

    void ShowEntity() override;
    void Death();

};

#endif //PLAYABLE_H
