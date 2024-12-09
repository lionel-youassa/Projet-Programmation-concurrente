//
// Created by siefo on 09/12/2024.
//
#include "../ClassDeclaration//UstensileDeCuisine.h"

UstensileDeCuisine::UstensileDeCuisine(int id, const std::string& nom, bool etat)
    : id(id), nom(nom), etat(etat) {}

bool UstensileDeCuisine::verifierEtat() const {
    return etat;
}
