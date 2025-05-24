#include "../include/consumable.h"
#include "item.cpp"

Consumable::Consumable(const char* name, const int plusHP = 0, const char* desc = "")
    : Item(name, desc) , PlusHP(plusHP) {}

Consumable::Consumable() : Consumable("") {}

std::ostream& operator<<(std::ostream& c, const Consumable& C){
    c << static_cast<Item>(C) << "HP: ";
    if(C.GetPlusHP() < 0) c << "-" << -C.GetPlusHP();
    else if(C.GetPlusHP() == 0) c << "0";
    else c << "+" << C.GetPlusHP();
    c << std::endl;
    return c;
}

inline auto McPuisor = Consumable("McPuisor", -40, "This item makes you a bit fatter.");
inline auto Apple = Consumable("Apple", 5, "Keeps the doctors away!");
inline auto Vodka = Consumable("Vodka", 300, "Russian wisdom cyka blyat");
inline auto PlateOfSpaghetti = Consumable("Plate of spaghetti", 300, "To forgetti your regretti.");
inline std::vector<std::pair<Consumable, int>> AllConsumables = {{McPuisor, 2}, {Apple, 1}, {Vodka, 10}, {PlateOfSpaghetti, 15}};

