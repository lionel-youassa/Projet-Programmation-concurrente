#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include<QScrollArea>
#include <QToolBar>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "../Model/ClassDeclaration/Personne.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
     MainWindow( int nbrClient, int nbrVague, int tempSimulation,QWidget *parent = nullptr);

private:
    QToolBar* createNavbar(); // Méthode pour créer la barre de navigation
    //MainWindow(QWidget *parent, int nbrePersonne, int vague);

    QWidget* createRangeTable(int numChairs, int numTables); // Existant
    QWidget* createImageWidget(const QString &imagePath, int width, int height); // Existant
    void insertPng(const std::string &pngPath, QWidget *parent, int ax, int ay, int aw, int ah); // Existant
    void deplacement(QWidget *personnage, QPoint positionB, int duree);

    void testDeplacement();

    void startCountdown(int duration);
    void setnbrClient(int nbrClient);
    void setnbrVague(int nbrVague);
    void settempSimulation(int temps);



private slots:
        void updateCountdown(); // Met à jour le compteur de temps

private:
    QLabel *countdownLabel = nullptr; // Label du compteur de temps
    QTimer *timer = nullptr;          // Timer pour le décompte
    int countdown=60;          // Temps initial (en secondes)
    int nbrClient;
    int nbrVague;
    int tempSimulation;




};




#endif // MAINWINDOW_H
