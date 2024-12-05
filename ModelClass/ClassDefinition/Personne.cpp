#include "../classDeclaration/Personne.h"
using namespace std;
#include<iostream>

Personne::Personne(int id, const std::string &nom, bool PosteFixe)
    : id(id), nom(nom), PosteFixe(PosteFixe) {}

void Personne::Deplacer(const Position &depart, const Position &arrivee) {
    std::cout << nom << " se déplace de (" << depart.x << ", " << depart.y
               << ") à (" << arrivee.x << ", " << arrivee.y << ").\n";
}


