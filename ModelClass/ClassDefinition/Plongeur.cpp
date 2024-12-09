//
// Created by siefo on 09/12/2024.
//
#include "../ClassDeclaration/Plongeur.h"

Plongeur::Plongeur(int id, const std::string& nom, bool estEnPoste)
    : Personne(id, nom, estEnPoste) {}

void Plongeur::LaverUstensiles(std::list<UstensileDeCuisine>& ustensiles) {
    // Logique pour laver les ustensiles
}
