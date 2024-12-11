#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>
#include "Commande.h"
#include "Client.h"

class Commande; // Forward declaration to avoid circular dependency

class Table {
public:
    Table(int numero, int nbPlaces, const std::string& statut = "libre");

    void AjouterClient(const Client& client);
    void LibererTable();
    void ChangerStatut(const std::string& nouveauStatut);
    void AssocierCommande(const Commande& commande);

    int getNumero() const;
    int getNbPlaces() const { return nbPlaces; } // Ajout de la méthode pour accéder à nbPlaces
    std::string getStatut() const; // Nouvelle méthode ajoutée pour obtenir le statut de la table
    std::vector<Commande>& getCommandes() { return commandes; } // Méthode pour accéder à commandes

private:
    int numero;
    int nbPlaces;
    std::string statut; // libre, en nettoyage, occupée
    std::vector<Client> clients;
    std::vector<Commande> commandes;
};

#endif // TABLE_H
