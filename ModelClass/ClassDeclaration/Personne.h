#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "Position.h"

class Personne {
public:
    int id;
    std::string nom;²²²²²²²²²²
    bool PosteFixe;

    Personne(int id, const std::string& nom, bool estOccupe = false);

    void Deplacer(const Position& depart, const Position& arrivee);
};

#endif // PERSONNE_H
