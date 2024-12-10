#ifndef TABLE_H
#define TABLE_H

#include <string>

class Table {
public:
    int numero;
    int nbPlaces;
    std::string statut; // libre, en nettoyage, occupée

    Table(int numero, int nbPlaces, const std::string& statut = "libre");

    void AjouterClient();
    void LibererTable();
    void ChangerStatut(const std::string& nouveauStatut);
};

#endif // TABLE_H
