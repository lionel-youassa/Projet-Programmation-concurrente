#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>
#include "Commande.h"
#include "Client.h"

using namespace std;

class Commande;
class Table {
public:
    int numero;
    int nbPlaces;
    std::string statut; // libre, en nettoyage, occupée

    Table(int numero, int nbPlaces, const std::string& statut = "libre");

    void AjouterClient(const Client& client);
    void LibererTable();
    void ChangerStatut(const std::string& nouveauStatut);
    void AssocierCommande(const Commande& commande);

    int getNumero() const; // Ajout de cette méthode

private:
    std::vector<Client> clients;
    std::vector<Commande> commandes;
};

#endif // TABLE_H
