#include "../../include/game.h"

Game* Game::GameInstancePointer = nullptr;

int main() {
    const auto game = Game::GetInstance();
    game->ReceiveAction();
    delete game;
    return 0;
}
