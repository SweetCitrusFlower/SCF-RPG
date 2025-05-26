#pragma once

#include "weapon.h"
#include "armor.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    const char *Name = nullptr;
    int AttackDamageBase = 0;
    int DefenseBase = 0;
    int HitPointsMax = 0;
    int HitPointsCurrent = 0;
    int Gold = 0;
    int Speed = 0;
    int XP = 0;
    bool alive = true;
    const char *Description = nullptr;
    Weapon *WeaponSlot = nullptr;
    Armor *ArmorSlot = nullptr;
public:

    virtual ~Entity() = default;
    virtual void ShowEntity() const = 0;
    virtual std::ostream& operator<<(std::ostream& os) const = delete;

    [[nodiscard]] int GetAD() const {return AttackDamageBase;}
    [[nodiscard]] int GetDEF() const {return DefenseBase;}
    [[nodiscard]] int GetHPMAX() const {return HitPointsMax;}
    [[nodiscard]] int GetHPCurrent() const {return HitPointsCurrent;}
    [[nodiscard]] int GetGold() const {return Gold;}
    [[nodiscard]] int GetSpeed() const {return Speed;}
    [[nodiscard]] const char* GetName() const {return Name;}
    [[nodiscard]] const char* GetDesc() const {return Description;}
    [[nodiscard]] int GetXP() const {return XP;}
    [[nodiscard]] bool GetAlive() const {return alive;}
    [[nodiscard]] Weapon* GetWeapon() const {return WeaponSlot;}
    [[nodiscard]] Armor* GetArmor() const {return ArmorSlot;}

    Entity* Kill() {this->alive = false; return this;}
    Entity* Revive() {this->alive = true; return this;}

    int& SetAD(const int x) {AttackDamageBase = x;return this->AttackDamageBase;}
    int& SetDEF(const int x) {DefenseBase = x;return this->DefenseBase;}
    int& SetHPMAX(const int x) {HitPointsMax = x;return this->HitPointsMax;}
    int& SetHPCurrent(const int x) {HitPointsCurrent = x; return this->HitPointsCurrent;}
    int& SetGold(const int x) {Gold = x; return Gold;}
    int& SetSpeed(const int x) {Speed = x; return this->Speed;}
    const char*& SetName(const char *name) {Name = name; return Name;}
    const char*& SetDesc(const char *desc) {Description = desc; return this->Description;}
    int& SetXP(const int x) {this->XP = x; return this->XP;}
    Weapon*& SetWeapon(Weapon *W) {WeaponSlot = W; return this->WeaponSlot;}
    Armor*& SetArmor(Armor *A) {ArmorSlot = A; return this->ArmorSlot;}

    Entity& operator=(const Entity &other) {
        if (this == &other)
            return *this;
        Name = other.Name;
        AttackDamageBase = other.AttackDamageBase;
        DefenseBase = other.DefenseBase;
        HitPointsMax = other.HitPointsMax;
        HitPointsCurrent = other.HitPointsCurrent;
        Gold = other.Gold;
        Speed = other.Speed;
        XP = other.XP;
        alive = other.alive;
        Description = other.Description;
        WeaponSlot = other.WeaponSlot;
        ArmorSlot = other.ArmorSlot;
        return *this;
    }
};

#endif //ENTITY_H
