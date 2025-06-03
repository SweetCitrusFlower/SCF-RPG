#pragma once

#include "team.h"

#ifndef GAME_H
#define GAME_H

class Game {
    static Game* GameInstancePointer;
    Game() = default;
    Team<Playable> PlayerTeam = {static_cast<Playable>(GOD()), static_cast<Playable>(GOD()), static_cast<Playable>(GOD())};

    void Fight();
    void TeamEditor();
    void ShowPlayables() const;
    void ShowWeaponsArmors() const;
    void Shop();

    std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans, new GOD};
    std::vector<Weapon*> AllWeapons = {new Plate, new Cigarette, new FlipPhone};
    std::vector<Armor*> AllArmors = {new SoulJacket, new LanaTShirt};
    std::vector<std::pair<Consumable*, int>*> AllConsumables = {new std::pair<Consumable*, int>(new McPuisor, 2), new std::pair<Consumable*, int>(new Apple, 1),
                                                                new std::pair<Consumable*, int>(new Vodka, 10), new std::pair<Consumable*, int>(new PlateOfSpaghetti, 15)};

public:

    [[nodiscard]] Team<Playable>& GetTeam() {return PlayerTeam;}
    Team<Playable>& SetTeam(const Team<Playable> &TEAM) {PlayerTeam = TEAM; return PlayerTeam;}

    Game(const Game&) = delete;
    static Game* GetInstance(){
        if(GameInstancePointer == nullptr)
            GameInstancePointer = new Game();
        return GameInstancePointer;
    }

    ~Game() = default;

    void ReceiveAction();
};

#endif //GAME_H