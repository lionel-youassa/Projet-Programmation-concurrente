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

void Personne::DeplacerTranquillement(QLabel *point, Position arrivee, QWidget *parentWidget, int vitesse) {
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
        verticalAnimation->setDuration(vitesse); // Durée de l'animation
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


void Personne::afficher(QLabel *point, QWidget *parent, int aw) const {
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


void Personne::AllerRetour(QLabel *point, Position arrivee, QWidget *parentWidget, int tempsAttente, int vitesse) {
    // Sauvegarder la position initiale
    Position positionInitiale = positionActuelle;

    // Calculer la distance entre la position initiale et la destination
    double distanceAller = std::sqrt(
        std::pow(arrivee.x - positionInitiale.x, 2) +
        std::pow(arrivee.y - positionInitiale.y, 2)
    );

    // Calculer la durée de l'animation en fonction de la vitesse (durée = distance / vitesse)
    int dureeAller = static_cast<int>((distanceAller / vitesse) * 1000); // Durée en millisecondes

    // Animation pour aller à l'endroit
    QPropertyAnimation *allerAnimation = new QPropertyAnimation(point, "geometry");
    allerAnimation->setDuration(dureeAller);
    allerAnimation->setStartValue(QRect(positionInitiale.x, positionInitiale.y, point->width(), point->height()));
    allerAnimation->setEndValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
    allerAnimation->setEasingCurve(QEasingCurve::InOutQuad);

    // Une fois l'animation d'aller terminée, attendre un certain temps avant de revenir
    QObject::connect(allerAnimation, &QPropertyAnimation::finished, [=]() {
        // Attente avant le retour
        QTimer::singleShot(tempsAttente, [=]() {
            // Calculer la distance pour le retour (identique à l'aller)
            double distanceRetour = distanceAller;

            // Calculer la durée de l'animation de retour
            int dureeRetour = static_cast<int>((distanceRetour / vitesse) * 1000);

            // Animation pour revenir à la position initiale
            QPropertyAnimation *retourAnimation = new QPropertyAnimation(point, "geometry");
            retourAnimation->setDuration(dureeRetour);
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

#include <vector>
#include <cstdlib> // Pour std::rand et std::srand
#include <ctime>   // Pour std::time

void Personne::DeplacementAvecAcceleration(QLabel *point, Position arrivee, QWidget *parentWidget, int vitesseInitiale, int tempsAcceleration, int vitesseFinale) {
    // Calculer la distance totale
    double distanceTotale = std::sqrt(
        std::pow(arrivee.x - positionActuelle.x, 2) +
        std::pow(arrivee.y - positionActuelle.y, 2)
    );

    // Calculer les proportions de distance pour chaque phase
    double distancePhase1 = (vitesseInitiale * tempsAcceleration) / 1000.0; // distance = vitesse * temps
    distancePhase1 = std::min(distancePhase1, distanceTotale); // Limiter à la distance totale

    // Calculer la position intermédiaire pour la première phase
    double ratioPhase1 = distancePhase1 / distanceTotale;
    Position positionPhase1 = {
        static_cast<float>(static_cast<int>(positionActuelle.x + ratioPhase1 * (arrivee.x - positionActuelle.x))),
        static_cast<float>(static_cast<int>(positionActuelle.y + ratioPhase1 * (arrivee.y - positionActuelle.y)))
    };

    // Phase 1 : Déplacement initial avec vitesseInitiale
    QPropertyAnimation *phase1Animation = new QPropertyAnimation(point, "geometry");
    phase1Animation->setDuration(static_cast<int>((distancePhase1 / vitesseInitiale) * 1000));
    phase1Animation->setStartValue(QRect(positionActuelle.x, positionActuelle.y, point->width(), point->height()));
    phase1Animation->setEndValue(QRect(positionPhase1.x, positionPhase1.y, point->width(), point->height()));
    phase1Animation->setEasingCurve(QEasingCurve::InOutQuad);

    // Phase 2 : Déplacement accéléré avec vitesseFinale
    QObject::connect(phase1Animation, &QPropertyAnimation::finished, [=]() {
        double distancePhase2 = distanceTotale - distancePhase1;

        QPropertyAnimation *phase2Animation = new QPropertyAnimation(point, "geometry");
        phase2Animation->setDuration(static_cast<int>((distancePhase2 / vitesseFinale) * 1000));
        phase2Animation->setStartValue(QRect(positionPhase1.x, positionPhase1.y, point->width(), point->height()));
        phase2Animation->setEndValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
        phase2Animation->setEasingCurve(QEasingCurve::InOutQuad);

        // Mettre à jour la position après la phase 2
        QObject::connect(phase2Animation, &QPropertyAnimation::finished, [=]() {
            positionActuelle = arrivee;
        });

        // Démarrer la phase 2
        phase2Animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    // Démarrer la phase 1
    phase1Animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Mettre à jour la position pour la phase 1
    positionActuelle = positionPhase1;
}


void DeplacerJuskaTable(QLabel *point, Position arrivee, QWidget *parentWidget) {

}

void Personne::DeplacementAvecAccelerationAllerRetour(QLabel *point, Position arrivee, Position positionRetour, QWidget *parentWidget, int vitesseInitiale, int tempsAcceleration, int vitesseFinale, int tempsAttente) {
    // Calculer la distance totale
    double distanceTotale = std::sqrt(
        std::pow(arrivee.x - positionActuelle.x, 2) +
        std::pow(arrivee.y - positionActuelle.y, 2)
    );

    // Calculer les proportions de distance pour chaque phase
    double distancePhase1 = (vitesseInitiale * tempsAcceleration) / 1000.0; // distance = vitesse * temps
    distancePhase1 = std::min(distancePhase1, distanceTotale); // Limiter à la distance totale

    // Calculer la position intermédiaire pour la première phase
    double ratioPhase1 = distancePhase1 / distanceTotale;
    Position positionPhase1 = {
        static_cast<float>(static_cast<int>(positionActuelle.x + ratioPhase1 * (arrivee.x - positionActuelle.x))),
        static_cast<float>(static_cast<int>(positionActuelle.y + ratioPhase1 * (arrivee.y - positionActuelle.y)))
    };

    // Phase 1 : Déplacement initial avec vitesseInitiale
    QPropertyAnimation *phase1Animation = new QPropertyAnimation(point, "geometry");
    phase1Animation->setDuration(static_cast<int>((distancePhase1 / vitesseInitiale) * 1000));
    phase1Animation->setStartValue(QRect(positionActuelle.x, positionActuelle.y, point->width(), point->height()));
    phase1Animation->setEndValue(QRect(positionPhase1.x, positionPhase1.y, point->width(), point->height()));
    phase1Animation->setEasingCurve(QEasingCurve::InOutQuad);

    // Phase 2 : Déplacement accéléré avec vitesseFinale
    QObject::connect(phase1Animation, &QPropertyAnimation::finished, [=]() {
        double distancePhase2 = distanceTotale - distancePhase1;

        QPropertyAnimation *phase2Animation = new QPropertyAnimation(point, "geometry");
        phase2Animation->setDuration(static_cast<int>((distancePhase2 / vitesseFinale) * 1000));
        phase2Animation->setStartValue(QRect(positionPhase1.x, positionPhase1.y, point->width(), point->height()));
        phase2Animation->setEndValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
        phase2Animation->setEasingCurve(QEasingCurve::InOutQuad);

        // Une fois la phase 2 terminée, attendre avant de revenir
        QObject::connect(phase2Animation, &QPropertyAnimation::finished, [=]() {
            QTimer::singleShot(tempsAttente, [=]() {
                // Phase de retour : Calcul de la distance et de la durée du retour
                double distanceRetour = std::sqrt(
                    std::pow(positionRetour.x - arrivee.x, 2) +
                    std::pow(positionRetour.y - arrivee.y, 2)
                );

                // Animation pour revenir à la position de retour
                QPropertyAnimation *retourAnimation = new QPropertyAnimation(point, "geometry");
                retourAnimation->setDuration(static_cast<int>((distanceRetour / vitesseFinale) * 1000));
                retourAnimation->setStartValue(QRect(arrivee.x, arrivee.y, point->width(), point->height()));
                retourAnimation->setEndValue(QRect(positionRetour.x, positionRetour.y, point->width(), point->height()));
                retourAnimation->setEasingCurve(QEasingCurve::InOutQuad);

                // Une fois la phase de retour terminée, mettre à jour la position
                QObject::connect(retourAnimation, &QPropertyAnimation::finished, [=]() {
                    positionActuelle = positionRetour;  // Mise à jour de la position finale après le retour
                    // Vous pouvez aussi appeler ici un signal ou méthode pour notifier que le déplacement est terminé
                });

                retourAnimation->start(QAbstractAnimation::DeleteWhenStopped);
            });
        });

        // Démarrer la phase 2 (accélération finale)
        phase2Animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    // Démarrer la phase 1 (déplacement initial)
    phase1Animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Mettre à jour la position pour la phase 1
    positionActuelle = positionPhase1;
}
