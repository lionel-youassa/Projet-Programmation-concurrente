//
// Created by siefo on 09/12/2024.
//
#include "../ClassDeclaration/Commis_deCuisine.h"

Commis_deCuisine::Commis_deCuisine(int id, const std::string& nom, bool estEnPoste)
    : Personne(id, nom, estEnPoste) {}

void Commis_deCuisine::EplucherLegumes() {
    // Logique pour éplucher les légumes
}
