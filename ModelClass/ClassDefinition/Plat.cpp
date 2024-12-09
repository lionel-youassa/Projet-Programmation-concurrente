#include "../classDeclaration/Plat.h"

Plat::Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation)
    : id(id), nom(nom), categorie(categorie), prix(prix), tempsPreparation(tempsPreparation), disponible(true) {}

bool Plat::estDisponible() const {
    return disponible;
}

std::string Plat::getNom() const {
    return nom;
}