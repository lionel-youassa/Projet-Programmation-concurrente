#include "../classDeclaration/Position.h"
Position::Position(float x, float y)  : x(x), y(y) {}

// Méthode pour déplacer la position
void Position::deplacer(float dx, float dy) {
    x += dx;
    y += dy;
}