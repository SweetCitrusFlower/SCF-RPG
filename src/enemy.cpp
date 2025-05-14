#include "../include/enemy.h"

Enemy::Enemy(const int ADB, const int DEFB, const int HPM, const int XP, const int G, const char* N, const char* Desc, Weapon* W, Armor* A) :
    XPGivenWhenSlain(XP), GoldGivenWhenSlain(G) {
    if (N == nullptr) N = "MissingNO";
    if (Desc == nullptr) Desc = "-";
    if (W == nullptr) W = new Weapon();
    if (A == nullptr) A = new Armor();
    this->AttackDamageBase = ADB;
    this->DefenseBase = DEFB;
    this->HitPointsMax = HPM;
    this->HitPointsCurrent = HPM;
    this->Name = N;
    this->Description = Desc;
    this->WeaponSlot = W;
    this->ArmorSlot = A;
}

Enemy::Enemy() : Enemy(0, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr) {};

std::ostream& operator<<(std::ostream& c, const Enemy& E) {
    c << E.GetName() << std::endl;
    c << E.GetAD() << "(+" << E.GetWeapon()->GetPlusAD() << ") AD, " << E.GetDEF() << "(+" << E.GetArmor()->GetPlusDef() << ") DEF, " << E.GetHPCurrent() << "/" << E.GetHPCurrent() + E.GetArmor()->GetPlusHP() << " HP" << std::endl;
    c << E.GetDesc() << std::endl;
    c << "Gives " << E.GetGoldWhenSlain() << " Gold and " << E.GetXPWhenSlain() << " XP when slain." << std::endl << std::endl;
    c << "Weapon: " << *E.GetWeapon();
    c << "Armor: " << *E.GetArmor();
    return c;
}
