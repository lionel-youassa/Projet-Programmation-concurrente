#ifndef TABLE_H
#define TABLE_H

#include <string>

#include "Personne.h"

class Table {
public:
    int numero;
    int nbPlaces;
    int places;
    int position_x;
    int position_y;
    std::string statut; // libre, en nettoyage, occupée
    Personne occupePar;

    Table();
    Table(int numero, int nbPlaces, const std::string& statut = "Non occupee",int position_x=0, int position_y=0);

    void AjouterClient(Personne client);
    void LibererTable();
    void ChangerStatut(const std::string& nouveauStatut);

    int getNumero() const;

    int getNbPlaces() const;

    const std::string &getStatut() const;

    int getPositionX() const;

    int getPositionY() const;


    void setPositionX(int position_x);
    void setPositionY(int position_y);
    void setStatut(const std::string& statut);
    void setNbPlaces(int nbPlaces);

};

#endif // TABLE_H
