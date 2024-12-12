//
// Created by lione on 03/12/2024.
//


#ifndef CONTROLEURSERVICE_H
#define CONTROLEURSERVICE_H
#include "../Model/ClassDeclaration/Personne.h"
#include "../Model/ClassDeclaration/Table.h"


class ControleurService {
public:
    static void AssignerClient(std::vector<Table>& mesTables, const Personne& client);
    static std::vector<Personne> genererClients(int nbrePersonne, int nbreVague);

};



#endif //CONTROLEURSERVICE_H
