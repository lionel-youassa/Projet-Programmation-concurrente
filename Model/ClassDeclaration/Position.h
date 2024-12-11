//
// Created by siefo on 03/12/2024.
//

#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    float x;
    float y;

    Position(float x = 0, float y = 0);

    // Méthode pour déplacer la position
    void deplacer(float dx, float dy);

};

#endif // POSITION_H
