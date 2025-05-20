#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "../src/weapon.cpp"
#include "../src/armor.cpp"
#include "virtualentity.h"

class Entity : public VirtualEntity {
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


public:
    Entity(const char*, int, int, int, int, int, const char*, const Weapon*, const Armor*);
    Entity();
    ~Entity() override = default;
    Entity(const Entity&);
    Entity(Entity&&) noexcept;
    Entity& operator=(const Entity&);
    Entity& operator=(Entity&&) noexcept;

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

    void ShowEntity() override;
};

#endif //ENTITY_H
