#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include <random>

class Enemy : public Entity {
public:
    Enemy(const char*, int, int, int, int, int, int, const char*, Weapon*, Armor*);
    ~Enemy() override = default;

    void ShowEntity() const override;
};

class Ogre : public Enemy {
public:
    Ogre(): Enemy("Ogre", 30 + std::rand() % 6, 13 + std::rand() % 5, 58 + std::rand() % 10, 44, 50,
              3 + std::rand() % 3, "A fearsome oger, grumpy mostly because you woke him up.",
              new Weapon("Ogre Club", 40, "Made of the bones of its ancestors."), &Skin) {}

    ~Ogre() override = default;
    void ShowEntity() const override {}
};

class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 7 + std::rand() % 4,  6 + std::rand() % 3, 22 + std::rand() % 8, 8, 10,
            8 + std::rand() % 4, "It screams, for the Void screams louder.",
            new Weapon("Goblin Bone", 10, "A wish bone that didn't crack properly."), &Skin) {};
    ~Goblin() override = default;
    void ShowEntity() const override {};
};

class ArmoredBeast : public Enemy {
public:
    ArmoredBeast() : Enemy("Armored Beast", 4 + std::rand() % 2, 13 + std::rand() % 3, 30 + std::rand() % 10, 44, 50,
                           2 + std::rand() % 2, "Heavy and slow, like the flow of time.", &Fists,
                           new Armor("Skeletal Armor", 140, 60, "A plated chestmail of great strength.")) {};
    ~ArmoredBeast() override = default;
    void ShowEntity() const override {};
};



class EnemyCreator{
public:
    virtual ~EnemyCreator() = default;
    virtual Enemy* FactoryMethod() const = 0;
    void ConfirmCreation() const{
        Enemy* E = this->FactoryMethod();
        if (E == nullptr)
            std::cout << "Enemy unable to be created.\n";
        else
            std::cout << "Enemy " << E->GetName() << " created.\n";
        delete E;
    }
};

class OgreCreator final : public EnemyCreator {
public:
    Enemy* FactoryMethod() const override {
        return new Ogre;
    }
};
class GoblinCreator final : public EnemyCreator {
public:
    Enemy* FactoryMethod() const override {
        return new Goblin;
    }
};
class BeastCreator final : public EnemyCreator {
public:
    Enemy* FactoryMethod() const override {
        return new ArmoredBeast;
    }
};

#endif //ENEMY_H
