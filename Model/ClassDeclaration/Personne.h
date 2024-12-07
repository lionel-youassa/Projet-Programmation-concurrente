#ifndef PERSONNE_H
#define PERSONNE_H

#include <qgraphicsscene.h>
#include <string>
#include "Position.h"
using namespace std;

class Personne {
public:
    int id;
    string nom;
    bool poste;
    bool disponibilite;
    Position positionActuelle;
    string imagePath;

    Personne();
    Personne(int id, const std::string &nom, bool poste,bool disponibilite, Position position, string imagePath);

    void Deplacer(const Position &arrivee);

    void afficher(QWidget *parent, int ax, int ay, int aw, int ah);
};

#endif // PERSONNE_H
