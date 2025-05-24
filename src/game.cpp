#include "../include/game.h"
#include <cstring>

void Game::ReceiveAction(){
    std::cout << "Welcome to SCF RPG! Select an option:\n";
    int x = 0;
    while (true) {
        std::cout << std::endl;
        std::cout << "1. Fight against a team of random enemies\n";
        std::cout << "2. Assemble your team\n";
        std::cout << "3. See your Playable characters\n";
        std::cout << "4. Shop for consumables\n";
        std::cout << "5. Exit\n> ";
        std::cin >> x;
        if (std::cin && x >= 1 && x <= 5)
        {
            std::cout << std::endl;
            switch (x) {
                case 1: Fight(); break;
                case 2: TeamAssembler(); break;
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
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Choose again.\n> ";
                std::cin >> x;
            } while (!std::cin || x < 1 || x > 5);
            std::cout << std::endl;
            switch (x) {
                case 1: Fight(); break;
                case 2: TeamAssembler(); break;
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

void Game::TeamAssembler() {
    std::cout << "This is your team:" << std::endl;
    for (int i = 0; i <= 2; i++)
        std::cout << i + 1 << ". " << PlayerTeam.GetMember(i).GetName() << std::endl;
    std::cout << "Would you like to change a teammate?\n[Y/N] ";
    bool changing = true;
    bool changed = false;
    while (changing) {
        std::string response;
        std::cin >> response;
        switch (static_cast<char>(std::strlen(response.c_str()) != 1) ? '0' : tolower(response[0])) {
            case 'y': {
                int i = 0;
                for (; i <= 2 && changed; i++)
                    std::cout << i + 1 << ". " << PlayerTeam.GetMember(i).GetName() << std::endl;
                std::cout << "Which teammate would you like to change? Pick a number between 1 and 3.\n> ";
                std::cin >> i;
                i--;
                if (i == 0 || i == 1 || i == 2) {
                    int k = 0;
                    for (auto &pl: AllPlayables)
                        std::cout << ++k << ". " << pl.GetName() << std::endl;
                    std::cout << "With what playable would you like to change " << PlayerTeam.GetMember(i).GetName() << "? Pick a number between 1 and " << AllPlayables.size() << ".\n> ";
                    do {
                        std::cin >> k;
                    }while (k <= 0 || k > AllPlayables.size());
                    PlayerTeam.ChangeMember(i + 1, k);
                    std::cout << "Teammate nr. " << i + 1 << " has been replaced with " << AllPlayables[k - 1].GetName() << "." << std::endl;
                    changed = true;
                    std::cout << "Would you like to change another teammate?\n[Y/N] ";
                    break;
                }
                std::cout << "Number out of bounds." << std::endl;
            }
            case 'n': {
                std::cout << "No teammate changed." << std::endl;
                changing = false;
                break;
            }
            default: {
                std::cout << "Invalid input. Choose again.\n> ";
                std::cin.clear();
            }
        }
    }
    if (changed) {
        std::cout << "Your final team is:" << std::endl;
        int i = 0;
        for (const auto& pl : PlayerTeam.GetTeam()) {
            std::cout << ++i << ". " << pl.GetName() << std::endl;
        }
    }
}

void Game::ShowPlayables() {
    int k = 0;
    for (auto &pl: AllPlayables)
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
