#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>

class Ingredients {
public:
    int id;         // Identifiant unique de l'ingrédient
    std::string nom; // Nom de l'ingrédient
    int qteStock;    // Quantité disponible en stock

    Ingredients(int id, const std::string& nom, int qteStock);

    // Méthodes définies sur le diagramme
    void AjouterQte(int quantite); // Ajoute une quantité au stock
    bool VerifierDisponible();    // Vérifie si l'ingrédient est disponible
};

#endif // INGREDIENTS_H
