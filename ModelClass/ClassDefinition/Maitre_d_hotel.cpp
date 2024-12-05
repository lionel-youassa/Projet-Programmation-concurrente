#include "../classDeclaration/Maitre_d_Hotel.h"
#include <iostream>

Maitre_dHotel::Maitre_dHotel(int id, const std::string& nom, bool poste)
    : Personne(id, nom, poste) {}

void Maitre_dHotel::AttribuerTable(std::vector<Client>& clients) {
    std::cout << "Maître d'hôtel attribue une table aux clients.\n";
}

void Maitre_dHotel::AppelerChef(ChefDeRang& chef, Table& table) {
    std::cout << "Maître d'hôtel appelle le Chef de Rang pour la table " << table.numero << ".\n";
}
