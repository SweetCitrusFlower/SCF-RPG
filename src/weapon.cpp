#include "../include/weapon.h"

Weapon::Weapon(const char *name, const int plusAD, const char *description) :
    PlusAD(plusAD){
        this->Name = name;
        this->Description = description;
    };

Weapon::Weapon() : Weapon("Fists", 0, "Ye Ole Reliable.") {}

std::ostream& operator<<(std::ostream &c, const Weapon &W){
    c << W.GetName() << std::endl;
    c << "AD: ";
    if(W.GetPlusAD() < 0) c << "-" << -W.GetPlusAD();
    else if(W.GetPlusAD() == 0) c << "0";
    else c << "+" << W.GetPlusAD();
    c << std::endl << W.GetDescription() << std::endl << std::endl;
    return c;
}
