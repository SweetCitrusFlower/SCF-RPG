#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
protected:
    const char *Name = nullptr;
    const char *Description = nullptr;

public:
    explicit Item(const char* name, const char* description = "") : Name(name), Description(description) {}
    Item(): Item("") {}
    virtual ~Item() = default;

    [[nodiscard]] const char*& GetName() {return Name;}
    [[nodiscard]] const char*& GetDescription() {return Description;}

};

#endif //ITEM_H

inline std::ostream& operator<<(std::ostream &c, Item* I){
    c << I->GetName() << std::endl << I->GetDescription() << std::endl;
    return c;
}