#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QList>

// Structure pour représenter un plat avec son image
struct Dish {
    QString name;     // Nom du plat
    QString imagePath; // Chemin de l'image associée
};

class MenuWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);

    // Méthode pour afficher une liste de plats avec leurs images
    void displayMenu(const QList<Dish> &dishes);

private:
    QLabel *menuTitleLabel;   // Titre de la fenêtre
    QGridLayout *menuLayout;  // Layout pour afficher le menu
    QPushButton *closeButton; // Bouton pour rafraîchir l'affichage
};

#endif // MENUWINDOW_H
