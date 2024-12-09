#include <iostream>
#include<list>

#include "../ClassDeclaration/ChefDeRang.h"

ChefDeRang::ChefDeRang(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void ChefDeRang::DistribuerCarte(Table& table) {
    // Logique pour distribuer la carte
}

void ChefDeRang::CoordonnerCommis(std::list<CommisDeSalle>& commis) {
    // Logique pour coordonner les commis de salle
}

void ChefDeRang::DresserTable(Table& table, const std::string& nappe) {
    // Logique pour dresser la table
}
