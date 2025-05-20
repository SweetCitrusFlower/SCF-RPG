#pragma once

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

class Consumable final : public Item {
protected:
    int PlusHP = 0;

public:

    Consumable(const char*, int, const char*);
    Consumable();
    ~Consumable() override;

    [[nodiscard]] int GetPlusHP() const { return PlusHP;}

    std::ostream& operator<<(std::ostream&) const override;

};

inline auto McPuisor = Consumable("McPuisor", -40, "This item makes you a bit fatter.");

#endif //CONSUMABLE_H
