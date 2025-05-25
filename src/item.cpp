#pragma once

#include "../include/item.h"

Item::Item(const char* name, const char* description = "") : Name(name), Description(description) {}

Item::Item() : Item("") {}

Item::Item(const Item &E) = default;

Item::Item(Item &&E) noexcept : Name(E.Name), Description(E.Description) {}

Item& Item::operator=(const Item &E){
    if(this == &E)
        return *this;
    Name = E.Name;
    Description = E.Description;
    return *this;
}
Item& Item::operator=(Item &&E) noexcept{
   if(this == &E)
       return *this;
   Name = E.Name;
   Description = E.Description;
   return *this;
}

std::ostream& operator<<(std::ostream &c, Item& I){
    c << std::endl << I.GetName() << std::endl << I.GetDescription() << std::endl;
    return c;
}