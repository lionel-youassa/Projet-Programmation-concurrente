#include "../classDeclaration/Personne.h"
#include "../classDeclaration/Position.h"
using namespace std;
#include<iostream>

Personne::Personne(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

void Personne::Deplacer(Position depart, Position arrive) {
    // Logique pour déplacer la personne d'une position à une autre
}

