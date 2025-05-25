#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

class Item {
protected:
    const char *Name = nullptr;
    const char *Description = nullptr;

public:

    Item(const char*, const char*);
    Item();
    virtual ~Item() = default;

    [[nodiscard]] const char*& GetName() {return Name;}
    [[nodiscard]] const char*& GetDescription() {return Description;}

};

#endif //ITEM_H