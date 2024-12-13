//
// Created by lione on 03/12/2024.
//

#include "ControleurService.h"
#include <vector>
using namespace std;
#include "../Model/ClassDeclaration/Personne.h"
#include "../Model/ClassDeclaration/Table.h"


Table ControleurService::AssignerClient(std::vector<Table> &mesTables, const Personne &client) {
    for (Table& table : mesTables) {
        // Vérifier si la table est libre et peut accueillir le nombre de personnes du client
        if (table.statut == "libre" && table.nbPlaces >= client.nbPersonne.toInt()) {
            table.AjouterClient(client); // Ajouter le client à la table
            return table;

        }
    }
}

std::vector<Personne> ControleurService::genererClients(int nbrePersonne, int nbreVague) {
    std::vector<Personne> clients;
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Initialiser le générateur aléatoire

    int totalRestant = nbrePersonne; // Nombre de personnes restant à répartir

    // Générer les vagues
    for (int vague = 0; vague < nbreVague; ++vague) {
        // Calculer un nombre aléatoire de personnes pour cette vague
        int nbreDansVague;
        if (vague == nbreVague - 1) {
            // Dernière vague : assignez toutes les personnes restantes
            nbreDansVague = totalRestant;
        } else {
            // Générer un nombre aléatoire entre 1 et le nombre restant moins le nombre minimum nécessaire pour les vagues restantes
            nbreDansVague = std::rand() % (totalRestant - (nbreVague - vague - 1)) + 1;
        }

        totalRestant -= nbreDansVague;

        // Créer les clients pour cette vague
        for (int i = 0; i < nbreDansVague; ++i) {
            int id = vague * nbrePersonne + i + 1;
            std::string nom = "Client_" + std::to_string(id);
            std::string poste = "Client";
            bool disponibilite = true;

            // Générer une position aléatoire
            Position position = Position(80,1600);


            // Créer un client et l'ajouter à la liste
            Personne client(id, nom, poste, disponibilite, position, "red", QString::number(nbreDansVague));
            clients.push_back(client);
        }
    }

    return clients;
}

#include <vector>
#include <QLabel>
#include <QWidget>

std::vector<QLabel*> ControleurService::genererPoints(int nbreVague, QWidget* parentWidget) {
    // Créer un vecteur pour stocker les QLabel
    std::vector<QLabel*> points;

    // Boucle pour générer les QLabel
    for (int i = 0; i < nbreVague; ++i) {
        // Créer un QLabel dynamique
        QLabel* point = new QLabel(parentWidget);

        // Configurer le QLabel
        point->setFixedSize(20, 20); // Taille de 20x20 pixels
        point->setStyleSheet("background-color: red; border-radius: 10px;"); // Apparence
        point->move(50 + i * 30, 50); // Position initiale (modifiez selon vos besoins)

        // Ajouter au parentWidget si nécessaire
        point->setParent(parentWidget);
        point->show();

        // Ajouter le QLabel au vecteur
        points.push_back(point);
    }

    // Retourner le vecteur contenant les QLabel
    return points;
}


