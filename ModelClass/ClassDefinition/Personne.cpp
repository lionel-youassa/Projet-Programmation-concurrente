#include "../classDeclaration/Personne.h"
using namespace std;
#include<iostream>

Personne::Personne(int id, const std::string& nom, bool estEnPoste)
    : id(id), nom(nom), estEnPoste(estEnPoste) {}

Personne::Personne(int i, const char *str, bool cond, bool cond1, Position pos, const char *text) {

}


void Personne::Deplacer(Position depart, Position arrive) {
    // Logique pour déplacer la personne d'une position à une autre
}

