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

    Item(const Item&);
    Item(Item&&) noexcept;
    Item& operator=(const Item&);
    Item& operator=(Item&&) noexcept;

    [[nodiscard]] const char* GetName() const& {return Name;}
    [[nodiscard]] const char* GetDescription() const& {return Description;}

};

#endif //ITEM_H