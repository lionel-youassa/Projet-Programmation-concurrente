//
// Created by siefo on 09/12/2024.
//
#ifndef PLONGEUR_H
#define PLONGEUR_H

#include "Personne.h"
#include "UstensileDeCuisine.h"
#include <list>

class Plongeur : public Personne {
public:
    Plongeur(int id, const std::string& nom, bool estEnPoste);
    void LaverUstensiles(std::list<UstensileDeCuisine>& ustensiles);

};

#endif // PLONGEUR_H
