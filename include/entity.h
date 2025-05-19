#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include "../src/weapon.cpp"
#include "../src/armor.cpp"
#include "../src/consumable.cpp"

class Entity {
protected:
    int AttackDamageBase = 0;
    int DefenseBase = 0;
    int HitPointsMax = 0;
    int HitPointsCurrent = 0;
    int Gold = 0;
    int Speed = 0;

    const char *Name = nullptr;
    const char *Description = nullptr;
    const Weapon *WeaponSlot = nullptr;
    const Armor *ArmorSlot = nullptr;

    virtual ~Entity() = default;

public:
    [[nodiscard]] int GetAD() const {return AttackDamageBase;}
    [[nodiscard]] int GetDEF() const {return DefenseBase;}
    [[nodiscard]] int GetHPMAX() const {return HitPointsMax;}
    [[nodiscard]] int GetHPCurrent() const {return HitPointsCurrent;}
    [[nodiscard]] int GetGold() const {return Gold;}
    [[nodiscard]] int GetSpeed() const {return Speed;}

    [[nodiscard]] const char* GetName() const {return Name;}
    [[nodiscard]] const char* GetDesc() const {return Description;}
    [[nodiscard]] const Weapon* GetWeapon() const {return WeaponSlot;}
    [[nodiscard]] const Armor* GetArmor() const {return ArmorSlot;}

    void SetAD(const int x) {AttackDamageBase = x;}
    void SetDEF(const int x) {DefenseBase = x;}
    void SetHPMAX(const int x) {HitPointsMax = x;}
    void SetHPCurrent(const int x) {HitPointsCurrent = x;}
    void SetGold(const int x) {Gold = x;}
    void SetSpeed(const int x) {Speed = x;}
    void SetName(const char *name) {Name = name;}
    void SetDesc(const char *desc) {Description = desc;}
    void SetWeapon(const Weapon *W) {WeaponSlot = W;}
    void SetArmor(const Armor *A) {ArmorSlot = A;}

    Entity(const char* N, const int ADB, const int DEFB, const int HPM, const int GOLD, const int SPEED, const char* Desc, const Weapon* W, const Armor* A) {
        SetAD(ADB);
        SetDEF(DEFB);
        SetHPMAX(HPM);
        SetHPCurrent(HPM);
        SetGold(GOLD);
        SetSpeed(SPEED);
        SetName(N);
        SetDesc(Desc);
        SetWeapon(W);
        SetArmor(A);
    }

    Entity() : Entity(nullptr, 0,0,0,0,0,nullptr, nullptr, nullptr){}

    Entity(const Entity &E) {
        SetAD(E.GetAD());
        SetDEF(E.GetDEF());
        SetHPMAX(E.GetHPMAX());
        SetHPCurrent(E.GetHPCurrent());
        SetGold(E.GetGold());
        SetSpeed(E.GetSpeed());
        SetName(E.GetName());
        SetDesc(E.GetDesc());
        SetArmor(E.GetArmor());
        SetWeapon(E.GetWeapon());
    }


    Entity(Entity &&E) noexcept :
        AttackDamageBase(E.AttackDamageBase),
        DefenseBase(E.DefenseBase),
        HitPointsMax(E.HitPointsMax),
        HitPointsCurrent(E.HitPointsCurrent),
        Speed(E.Speed),
        Name(E.Name),
        Description(E.Description),
        WeaponSlot(E.WeaponSlot),
        ArmorSlot(E.ArmorSlot) {}

    Entity& operator=(const Entity &E) {
        if(this == &E)
            return *this;
        AttackDamageBase = E.AttackDamageBase;
        DefenseBase = E.DefenseBase;
        HitPointsMax = E.HitPointsMax;
        HitPointsCurrent = E.HitPointsCurrent;
        Speed = E.Speed;
        Name = E.Name;
        Description = E.Description;
        WeaponSlot = E.WeaponSlot;
        ArmorSlot = E.ArmorSlot;
        return *this;
    }

    Entity& operator=(Entity &&E) noexcept {
        if(this == &E)
            return *this;
        AttackDamageBase = E.AttackDamageBase;
        DefenseBase = E.DefenseBase;
        HitPointsMax = E.HitPointsMax;
        HitPointsCurrent = E.HitPointsCurrent;
        Speed = E.Speed;
        Name = E.Name;
        Description = E.Description;
        WeaponSlot = E.WeaponSlot;
        ArmorSlot = E.ArmorSlot;
        return *this;
    }
};

#endif //ENTITY_H
