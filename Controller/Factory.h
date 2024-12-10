//
// Created by lione on 10/12/2024.
//

#ifndef FACTORY_H
#define FACTORY_H
#include <vector>

#include "../Model/ClassDeclaration/Table.h"


class Factory {
public:
    void creaTable();

    std::vector<Table> get_table_();

    std::vector<Table> tables;


};



#endif //FACTORY_H
