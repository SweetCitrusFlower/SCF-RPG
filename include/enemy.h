#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy final : public Entity {
public:
    Enemy(const char*, int, int, int, int, int, int, const char*, Weapon*, Armor*);
    Enemy();
    ~Enemy() override = default;

    void ShowEntity() const override;
};

#endif //ENEMY_H
