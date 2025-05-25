#include "../include/game.h"
#include <cstring>

void Game::ReceiveAction(){
    std::cout << "Welcome to SCF RPG! Select an option:\n";
    unsigned long x = 0;
    while (true) {
        std::cout << std::endl;
        std::cout << "1. Fight against a team of random enemies\n";
        std::cout << "2. Edit your team\n";
        std::cout << "3. See your \"Playable\" characters\n";
        std::cout << "4. Shop for consumables\n";
        std::cout << "5. Exit\n> ";
        std::cin >> x;
        if (std::cin && x >= 1 && x <= 5)
        {
            std::cout << std::endl;
            switch (x) {
                case 1: Fight(); break;
                case 2: TeamEditor(); break;
                case 3: ShowPlayables(); break;
                case 4: Shop(); break;
                default: break;
            }
            if (x == 5) {
                std::cout << "Goodbye!";
                break;
            }
        }
        else {
            do {
                std::cin.clear();
                std::cout << "Invalid input. Choose again.\n> ";
                std::cin >> x;
            } while (!std::cin || x > 5);
            std::cout << std::endl;
            switch (x) {
                case 1: Fight(); break;
                case 2: TeamEditor(); break;
                case 3: ShowPlayables(); break;
                case 4: Shop(); break;
                default: break;
            }
            if (x == 5) {
                std::cout << "Goodbye!";
                break;
            }
        }
    }
}

void Game::Fight() {
    auto ET = new Team<Enemy*>;
    for (int i = 0; i < 3; i++) {
        switch (std::rand() % 3) {
            case 0: {
                const auto EC = new GoblinCreator;
                ET->SetMember(i, EC->FactoryMethod());
                delete EC;
                break;
            }
            case 1: {
                const auto OC = new OgreCreator;
                ET->SetMember(i, OC->FactoryMethod());
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
    auto a0 = dynamic_cast<Entity*>(this->GetTeam().GetMember(0));
    auto a1 = dynamic_cast<Entity*>(this->GetTeam().GetMember(1));
    auto a2 = dynamic_cast<Entity*>(this->GetTeam().GetMember(2));
    auto e0 = dynamic_cast<Entity*>(ET->GetMember(0));
    auto e1 = dynamic_cast<Entity*>(ET->GetMember(1));
    auto e2 = dynamic_cast<Entity*>(ET->GetMember(2));
    int i = 0;
    while (!this->GetTeam().GetTeam().empty() && !ET->GetTeam().empty()) {
        std::vector<Entity*> OrderOfAttack;
        for (const auto& ally : this->GetTeam().GetTeam())
            OrderOfAttack.push_back((ally));
        for (const auto& enemy : ET->GetTeam())
            OrderOfAttack.push_back((enemy));
        std::sort(OrderOfAttack.begin(), OrderOfAttack.end(), [](const Entity* a, const Entity* b) {
                                                                            return a->GetSpeed() > b->GetSpeed();
                                                                            });
        for (const auto& fd : OrderOfAttack)
            std::cout << fd->GetName() << ' ' << fd->GetSpeed() << std::endl;
        const auto slowest = OrderOfAttack[OrderOfAttack.size() - 1];
        const auto itAlly = std::find(this->GetTeam().GetTeam().begin(), this->GetTeam().GetTeam().end(), slowest);
        const auto itEnemy = std::find(ET->GetTeam().begin(), ET->GetTeam().end(), slowest);
        if (itAlly == this->GetTeam().GetTeam().end())
            ET->MemberDeath(dynamic_cast<Enemy*>(slowest));
        else
            this->GetTeam().MemberDeath(dynamic_cast<Playable*>(slowest));
        std::cout << std::endl;
    }
    if (!this->GetTeam().GetTeam().empty()) {
        std::cout << "YOU WON!!!!" << std::endl;
    }
    else
        std::cout << "You lost..." << std::endl;
    delete ET;
    delete a0;
    delete a1;
    delete a2;
    delete e0;
    delete e1;
    delete e2;
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
        std::cout << "2. Change a teammate with another \"Playable\"" << std::endl;
        std::cout << "3. Check a teammate's stats and inventory" << std::endl;
        std::cout << "4. Change a teammate's weapon" << std::endl;
        std::cout << "5. Change a teammate's armor" << std::endl;
        std::cout << "6. Nothing." << std::endl;
        std::cout << "Please enter a number between 1 and 6." << std::endl << "> ";
        std::cin >> i;
        if (std::cin && i >= 1 && i <= 6) {
            switch (i) {
                case 1: {
                    unsigned long i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    break;
                }
                case 2: {
                    unsigned long i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i2 = 0;
                    std::cout << "Which teammate would you like to change? Pick a number between 1 and 3.\n> ";
                    std::cin >> i2;
                    i2--;
                    if (i2 == 0 || i2 == 1 || i2 == 2) {
                        unsigned long k = 0;
                        std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans};
                        for (auto &pl: AllPlayables)
                            std::cout << ++k << ". " << pl->GetName() << std::endl;
                        std::cout << "With what playable would you like to change " << PlayerTeam.GetMember(static_cast<int>(i))->GetName() << "? Pick a number between 1 and " << AllPlayables.size() << "." << std::endl;
                        do {
                            if (!std::cin) std::cin.clear();
                            std::cout << "> ";
                            std::cin >> k;
                        }while (!std::cin || k > AllPlayables.size());
                        PlayerTeam.ChangeMember(static_cast<int>(i2) + 1, static_cast<int>(k));
                        changed = true;
                        std::cout << "Teammate nr. " << static_cast<int>(i2) + 1 << " replaced with " << AllPlayables[k - 1]->GetName() << "." << std::endl;
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 3: {
                    unsigned long i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
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
                            for (const auto& cons: this->GetTeam().GetMember(static_cast<int>(i3))->GetInventory())
                                std::cout << ++j3 << ". " << cons->GetName() << std::endl;
                        }
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 4: {
                    unsigned long i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i4 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i4;
                    i4--;
                    if (i4 == 0 || i4 == 1 || i4 == 2) {
                        std::cout << "Which weapon would you like to choose?" << std::endl;
                        unsigned long j = 0;
                        std::vector<Weapon*> AllWeapons = {new Plate, new Cigarette, new FlipPhone};
                        for (const auto& w : AllWeapons) {
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
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 5: {
                    unsigned long i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm->GetName() << std::endl;
                    unsigned long i5 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i5;
                    i5--;
                    if (i5 == 0 || i5 == 1 || i5 == 2) {
                        std::cout << "Which armor would you like to choose?" << std::endl;
                        unsigned long j = 0;
                        std::vector<Armor*> AllArmors = {new SoulJacket(), new LanaTShirt()};
                        for (const auto& w : AllArmors) {
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
        for (const auto& pl : PlayerTeam.GetTeam()) {
            std::cout << ++ig << ". " << pl->GetName() << std::endl;
        }
    }
}

void Game::ShowPlayables() {
    const std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans};
    unsigned long k = 0;
    for (const auto pl: AllPlayables)
        std::cout << ++k << ". " << *pl << std::endl;
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
}
