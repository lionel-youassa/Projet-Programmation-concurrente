#include "../classDeclaration/Commande.h"

Commande::Commande(int id, const std::string& statut)
    : id(id), statut(statut) {}

void Commande::AjouterPlat(const Plat& plat) {
    // Implémentation à venir
}

void Commande::ChangerStatut(const std::string& nouveauStatut) {
    // Implémentation à venir
}
