#include "../classDeclaration/Chef_de_rang.h"
#include <iostream>

ChefDeRang::ChefDeRang(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void ChefDeRang::DistribuerCarte(Table& table) {
    if (table.getStatut() == "libre") {
        std::cout << "Distribution des cartes à la table numéro " << table.getNumero() << std::endl;
        table.ChangerStatut("occupée");
    } else {
        std::cout << "Impossible de distribuer les cartes : la table n'est pas libre." << std::endl;
    }
}

void ChefDeRang::CoordonnerCommis(std::list<CommisDeSalle>& commisList) {
    for (CommisDeSalle& commis : commisList) {
        std::cout << "Coordination du commis de salle avec ID " << commis.getId() << std::endl;
        commis.VerifierBesoinClient();  // Appel correct à la méthode
    }
    std::cout << "Coordination des commis de salle terminée." << std::endl;
}

void ChefDeRang::DresserTable(Table& table, const std::string& nappe) {
    if (table.getStatut() == "libre") {
        std::cout << "La table numéro " << table.getNumero() << " est en cours de dressage avec une nappe " << nappe << std::endl;
        table.ChangerStatut("en dressage");
        std::cout << "La table a été dressée avec succès." << std::endl;
        table.ChangerStatut("prête");
    } else {
        std::cout << "Impossible de dresser la table : la table n'est pas libre." << std::endl;
    }
}
