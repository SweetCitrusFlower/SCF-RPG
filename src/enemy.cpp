#include "../include/enemy.h"

Enemy::Enemy(const char* N, const int ADB = 1, const int DEFB = 0, const int HPM = 1, const int XP = 0, const int GOLD = 0, const int SPEED = 0, const char* Desc = "Stupid dumbass enemy.", Weapon* W = nullptr, Armor* A = nullptr) {
    this->SetName(N);
    this->SetWeapon(W);
    this->SetArmor(A);
    this->SetAD(ADB + this->GetWeapon()->GetPlusAD());
    this->SetDEF(DEFB + this->GetArmor()->GetPlusDef());
    this->SetHPMAX(HPM + this->GetArmor()->GetPlusHP());
    this->SetHPCurrent(GetHPMAX());
    this->SetGold(GOLD);
    this->SetSpeed(SPEED);
    this->SetDesc(Desc);
}

Enemy::Enemy() : Enemy("Goblin"){}

std::ostream& operator<<(std::ostream& c, const Enemy& E){
    E.ShowEntity();
    c << "Gives " << E.GetXP() << " XP and " << E.GetGold() << " Gold when slain." << std::endl;
    return c;
}

void Enemy::ShowEntity() const {
    std::cout << this->GetName() << std::endl << this->GetDesc() << std::endl;
    std::cout << this->GetAD() << " AD, " << this->GetHPCurrent() << "/" << this->GetHPMAX() << " HP, " << this->GetDEF() << " DEF" << std::endl;
}

