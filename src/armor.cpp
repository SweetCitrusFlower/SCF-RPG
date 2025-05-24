#include "../include/armor.h"
#include "item.cpp"

Armor::Armor(const char* name, const int plusDef = 0, const int plusHP = 0, const char* description = nullptr)
    : Item(name, description), PlusDef(plusDef), PlusHP(plusHP) {}

Armor::Armor() : Armor("No Armor") {}

std::ostream& operator<<(std::ostream &c, const Armor& A){
    c << static_cast<Item>(A) << "DEF: ";
    if(A.GetPlusDef() < 0) c << "-" << -A.GetPlusDef();
    else if(A.GetPlusDef() == 0) c << "0";
    else c << "+" << A.GetPlusDef();

    c << std::endl << "HPMax: ";
    if(A.GetPlusHP() < 0) c << "-" << -A.GetPlusHP();
    else if(A.GetPlusHP() == 0) c << "0";
    else c << "+" << A.GetPlusHP();
    c << std::endl;

    return c;
}

inline auto Skin = Armor("Skin", 0, 1, "You're naked. Gross.");
inline auto SoulJacket = Armor("Soul Jacket", 200, 300, "The ultimate sacrifice: to live with your heart on your sleeve.");
inline auto LanaTShirt = Armor("Lana del Rey T-Shirt", 20, 500, "Given with love. Kinda want it back tho ngl");
inline std::vector AllArmors = {SoulJacket, LanaTShirt};
