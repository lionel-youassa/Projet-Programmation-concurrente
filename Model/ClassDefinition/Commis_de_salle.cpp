#include "../classDeclaration/Commis_de_salle.h"

CommisDeSalle::CommisDeSalle(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void CommisDeSalle::ServirPlat(Table& table) {
    // Implémentation à venir
}

void CommisDeSalle::VerifierBesoinClient() {
    // Implémentation à venir
}
