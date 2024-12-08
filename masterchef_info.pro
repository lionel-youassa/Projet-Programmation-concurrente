# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = masterchef_info

# Fichiers source
SOURCES += \
Controller/ControleurService.cpp \
    Model/classDefinition/Chef_de_rang.cpp \
    Model/classDefinition/Client.cpp \
    Model/classDefinition/Commande.cpp \
    Model/classDefinition/Commis_de_salle.cpp \
    Model/classDefinition/Maitre_d_hotel.cpp \
    Model/classDefinition/Personne.cpp \
    Model/classDefinition/Plat.cpp \
    Model/classDefinition/Position.cpp \
    Model/classDefinition/Serveur.cpp \
    Model/classDefinition/Table.cpp \
    Model/PostgreSQLConnection.cpp \
    Model/ClassDefinition/Chef_de_rang.cpp \
    Model/ClassDefinition/Client.cpp \
    Model/ClassDefinition/Commande.cpp \
    Model/ClassDefinition/Commis_de_salle.cpp \
    Model/ClassDefinition/Maitre_d_hotel.cpp \
    Model/ClassDefinition/Personne.cpp \
    Model/ClassDefinition/Plat.cpp \
    Model/ClassDefinition/Position.cpp \
    Model/ClassDefinition/Serveur.cpp \
    Model/ClassDefinition/Table.cpp \
    View/formulaire.cpp \
    View/InterfaceAcceuil.cpp \
    View/MainWindow.cpp

# Fichiers header
HEADERS += \
Controller/ControleurService.h \
    Model/classDeclaration/Chef_de_rang.h \
    Model/classDeclaration/Client.h \
    Model/classDeclaration/Commande.h \
    Model/classDeclaration/Commis_de_salle.h \
    Model/classDeclaration/Maitre_d_hotel.h \
    Model/classDeclaration/Personne.h \
    Model/classDeclaration/Plat.h \
    Model/classDeclaration/Position.h \
    Model/classDeclaration/Serveur.h \
    Model/classDeclaration/Table.h \
    Model/PostgreSQLConnection.h \
    Model/ClassDeclaration/Chef_de_rang.h \
    Model/ClassDeclaration/Client.h \
    Model/ClassDeclaration/Commande.h \
    Model/ClassDeclaration/Commis_de_salle.h \
    Model/ClassDeclaration/Maitre_d_hotel.h \
    Model/ClassDeclaration/Personne.h \
    Model/ClassDeclaration/Plat.h \
    Model/ClassDeclaration/Position.h \
    Model/ClassDeclaration/Serveur.h \
    Model/ClassDeclaration/Table.h \
    View/formulaire.h \
    View/InterfaceAcceuil.h \
    View/MainWindow.h

# Ajout des fichiers ressources
RESOURCES += ressources.qrc

# Modules Qt nécessaires
QT += widgets gui

# Configuration spécifique
CONFIG += c++17

# Répertoires d'inclusion
INCLUDEPATH += \
Controller \
    Model \
    Model/ClassDeclaration \
    Model/ClassDefinition \
    Model/classDeclaration \
    Model/classDefinition \
    View
