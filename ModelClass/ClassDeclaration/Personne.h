#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "Position.h"  // Pour inclure la classe Position

class Personne {
public:
    Personne(int id, const std::string& nom, bool estEnPoste);

    void Deplacer(Position depart, Position arrive);

private:
    int id;
    std::string nom;
    bool estEnPoste;
};

#endif // PERSONNE_H
