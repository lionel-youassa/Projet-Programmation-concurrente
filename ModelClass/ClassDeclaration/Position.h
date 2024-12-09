#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    float x, y;
    Position(float x, float y);
    void Deplacer(Position depart, Position arrive);
};

#endif // POSITION_H
