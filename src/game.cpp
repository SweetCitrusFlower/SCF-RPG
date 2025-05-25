#include "../include/game.h"
#include <cstring>

void Game::ReceiveAction(){
    std::cout << "Welcome to SCF RPG! Select an option:\n";
    int x = 0;
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
            } while (!std::cin || x < 1 || x > 5);
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
    auto CurrTeam = PlayerTeam;

}

void Game::TeamEditor() {
    std::cout << "This is your current team:" << std::endl;
    int i = 0;
    for (; i <= 2; i++)
        std::cout << i + 1 << ". " << PlayerTeam.GetMember(i).GetName() << std::endl;
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
                    int i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm.GetName() << std::endl;
                    break;
                }
                case 2: {
                    int i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm.GetName() << std::endl;
                    int i2 = 0;
                    std::cout << "Which teammate would you like to change? Pick a number between 1 and 3.\n> ";
                    std::cin >> i2;
                    i2--;
                    if (i2 == 0 || i2 == 1 || i2 == 2) {
                        int k = 0;
                        for (auto &pl: AllPlayables)
                            std::cout << ++k << ". " << pl.GetName() << std::endl;
                        std::cout << "With what playable would you like to change " << PlayerTeam.GetMember(i).GetName() << "? Pick a number between 1 and " << AllPlayables.size() << "." << std::endl;
                        do {
                            if (!std::cin) std::cin.clear();
                            std::cout << "> ";
                            std::cin >> k;
                        }while (!std::cin || k <= 0 || k > AllPlayables.size());
                        PlayerTeam.ChangeMember(i2 + 1, k);
                        changed = true;
                        std::cout << "Teammate nr. " << i2 + 1 << " replaced with " << AllPlayables[k - 1].GetName() << "." << std::endl;
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 3: {
                    int i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm.GetName() << std::endl;
                    int i3 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i3;
                    i3--;
                    if (i3 == 0 || i3 == 1 || i3 == 2) {
                        std::cout << this->GetTeam().GetMember(i3);
                        if (this->GetTeam().GetMember(i3).GetInventory().empty())
                            std::cout << "Empty inventory." << std::endl;
                        else {
                            std::cout << "Inventory:" << std::endl;
                            int j3 = 0;
                            for (const auto& cons: this->GetTeam().GetMember(i3).GetInventory())
                                std::cout << ++j3 << ". " << cons.GetName() << std::endl;
                        }
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 4: {
                    int i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm.GetName() << std::endl;
                    int i4 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i4;
                    i4--;
                    if (i4 == 0 || i4 == 1 || i4 == 2) {
                        std::cout << "Which weapon would you like to choose?" << std::endl;
                        int j = 0;
                        for (const auto& w : AllWeapons) {
                            std::cout << ++j << ". " << w.GetName();
                            if (w.GetName() == "Fists") std::cout << "(~unequip)";
                            std::cout << ", ";
                            if (w.GetPlusAD() - PlayerTeam.GetMember(i4).GetWeapon()->GetPlusAD() >= 0)
                                std::cout << "+";
                            std::cout << w.GetPlusAD() - PlayerTeam.GetMember(i4).GetWeapon()->GetPlusAD() << " AD" << std::endl;
                        }
                        std::cout << "Pick a number between 1 and " << AllWeapons.size() << ".\n> ";
                        int k = 0;
                        std::cin >> k;
                        k--;
                        if (std::cin && k >= 0 && k < AllWeapons.size()) {
                            auto& AuxMemb = PlayerTeam.GetMember(i4);
                            AuxMemb.ChangeWeapon(AllWeapons[k]);
                            PlayerTeam.SetMember(i4, AuxMemb);
                        }
                        break;
                    }
                    std::cout << "invalid input." << std::endl;
                    break;
                }
                case 5: {
                    int i1 = 0;
                    for (const auto& tm : this->GetTeam().GetTeam())
                        std::cout << ++i1 << ". " << tm.GetName() << std::endl;
                    int i5 = 0;
                    std::cout << "Pick a number between 1 and 3.\n> ";
                    std::cin >> i5;
                    i5--;
                    if (i5 == 0 || i5 == 1 || i5 == 2) {
                        std::cout << "Which armor would you like to choose?" << std::endl;
                        int j = 0;
                        for (const auto& w : AllArmors) {
                            std::cout << ++j << ". " << w.GetName();
                            if (w.GetName() == "Skin") std::cout << "(a.k.a. unequip)" << std::endl;
                            std::cout << ", ";
                            if (w.GetPlusHP() - PlayerTeam.GetMember(i5).GetArmor()->GetPlusHP() >= 0)
                                std::cout << "+";
                            std::cout << w.GetPlusHP() - PlayerTeam.GetMember(i5).GetArmor()->GetPlusHP() << " MaxHP, ";
                            if (w.GetPlusDef() - PlayerTeam.GetMember(i5).GetArmor()->GetPlusDef() >= 0)
                                std::cout << "+";
                            std::cout << w.GetPlusDef() - PlayerTeam.GetMember(i5).GetArmor()->GetPlusDef() << " DEF" << std::endl;
                        }
                        std::cout << "Pick a number between 1 and " << AllArmors.size() << ".\n> ";
                        int k = 0;
                        std::cin >> k;
                        k--;
                        if (std::cin && k >= 0 && k < AllArmors.size()) {
                            auto& AuxMemb = PlayerTeam.GetMember(i5).ChangeArmor(AllArmors[k]);
                            PlayerTeam.SetMember(i5, AuxMemb);
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
            } while (!std::cin || i < 1 || i > 6);
    }
    if (changed) {
        std::cout << "Your final team is:" << std::endl;
        int ig = 0;
        for (const auto& pl : PlayerTeam.GetTeam()) {
            std::cout << ++ig << ". " << pl.GetName() << std::endl;
        }
    }
}

void Game::ShowPlayables() {
    int k = 0;
    for (const auto &pl: AllPlayables)
        std::cout << ++k << ". " << pl << std::endl;
}

void Game::Shop() {
    std::cout << "The Shop(TM) has " << AllConsumables.size() << " consumables:" << std::endl;
    int k = 0;
    for (auto &[cons, cost]: AllConsumables) {
        std::cout << ++k << ". " << cons.GetName() << " - " << cost << " Gold" << std::endl;
    }
    std::cout << "Who are you buying for?" << std::endl;
    int i = 0;
    for (; i <= 2; i++)
        std::cout << i + 1 << ". " << PlayerTeam.GetMember(i).GetName() << std::endl;
    std::cout << "Pick a number between 1 and 3.\n> ";
    std::cin >> i;
    i--;
    if (i == 0 || i == 1 || i == 2) {
        std::cout << "Which consumable would you like to buy? Pick a number between 1 and " << AllConsumables.size() << ".\n> ";
        bool shopping = true;
        do {
            int j = 0;
            std::cin >> j;
            j--;
            if (j >= 0 && j < AllConsumables.size())
            {
                if (PlayerTeam.GetMember(i).GetGold() >= AllConsumables[j].second)
                {
                    auto AuxTeam = PlayerTeam.GetTeam();
                    AuxTeam[i].AddConsumableToInventory(AllConsumables[j].first);
                    AuxTeam[i].SetGold(AuxTeam[i].GetGold() - AllConsumables[j].second);
                    PlayerTeam.SetTeam(AuxTeam);
                    std::cout << PlayerTeam.GetMember(i).GetName() << " bought " << AllConsumables[j].first.GetName() << "." << std::endl;
                }
                else
                    std::cout << PlayerTeam.GetMember(i).GetName() << " has only " << PlayerTeam.GetMember(i).GetGold() << " Gold, which isn't enough." << std::endl;
            }else {
                std::cout << "Sir, please, buy from inside the shop." << std::endl;
            }
            std::cout << "Would you like to keep shopping?\n[Y/N] ";
            std::string response;
            std::cin >> response;
            switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
                case 'y': {std::cout << "Which consumable would you like to buy?\n> "; break;}
                default: std::cout << "We'll take that as a \"No\".\n";
                case 'n': {shopping = false; break;}
            }
        }while (shopping);
        std::cout << "Bye-bye!" << std::endl;
    }
    else
        std::cout << "Player id out of bounds. Exiting shop... :(" << std::endl;
}
