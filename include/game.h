#pragma once

#ifndef GAME_H
#define GAME_H

#include "../src/team.cpp"

class Game {
protected:
    static Game* GameInstancePointer;
    Game() {}
    Team<Playable> PlayerTeam = Team(Weakling, Weakling, Weakling);

    void Fight();
    void TeamEditor();
    static void ShowPlayables();
    void Shop();

public:

    [[nodiscard]] Team<Playable>& GetTeam() {return PlayerTeam;}
    Team<Playable>& SetTeam(const Team<Playable> &TEAM) {PlayerTeam = TEAM; return PlayerTeam;}

    Game(const Game&) = delete;
    static Game* GetInstance(){
        if(GameInstancePointer == nullptr)
            GameInstancePointer = new Game();
        return GameInstancePointer;
    };
    void ReceiveAction();
};

#endif //GAME_H
