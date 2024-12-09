//
// Created by siefo on 09/12/2024.
//

#ifndef LAVE_VAISSELLE_H
#define LAVE_VAISSELLE_H

#include <list>
#include "UstensileDeCuisine.h"

class LaveVaisselle {
public:
    LaveVaisselle(int id);
    void Laver(std::list<UstensileDeCuisine>& ustensiles);

private:
    int id;
};

#endif // LAVE_VAISSELLE_H
