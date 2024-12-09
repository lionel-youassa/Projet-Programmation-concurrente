#ifndef MENU_H
#define MENU_H

#include <list>
#include "Plat.h"

class Menu {
public:
    Menu(int id, const std::string& date);
    void AjouterPlat(const Plat& plat);

private:
    int id;
    std::string date;
    std::list<Plat> plats;
};

#endif // MENU_H
