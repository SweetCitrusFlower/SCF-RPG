#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy final : public Entity {
protected:
    int XPGivenWhenSlain = 0;

public:
    Enemy(const char*, int, int, int, int, int, int, const char*, const Weapon*, const Armor*);
    Enemy();
    ~Enemy() override = default;

    [[nodiscard]] int GetXPWhenSlain() const {return XPGivenWhenSlain;}
    void ShowEntity() override;
};

#endif //ENEMY_H
