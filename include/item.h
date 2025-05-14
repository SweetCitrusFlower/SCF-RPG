#pragma once

#ifndef ITEM_H
#define ITEM_H

class Item {
protected:
    const char *Name = nullptr;
    const char *Description = nullptr;

    virtual ~Item() = default;
    virtual void Drop();

public:
    [[nodiscard]] const char* GetName() const {return Name;}
    [[nodiscard]] const char* GetDescription() const {return Description;}
};

#endif //ITEM_H