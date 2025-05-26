#include "../include/game.h"
#include <cstring>
#include <ostream>
#include <algorithm>

void Game::ReceiveAction(){
    std::cout << std::endl << "Welcome to SCF RPG! Select an option:\n";
    unsigned long x = 0;
    while (true) {
        std::cout << "1. Fight against a team of random enemies\n";
        std::cout << "2. Edit your team\n";
        std::cout << "3. Show available \"Playables\"\n";
        std::cout << "4. Show available Weapons and Armors\n";
        std::cout << "5. Shop for consumables\n";
        std::cout << "6. Exit\n> ";
        std::cin.clear();
        std::cin >> x;
        if (std::cin && x >= 1 && x <= 6)
        {
            std::cout << std::endl;
            switch (x) {
                case 1: Fight(); break;
                case 2: TeamEditor(); break;
                case 3: ShowPlayables(); break;
                case 4: ShowWeaponsArmors(); break;
                case 5: Shop(); break;
                default: break;
            }
            if (x == 6) {
                std::cout << "Goodbye! Thanks for tuning in!" << std::endl;
                break;
            }
        }
        else {
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Choose again.\n> ";
                std::cin >> x;
            } while (!std::cin || x > 6);
            std::cout << std::endl;
            switch (x) {
                case 1: Fight();break;
                case 2: TeamEditor(); break;
                case 3: ShowPlayables(); break;
                case 4: ShowWeaponsArmors(); break;
                case 5: Shop(); break;
                default: break;
            }
            if (x == 6) {
                std::cout << "Goodbye! Thanks for tuning in!" << std::endl;
                break;
            }
        }
    }
}

void Game::Fight(){
    const auto ET = new Team<Enemy*>;
    std::vector<Playable*> AuxTeam;
    AuxTeam.assign(this->GetTeam().GetTeam().begin(), this->GetTeam().GetTeam().end());
    for (int i = 0; i < 3; i++) {
        switch (rand() % 3) {
            case 0: {
                const auto EC = new GoblinCreator;
                ET->SetMember(i, EC->FactoryMethod());
                EC->ConfirmCreation();
                delete EC;
                break;
            }
            case 1: {
                const auto OC = new OgreCreator;
                ET->SetMember(i, OC->FactoryMethod());
                OC->ConfirmCreation();
                delete OC;
                break;
            }
            default: {
                const auto BC = new BeastCreator;
                ET->SetMember(i, BC->FactoryMethod());
                delete BC;
                break;
            }
        }
    }
    int turn = 0;
    int fleeing = false;
    while (!AuxTeam.empty() && !ET->GetTeam().empty() && !fleeing) {
        std::vector<Entity*> OrderOfAttack;
        for (const auto& ally : AuxTeam)
            OrderOfAttack.push_back(ally);
        for (const auto& enemy : ET->GetTeam())
            OrderOfAttack.push_back(enemy);
        std::ranges::sort(OrderOfAttack, [](const Entity* a, const Entity* b) {
                                                                            return a->GetSpeed() > b->GetSpeed();
                                                                            });
        std::cout << "Turn " << ++turn << ". Order of attack:" << std::endl;
        for (auto*& ent : OrderOfAttack)
            std::cout << ent->GetName() << " " << ent->GetHPCurrent() << "/" << ent->GetHPMAX() << std::endl;
        std::cout << std::endl;
        for (auto& ent: OrderOfAttack) {
            if (fleeing)
                break;
            if (ent->GetAlive()) {
                std::cout << std::endl;
                bool TurnOver = false;
                while (!TurnOver) {
                    if (auto itAlly =
                    std::ranges::find(AuxTeam, ent); itAlly < AuxTeam.end()) {
                        std::cout << "What will " << ent->GetName() << " do?" << std::endl;
                        std::cout << "1. Attack an Enemy" << std::endl << "2. Use a consumable" << std::endl << "3. Flee" << std::endl << "> ";
                        int resp1;
                        std::cin >> resp1;
                        if (std::cin) {
                            if (resp1 == 1) {
                                std::cout << "Which enemy?" << std::endl;
                                int resp2 = 0;
                                for (auto* const& enemy : ET->GetTeam())
                                    std::cout << ++resp2 << ". " << enemy->GetName() << std::endl;
                                std::cout << "> ";
                                std::cin >> resp1;
                                if (std::cin) {
                                    const auto& enemy = ET->GetTeam()[resp1 - 1];
                                    const int ActualDMG = static_cast<int>(50.0 * ent->GetAD() / (enemy->GetDEF() + 50.0));
                                    enemy->SetHPCurrent(enemy->GetHPCurrent() - ActualDMG);
                                    std::cout << enemy->GetName() << " lost " << ActualDMG << "HP!" << std::endl;
                                    if (enemy->GetHPCurrent() <= 0) {
                                        std::cout << ent->GetName() << " has slain " << enemy->GetName() << "!" << std::endl
                                            << "They have gained " << enemy->GetXP() << " XP and " << enemy->GetGold() << " Gold." << std::endl;
                                        ent->SetGold(ent->GetGold() + enemy->GetGold());
                                        ent->SetXP(ent->GetXP() + enemy->GetXP());
                                        enemy->Kill();
                                        ET->GetTeam().erase(std::find(ET->GetTeam().begin(), ET->GetTeam().end(), enemy));
                                    }
                                }
                                else {
                                    std::cout << ent->GetName() << " chose to attack themselves. Damn... They lost 5 HP!" << std::endl;
                                    ent->SetHPCurrent(ent->GetHPCurrent() - 5);
                                }
                                TurnOver = true;
                            }
                            else if (resp1 == 2) {
                                if (dynamic_cast<Playable*>(ent)->GetInventory().empty())
                                    std::cout << ent->GetName() << " has no items!" << std::endl;
                                else
                                    TurnOver = true, dynamic_cast<Playable*>(ent)->CheckInventory();
                            }
                            else {fleeing = true; break;}
                        }
                        else {
                            TurnOver = true;
                            std::cout << ent->GetName() << " had a little stroke. They did nothing and also lost 5 HP." << std::endl;
                            ent->SetHPCurrent(ent->GetHPCurrent() - 5);
                        }
                    }
                    else {
                        TurnOver = true;
                        if (AuxTeam.empty())
                            break;
                        Entity* enemy = AuxTeam.at(rand() % AuxTeam.size());
                        const int ActualDMG = static_cast<int>(50.0 * ent->GetAD() / (enemy->GetDEF() + 50.0));
                        enemy->SetHPCurrent(enemy->GetHPCurrent() - ActualDMG);
                        std::cout << ent->GetName() << " attacked " << enemy->GetName() << " and they lost " << ActualDMG << "HP!" << std::endl;
                        if (enemy->GetHPCurrent() <= 0) {
                            std::cout << enemy->GetName() << " has passed away..." << std::endl;
                            enemy->Kill();
                            AuxTeam.erase(std::find(AuxTeam.begin(), AuxTeam.end(), enemy));
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    if (!AuxTeam.empty()) {
        if (!ET->GetTeam().empty())
            std::cout << "Your team ran away." << std::endl;
        else
            std::cout << "YOUR TEAM WON!!!" << std::endl;
        for (auto*& OrigTM : this->GetTeam().GetTeam()) {
            OrigTM->Revive(), OrigTM->SetHPCurrent(std::max(OrigTM->GetHPCurrent(), 1));
            for (auto*& CopyTM : AuxTeam)
                if (CopyTM->GetName() == OrigTM->GetName())
                    OrigTM->SetGold(CopyTM->GetGold()), OrigTM->SetXP(CopyTM->GetXP());
        }
    }
    else
        std::cout << "Your team lost..." << std::endl;
    std::cout << std::endl;
    delete ET;
}

void Game::TeamEditor() {
    std::cout << "This is your current team:" << std::endl;
    unsigned long i = 0;
    for (; i <= 2; i++)
        std::cout << i + 1 << ". " << PlayerTeam.GetMember(static_cast<int>(i))->GetName() << std::endl;
    bool changed = false;
    bool NavigatingMenu = true;
    while (NavigatingMenu) {
        std::cout << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Show my team" << std::endl;
        std::cout << "2. Check a teammate's stats and inventory" << std::endl;
        std::cout << "3. Change a teammate with another \"Playable\"" << std::endl;
        std::cout << "4. Change a teammate's weapon" << std::endl;
        std::cout << "5. Change a teammate's armor" << std::endl;
        std::cout << "6. Nothing." << std::endl;
        std::cout << "Please enter a number between 1 and 6." << std::endl << "> ";
        std::cin >> i;
        if (std::cin && i >= 1 && i <= 6) {
            switch (i) {
                case 1: {
                    unsigned long i1 = 0;
                    for (const auto* tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    break;
                }
                case 2: {
                    unsigned long i1 = 0;
                    for (const auto* tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i3 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i3;
                    i3--;
                    if (i3 == 0 || i3 == 1 || i3 == 2) {
                        std::cout << *this->GetTeam().GetMember(static_cast<int>(i3));
                        if (this->GetTeam().GetMember(static_cast<int>(i3))->GetInventory().empty())
                            std::cout << "Empty inventory." << std::endl;
                        else {
                            std::cout << "Inventory:" << std::endl;
                            unsigned long j3 = 0;
                            for (Item* cons: this->GetTeam().GetMember(static_cast<int>(i3))->GetInventory())
                                std::cout << ++j3 << ". " << cons->GetName() << std::endl;
                        }
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 3: {
                    unsigned long i1 = 0;
                    for (const auto* tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i2 = 0;
                    std::cout << "Which teammate would you like to change? Pick a number between 1 and 3.\n> ";
                    std::cin >> i2;
                    i2--;
                    if (i2 == 0 || i2 == 1 || i2 == 2) {
                        unsigned long k = 0;
                        std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans};
                        for (auto* &pl: AllPlayables)
                            std::cout << ++k << ". " << pl->GetName() << std::endl;
                        std::cout << "With what playable would you like to change " << PlayerTeam.GetMember(static_cast<int>(i2))->GetName() << "? Pick a number between 1 and " << AllPlayables.size() << "." << std::endl;
                        do {
                            if (!std::cin) std::cin.clear();
                            std::cout << "> ";
                            std::cin >> k;
                        }while (!std::cin || k > AllPlayables.size());
                        PlayerTeam.ChangeMember(static_cast<int>(i2) + 1, static_cast<int>(k));
                        changed = true;
                        std::cout << "Teammate nr. " << static_cast<int>(i2) + 1 << " replaced with " << AllPlayables[k - 1]->GetName() << "." << std::endl;
                        delete &AllPlayables;
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 4: {
                    unsigned long i1 = 0;
                    for (const auto* tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i4 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i4;
                    i4--;
                    if (i4 == 0 || i4 == 1 || i4 == 2) {
                        std::cout << "Which weapon would you like to choose?" << std::endl;
                        unsigned long j = 0;
                        std::vector<Weapon*> AllWeapons = {new Plate, new Cigarette, new FlipPhone};
                        for (auto* w : AllWeapons) {
                            std::cout << ++j << ". " << w->GetName();
                            if (strcmp(w->GetName(), "Fists") == 0) std::cout << "(~unequip)";
                            std::cout << ", ";
                            if (w->GetPlusAD() - PlayerTeam.GetMember(static_cast<int>(i4))->GetWeapon()->GetPlusAD() >= 0)
                                std::cout << "+";
                            std::cout << w->GetPlusAD() - PlayerTeam.GetMember(static_cast<int>(i4))->GetWeapon()->GetPlusAD() << " AD" << std::endl;
                        }
                        std::cout << "Pick a number between 1 and " << AllWeapons.size() << ".\n> ";
                        unsigned long k = 0;
                        std::cin >> k;
                        k--;
                        if (std::cin && k < AllWeapons.size()) {
                            PlayerTeam.SetMember(static_cast<int>(i4), &PlayerTeam.GetMember(static_cast<int>(i4))->ChangeWeapon(*AllWeapons[k]));
                        }
                        delete &AllWeapons;
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 5: {
                    unsigned long i1 = 0;
                    for (const auto* tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i5 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i5;
                    i5--;
                    if (i5 == 0 || i5 == 1 || i5 == 2) {
                        std::cout << "Which armor would you like to choose?" << std::endl;
                        unsigned long j = 0;
                        std::vector<Armor*> AllArmors = {new SoulJacket(), new LanaTShirt()};
                        for (auto* w : AllArmors) {
                            std::cout << ++j << ". " << w->GetName();
                            if (strcmp(w->GetName(), "Skin") == 0) std::cout << "(a.k.a. unequip)" << std::endl;
                            std::cout << ", ";
                            if (w->GetPlusHP() - PlayerTeam.GetMember(static_cast<int>(i5))->GetArmor()->GetPlusHP() >= 0)
                                std::cout << "+";
                            std::cout << w->GetPlusHP() - PlayerTeam.GetMember(static_cast<int>(i5))->GetArmor()->GetPlusHP() << " MaxHP, ";
                            if (w->GetPlusDef() - PlayerTeam.GetMember(static_cast<int>(i5))->GetArmor()->GetPlusDef() >= 0)
                                std::cout << "+";
                            std::cout << w->GetPlusDef() - PlayerTeam.GetMember(static_cast<int>(i5))->GetArmor()->GetPlusDef() << " DEF" << std::endl;
                        }
                        std::cout << "Pick a number between 1 and " << AllArmors.size() << ".\n> ";
                        unsigned long k = 0;
                        std::cin >> k;
                        k--;
                        if (std::cin && k < AllArmors.size()) {
                            PlayerTeam.SetMember(static_cast<int>(i5), &PlayerTeam.GetMember(static_cast<int>(i5))->ChangeArmor(*AllArmors[k]));
                        }
                        delete &AllArmors;
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 6: {
                    std::cout << "Okay. Byeee!" << std::endl;
                    NavigatingMenu = false;
                    break;
                }
                default: {
                    std::cout << "Invalid input. Choose again.\n> ";
                    std::cin.clear();
                    break;
                }
            }
        }
        else
            do {
                std::cin.clear();
                std::cout << "Invalid input. Choose again.\n> ";
                std::cin >> i;
            } while (!std::cin || i > 6);
    }
    if (changed) {
        std::cout << "Your final team is:" << std::endl;
        unsigned long ig = 0;
        for (const auto* pl : PlayerTeam.GetTeam()) {
            std::cout << ++ig << ". " << pl->GetName() << std::endl;
        }
    }
}

void Game::ShowPlayables() {
    unsigned long k = 0;
    for (const std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans}; const auto pl: AllPlayables)
        std::cout << ++k << ". " << *pl << std::endl;
}

void Game::ShowWeaponsArmors() {
    std::cout << "Weapons:" << std::endl;
    unsigned long j = 0;
    for (std::vector<Weapon*> AllWeapons = {new Plate, new Cigarette, new FlipPhone}; Weapon *&w : AllWeapons) {
        std::cout << ++j << ". " << w;
    }
    std::cout << std::endl << "Armors:" << std::endl;
    j = 0;
    for (std::vector<Armor*> AllArmors = {new SoulJacket, new LanaTShirt}; Armor *&a : AllArmors) {
        std::cout << ++j << ". " << a;
    }
    std::cout << std::endl;
}


void Game::Shop() {
    std::vector<std::pair<Consumable*, int>> AllConsumables = {{new McPuisor, 2}, {new Apple, 1}, {new Vodka, 10}, {new PlateOfSpaghetti, 15}};
    std::cout << "The Shop(TM) has " << AllConsumables.size() << " consumables:" << std::endl;
    unsigned long k = 0;
    for (auto &[cons, cost]: AllConsumables) {
        std::cout << ++k << ". " << cons->GetName() << " - " << cost << " Gold" << std::endl;
    }
    std::cout << "Who are you buying for?" << std::endl;
    unsigned long i = 0;
    for (; i <= 2; i++)
        std::cout << i + 1 << ". " << PlayerTeam.GetMember(static_cast<int>(i))->GetName() << std::endl;
    std::cout << "Pick a number between 1 and 3.\n> ";
    std::cin >> i;
    i--;
    if (i == 0 || i == 1 || i == 2) {
        std::cout << "Which consumable would you like to buy? Pick a number between 1 and " << AllConsumables.size() << ".\n> ";
        bool shopping = true;
        do {
            unsigned long j = 0;
            std::cin >> j;
            j--;
            if (std::cin && j < AllConsumables.size())
            {
                if (PlayerTeam.GetMember(static_cast<int>(i))->GetGold() >= AllConsumables[j].second)
                {
                    auto AuxTeam = PlayerTeam.GetTeam();
                    AuxTeam[i]->AddConsumableToInventory(*AllConsumables[j].first);
                    AuxTeam[i]->SetGold(AuxTeam[i]->GetGold() - AllConsumables[j].second);
                    PlayerTeam.SetTeam(AuxTeam);
                    std::cout << PlayerTeam.GetMember(static_cast<int>(i))->GetName() << " bought " << AllConsumables[j].first->GetName() << "." << std::endl;
                }
                else
                    std::cout << PlayerTeam.GetMember(static_cast<int>(i))->GetName() << " has only " << PlayerTeam.GetMember(static_cast<int>(i))->GetGold() << " Gold, which isn't enough." << std::endl;
            }else {
                std::cout << "Sir, please, buy from inside the shop." << std::endl;
            }
            std::cout << "Would you like to keep shopping?\n[Y/N] ";
            std::string response;
            std::cin >> response;
            switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
                case 'y': {std::cout << "Which consumable would you like to buy?\n> "; break;}
                case 'n': {shopping = false; break;}
                default: {std::cout << "We'll take that as a \"No\".\n", shopping = false; break;}
            }
        }while (shopping);
        std::cout << "Bye-bye!" << std::endl;
    }
    else
        std::cout << "Player id out of bounds. Exiting shop... :(" << std::endl;
    delete &AllConsumables;
}