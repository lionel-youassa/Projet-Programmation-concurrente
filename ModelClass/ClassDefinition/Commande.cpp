#include "../classDeclaration/Commande.h"
#include<iostream>
Commande::Commande(int id, Table* table) : id(id), table(table), statut("En attente") {}

void Commande::AjouterPlat(const Plat& plat) {
    plats.push_back(plat); // Ajouter un plat à la commande
    std::cout << "Plat " << plat.getNom() << " ajouté à la commande " << id << ".\n";
}

void Commande::ChangerStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut; // Changer le statut de la commande
    std::cout << "Statut de la commande " << id << " changé à " << statut << ".\n";
}
