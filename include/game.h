#pragma once

#include "team.h"

#ifndef GAME_H
#define GAME_H

class Game {
protected:
    static Game* GameInstancePointer;
    Game() = default;
    Team<Playable*> PlayerTeam = Team<Playable*>(new Mera, new Dragos, new sans);

    void Fight();
    void TeamEditor();
    static void ShowPlayables();
    static void ShowWeaponsArmors();
    void Shop();

public:

    [[nodiscard]] Team<Playable*>& GetTeam() {return PlayerTeam;}
    Team<Playable*>& SetTeam(const Team<Playable*> &TEAM) {PlayerTeam = TEAM; return PlayerTeam;}

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
