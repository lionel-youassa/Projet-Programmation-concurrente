// Plat.cpp
#include "../ClassDeclaration/Plat.h"

Plat::Plat(int id, const std::string& name, const std::string& cat, float price)
    : id(id), nom(name), categorie(cat), prix(price), estDisponible(true) {}

void Plat::ajouterIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

bool Plat::verifierDisponibilite() const {
    return estDisponible;
}

std::string Plat::getNom() const {
    return nom;
}
