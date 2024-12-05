#include "../classDeclaration/Plat.h"

Plat::Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation, bool estDisponible)
    : id(id), nom(nom), categorie(categorie), prix(prix), tempsPreparation(tempsPreparation), estDisponible(estDisponible) {}

std::string Plat::getNom() const {
    return nom;
}

bool Plat::verifierDisponible() const {
    return estDisponible;
}
