#include "include/game.h"

Game* Game::GameInstancePointer = nullptr;

int main() {
    Game::GetInstance()->ReceiveAction();
    return 0;
}