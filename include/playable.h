#ifndef PLAYABLE_H
#define PLAYABLE_H

#include <array>

#include "entity.h"
#include "consumable.h"

class Playable : public Entity {
protected:
    int XP = 0;
    std::vector<Consumable *> Inventory {};

public:
    Playable(const char*, int, int, int, int, int, int, const char*, const Weapon*, const Armor*, std::vector<Consumable*>);
    Playable();
    ~Playable() override;

    [[nodiscard]] std::vector<Consumable *> GetInventory() const {return Inventory;}

    void ChangeWeapon(const Weapon&);
    void ChangeArmor(const Armor&);
    void CheckInventory();
    void AddConsumableToInventory(Consumable&);

    std::ostream& operator<<(std::ostream&);
};

#endif //PLAYABLE_H
