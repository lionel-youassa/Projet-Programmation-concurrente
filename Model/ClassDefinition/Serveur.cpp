#include "../classDeclaration/Serveur.h"
#include <iostream>

void Serveur::PrendreCommande(Table& table) {
    if (table.getStatut() == "occupée") {
        // Simuler la prise de commande (peut être remplacé par une vraie interaction avec la classe Commande)
        std::cout << "Le serveur prend la commande pour la table " << table.getNumero() << ".\n";
        Commande nouvelleCommande;  // Création d'une commande fictive
        table.AssocierCommande(nouvelleCommande);  // Associer la commande à la table
    } else {
        std::cout << "Impossible de prendre la commande : la table n'est pas occupée.\n";
    }
}

void Serveur::ServirCommande(Table& table) {
    if (table.getStatut() == "occupée" && !table.getCommandes().empty()) {
        std::cout << "Le serveur sert la commande pour la table numéro " << table.getNumero() << "." << std::endl;
        // Logique pour servir la commande (par exemple, servir les plats)
    } else {
        std::cout << "Aucune commande à servir pour la table numéro " << table.getNumero() << "." << std::endl;
    }
}


void Serveur::RamasserVaisselle(Table& table) {
    if (table.getStatut() == "occupée") {
        std::cout << "Le serveur ramasse la vaisselle à la table " << table.getNumero() << ".\n";
        // Après ramassage, on pourrait par exemple libérer la table
        table.LibererTable();  // Remet la table à l'état "libre"
    } else {
        std::cout << "Impossible de ramasser la vaisselle : la table n'est pas occupée.\n";
    }
}
