#pragma once

#ifndef PLAYABLE_H
#define PLAYABLE_H

#include "entity.h"
#include "consumable.h"
#include <vector>

class Playable final : public Entity {
protected:
    int XP = 0;
    std::vector<Consumable *> Inventory {};
    void Death() const;

public:
    Playable(const char*, int, int, int, int, int, int, const char*, const Weapon*, const Armor*, const std::vector<Consumable*> &);
    Playable();
    ~Playable() override = default;

    [[nodiscard]] std::vector<Consumable *> GetInventory() const {return Inventory;}

    void ChangeWeapon(const Weapon&);
    void ChangeArmor(const Armor&);
    void CheckInventory();
    void AddConsumableToInventory(Consumable&);
    void UseConsumable(int);

    void ShowEntity() override;
};

#endif //PLAYABLE_H
