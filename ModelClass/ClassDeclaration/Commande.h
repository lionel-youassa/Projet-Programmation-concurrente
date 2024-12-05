#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include "Plat.h"
#include "Table.h" // Inclure Table pour la relation

class Commande {
public:
    int id;
    std::vector<Plat> plats; // Plats associés à la commande
    Table* table; // Table associée à la commande
    std::string statut; // Statut de la commande

    Commande(int id, Table* table); // Constructeur avec la table en paramètre

    void AjouterPlat(const Plat& plat); // Ajouter un plat à la commande
    void ChangerStatut(const std::string& nouveauStatut); // Changer le statut de la commande
};

#endif // COMMANDE_H
