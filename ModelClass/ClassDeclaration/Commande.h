#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include <string>
#include "Plat.h"

class Commande {
public:
    int id;
    std::string statut; // en cours, prêt, servi
    std::vector<Plat> plats;

    Commande(int id, const std::string& statut = "en cours");

    void AjouterPlat(const Plat& plat);
    void ChangerStatut(const std::string& nouveauStatut);
};

#endif // COMMANDE_H
