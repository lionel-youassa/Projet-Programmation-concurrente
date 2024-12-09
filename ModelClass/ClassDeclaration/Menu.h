#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <list>

class Menu {
public:
    int id;         // Identifiant du menu
    std::string date; // Date du menu

    Menu(int id, const std::string& date);
    // Méthode pour obtenir un plat disponible
    Plat GetPlatDisponible();
};
    // Méthodes définies sur le diagramme
    // (aucune méthode supplémentaire indiquée)

#endif // MENU_H
