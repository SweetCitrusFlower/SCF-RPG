#pragma once

#include "../include/playable.h"
#include "entity.cpp"

#include <algorithm>
#include <vector>
#include <cstring>

Playable::Playable(const char* N, const int ADB = 0, const int DEFB = 0, const int HPM = 0, const int GOLD = 0, const int XP = 0, const int SPEED = 0, const char* Desc = "-", const Weapon* W = &Fists, const Armor* A = &Skin, const std::vector<Consumable*> &I = {})
    : Entity(N, ADB, DEFB, HPM, GOLD, SPEED, Desc, W, A), XP(XP), Inventory(I){
    std::cout << "Hello, " << N << "!\n\n";
}

Playable::Playable() : Playable("MissingNo"){}

void Playable::ChangeWeapon(const Weapon &W){
    if (this->GetWeapon() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return;
    }
    if (strcmp(W.GetName(), "Fists") == 0) {
        std::cout << this->GetName() << " has unequipped \"" << this->GetWeapon()->GetName() << "\".\n\n";
        this->WeaponSlot = &W;
        return;
    }
    if (strcmp(this->GetWeapon()->GetName() ,"Fists") == 0) {
        this->WeaponSlot = &W;
        std::cout << this->GetName() << " has eqquiped \"" << W.GetName() << "\"!" << std::endl << std::endl;
        return;
    }

    if (this->GetWeapon() == &W) {
        std::cout << this->GetName() << " already has this weapon equipped." << std::endl << std::endl;
        return;
    }
    std::string response;
    short nr_answers = 0;
    std::cout << this->GetName() << " has another weapon equipped. Do you want to change it to \"" << W.GetName() << "\"?" << std::endl << "[Y/N]: ";
    do {
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                this->WeaponSlot = &W;
                std::cout << this->GetName() << "'s weapon has been changed to \"" << W.GetName() << "\"!" << std::endl << std::endl;
                return;
            }
            case 'n' : {
                std::cout << this->GetName() << "'s weapon has not been changed." << std::endl << std::endl;
                return;
            }
            default: {
                nr_answers++;
                if (nr_answers < 5) {
                    std::cout << "Please give a valid answer." << std::endl;
                }
                if (nr_answers == 5) {
                    std::cout << "DUDE JUST WRITE Y FOR YES OR N FOR NO IT'S NOT THAT FUCKING HARD!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
                }
                if (nr_answers > 5) {
                    std::cout << "That's it, I'm changing it." << std::endl << std::endl;
                    this->WeaponSlot = &W;
                    std::cout << this->GetName() << "'s weapon has been changed to \"" << W.GetName() << "\"!" << std::endl << std::endl;
                    return;
                }
                std::cout << "[Y/N]: ";
            }
        }
    } while (true);
}

void Playable::ChangeArmor(const Armor &A){
    if (this->GetArmor() == nullptr) {
        std::cout << "how did you do this.\n\n";
        return;
    }
    if (strcmp(A.GetName(), "Skin") == 0) {
        std::cout << this->GetName() << " has unequipped  \"" << this->GetArmor()->GetName() << "\".\n\n";
        this->ArmorSlot = &A;
        return;
    }
    if (strcmp(this->GetArmor()->GetName(), "Skin") == 0) {
        this->ArmorSlot = &A;
        std::cout << this->GetName() << " has eqquiped \"" << A.GetName() << "\"!\n\n";
        return;
    }
    if (this->GetArmor() == &A) {
        std::cout << this->GetName() << " already has this armor equipped.\n\n";
        return;
    }
    std::string response;
    short nr_answers = 0;
    std::cout << this->GetName() << " has another armor equipped. Do you want to change it to \"" << A.GetName() << "\"?\n[Y/N]: ";
    do {
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                this->ArmorSlot = &A;
                std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!\n\n";
                return;
            }
            case 'n' : {
                std::cout << this->GetName() << "'s armor has not been changed.\n\n";
                return;
            }
            default: {
                nr_answers++;
                if (nr_answers < 5) {
                    std::cout << "Please give a valid answer.\n";
                }
                if (nr_answers == 5) {
                    std::cout << "DUDE JUST WRITE Y FOR YES OR N FOR NO IT'S NOT THAT FUCKING HARD!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                }
                if (nr_answers > 5) {
                    std::cout << "That's it, I'm changing it.\n";
                    this->ArmorSlot = &A;
                    std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!\n\n";
                    return;
                }
                std::cout << "[Y/N]: ";
            }
        }
    } while (true);
}

void Playable::CheckInventory(){

    if (this->Inventory.empty()) {
        std::cout << Name << "'s inventory is empty!";
        return;
    }
    std::cout << Name << " has " << Inventory.size() << " item";
    if (Inventory.size() >= 2) {
        std::sort(Inventory.begin(), Inventory.end(), [](const Consumable* a, const Consumable* b)
                                                                                            {if (strcmp(a->GetDescription(), b->GetDescription()) < 0)
                                                                                                    return true;
                                                                                                return false;
                                                                                            } );
        std::cout << "s";
    }
    std::cout << ":" << std::endl;
    for (auto item = 0; item <= Inventory.size(); ++item) {
        std::cout << item + 1 << ". " << Inventory[item]->GetName() << std::endl;
    }
    std::cout << std::endl;
}

void Playable::AddConsumableToInventory(Consumable& I) {
    if (this->Inventory.size() == 5) {
        std::sort(Inventory.begin(), Inventory.end(), [](const Consumable* a, const Consumable* b)
                                                                                            {if (strcmp(a->GetDescription(), b->GetDescription()) < 0)
                                                                                                return true;
                                                                                            return false;
                                                                                        } );
        std::cout << "Your inventory is full! Do you want to replace an item from your inventory?\n[Y/N] ";
        std::string response;
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                std::cout << "Which item would you like to replace?\n";
                for (auto item = 0; item <= Inventory.size(); ++item) {
                    std::cout << item + 1 << ". " << Inventory[item]->GetName() << std::endl;
                }
                std::cout << "\nPlease enter a number between 1 and " << Inventory.size() << ".\n> ";
                auto nr = 0;
                std::cin >> nr;
                nr = (nr - 1) % Inventory.size();
                Inventory.erase(Inventory.begin() + nr);
                Inventory.insert(Inventory.begin() + nr, &I);
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
        Inventory.push_back(&I);
        std::cout <<  "Consumable \"" << I.GetName() << "\" added to " << Name << "\'s inventory succesfully!" << std::endl;
    }
    std::cout << std::endl;
}

void Playable::UseConsumable(const int i) {
    const auto I = Inventory[i - 1];
    Inventory.erase(Inventory.begin() + i - 1);
    HitPointsCurrent += I->GetPlusHP();
    if (HitPointsCurrent < 0)
        HitPointsCurrent = 0;
    if (HitPointsCurrent > GetHPMAX())
        HitPointsCurrent = GetHPMAX();
    std::cout << Name << " has used \"" << I->GetName() << "\"! They have ";
    if (I->GetPlusHP() < 0)
        std::cout << "lost " << -I->GetPlusHP();
    else
        std::cout << "gained " << I->GetPlusHP();
    std::cout << "HP!" << std::endl;
    if (this->GetHPCurrent() == 0){
        Death();
    }
}

std::ostream& operator<<(std::ostream& c, const Playable& P){
    c << (Entity&)P << "Has " << P.GetGold() << " Gold to their name." << std::endl;
    return c;
}

void Playable::ShowEntity() {
    std::cout << *this;
}

void Playable::Death() const {
    std::cout << this->Name << " has passed away...";
}