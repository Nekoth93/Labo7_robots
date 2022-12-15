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
#include <algorithm>
#include "terrain.hpp"
#include "saisie.hpp"
#include "aleatoire.hpp"

using namespace std;

void Terrain::simulerCombat() {



}

void Terrain::afficherTerrain() {
   const char MUR_HAUT = '-';
   const char MUR_COTE = '|';
   const char VIDE     = ' ';

    // + 2, car on souhaite un terrain qui soit effectivement d'une largeur de 20, or
    // les murs prennent chacun une place.
    // Pour la longueur, nous faisons que +1, parce qu'on commence la boucle à 1.
   const unsigned largeurTerrainAffichee = largeur + 2;
   const unsigned longeurTerrainAffichee = longeur + 1;

   const string ESPACE_LIBRE (largeur, VIDE);

   string terrain (largeurTerrainAffichee, MUR_HAUT);
   terrain.append("\n");
   for(size_t i = 1; i <= longeurTerrainAffichee; ++i) {
      terrain.append(1, MUR_COTE);
      terrain.append(ESPACE_LIBRE);
      terrain.append(1, MUR_COTE);
      terrain.append("\n");
   }
   terrain.append(largeurTerrainAffichee, MUR_HAUT);

   cout << terrain;

}

vector<Robot> Terrain::initialiserRobot() {
   vector<Robot> robots;
   const int min = 1;

   unsigned x;
   unsigned y;

   for (unsigned i = 0; i < Terrain::nombreRobots; ++i) {
      do {
         x= aleatoireEntreDeuxEntiersPositifs(min, getlargeur());
         y = aleatoireEntreDeuxEntiersPositifs(min, getLongeur());
      }while(existeDeja(robots, x, y));
      robots.emplace_back(x, y, i);
   }

   return robots;
}

unsigned Terrain::getlargeur() const {
   return largeur;
}

unsigned Terrain::getLongeur() const {
   return longeur;
}
// à revoir en foncteur (selon indication du prof)
bool Terrain::existeDeja(const vector<Robot>& robots, unsigned x, unsigned y) {
   for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it) {
      Robot monRobot = *it;

      if(monRobot.getPosX() == x and monRobot.getPosY() == y) {
         return true;
      }
   }

   return false;
}
