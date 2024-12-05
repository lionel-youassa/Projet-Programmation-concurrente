#ifndef PLAT_H
#define PLAT_H

#include <string>
#include "Ingredients.h"

class Plat {
public:
    int id;
    std::string nom;
    std::string categorie; // Entrée, plat principal, dessert
    double prix;
    int tempsPreparation;
    bool estDisponible;

    Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation, bool estDisponible);

    // Méthodes
    std::string getNom() const;
    bool verifierDisponible() const;
};

#endif // PLAT_H
