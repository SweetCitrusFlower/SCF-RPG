#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity {
protected:
    const int XPGivenWhenSlain;
    const int GoldGivenWhenSlain;
public:
    Enemy(int, int, int, int, int, const char*, const char*, Weapon*, Armor*);
    Enemy();

    [[nodiscard]] int GetXPWhenSlain() const {return XPGivenWhenSlain;}
    [[nodiscard]] int GetGoldWhenSlain() const {return GoldGivenWhenSlain;}

    friend std::ostream& operator<<(std::ostream&, const Enemy&);
    ~Enemy() override = default;
};

#endif //ENEMY_H
