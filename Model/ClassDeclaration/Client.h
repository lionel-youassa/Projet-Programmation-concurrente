#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Commande.h"
#include "Plat.h"

class Client {
public:
    int id;
    std::string type; // Individu, Groupe, etc.

    Client(int id, const std::string& type);

    void Commander(Commande& commande, const Plat& plat);
};

#endif // CLIENT_H
