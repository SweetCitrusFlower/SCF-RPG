#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include "../src/weapon.cpp"
#include "../src/armor.cpp"

#include <cstring>

class Entity {
protected:
    int AttackDamageBase = 0;
    int DefenseBase = 0;
    int HitPointsMax = 0;
    int HitPointsCurrent = 0;
    int Gold = 0;

    const char *Name = nullptr;
    const char *Description = nullptr;
    const Weapon *WeaponSlot = nullptr;
    const Armor *ArmorSlot = nullptr;
    const std::vector<const Item&> *Inventory = nullptr;

    virtual ~Entity() = default;

public:
    [[nodiscard]] int GetAD() const {return AttackDamageBase;}
    [[nodiscard]] int GetDEF() const {return DefenseBase;}
    [[nodiscard]] int GetHPMAX() const {return HitPointsMax;}
    [[nodiscard]] int GetHPCurrent() const {return HitPointsCurrent;}
    [[nodiscard]] int GetGold() const {return Gold;}

    [[nodiscard]] const char* GetName() const {return Name;}
    [[nodiscard]] const char* GetDesc() const {return Description;}
    [[nodiscard]] const Weapon* GetWeapon() const {return WeaponSlot;}
    [[nodiscard]] const Armor* GetArmor() const {return ArmorSlot;}
    [[nodiscard]] const std::vector<const Item&>* GetInventory() const {return Inventory;}

    void SetAD(const int x) {AttackDamageBase = x;}
    void SetDEF(const int x) {DefenseBase = x;}
    void SetHPMAX(const int x) {HitPointsMax = x;}
    void SetHPCurrent(const int x) {HitPointsCurrent = x;}
    void SetGold(const int x) {Gold = x;}
    void SetName(const char *name) {Name = name;}
    void SetDesc(const char *desc) {Description = desc;}
    void SetWeapon(const Weapon *W) {WeaponSlot = W;}
    void SetArmor(const Armor *A) {ArmorSlot = A;}
    void AddItemToInventory(const Item& I) {
        if (Inventory->capacity() == 9) {
            std::cout << "Your inventory is full! Do you want to replace an item from your inventory?\n[Y/N] ";
            const std::string response;
            switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
                case 'y' : {
                    std::cout << "\nWhich item would you like to replace?\nEnter a number between 1 and 9.\n";
                    int nr = 1;
                    for (const auto& item : Inventory) {
                        std::cout << nr++ << ". " << item->GetName() << std::endl;
                    }
                    nr = 0;
                    std::cin >> nr;
                    nr = (nr - 1) % 9 + 1;
                    Inventory->erase(Inventory->begin() + nr);
                    Inventory->insert(Inventory->begin() + nr, &I);
                    std::cout << "Item replaced succesfully!" << std::endl;
                    break;
                }
                default: {
                    std::cout << "Response not recognized! ";
                }
                case 'n' : {
                    std::cout << "Item not picked up." << std::endl;
                    break;
                }
            }
        }
        else {
            Inventory->insert(Inventory->begin(), &I);
            std::cout << "Item \"" << I.GetName() << "\" added succesfully!" << std::endl;
        }
    };

    Entity(const Entity &E) {
        this->AttackDamageBase = E.AttackDamageBase,
        this->DefenseBase = E.DefenseBase,
        this->HitPointsMax = E.HitPointsMax,
        this->HitPointsCurrent = E.HitPointsCurrent,
        this->Name = E.Name,
        this->Description = E.Description,
        this->WeaponSlot = E.WeaponSlot,
        this->ArmorSlot = E.ArmorSlot;
    }

    Entity(Entity &&E) noexcept :
        AttackDamageBase(E.AttackDamageBase),
        DefenseBase(E.DefenseBase),
        HitPointsMax(E.HitPointsMax),
        HitPointsCurrent(E.HitPointsCurrent),
        Name(E.Name),
        Description(E.Description),
        WeaponSlot(E.WeaponSlot),
        ArmorSlot(E.ArmorSlot) {}

    Entity() = default;

    Entity& operator=(const Entity &E) {
        if(this == &E)
            return *this;
        AttackDamageBase = E.AttackDamageBase;
        DefenseBase = E.DefenseBase;
        HitPointsMax = E.HitPointsMax;
        HitPointsCurrent = E.HitPointsCurrent;
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
        Name = E.Name;
        Description = E.Description;
        WeaponSlot = E.WeaponSlot;
        ArmorSlot = E.ArmorSlot;
        return *this;
    }
};

#endif //ENTITY_H
