#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <list>
#include "Plat.h"

class Commande {
public:
    Commande(int id, const std::string& statut);

    void AjouterPlat(const Plat& plat);
    void ChangerStatut(const std::string& statut);

private:
    int id;
    std::string statut;
    std::list<Plat> plats;
};

#endif // COMMANDE_H
