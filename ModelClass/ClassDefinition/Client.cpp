#include "../classDeclaration/Client.h"
#include "../classDeclaration/Plat.h"

Client::Client(int id, const std::string& type) : id(id), type(type) {}

void Client::Commander(Menu& menu) {
    // Logique pour commander un menu
}
