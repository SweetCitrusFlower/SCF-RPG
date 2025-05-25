#include "../include/playable.h"
#include <algorithm>
#include <cmath>
#include <cstring>

Playable::Playable(const char* N, const int ADB = 0, const int DEFB = 0, const int HPM = 0, const int GOLD = 0, const int SPEED = 0, const char* Desc = "-", Weapon* W = &Fists, Armor* A = &Skin, const std::vector<Consumable>& I = {}) {
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
}

Playable::Playable() : Playable("MissingNo"){}

Playable& Playable::ChangeWeapon(Weapon &W){
    if (this->GetWeapon() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return *this;
    }
    if (&W == &Fists && this->GetWeapon() == &Fists) {
        std::cout << "Changing fists for fists? Very funny." << std::endl;
        return *this;
    }
    SetAD(this->GetAD() - this->GetWeapon()->GetPlusAD() + W.GetPlusAD());
    if (&W == &Fists) {
        std::cout << this->GetName() << " has unequipped \"" << this->GetWeapon()->GetName() << "\"."  << std::endl << std::endl;
        this->SetWeapon(&W);
        return *this;
    }
    if (this->GetWeapon() == &Fists) {
        std::cout << this->GetName() << " has eqquiped \"" << W.GetName() << "\"!" << std::endl << std::endl;
        this->SetWeapon(&W);
        return *this;
    }
    if (this->GetWeapon() == &W) {
        std::cout << this->GetName() << " already has this weapon equipped." << std::endl << std::endl;
        return *this;
    }
    this->SetWeapon(&W);
    std::cout << this->GetName() << "'s weapon has been changed to \"" << W.GetName() << "\"!" << std::endl << std::endl;
    return *this;
}

Playable& Playable::ChangeArmor(Armor &A){
    if (this->GetArmor() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return *this;
    }
    if (&A == &Skin && this->GetArmor() == &Skin) {
        std::cout << "Changing skin for skin? Very funny." << std::endl;
        return *this;
    }
    SetHPMAX(this->GetHPMAX() - this->GetArmor()->GetPlusHP() + A.GetPlusHP());
    SetDEF(this->GetDEF() - this->GetArmor()->GetPlusDef() + A.GetPlusDef());
    SetHPCurrent(std::min(this->GetHPMAX(), this->GetHPCurrent()));
    if (&A == &Skin) {
        std::cout << this->GetName() << " has unequipped \"" << this->GetArmor()->GetName() << "\"."  << std::endl << std::endl;
        this->SetArmor(&A);
        return *this;
    }
    if (this->GetArmor() == &Skin) {
        std::cout << this->GetName() << " has eqquiped \"" << A.GetName() << "\"!" << std::endl << std::endl;
        this->SetArmor(&A);
        return *this;
    }
    if (this->GetArmor() == &A) {
        std::cout << this->GetName() << " already has this armor equipped." << std::endl << std::endl;
        return *this;
    }
    this->SetArmor(&A);
    std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!" << std::endl << std::endl;
    return *this;
}

void Playable::CheckInventory(){

    if (this->Inventory.empty()) {
        std::cout << Name << "'s inventory is empty!";
        return;
    }
    std::cout << Name << " has " << Inventory.size() << " item";
    if (Inventory.size() >= 2) {
        std::sort(Inventory.begin(), Inventory.end(), [](Consumable& a, Consumable& b)
                                                                    {if (strcmp(a.GetDescription(), b.GetDescription()) < 0)
                                                                            return true;
                                                                        return false;
                                                                    } );
        std::cout << "s";
    }
    std::cout << ":" << std::endl;
    for (unsigned long item = 0; item < Inventory.size(); ++item) {
        std::cout << item + 1 << ". " << Inventory[item].GetName() << std::endl;
    }
    std::cout << "Do you want to use a consumable on " << this->GetName() << "?\n[Y/N] ";
    std::string response;
    std::cin >> response;
    switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
        case 'y' : {
            std::cout << "Enter a number between 1 and " << Inventory.size() << ":\n";
            unsigned long nr;
            std::cin >> nr;
            if (nr > Inventory.size()) {
                std::cout << "Number out of bounds. " << (nr - 1) % Inventory.size() + 1 << " chosen.";
            }
            nr = (nr - 1) % static_cast<int>(Inventory.size()) + 1;
            this->UseConsumable(static_cast<int>(nr));
            break;
        }
        default: {
            break;
        }
    }
    std::cout << std::endl;
}

std::vector<Consumable>& Playable::AddConsumableToInventory(const Consumable& I) {
    if (this->GetInventory().size() >= 5) {
        std::sort(Inventory.begin(), Inventory.end(), [](Consumable& a, Consumable& b)
                                                                    {if (strcmp(a.GetName(), b.GetName()) < 0)
                                                                        return true;
                                                                    return false;
                                                                    } );
        std::cout << this->GetName() << "\'s inventory is full! Do you want to replace an item?\n[Y/N] ";
        std::string response;
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                std::cout << "Which item would you like to replace?\n";
                for (unsigned long item = 0; item < this->GetInventory().size(); ++item) {
                    std::cout << item + 1 << ". " << this->GetInventory()[item].GetName() << std::endl;
                }
                std::cout << "\nPlease enter a number between 1 and 5.\n> ";
                auto nr = 0;
                std::cin >> nr;
                nr = (nr - 1) % this->GetInventory().size();
                this->GetInventory().erase(this->GetInventory().begin() + nr);
                Inventory.push_back(I);
                std::cout <<  "Consumable \"" << I.GetName() << "\" added to " << Name << "\'s inventory succesfully!" << std::endl;
                break;
            }
            default: {
                std::cout << "Response not recognized! ";
            }
            case 'n' : {
                std::cout << "Item not replaced." << std::endl;
                break;
            }
        }
    }
    else {
        Inventory.push_back(I);
    }
    return Inventory;
}

std::vector<Consumable>& Playable::UseConsumable(const int i) {
    const auto I = Inventory[i - 1];
    SetHPCurrent(this->GetHPCurrent() + I.GetPlusHP());
    if (this->GetHPCurrent() < 0)
        SetHPCurrent(0);
    if (this->GetHPCurrent() > this->GetHPMAX())
        SetHPCurrent(GetHPMAX());
    std::cout << this->GetName() << " has used \"" << I.GetName() << "\"! They have ";
    if (I.GetPlusHP() < 0)
        std::cout << "lost " << -I.GetPlusHP();
    else
        std::cout << "gained " << I.GetPlusHP();
    std::cout << " HP!" << std::endl;
    Inventory.erase(Inventory.begin() + i - 1);
    if (this->GetHPCurrent() == 0){}
    return Inventory;
}

std::ostream& operator<<(std::ostream& c, const Playable& P){
    P.ShowEntity();
    const int LVL = ceil(log2(1 + P.GetXP()));
    c << "LVL: " << LVL << ", XP: " << P.GetXP() << std::endl;
    c << "Next LVL threshold at " << pow(2, LVL) << " XP" << std::endl;
    c << "Has " << P.GetGold() << " Gold to their name." << std::endl;
    return c;
}

void Playable::ShowEntity() const {
    std::cout << this->GetName() << std::endl << this->GetDesc() << std::endl;
    std::cout << this->GetAD() << " AD, " << this->GetHPCurrent() << "/" << this->GetHPMAX() << " HP, " << this->GetDEF() << " DEF" << std::endl;
    std::cout << "Weapon: " << this->GetWeapon()->GetName() << std::endl;
    std::cout << "Armor: " << this->GetArmor()->GetName() << std::endl;
}

inline auto Mera = Playable("Mera", 5, 2, 30, 46, 3, "He loves playing League", &FlipPhone, &Skin, {Vodka});
inline auto Dragos = Playable("Dragos", 15, 1, 115, 5, 11, "A beautiful feller", &Cigarette, &LanaTShirt, {Apple});
inline auto Weakling = Playable("Weakling", 0, 0, 1, 0, 1, "-", &Fists, &Skin, {});
inline auto sans = Playable("sans.", 1, 1, 1, 43, 1, "erererererer", &Fists, &Skin, {});
inline std::vector AllPlayables = {Mera, Dragos, Weakling, sans};
