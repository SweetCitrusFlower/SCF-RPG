#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <cstring>

class Item {
protected:
    const char *Name = nullptr;
    const char *Description = nullptr;

    virtual ~Item() = default;

public:
    explicit Item(const char* name, const char* description) : Name(name), Description(description) {}
    Item() : Item(nullptr, nullptr) {}
    [[nodiscard]] const char* GetName() const {return Name;}
    [[nodiscard]] const char* GetDescription() const {return Description;}

};

#endif //ITEM_H