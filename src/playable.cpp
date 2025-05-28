#include "../include/playable.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>

Playable::Playable(const char* N, const int ADB = 0, const int DEFB = 0, const int HPM = 0, const int GOLD = 0, const int SPEED = 0, const char* Desc = "-", Weapon* W = std::make_unique<Fists>().get(), Armor* A = std::make_unique<Skin>().get(), std::vector<Consumable*>* I = {}) {
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
    this->SetInventory(I);
    this->Revive();
}

Playable::Playable() : Playable("MissingNo"){}

Playable &Playable::ChangeWeapon(Weapon *&W){
    if (this->GetWeapon() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return *this;
    }
    if (strcmp(W->GetName(), "Fists") == 0 && strcmp(this->GetWeapon()->GetName(), "Fists") == 0) {
        std::cout << "Changing fists for fists? Very funny." << std::endl;
        return *this;
    }
    this->SetAD(this->GetAD() - this->GetWeapon()->GetPlusAD() + W->GetPlusAD());
    if (strcmp(W->GetName(), "Fists") == 0) {
        std::cout << this->GetName() << " has unequipped \"" << this->GetWeapon()->GetName() << "\"."  << std::endl << std::endl;
        delete WeaponSlot;
        this->WeaponSlot = W;
        return *this;
    }
    if (strcmp(this->GetWeapon()->GetName(), "Fists") == 0) {
        std::cout << this->GetName() << " has equipped \"" << W->GetName() << "\"!" << std::endl << std::endl;
        delete WeaponSlot;
        this->WeaponSlot = W;
        return *this;
    }
    if (strcmp(this->GetWeapon()->GetName(), W->GetName()) == 0) {
        std::cout << this->GetName() << " already has this weapon equipped." << std::endl << std::endl;
        return *this;
    }
    delete WeaponSlot;
    this->WeaponSlot = W;
    std::cout << this->GetName() << "'s weapon has been changed to \"" << W->GetName() << "\"!" << std::endl << std::endl;
    return *this;
}

Playable &Playable::ChangeArmor(Armor *&A){
    if (this->GetArmor() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return *this;
    }
    if (strcmp(A->GetName(), "Skin") == 0 && strcmp(this->GetArmor()->GetName(), "Skin") == 0) {
        std::cout << "Changing skin for skin? Very funny." << std::endl;
        return *this;
    }
    this->SetHPMAX(this->GetHPMAX() - this->GetArmor()->GetPlusHP() + A->GetPlusHP());
    this->SetDEF(this->GetDEF() - this->GetArmor()->GetPlusDef() + A->GetPlusDef());
    this->SetHPCurrent(std::min(this->GetHPMAX(), this->GetHPCurrent()));
    if (strcmp(A->GetName(), "Skin") == 0) {
        std::cout << this->GetName() << " has unequipped \"" << this->GetArmor()->GetName() << "\"."  << std::endl << std::endl;
        delete ArmorSlot;
        this->SetArmor(A);
        return *this;
    }
    if (strcmp(this->GetArmor()->GetName(), "Skin") == 0) {
        std::cout << this->GetName() << " has equipped \"" << A->GetName() << "\"!" << std::endl << std::endl;
        delete ArmorSlot;
        this->SetArmor(A);
        return *this;
    }
    if (strcmp(this->GetArmor()->GetName(), A->GetName()) == 0) {
        std::cout << this->GetName() << " already has this armor equipped." << std::endl << std::endl;
        return *this;
    }
    delete ArmorSlot;
    this->SetArmor(A);
    std::cout << this->GetName() << "'s armor has been changed to \"" << A->GetName() << "\"!" << std::endl << std::endl;
    return *this;
}

void Playable::CheckInventory(){

    if (this->Inventory->empty()) {
        std::cout << Name << "'s inventory is empty!";
        return;
    }
    std::cout << Name << " has " << Inventory->size() << " item";
    if (Inventory->size() == 1) {
        std::cout << "." << std::endl;
        this->UseConsumable(1);
    }
    else {
        std::ranges::sort(*Inventory, [](Consumable* a, Consumable* b)
        {if (strcmp(a->GetDescription(), b->GetDescription()) < 0)
                return true;
            return false;
        } );
        std::cout << "s:" << std::endl;
        for (unsigned long item = 0; item < Inventory->size(); ++item) {
            std::cout << item + 1 << ". " << Inventory->at(item)->GetName() << std::endl;
        }
        std::cout << "Enter a number between 1 and " << Inventory->size() << ":\n> ";
        unsigned long nr;
        std::cin >> nr;
        if (nr > Inventory->size())
            std::cout << "Number out of bounds. " << (nr - 1) % Inventory->size() + 1 << " chosen.";
        nr = (nr - 1) % static_cast<int>(Inventory->size()) + 1;
        this->UseConsumable(static_cast<int>(nr));
    }
}

std::vector<Consumable*>& Playable::AddConsumableToInventory(Consumable& I) const {
    if (this->GetInventory()->size() >= 5) {
        std::ranges::sort(*Inventory, [](Consumable* a, Consumable* b)
        {if (strcmp(a->GetName(), b->GetName()) < 0)
                return true;
            return false;
        } );
        std::cout << this->GetName() << "\'s inventory is full! Do you want to replace an item?\n[Y/N] ";
        std::string response;
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                std::cout << "Which item would you like to replace?\n";
                for (unsigned long item = 0; item < this->GetInventory()->size(); ++item) {
                    std::cout << item + 1 << ". " << this->GetInventory()->at(item)->GetName() << std::endl;
                }
                std::cout << "\nPlease enter a number between 1 and 5.\n> ";
                unsigned long nr = 0;
                std::cin >> nr;
                nr = (nr - 1) % this->GetInventory()->size();
                this->GetInventory()->erase(this->GetInventory()->begin() + nr);
                this->GetInventory()->push_back(&I);
                std::cout <<  "Consumable \"" << I.GetName() << "\" added to " << Name << "\'s inventory successfully!" << std::endl;
                break;
            }
            case 'n' : {
                std::cout << "Item not replaced." << std::endl;
                break;
            }
            default: {
                std::cout << "Response not recognized! Item not replaced." << std::endl;
                break;
            }
        }
    }
    else {
        this->GetInventory()->push_back(&I);
    }
    return *Inventory;
}

std::vector<Consumable*>& Playable::UseConsumable(const int i) {
    const auto I = Inventory->at(i-1);
    SetHPCurrent(this->GetHPCurrent() + I->GetPlusHP());
    if (this->GetHPCurrent() < 0)
        SetHPCurrent(0);
    if (this->GetHPCurrent() > this->GetHPMAX())
        SetHPCurrent(GetHPMAX());
    std::cout << this->GetName() << " used \"" << I->GetName() << "\"! They ";
    if (I->GetPlusHP() < 0)
        std::cout << "lost " << -I->GetPlusHP();
    else
        std::cout << "gained " << I->GetPlusHP();
    std::cout << " HP!" << std::endl;
    Inventory->erase(Inventory->begin() + i - 1);
    delete I;
    return *Inventory;
}