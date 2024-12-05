#include "../classDeclaration/Commis_de_salle.h"
#include <iostream>

CommisDeSalle::CommisDeSalle(int id, const std::string& nom, bool poste)
    : Personne(id, nom, poste) {}

void CommisDeSalle::ServirPlat(Table& table) {
    std::cout << "Commis de Salle sert le plat à la table " << table.numero << ".\n";
}

void CommisDeSalle::VerifierBesoinClient() {
    std::cout << "Commis de Salle vérifie les besoins des clients.\n";
}
