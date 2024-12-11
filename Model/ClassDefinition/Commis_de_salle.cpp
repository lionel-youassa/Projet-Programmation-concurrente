#include "../classDeclaration/Commis_de_salle.h"
#include <iostream>

CommisDeSalle::CommisDeSalle(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void CommisDeSalle::ServirPlat(Table& table) {
    std::cout << "Le commis " << nom << " sert un plat à la table numéro " << table.getNumero() << "." << std::endl;
}

void CommisDeSalle::VerifierBesoinClient() {
    std::cout << "Le commis " << nom << " vérifie les besoins des clients." << std::endl;
}

int CommisDeSalle::getId() const {
    return id;
}
