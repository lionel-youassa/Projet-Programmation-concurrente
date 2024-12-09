#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Menu.h"

class Client {
public:
    Client(int id, const std::string& type);
    void Commander(Menu& menu);

private:
    int id;
    std::string type;
};

#endif // CLIENT_H
