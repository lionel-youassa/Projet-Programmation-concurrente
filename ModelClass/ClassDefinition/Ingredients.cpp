#include "../classDeclaration/Ingredients.h"
#include <iostream>

Ingredients::Ingredients(int id, const std::string& nom, int qteStock)
    : id(id), nom(nom), qteStock(qteStock) {}

void Ingredients::AjouterQte(int quantite) {
    qteStock += quantite;
    std::cout << "Ajout de " << quantite << " unités à l'ingrédient \"" << nom << "\". Stock actuel : " << qteStock << ".\n";
}

bool Ingredients::VerifierDisponible() {
    if (qteStock > 0) {
        std::cout << "L'ingrédient \"" << nom << "\" est disponible. Quantité actuelle : " << qteStock << ".\n";
        return true;
    }
    std::cout << "L'ingrédient \"" << nom << "\" n'est pas disponible.\n";
    return false;
}
