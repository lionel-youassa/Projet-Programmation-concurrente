//
// Created by siefo on 11/12/2024.
//
// Ingredient.h
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    int id;
    std::string nom;
    int qteStock;

public:
    Ingredient(int id, const std::string& nom, int qteStock);
    void ajouterStock(int quantite);
    bool verifierDisponibilite() const;
};

#endif // INGREDIENT_H
