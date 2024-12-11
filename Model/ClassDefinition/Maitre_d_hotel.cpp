#include "../classDeclaration/Maitre_d_hotel.h"
#include <iostream>

void Maitre_dHotel::AttribuerTable(const std::vector<int>& clients, Table& table) {
    std::cout << "Maître d'hôtel attribue une table aux clients.\n";
}
void Maitre_dHotel::AppelerChef(ChefDeRang& chef, Table& table) {
   std::cout << "Maître d'hôtel appelle le Chef de Rang pour la table " << table.numero << ".\n"; // Implémentation à venir
}