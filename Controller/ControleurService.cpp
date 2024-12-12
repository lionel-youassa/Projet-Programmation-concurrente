//
// Created by lione on 03/12/2024.
//

#include "ControleurService.h"
#include <vector>
using namespace std;
#include "../Model/ClassDeclaration/Personne.h"
#include "../Model/ClassDeclaration/Table.h"




void ControleurService::AssignerClient(std::vector<Table>& mesTables, const Personne& client) {
    for (Table& table : mesTables) {
        // Vérifier si la table est libre et peut accueillir le nombre de personnes du client
        if (table.statut == "libre" && table.nbPlaces >= client.nbPersonne.toInt()) {
            table.AjouterClient(client); // Ajouter le client à la table
            break; // Une fois affecté, on sort de la boucle
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
            Position position = Position(300,1600);

            // Générer une couleur aléatoire
            char couleurHex[7];
            std::snprintf(couleurHex, sizeof(couleurHex), "#%06X", std::rand() % 0xFFFFFF);
            std::string couleur = couleurHex;

            // Créer un client et l'ajouter à la liste
            Personne client(id, nom, poste, disponibilite, position, couleur, QString::number(nbreDansVague));
            clients.push_back(client);
        }
    }

    return clients;
}



