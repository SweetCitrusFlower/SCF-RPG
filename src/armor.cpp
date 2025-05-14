#include "../include/armor.h"

Armor::Armor(const char* name, const int plusDef, const int plusHP, const char* description) :
    PlusDef(plusDef), PlusHP(plusHP){
      this->Name = name;
      this->Description = description;
    };

Armor::Armor() : Armor("Skin", 0, 1, "You're naked. Gross.") {};

std::ostream& operator<<(std::ostream &c, const Armor &A){
    c << A.GetName() << std::endl;
    c << "+DEF: ";
    if(A.GetPlusDef() < 0) c << "-" << -A.GetPlusDef();
    else c << A.GetPlusDef();

    c << std::endl << "+HP: ";
    if(A.GetPlusHP() < 0) c << "-" << -A.GetPlusHP();
    else c << A.GetPlusHP();

    c << std::endl << A.GetDescription() << std::endl << std::endl;
    return c;
};