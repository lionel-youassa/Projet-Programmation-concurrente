-- Database: ProgrammationConcourrente

-- DROP DATABASE IF EXISTS "ProgrammationConcourrente";

CREATE DATABASE "ProgrammationConcourrente"
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'fr_FR.UTF-8'
    LC_CTYPE = 'fr_FR.UTF-8'
    CONNECTION LIMIT = -1;



-- Création des types ENUM
CREATE TYPE etat_table AS ENUM ('Libre', 'Occupée', 'En Nettoyage');
CREATE TYPE statut_commande AS ENUM ('En cours', 'Servie', 'Pret');
CREATE TYPE categorie_plat AS ENUM ('Entrée', 'Plat principal', 'Dessert');
CREATE TYPE etat_ustensile AS ENUM ('Propre', 'Sale');
CREATE TYPE type_machine AS ENUM ('Lave-vaisselle', 'Machine à laver');
CREATE TYPE etat_machine AS ENUM ('Disponible', 'En cours', 'En attente');

-- Table Personnel
CREATE TABLE Personnel (
    id_personnel SERIAL PRIMARY KEY,
    nom VARCHAR(50) NOT NULL,
    poste VARCHAR(50) NOT NULL,
    disponibilite BOOLEAN DEFAULT TRUE
);

-- Table Carré
CREATE TABLE Carre (
    id_carre SERIAL PRIMARY KEY,
    nom_carre VARCHAR(50) NOT NULL
);

-- Table Rang
CREATE TABLE Rang (
    id_rang SERIAL PRIMARY KEY,
    id_carre INT NOT NULL REFERENCES Carre(id_carre)
);

-- Table pour associer Chef de Rang et Carré
CREATE TABLE ChefDeRang_Carre (
    id_carre INT NOT NULL REFERENCES Carre(id_carre),
    id_personnel INT NOT NULL REFERENCES Personnel(id_personnel),
    PRIMARY KEY (id_carre, id_personnel)
);

-- Table Table_Restaurant
CREATE TABLE Table_Restaurant (
    id_table SERIAL PRIMARY KEY,
    capacite INT NOT NULL,
    etat etat_table NOT NULL DEFAULT 'Libre',
    id_rang INT NOT NULL REFERENCES Rang(id_rang)
);

-- Table Commande
CREATE TABLE Commande (
    id_commande SERIAL PRIMARY KEY,
    id_table INT NOT NULL REFERENCES Table_Restaurant(id_table),
    date_commande TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    statut statut_commande NOT NULL DEFAULT 'En cours',
    montant_total DECIMAL(10, 2) NOT NULL
);

-- Table Plat
CREATE TABLE Plat (
    id_plat SERIAL PRIMARY KEY,
    nom_plat VARCHAR(100) NOT NULL,
    categorie categorie_plat NOT NULL,
    temps_preparation INT NOT NULL, -- Temps en secondes
    ingredients TEXT,
    prix DECIMAL(10, 2) NOT NULL
);

-- Table Contenu_Commande (association entre Commande et Plat)
CREATE TABLE Contenu_Commande (
    id_contenu SERIAL PRIMARY KEY,
    id_commande INT NOT NULL REFERENCES Commande(id_commande),
    id_plat INT NOT NULL REFERENCES Plat(id_plat),
    quantite INT NOT NULL
);

-- Table StockIngredient
CREATE TABLE StockIngredient (
    id_produit SERIAL PRIMARY KEY,
    nom_produit VARCHAR(100) NOT NULL,
    categorie VARCHAR(100) NOT NULL,
    quantite_disponible INT NOT NULL
);

-- Table Ustensile
CREATE TABLE Ustensile (
    id_ustensile SERIAL PRIMARY KEY,
    nom_ustensile VARCHAR(50) NOT NULL,
    quantite_total INT NOT NULL,
    quantite_disponible INT NOT NULL,
    etat etat_ustensile NOT NULL DEFAULT 'Propre',
    temps_lavage INT NOT NULL DEFAULT 0
);

-- Table Plat_Ustensile (association entre Plat et Ustensile)
CREATE TABLE Plat_Ustensile (
    id_plat INT NOT NULL REFERENCES Plat(id_plat),
    id_ustensile INT NOT NULL REFERENCES Ustensile(id_ustensile),
    PRIMARY KEY (id_plat, id_ustensile)
);

-- Table Machine
CREATE TABLE Machine (
    id_machine SERIAL PRIMARY KEY,
    type_machine type_machine NOT NULL,
    capacite_max INT NOT NULL,
    etat etat_machine NOT NULL DEFAULT 'Disponible',
    temps_restant INT DEFAULT 0,
    date_dernier_lavage TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
