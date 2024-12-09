#include "../classDeclaration/CommisDeSalle.h"
#include <iostream>

CommisDeSalle::CommisDeSalle(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void CommisDeSalle::ServirPlat(Table& table) {
    // Logique pour servir le plat
}

void CommisDeSalle::VerifierBesoinClient() {
    // Logique pour vérifier les besoins des clients
}
