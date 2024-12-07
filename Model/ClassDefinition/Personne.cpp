#include "../classDeclaration/Personne.h"
#include<QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QString>
#include <string>


Personne::Personne(int id, const std::string &nom, bool poste,bool disponibilite, Position position, string imagePath)
    : id(id), nom(nom), poste(poste), disponibilite(disponibilite), positionActuelle(position), imagePath(imagePath) {
}

// Constructeur par défaut
// Personne::Personne(): id(0), poste(false), disponibilite(false) {
//     positionActuelle.x = 0;
//     positionActuelle.y = 0;
// }


void Personne::Deplacer(const Position &arrivee) {
    // Déplacement sur l'axe X
    if (positionActuelle.x != arrivee.x) {
        // Calcul de la direction (gauche ou droite)
        float directionX = (arrivee.x - positionActuelle.x> 0) ? 1.0 : -1.0;
        positionActuelle.x += directionX;
    }

    // Déplacement sur l'axe Y
    if (positionActuelle.y != arrivee.y) {
        // Calcul de la direction (haut ou bas)
        float directionY = (arrivee.y - positionActuelle.y > 0) ? 1.0 : -1.0;
        positionActuelle.y += directionY;
    }
}



void Personne::afficher(QWidget *parent, int ax, int ay, int aw, int ah) {
    QLabel *imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("border: none;");

    QPixmap pixmap(QString::fromStdString(imagePath));
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(aw, ah, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("Image introuvable");
    }

    imageLabel->setFixedSize(aw, ah);
    imageLabel->setParent(parent);
    imageLabel->setGeometry(ax, ay, aw, ah);
}

