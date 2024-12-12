#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <vector>
#include "../PostgreSQLConnection.h"

class Plat {
public:
    int id;                          // Identifiant unique du plat
    std::string nom;                 // Nom du plat
    std::string categorie;           // Catégorie du plat (Entrée, Plat, Dessert, etc.)
    double prix;                     // Prix du plat
    int tempsPreparation;            // Temps de préparation en minutes
    bool estDisponible;              // Indique si le plat est disponible
    std::string imagePath;

    struct Dish {
    QString description;
    QString imagePath;
        Dish();

    Dish(const QString & chars, const QString & string);
    };


    // Constructeur
     Plat();
    Plat(int id, const std::string& nom, const std::string& categorie,
         double prix, int tempsPreparation, bool estDisponible = true, const std::string& imagePath="");

    // Méthode pour vérifier la disponibilité du plat
    void verifierDisponible();

    // Méthode statique pour récupérer tous les plats depuis la base de données
    static std::vector<Plat> getPlat(PostgreSQLConnection* PostgreSQLConnection);

    // Méthode statique pour afficher une liste de plats sur le terminal
    static void afficherPlats(const std::vector<Plat>& plats);

    // Nouvelle méthode pour sélectionner des plats au hasard
    static QList<Plat::Dish>creerListeDishParCategorie(const std::vector<Plat> &plats);
};

#endif // PLAT_H
