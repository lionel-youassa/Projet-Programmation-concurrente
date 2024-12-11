#ifndef MENU_H
#define MENU_H

#include <list>
#include "Plat.h"

class Menu {
public:
    Menu(int id, const std::string& date);
    void AjouterPlat(const Plat& plat);
    void AfficherPlats() const;            // Déclaration de la méthode pour afficher les plats
    Plat ObtenirPlat(int index) const;     // Déclaration de la méthode pour obtenir un plat par index

private:
    int id;
    std::string date;
    std::list<Plat> plats;                 // Liste des plats dans le menu
};

#endif // MENU_H
