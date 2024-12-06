#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Menu.h"

class Client {
public:
    int id;                // Identifiant unique du client
    std::string type;      // Type de client (par exemple : Individu, Groupe)

    // Constructeur
    Client(int id, const std::string& type);

    // Méthode pour commander un plat
    Plat Commander(Menu& menu);
};

#endif // CLIENT_H
