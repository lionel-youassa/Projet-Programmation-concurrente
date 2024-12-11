#include "../classDeclaration/Maitre_d_hotel.h"
#include <iostream>

void Maitre_dHotel::AttribuerTable(const std::vector<int>& clients, Table& table) {
    if (table.getStatut() == "libre" && clients.size() <= static_cast<size_t>(table.getNbPlaces())) {
        // Logique pour attribuer la table en fonction des clients
        table.ChangerStatut("occupée");
        std::cout << "Table numéro " << table.getNumero() << " attribuée aux " << clients.size() << " clients." << std::endl;
    } else {
        std::cout << "Impossible d'attribuer la table numéro " << table.getNumero() << " : "
                  << (table.getStatut() == "libre" ? "trop de clients" : "table non disponible") << std::endl;
    }
}

void Maitre_dHotel::AppelerChef(ChefDeRang& chef, Table& table) {
    std::cout << "Appel du Chef de Rang pour la table numéro " << table.getNumero() << std::endl;
    chef.DresserTable(table, "blanche");  // Exemple d'appel de méthode pour dresser la table
}
