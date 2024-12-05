#include "../classDeclaration/Chef_de_Cuisine.h"
#include <iostream>

ChefDeCuisine::ChefDeCuisine(int id, const std::string& nom, bool poste)
    : Personne(id, nom, poste) {}

void ChefDeCuisine::DispatcherCommandes(std::vector<Commande>& commandes) {
    std::cout << "Chef de Cuisine répartit les commandes entre les commis.\n";
}

void ChefDeCuisine::Superviser() {
    std::cout << "Chef de Cuisine supervise les opérations en cuisine.\n";
}
