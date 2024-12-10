#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <QWidget>
#include "Position.h"

class Personne {
public:
    // Attributs
    int id;
    std::string nom;
    bool poste;
    bool disponibilite;
    Position positionActuelle;
    std::string imagePath;

    // Constructeurs
    Personne();
    Personne(int id, const std::string &nom, bool poste, bool disponibilite, Position position, std::string imagePath);

    // Méthodes
    void Deplacer(const Position &arrivee);
    void afficher(QWidget *parent, int aw, int ah);
};

#endif // PERSONNE_H
