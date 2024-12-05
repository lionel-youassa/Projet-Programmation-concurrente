#include "../classDeclaration/Commande.h"

Commande::Commande(int id, Table* table) : id(id), table(table), statut("En attente") {}

void Commande::AjouterPlat(const Plat& plat) {
    plats.push_back(plat); // Ajouter un plat à la commande
}

void Commande::ChangerStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut; // Changer le statut de la commande
}
