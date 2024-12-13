#include "../classDeclaration/Table.h"
#include "../classDeclaration/Personne.h"


Table::Table(int numero, int nbPlaces, const std::string& statut, int position_x , int position_y)
    : numero(numero), nbPlaces(nbPlaces), statut(statut), pos(Position(position_x,position_y)) {}

void Table::AjouterClient(Personne client) {
    occupePar = client;
    statut="occupee";
}

void Table::LibererTable() {
    occupePar = Personne();
    statut="Libre";
}

void Table::ChangerStatut(const std::string& nouveauStatut) {

}

int Table::getNumero() const {
    return numero;
}

int Table::getNbPlaces() const {
    return nbPlaces;
}
const std::string& Table::getStatut() const {
    return statut;
}

Table::Table(): numero(0), nbPlaces(0), places(0) {
}


void Table::setStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut;
}

void Table::setNbPlaces(int nbPlaces) {
    this->nbPlaces = nbPlaces;
}



