//
// Created by siefo on 05/12/2024.
//

#ifndef CHEF_DE_CUISINE_H
#define CHEF_DE_CUISINE_H
#include "Personne.h"
#include "Commande.h"
#include <vector>

class ChefDeCuisine : public Personne {
public:
    ChefDeCuisine(int id, const std::string& nom, bool poste);

    // Méthodes
    void DispatcherCommandes(std::vector<Commande>& commandes);
    void Superviser();
};

#endif // CHEF_DE_CUISINE_H
#endif //CHEF_DE_CUISINE_H
