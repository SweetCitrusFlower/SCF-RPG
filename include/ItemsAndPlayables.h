#ifndef ITEMSANDPLAYABLES_H
#define ITEMSANDPLAYABLES_H


#include "weapon.h"
#include "armor.h"
#include "consumable.h"
#include "playable.h"

inline auto Fists = Weapon("Fists", 0, "Ye Ole Reliable.");
inline auto Plate = Weapon("Plate", 100, "Can hurt a lot, but is very fragile. Just like a betrayed heart.");
inline auto Cigarette = Weapon("Cigarette", 30, "It's gonna be put out on your skin.");
inline auto FlipPhone = Weapon("Flip Phone", 150, "Single use. But you keep using it.");
inline std::vector AllWeapons = {&Plate, &Cigarette, &FlipPhone};

inline auto Skin = Armor("Skin", 0, 1, "You're naked. Gross.");
inline auto SoulJacket = Armor("Soul Jacket", 200, 300, "The ultimate sacrifice: to live with your heart on your sleeve.");
inline auto LanaTShirt = Armor("Lana del Rey T-Shirt", 20, 500, "Given with love. Kinda want it back tho ngl");
inline std::vector AllArmors = {SoulJacket, LanaTShirt};

inline auto McPuisor = Consumable("McPuisor", -40, "This item makes you a bit fatter.");
inline auto Apple = Consumable("Apple", 5, "Keeps the doctors away!");
inline auto Vodka = Consumable("Vodka", 300, "Russian wisdom cyka blyat");
inline auto PlateOfSpaghetti = Consumable("Plate of spaghetti", 300, "To forgetti your regretti.");
inline std::vector<std::pair<Consumable, int>> AllConsumables = {{McPuisor, 2}, {Apple, 1}, {Vodka, 10}, {PlateOfSpaghetti, 15}};

inline auto Weakling = Playable("Weakling", 0, 0, 1, 0, 1, "-", &Fists, &Skin, {});
inline auto Mera = Playable("Mera", 5, 2, 30, 46, 3, "He loves playing League", &FlipPhone, &Skin, {Vodka});
inline auto Dragos = Playable("Dragos", 15, 1, 115, 5, 11, "A beautiful feller", &Cigarette, &LanaTShirt, {Apple});
inline auto sans = Playable("sans.", 1, 1, 1, 43, 1, "erererererer", &Fists, &Skin, {});
inline std::vector AllPlayables = {Mera, Dragos, sans};

#endif //ITEMSANDPLAYABLES_H
