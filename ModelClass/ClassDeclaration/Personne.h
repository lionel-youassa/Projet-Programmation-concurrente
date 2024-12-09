#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "Position.h"  // Pour inclure la classe Position
#include <QWidget>

class Personne {
public:
    Personne(int id, const std::string& nom, bool estEnPoste);

    Personne(int i, const char * str, bool cond, bool cond1, Position pos, const char * text);

    void Deplacer(Position depart, Position arrive);

    void afficher(QWidget * widget, int i, int i1);

private:
    int id;
    std::string nom;
    bool estEnPoste;
};

#endif // PERSONNE_H
