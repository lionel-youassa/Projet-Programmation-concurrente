//
// Created by siefo on 09/12/2024.
//

#ifndef CHEF_DEPARTIE_H
#define CHEF_DEPARTIE_H

#include "Personne.h"
#include "Commande.h"
#include "Plat.h"
#include <list>

class Chef_dePartie : public Personne {
public:
    Chef_dePartie(int id, const std::string& nom, bool estEnPoste, const std::string& specialite);
    void PreparerPlat(const Commande& commande, std::list<Plat>& plats);

private:
    std::string specialite;
};

#endif // CHEF_DEPARTIE_H
