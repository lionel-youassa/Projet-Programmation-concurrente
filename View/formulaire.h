#ifndef FORMULAIRE_H
#define FORMULAIRE_H


#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include "mainwindow.h"


class Formulaire : public QWidget {
    Q_OBJECT
public:
    explicit Formulaire(QWidget *parent = nullptr);

private:
    void setupFormLayout(QFormLayout *formLayout);
    void setupStartButton(QVBoxLayout *mainLayout);

    int getNombreClient();
    int  getNombreDeVague ();
    int getTempsDeSimulation ();



    QSpinBox *placeInput;
    QSpinBox *tableInput;
    QSpinBox *timeInput;
};


#endif // FORMULAIRE_H
