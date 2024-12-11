//
// Created by siefo on 11/12/2024.
//
// Ingredient.cpp
#include "../ClassDeclaration/Ingredient.h"

Ingredient::Ingredient(int id, const std::string& name, int stock)
    : id(id), nom(name), qteStock(stock) {}

void Ingredient::ajouterStock(int quantite) {
    qteStock += quantite;
}

bool Ingredient::verifierDisponibilite() const {
    return qteStock > 0;
}
