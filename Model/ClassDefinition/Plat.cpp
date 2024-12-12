#include "../ClassDeclaration/Plat.h"
#include <libpq-fe.h>
#include <iostream>
#include <vector>
#include <random>
#include <QString> // Assurez-vous d'inclure la bibliothèque Qt

// Constructeur de la classe Plat mis à jour avec imagePath
Plat::Plat(int id, const std::string& nom, const std::string& categorie, double prix, int tempsPreparation, bool estDisponible, const std::string& imagePath)
    : id(id), nom(nom), categorie(categorie), prix(prix), tempsPreparation(tempsPreparation), estDisponible(estDisponible), imagePath(imagePath) {}

Plat::Plat() {}

// Plat.cpp ou Dish.cpp
Plat::Dish::Dish(const QString& param1, const QString& param2) {
    // Implémentation ici
}




void Plat::verifierDisponible() {
    // Logique pour vérifier la disponibilité (exemple simple)
    estDisponible = true; // Peut être remplacé par une logique plus complexe
}

std::vector<Plat> Plat::getPlat(PostgreSQLConnection* PostgreSQLConnection) {
    std::vector<Plat> plats;

    // Connexion à la base de données
    PGconn *conn = PostgreSQLConnection->getConnection();
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Erreur de connexion à la base de données : " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return plats;
    }

    // Requête SQL pour récupérer les plats, incluant image_path
    const char *query = "SELECT id_plat, nom_plat, categorie, temps_preparation, ingredients, prix, image_path FROM public.plat";
    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "Erreur lors de l'exécution de la requête : " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return plats;
    }

    // Parcourir les résultats
    int rows = PQntuples(res);
    for (int i = 0; i < rows; ++i) {
        int id = std::stoi(PQgetvalue(res, i, 0));
        std::string nom = PQgetvalue(res, i, 1);
        std::string categorie = PQgetvalue(res, i, 2);
        int tempsPreparation = std::stoi(PQgetvalue(res, i, 3));
        std::string ingredients = PQgetvalue(res, i, 4); // Vous pouvez l'utiliser si nécessaire
        double prix = std::stod(PQgetvalue(res, i, 5));
        std::string imagePath = PQgetvalue(res, i, 6); // Récupération du chemin de l'image
        bool estDisponible = true; // Peut être calculé ou défini dynamiquement

        // Ajout du plat avec l'image
        plats.emplace_back(id, nom, categorie, prix, tempsPreparation, estDisponible, imagePath);
    }

    // Libérer les ressources
    PQclear(res);
    PQfinish(conn);

    return plats;
}

// Méthode pour afficher les plats (non modifiée)
void Plat::afficherPlats(const std::vector<Plat>& plats) {
    std::cout << std::left << std::setw(5)  << "ID"
              << std::setw(20) << "Nom"
              << std::setw(15) << "Catégorie"
              << std::setw(10) << "Prix (€)"
              << std::setw(20) << "Temps Préparation (min)"
              << std::setw(15) << "Disponibilité" << std::endl;
    std::cout << std::string(85, '-') << std::endl;

    for (const auto& plat : plats) {
        std::cout << std::left << std::setw(5)  << plat.id
                  << std::setw(20) << plat.nom
                  << std::setw(15) << plat.categorie
                  << std::setw(10) << std::fixed << std::setprecision(2) << plat.prix
                  << std::setw(20) << plat.tempsPreparation
                  << std::setw(15) << (plat.estDisponible ? "Disponible" : "Indisponible")
                  << std::endl;
    }
}

void afficherResultats(const QList<Plat::Dish>& resultats) {
    for (const auto& dish : resultats) {
        qDebug() << "Nom du plat :" << dish.description;
        qDebug() << "Chemin de l'image :" << dish.imagePath;
    }
}


QList<Plat::Dish> Plat::creerListeDishParCategorie(const std::vector<Plat> &plats) {
    QMap<QString, Plat> platsParCategorie;

    // Organiser les plats par catégorie (un seul plat par catégorie)
    for (const auto &plat : plats) {
        QString categorie = QString::fromStdString(plat.categorie);
        if (!categorie.isEmpty() && !platsParCategorie.contains(categorie)) {
            platsParCategorie[categorie] = plat;
        }
    }

    // Configurer l'ordre des catégories
    QStringList ordreCategories = {"Entrée", "Dessert", "Plat"};
    QList<Dish> resultats;

    // Ajouter les plats dans l'ordre des catégories
    for (const auto &categorie : ordreCategories) {
        if (platsParCategorie.contains(categorie)) {
            const auto &platSelectionne = platsParCategorie[categorie];
            QString nomPlat = QString::fromStdString(platSelectionne.nom);
            QString cheminImage = QString::fromStdString("../images/" + platSelectionne.imagePath);

            // Vérifications
            if (nomPlat.isEmpty()) {
                qWarning() << "Nom de plat manquant pour la catégorie :" << categorie;
                nomPlat = "Plat inconnu";
            }

            if (cheminImage.isEmpty() || cheminImage.endsWith("../images/")) {
                qWarning() << "Chemin de l'image manquant ou incorrect pour le plat :" << nomPlat;
                cheminImage = "../images/default.jpg"; // Utiliser une image par défaut
            }

            // Ajouter le plat à la liste des résultats
            resultats.append(Dish(nomPlat, cheminImage));
        } else {
            qWarning() << "Aucun plat disponible pour la catégorie :" << categorie;
        }
    }

    return resultats;
}

