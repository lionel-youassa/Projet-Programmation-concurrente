#include "../classDeclaration/Commande.h"
#include "../classDeclaration/Commande.h"
#include "../classDeclaration/Table.h"
#include "../classDeclaration/Table.h"
#include<iostream>

Commande::Commande(int id, Table* table) :
id(id), table(table), statut("En attente") {}

// Constructeur par défaut
Commande::Commande()
    : id(0), table(nullptr), statut("en attente") {
    // Valeurs par défaut pour les membres
}

void Commande::AjouterPlat(const Plat& plat) {
    plats.push_back(plat); // Ajouter un plat à la commande
}

void Commande::ChangerStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut; // Changer le statut de la commande
    std::cout << "Statut de la commande " << id << " changé à " << statut << ".\n";
}
