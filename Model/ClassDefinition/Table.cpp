#include "../classDeclaration/Table.h"

Table::Table(int numero, int nbPlaces, const std::string& statut, int position_x , int position_y)
    : numero(numero), nbPlaces(nbPlaces), statut(statut), position_x(position_x), position_y(position_y) {}

void Table::AjouterClient() {

}

void Table::LibererTable() {

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

int Table::getPositionX() const {
    return position_x;
}

int Table::getPositionY() const {
    return position_y;
}

void Table::setPositionX(int position_x) {
    this->position_x = position_x;
}

void Table::setPositionY(int position_y) {
    this->position_y = position_y;
}
void Table::setStatut(const std::string& nouveauStatut) {
    statut = nouveauStatut;
}

void Table::setNbPlaces(int nbPlaces) {
    this->nbPlaces = nbPlaces;
}



