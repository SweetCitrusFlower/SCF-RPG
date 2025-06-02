#pragma once

#include "entity.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Entity {
public:
    explicit Enemy(const char* N, const int ADB = 1, const int DEFB = 0, const int HPM = 1, const int XP = 0, const int GOLD = 0, const int SPEED = 0, const char* Desc = "Stupid dumbass enemy.", Weapon* W = new Fists, Armor* A = new Skin) {
        this->SetName(N);
        this->SetWeapon(W);
        this->SetArmor(A);
        this->SetAD(ADB + this->GetWeapon()->GetPlusAD());
        this->SetDEF(DEFB + this->GetArmor()->GetPlusDef());
        this->SetHPMAX(HPM + this->GetArmor()->GetPlusHP());
        this->SetXP(XP);
        this->SetHPCurrent(GetHPMAX());
        this->SetGold(GOLD);
        this->SetSpeed(SPEED);
        this->SetDesc(Desc);
        this->Revive();
    }

    friend std::ostream& operator<<(std::ostream& c, const Enemy& E) {
        E.ShowEntity();
        c << "Gives " << E.GetXP() << " XP and " << E.GetGold() << " Gold when slain." << std::endl;
        return c;
    }

    ~Enemy() override = default;

    void ShowEntity() const override {std::cout << std::endl;}
};

class Ogre final : public Enemy {
public:
    Ogre(): Enemy("Ogre", 30 + std::rand() % 6, 13 + std::rand() % 5, 58 + std::rand() % 10, 44, 50,
              3 + std::rand() % 3, "A fearsome oger, grumpy mostly because you woke him up.",
              new Weapon("Ogre Club", 40, "Made of the bones of its ancestors."), new Skin) {}
    ~Ogre() override = default;
    void ShowEntity() const override {
        std::cout << this->GetName() << std::endl << this->GetDesc() << std::endl;
        std::cout << this->GetAD() << " AD, " << this->GetHPCurrent() << "/" << this->GetHPMAX() << " HP, " << this->GetDEF() << " DEF, " << this->GetSpeed() << " Speed" << std::endl;
        std::cout << "Weapon: " << this->GetWeapon()->GetName() << std::endl;
        std::cout << "Armor: " << this->GetArmor()->GetName() << std::endl;
    }
};

class Goblin final : public Enemy {
public:
    Goblin() : Enemy("Goblin", 7 + std::rand() % 4,  6 + std::rand() % 3, 22 + std::rand() % 8, 8, 10,
            8 + std::rand() % 4, "It screams, for the Void screams louder.",
            new Weapon("Goblin Bone", 10, "A wish bone that didn't crack properly."), new Skin) {}
    ~Goblin() override = default;
    void ShowEntity() const override {}
};

class ArmoredBeast final : public Enemy {
public:
    ArmoredBeast() : Enemy("Armored Beast", 4 + std::rand() % 2, 13 + std::rand() % 3, 30 + std::rand() % 10, 44, 50,
                           2 + std::rand() % 2, "Heavy and slow, like the flow of time.", new Fists,
                           new Armor("Skeletal Armor", 140, 60, "A plated chestmail of great strength.")) {}
    ~ArmoredBeast() override = default;
    void ShowEntity() const override {}
};



class EnemyCreator{
public:
    virtual ~EnemyCreator() = default;
    [[nodiscard]] virtual Enemy *FactoryMethod() = 0;
};

class OgreCreator final : public EnemyCreator {
public:
    [[nodiscard]] Enemy* FactoryMethod() override {
        auto* i = new Ogre;
        return i;
    }
};
class GoblinCreator final : public EnemyCreator {
public:
    [[nodiscard]] Enemy* FactoryMethod() override {
        auto* i = new Goblin;
        return i;
    }
};
class BeastCreator final : public EnemyCreator {
public:
    [[nodiscard]] Enemy* FactoryMethod() override {
        auto* i = new ArmoredBeast;
        return i;
    }
};

#endif //ENEMY_H