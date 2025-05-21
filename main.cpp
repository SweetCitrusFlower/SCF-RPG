#include <iostream>

#include "src/playable.cpp"
#include "src/enemy.cpp"
#include "src/consumable.cpp"
#include "src/weapon.cpp"
#include "src/armor.cpp"
#include "src/team.cpp"

int main() {

    auto Alex = Playable("Alex", 10, 3, 4, 5, 66, 7, "He's so cool", &Cigarette, &LanaTShirt, {McPuisor, McPuisor, Apple});
    auto Echipa = Team(Alex, Playable("Mera"), Playable("huh"));

    auto Gremlin = Enemy("GREMLIN");
    const auto Gremlin2 = Gremlin;
    const auto Gremlin3 = Gremlin;
    auto EchipaInamica = Team(Gremlin, Gremlin2, Gremlin3);
    Echipa.ShowTeam();
    EchipaInamica.ShowTeam();

    Alex.CheckInventory();
    return 0;
}
