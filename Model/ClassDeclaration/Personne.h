#ifndef PERSONNE_H
#define PERSONNE_H

#include <QApplication>
#include <string>
#include <QWidget>
#include <QGraphicsView>
#include <qlabel.h>
#include <SFML/Graphics.hpp>

#include "Position.h"
using namespace Qt;

class Personne {
public:
    // Attributs
    int id;
    std::string nom;
    std::string poste;
    bool disponibilite;
    Position positionActuelle;
    std::string imagePath;
    std::string couleur;
    sf::CircleShape point;
    QString nbPersonne;


    // Constructeurs
    Personne();
    Personne(int id, const std::string &nom, std::string poste, bool disponibilite, Position position,  std::string couleur, QString nbPersonne );

    // Méthodes
    void Deplacer(QLabel *point, Position arrivee, QWidget *parentWidget);

    void DeplacerTranquillement(QLabel *point, Position arrivee, QWidget *parentWidget);

    void afficher(QLabel *point, QWidget *parent, int aw);

    void AllerRetour(QLabel *point, Position arrivee, QWidget *parentWidget, int tempsAttente);



    std::vector<Personne> genererClients(int nbrePersonne, int nbreVague);
};

#endif // PERSONNE_H
