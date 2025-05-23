#include "../include/entity.h"
#include <iostream>

Entity::Entity(const char* Name, const int ADB = 0, const int DEFB = 0, const int HPM = 0, const int GOLD = 0, const int SPEED = 0, const char* Desc = nullptr, const Weapon* W = nullptr, const Armor* A = nullptr) {
        SetAD(ADB);
        SetDEF(DEFB);
        SetHPMAX(HPM);
        SetHPCurrent(HPM);
        SetGold(GOLD);
        SetSpeed(SPEED);
        SetName(Name);
        SetDesc(Desc);
        SetWeapon(W);
        SetArmor(A);
    }

Entity::Entity() : Entity(nullptr){}

// Entity::Entity(const Entity &E) {
//         SetAD(E.GetAD());
//         SetDEF(E.GetDEF());
//         SetHPMAX(E.GetHPMAX());
//         SetHPCurrent(E.GetHPCurrent());
//         SetGold(E.GetGold());
//         SetSpeed(E.GetSpeed());
//         SetName(E.GetName());
//         SetDesc(E.GetDesc());
//         SetArmor(E.GetArmor());
//         SetWeapon(E.GetWeapon());
//     }
//
//
// Entity::Entity(Entity &&E) noexcept :
//     AttackDamageBase(E.AttackDamageBase),
//     DefenseBase(E.DefenseBase),
//     HitPointsMax(E.HitPointsMax),
//     HitPointsCurrent(E.HitPointsCurrent),
//     Speed(E.Speed),
//     Name(E.Name),
//     Description(E.Description),
//     WeaponSlot(E.WeaponSlot),
//     ArmorSlot(E.ArmorSlot) {}
//
// Entity& Entity::operator=(const Entity &E) {
//     if(this == &E)
//         return *this;
//     AttackDamageBase = E.AttackDamageBase;
//     DefenseBase = E.DefenseBase;
//     HitPointsMax = E.HitPointsMax;
//     HitPointsCurrent = E.HitPointsCurrent;
//     Speed = E.Speed;
//     Name = E.Name;
//     Description = E.Description;
//     WeaponSlot = E.WeaponSlot;
//     ArmorSlot = E.ArmorSlot;
//     return *this;
// }
//
// Entity& Entity::operator=(Entity &&E) noexcept {
//     if(this == &E)
//         return *this;
//     AttackDamageBase = E.AttackDamageBase;
//     DefenseBase = E.DefenseBase;
//     HitPointsMax = E.HitPointsMax;
//     HitPointsCurrent = E.HitPointsCurrent;
//     Speed = E.Speed;
//     Name = E.Name;
//     Description = E.Description;
//     WeaponSlot = E.WeaponSlot;
//     ArmorSlot = E.ArmorSlot;
//     return *this;
// }

std::ostream& operator<<(std::ostream& c, const Entity& P){
    c << std::endl << P.GetName() << std::endl;
    c << P.GetAD() << " AD, " << P.GetDEF() << " DEF, " << P.GetHPCurrent() << "/" << P.GetHPMAX() << " HP, " << P.GetSpeed() << " SPEED" << std::endl;
    c << P.GetDesc() << std::endl;
    c << "Weapon: " << P.GetWeapon()->GetName() << std::endl;
    c << "Armor: " << P.GetArmor()->GetName() << std::endl;
    return c;
}

void Entity::ShowEntity() {
    std::cout << *this;
}

