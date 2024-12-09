//
// Created by siefo on 09/12/2024.
//
#include "../ClassDeclaration/Chef_dePartie.h"

Chef_dePartie::Chef_dePartie(int id, const std::string& nom, bool estEnPoste, const std::string& specialite)
    : Personne(id, nom, estEnPoste), specialite(specialite) {}

void Chef_dePartie::PreparerPlat(const Commande& commande, std::list<Plat>& plats) {
    // Logique pour préparer les plats dans une commande
}
