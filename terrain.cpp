/*
  ---------------------------------------------------------------------------
  Fichier     : terrain.cpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Définition de la classe Robot.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include <vector>
#include <string>
#include <iostream>
#include "terrain.hpp"
#include "saisie.hpp"
#include "aleatoire.hpp"

using namespace std;

void Terrain::simulerCombat() {


}

void Terrain::afficherTerrain() {
   const char MUR_HAUT = '-';
   const char MUR_COTE = '|';
   string terrain;

   // Première ligne
   for(unsigned i = 0; i <= Terrain::largeur; i++) {
      terrain.append(1, MUR_HAUT);
   }

   cout << terrain;

}

void Terrain::initialiserRobot() {
   vector<Robot> robots;
   const int min = 1;

   for (unsigned i = 0; i < Terrain::nombreRobots; ++i) {
      unsigned x = (unsigned)aleatoireEntreDeuxEntiers(min, (int)getX());
      unsigned y = (unsigned)aleatoireEntreDeuxEntiers(min, (int)getY());
      robots.push_back(Robot(x, y, i));
   }

}

unsigned Terrain::getX() const {
   return largeur;
}

unsigned Terrain::getY() const {
   return longeur;
}
