#include "../classDeclaration/Client.h"
#include "../classDeclaration/Plat.h"
#include "../classDeclaration/Menu.h"
#include "../classDeclaration/Commande.h"
#include <iostream>
using namespace std;

Client::Client(int id, const std::string& type) :
    id(id), type(type) {}

void Client::Commander(Menu& menu) {
    std::cout << "Client " << id << " (type: " << type << ") consulte le menu." << std::endl;

    // Afficher les plats disponibles dans le menu
    menu.AfficherPlats();

    // Supposons que le client choisit deux plats (ceci est un exemple, vous pouvez demander des entrées utilisateur)
    Plat plat1 = menu.ObtenirPlat(1);  // Obtenir un plat par son index (ou ID)
    Plat plat2 = menu.ObtenirPlat(2);  // Idem pour le second plat

    // Créer une nouvelle commande pour ce client (à associer à la table plus tard)
    Commande commande(id, nullptr);  // Vous pouvez associer une table ici si nécessaire

    // Ajouter les plats choisis à la commande
    commande.AjouterPlat(plat1);
    commande.AjouterPlat(plat2);

    std::cout << "Commande passée par le client " << id << " avec les plats suivants : " << std::endl;
    std::cout << "Plat 1: " << plat1.getNom() << std::endl;
    std::cout << "Plat 2: " << plat2.getNom() << std::endl;

    // Lier la commande à la table du client si vous avez un système de tables (sinon, à un serveur)
    // table.AssocierCommande(commande);// Logique pour commander un menu
}
