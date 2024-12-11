//
// Created by lione on 03/12/2024.
//

#include "ControleurService.h"
#include <vector>
using namespace std;
#include "../Model/ClassDeclaration/Personne.h"
#include "../Model/ClassDeclaration/Table.h"


void AssignerClient(std::vector<Table>& mesTables, const Personne& client) {
    for (Table& table : mesTables) {
        // Vérifier si la table est libre et peut accueillir le nombre de personnes du client
        if (table.statut == "libre" && table.nbPlaces >= client.nbPersonne.toInt()) {
            table.AjouterClient(client); // Ajouter le client à la table
            break; // Une fois affecté, on sort de la boucle
        }
    }
}

