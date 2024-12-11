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
    // Constructeur par défaut
    Plat() : id(0), nom("Inconnu"), categorie("Inconnu"), prix(0.0f), tempsPreparation(0), estDisponible(true) {}

    // Constructeur avec paramètres
    Plat(int id, const std::string& nom, const std::string& categorie, float prix);

    // Méthodes pour accéder aux informations des plats
    std::string getNom() const;
    float getPrix() const;  // Ajouter cette méthode pour obtenir le prix du plat

    // Méthodes supplémentaires
    void ajouterIngredient(const Ingredient& ingredient);
    bool verifierDisponibilite() const;
};

#endif // PLAT_H
