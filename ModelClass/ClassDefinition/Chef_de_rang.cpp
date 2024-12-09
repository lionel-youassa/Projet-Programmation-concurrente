#include "../ClassDeclaration/Chef_de_rang.h"
#include <iostream>
#include<list>

Chef_de_rang::ChefDeRang(int id, const std::string& nom, bool estEnPoste)
    : Personne(id, nom, estEnPoste) {}

void Chef_de_rang::DistribuerCarte(Table& table) {
    // Logique pour distribuer la carte
}

void Chef_de_rang::CoordonnerCommis(std::list<Commis_de_salle>& commis) {
    // Logique de coordination des commis
}

void Chef_de_rang::DresserTable(Table& table, std::string nappe) {
    // Logique pour dresser la table
}
