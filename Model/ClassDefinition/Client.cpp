#include "../classDeclaration/Client.h"

Client::Client(int id, const std::string& type)
    : id(id), type(type) {}

void Client::Commander(Commande& commande, const Plat& plat) {
    // Implémentation à venir
}
