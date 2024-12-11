// Plat.h
#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <vector>
#include "Ingredient.h"

class Plat {
private:
    int id;
    std::string nom;
    std::string categorie;
    float prix;
    int tempsPreparation;
    bool estDisponible;
    std::vector<Ingredient> ingredients;  // Composition : un plat est composé de plusieurs ingrédients

public:
    Plat(int id, const std::string& nom, const std::string& categorie, float prix);
    void ajouterIngredient(const Ingredient& ingredient);
    bool verifierDisponibilite() const;
    std::string getNom() const;
};

#endif // PLAT_H
