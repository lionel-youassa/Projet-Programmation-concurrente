#include "../classDeclaration/Menu.h"
#include "../classDeclaration/Plat.h"
#include <iostream>

Menu::Menu(int id, const std::string& date)
    : id(id), date(date) {}

void Menu::AjouterPlat(const Plat& plat) {
    plats.push_back(plat);
}

// Méthode pour afficher tous les plats du menu
void Menu::AfficherPlats() const {
    std::cout << "Plats disponibles dans le menu : " << std::endl;
    int index = 1;
    for (const Plat& plat : plats) {
        std::cout << index++ << ". " << plat.getNom() << " - " << plat.getPrix() << "€" << std::endl;
    }
}

// Méthode pour obtenir un plat par son index
Plat Menu::ObtenirPlat(int index) const {
    if (index >= 0 && index < plats.size()) {
        auto it = plats.begin();
        std::advance(it, index);  // Avance le pointeur jusqu'à l'index demandé
        return *it;               // Retourne le plat à cet index
    } else {
        std::cerr << "Index invalide." << std::endl;
        return Plat();  // Retourne un plat par défaut ou gère une exception
    }
}
