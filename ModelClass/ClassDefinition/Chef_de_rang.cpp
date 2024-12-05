#include "../ClassDeclaration/Chef_de_rang.h"
#include <iostream>

void ChefDeRang::DistribuerCarte(Table& table) {
     std::cout << "Chef de Rang distribue les cartes à la table " << table.numero << ".\n";// Implémentation à venir
}

void ChefDeRang::Coordonner(CommisDeSalle& commis) {
     std::cout << "Chef de Rang coordonne le commis de salle.\n";// Implémentation à venir
}

void ChefDeRang::DresserTable(Table& table, const std::string& nappe) {
        std::cout << "Chef de Rang dresse la table " << table.numero << " avec une nappe.\n"; // Implémentation à venir
}
