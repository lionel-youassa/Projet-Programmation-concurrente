#include "../classDeclaration/Table.h"

Table::Table(int numero, int nbPlaces, const std::string& statut)
    : numero(numero), nbPlaces(nbPlaces), statut(statut) {}

void Table::AjouterClient(const Client& client) {
    if (statut == "libre" && clients.size() < static_cast<size_t>(nbPlaces)) {
        clients.push_back(client);
    }
}

void Table::LibererTable() {
    clients.clear();
    commandes.clear();
    statut = "libre";
}

void Table::ChangerStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut;
}

void Table::AssocierCommande(const Commande& commande) {
    commandes.push_back(commande);
}
