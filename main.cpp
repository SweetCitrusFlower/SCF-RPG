#include <iostream>
#include <vector>

#include "src/playable.cpp"
#include "src/enemy.cpp"

int main() {

    auto Mera = Playable(11, 2, 5, 300, 0, "Mera", "hello my name is email", nullptr, nullptr, {});
    Mera.ChangeWeapon(Weapon("Broken Phone", 20, "Single use. But you keep using it."));

    Mera.AddItemToInventory(Weapon("Broken Phone", 20, "Single use. But you keep using it."));

    std::vector<const Playable&> Team = {Mera, Playable(), Mera};
    for (const auto& Player:Team)
        std::cout << Player << std::endl;
    return 0;
}
