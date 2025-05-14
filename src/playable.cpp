#include "../include/playable.h"

#include <array>
#include <cstring>

Playable::Playable(const int ADB, const int DEFB, const int HPM, const int GOLD, const int XP, const char* N, const char* Desc, const Weapon* W, const Armor* A, const std::vector<const Item&> *I)
{
    if(N == nullptr) N = "MissingNO";
    if(Desc == nullptr) Desc = "-";
    if(W == nullptr) W = new Weapon();
    if(A == nullptr) A = new Armor();
    this->AttackDamageBase = ADB;
    this->DefenseBase = DEFB;
    this->HitPointsMax = HPM;
    this->Gold = GOLD;
    this->XP = XP;
    this->HitPointsCurrent = HPM;
    this->Name = N;
    this->Description = Desc;
    this->WeaponSlot = W;
    this->ArmorSlot = A;
    this->Inventory = I;
}

Playable::Playable() : Playable(0, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr, nullptr){}

void Playable::ChangeWeapon(const Weapon &W){
    if (this->GetWeapon() == nullptr) {
        std::cout << "how did you do this." << std::endl;
        return;
    }
    if (this->GetWeapon()->GetName() == "Fists") {
        this->WeaponSlot = &W;
        std::cout << this->GetName() << "'s weapon has been changed to \"" << W.GetName() << "\"!" << std::endl << std::endl;
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
        std::cout << "how did you do this." << std::endl;
        return;
    }
    if (this->GetArmor()->GetName() == "Skin") {
        this->ArmorSlot = &A;
        std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!" << std::endl << std::endl;
        return;
    }
    if (this->GetArmor() == &A) {
        std::cout << this->GetName() << " already has this armor equipped." << std::endl << std::endl;
        return;
    }
    std::string response;
    short nr_answers = 0;
    std::cout << this->GetName() << " has another armor equipped. Do you want to change it to \"" << A.GetName() << "\"?" << std::endl << "[Y/N]: ";
    do {
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y' : {
                this->ArmorSlot = &A;
                std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!" << std::endl << std::endl;
                return;
            }
            case 'n' : {
                std::cout << this->GetName() << "'s armor has not been changed." << std::endl << std::endl;
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
                    this->ArmorSlot = &A;
                    std::cout << this->GetName() << "'s armor has been changed to \"" << A.GetName() << "\"!" << std::endl << std::endl;
                    return;
                }
                std::cout << "[Y/N]: ";
            }
        }
    } while (true);
}

std::ostream& operator<<(std::ostream& c, const Playable& P) {
    c << P.GetName() << std::endl;
    c << P.GetAD() << "(+" << P.GetWeapon()->GetPlusAD() << ") AD, " << P.GetDEF() << "(+" << P.GetArmor()->GetPlusDef() << ") DEF, " << P.GetHPCurrent() << "/" << P.GetHPCurrent() + P.GetArmor()->GetPlusHP() << " HP" << std::endl;
    c << P.GetDesc() << std::endl;
    c << "Has " << P.GetGold() << " Gold to their name." << std::endl << std::endl;
    c << "Weapon: " << *P.GetWeapon();
    c << "Armor: " << *P.GetArmor();
    return c;
}

// std::istream& operator>>(std::istream& c, const Playable& P) {
//
//     int Name;
//     std::cout << "Hello and welcome to the SCF Player Maker! \n Please give your player a name:\n> ";
//     c >> Name;
//     std::cout << "";
//     return c;
// }

void Playable::CheckInventory() {
    if (this->GetInventory()->empty()) {
        std::cout << this->GetName() << "'s inventory is empty!";
        return;
    }
    std::cout << this->GetName() << " has " << this->GetInventory()->size() << " item";
    if (this->GetInventory()->size() >= 2)
        std::cout << "s";
    std::cout << ":" << std::endl;
    int nr = 1;
    for (const auto& item : this->GetInventory()) {
        std::cout << nr++ << ". " << item->GetName() << std::endl;
    }
}

void Playable::AddItemToInventory(const Item& I) {
    if (this->GetInventory()->capacity() == 9) {
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


Playable::~Playable() {
    std::cout << this->GetName() << " has passed away..." << std::endl;
}