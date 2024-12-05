#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <vector>

class Menu {
public:
    int id;         // Identifiant du menu
    std::string date; // Date du menu

    Menu(int id, const std::string& date);

    // Méthodes définies sur le diagramme
    // (aucune méthode supplémentaire indiquée)
};

#endif // MENU_H
