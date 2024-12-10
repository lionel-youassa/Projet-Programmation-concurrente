#include "../classDeclaration/Personne.h"
#include <QLabel>
#include <QPixmap>
#include <QString>

// Constructeur avec paramètres
Personne::Personne(int id, const std::string &nom, bool poste, bool disponibilite, Position position, std::string imagePath)
    : id(id), nom(nom), poste(poste), disponibilite(disponibilite), positionActuelle(position), imagePath(imagePath) {}

// Constructeur par défaut
Personne::Personne() : id(0), poste(false), disponibilite(false) {
    positionActuelle.x = 0;
    positionActuelle.y = 0;
}

// Méthode de déplacement
void Personne::Deplacer(const Position &arrivee) {
    positionActuelle = arrivee;
    float step = 1.0; // Taille du pas

    if (std::abs(positionActuelle.x - arrivee.x) > step) {
        float directionX = (arrivee.x - positionActuelle.x > 0) ? step : -step;
        positionActuelle.x += directionX;
    } else {
        positionActuelle.x = arrivee.x; // Correction pour s'arrêter exactement sur la position cible
    }

    if (std::abs(positionActuelle.y - arrivee.y) > step) {
        float directionY = (arrivee.y - positionActuelle.y > 0) ? step : -step;
        positionActuelle.y += directionY;
    } else {
        positionActuelle.y = arrivee.y; // Correction pour s'arrêter exactement sur la position cible
    }
}

// Méthode d'affichage
void Personne::afficher(QWidget *parent,int aw, int ah) {
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
    imageLabel->setGeometry(positionActuelle.x, positionActuelle.y, aw, ah);
}
