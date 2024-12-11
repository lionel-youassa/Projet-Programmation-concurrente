#include "../classDeclaration/Personne.h"

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QColor>
#include <QPointF>
#include <QThread> // Pour utiliser QThread::msleep
#include <QCoreApplication>

#include <QWidget>
#include <QPainter>





// Constructeur avec paramètres
Personne::Personne(int id, const std::string &nom, std::string poste, bool disponibilite, Position position,   std::string couleur, QString nbPersonne="1")
    : id(id), nom(nom), poste(poste), disponibilite(disponibilite), positionActuelle(position), couleur(couleur), nbPersonne(nbPersonne) {

}

// Constructeur par défaut
Personne::Personne() : id(0), disponibilite(false) {
    positionActuelle.x = 0;
    positionActuelle.y = 0;
}

// Méthode de déplacement
#include <QPropertyAnimation>

#include <QLabel>
#include <QTimer>

void Personne::Deplacer(QLabel *point, Position arrivee, QWidget *parentWidget) {
    // Crée un QLabel pour représenter le point si ce n'est pas déjà fait

    point->setStyleSheet(QString("background-color: %1; border-radius: 5px;")
                         .arg(QString::fromStdString(couleur)));
    point->setFixedSize(10, 10);
    point->move(positionActuelle.x, positionActuelle.y);
    point->show();

    // Animation pour déplacer le point
    QPropertyAnimation *animation = new QPropertyAnimation(point, "geometry");
    animation->setDuration(100000); // Durée de l'animation en millisecondes
    animation->setStartValue(QRect(positionActuelle.x, positionActuelle.y, 10, 10));
    animation->setEndValue(QRect(arrivee.x, arrivee.y, 10, 10));
    animation->setEasingCurve(QEasingCurve::InOutQuad); // Courbe d'animation pour un mouvement fluide

    // Lancer l'animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Mettre à jour la position actuelle de la personne
    positionActuelle = arrivee;
}

void Personne::DeplacerTranquillement(QLabel *point, Position arrivee, QWidget *parentWidget) {
    // Récupérer la position actuelle du QLabel
    QRect currentGeometry = point->geometry();

    // Étape 1 : Animation pour le déplacement horizontal
    QPropertyAnimation *horizontalAnimation = new QPropertyAnimation(point, "geometry");
    horizontalAnimation->setDuration(10000); // Durée de l'animation
    horizontalAnimation->setStartValue(currentGeometry);
    horizontalAnimation->setEndValue(QRect(arrivee.x, currentGeometry.top(), currentGeometry.width(), currentGeometry.height()));
    horizontalAnimation->setEasingCurve(QEasingCurve::Linear); // Easing linéaire

    // Connecter le signal "finished" de l'animation horizontale pour démarrer l'animation verticale
    QObject::connect(horizontalAnimation, &QPropertyAnimation::finished, [=]() {
        // Mettre à jour la position actuelle après l'animation horizontale
        positionActuelle.x = arrivee.x;

        // Étape 2 : Animation pour le déplacement vertical
        QPropertyAnimation *verticalAnimation = new QPropertyAnimation(point, "geometry");
        verticalAnimation->setDuration(10000); // Durée de l'animation
        verticalAnimation->setStartValue(QRect(arrivee.x, currentGeometry.top(), currentGeometry.width(), currentGeometry.height()));
        verticalAnimation->setEndValue(QRect(arrivee.x, arrivee.y, currentGeometry.width(), currentGeometry.height()));
        verticalAnimation->setEasingCurve(QEasingCurve::Linear); // Easing linéaire

        // Connecter le signal "finished" de l'animation verticale pour finaliser la mise à jour
        QObject::connect(verticalAnimation, &QPropertyAnimation::finished, [=]() {
            // Mettre à jour la position actuelle après l'animation verticale
            positionActuelle.y = arrivee.y;
        });

        // Démarrer l'animation verticale
        verticalAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    // Démarrer l'animation horizontale
    horizontalAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}


void Personne::afficher(QLabel *point, QWidget *parent, int aw) {
    QString textToDisplay;

    if (poste == "Client") {
        textToDisplay = nbPersonne; // Affiche directement le nombre de personnes
    } else {
        // Extraire uniquement les lettres majuscules du poste
        for (const QChar &c : QString::fromStdString(poste)) {
            if (c.isUpper()) {
                textToDisplay.append(c);
            }
        }
    }

    point->setText(textToDisplay); // Afficher le texte filtré
    int pointSize = aw; // Utilise la plus petite dimension pour un cercle
    point->setStyleSheet(QString("background-color: %1; border-radius: %2px; font-size: %3px; color: white; text-align: center;")
                         .arg(QString::fromStdString(couleur))
                         .arg(pointSize / 2)
                         .arg(pointSize / 2)); // Ajuste la taille de la police en fonction de la taille du QLabel
    point->setFixedSize(pointSize, pointSize);
    point->move(positionActuelle.x, positionActuelle.y);
    point->setAlignment(Qt::AlignCenter); // Centrer le texte
    point->show();
}


void Personne::AllerRetour(QLabel *point, Position arrivee, QWidget *parentWidget, int tempsAttente) {
    // Sauvegarder la position initiale
    Position positionInitiale = positionActuelle;

    // Animation pour aller à l'endroit
    QPropertyAnimation *allerAnimation = new QPropertyAnimation(point, "geometry");
    allerAnimation->setDuration(5000); // 5 secondes pour atteindre la destination
    allerAnimation->setStartValue(QRect(positionInitiale.x, positionInitiale.y, point->width(), point->height()));
    allerAnimation->setEndValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
    allerAnimation->setEasingCurve(QEasingCurve::InOutQuad);

    // Une fois l'animation d'aller terminée, attendre 5 secondes avant de revenir
    QObject::connect(allerAnimation, &QPropertyAnimation::finished, [=]() {
        // Attente de 5 secondes
        QTimer::singleShot(tempsAttente, [=]() {
            // Animation pour revenir à la position initiale
            QPropertyAnimation *retourAnimation = new QPropertyAnimation(point, "geometry");
            retourAnimation->setDuration(5000); // 5 secondes pour revenir
            retourAnimation->setStartValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
            retourAnimation->setEndValue(QRect(positionInitiale.x, positionInitiale.y, point->width(), point->height()));
            retourAnimation->setEasingCurve(QEasingCurve::InOutQuad);

            // Mettre à jour la position actuelle après le retour
            QObject::connect(retourAnimation, &QPropertyAnimation::finished, [=]() {
                positionActuelle = positionInitiale;
            });

            // Démarrer l'animation de retour
            retourAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        });
    });

    // Démarrer l'animation d'aller
    allerAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    // Mettre à jour la position actuelle pour l'aller
    positionActuelle = arrivee;
}

// std::vector<Personne> genererClients(int nbrePersonne, int nbreVague) {
//
//     return ;
// }
