#include "../classDeclaration/Serveur.h"
#include <iostream>
using namespace std;

void Serveur::PrendreCommande(Table& table) {
     std::cout << "Serveur prend la commande pour la table " << table.numero << ".\n"; // Implémentation à venir
}

void Serveur::ServirCommande(Table& table) {
     std::cout << "Serveur sert la commande pour la table " << table.numero << ".\n";// Implémentation à venir
}

void Serveur::RamasserVaisselle(Table& table) {
    std::cout << "Serveur ramasse la vaisselle à la table " << table.numero << ".\n";// Implémentation à venir
}
