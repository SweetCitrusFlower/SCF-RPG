#pragma once

#include "../include/enemy.h"
#include "entity.cpp"

Enemy::Enemy(const char* N, const int ADB = 1, const int DEFB = 0, const int HPM = 1, const int XP = 0, const int G = 0, const int SPEED = 0, const char* Desc = "Stupid dumbass enemy.", const Weapon* W = &Fists, const Armor* A = &Skin) :
    Entity(N, ADB, DEFB, HPM, G, SPEED, Desc, W, A), XPGivenWhenSlain(XP){}

Enemy::Enemy() : Enemy("Goblin"){}

std::ostream& operator<<(std::ostream& c, const Enemy& E){
    c << static_cast<Entity>(E) << "Gives " << E.GetXPWhenSlain() << " XP and " << E.GetGold() << " Gold when slain." << std::endl;
    return c;
}

void Enemy::ShowEntity() {
    std::cout << *this;
}

