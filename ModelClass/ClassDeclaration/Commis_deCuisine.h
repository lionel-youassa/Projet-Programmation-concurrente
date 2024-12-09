//
// Created by siefo on 09/12/2024.
//

#ifndef COMMIS_DECUSINE_H
#define COMMIS_DECUSINE_H

#include "Personne.h"

class Commis_deCuisine : public Personne {
public:
    Commis_deCuisine(int id, const std::string& nom, bool estEnPoste);
    void EplucherLegumes();
};

#endif // COMMIS_DECUSINE_H
