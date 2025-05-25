#include "../include/item.h"

Item::Item(const char* name, const char* description = "") : Name(name), Description(description) {}

Item::Item() : Item("") {}

std::ostream& operator<<(std::ostream &c, Item& I){
    c << std::endl << I.GetName() << std::endl << I.GetDescription() << std::endl;
    return c;
}