#ifndef PLAYABLE_H
#define PLAYABLE_H

#include <array>

#include "entity.h"
#include "item.h"

class Playable : public Entity {
protected:
    int XP = 0;
public:
    Playable(int, int, int, int, int, const char*, const char*, const Weapon*, const Armor*, const std::vector<const Item&>*);
    Playable();
    ~Playable() override;

    void ChangeWeapon(const Weapon&);
    void ChangeArmor(const Armor&);
    void CheckInventory();

    // friend std::istream& operator>>(std::istream&);
    std::ostream& operator<<(std::ostream&);
};

#endif //PLAYABLE_H
