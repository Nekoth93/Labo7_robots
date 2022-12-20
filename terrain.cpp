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

#include <random>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <iomanip>
#include "terrain.hpp"
#include "saisie.hpp"
#include "aleatoire.hpp"

using namespace std;

/// @brief vérifie si la première valeur d'un tableaux est plus grande que l'autre
/// @param a premier tableau
/// @param b second tableau
/// @return si une est plus grande que l'autre
bool trierIntVector(vector<unsigned> a, vector<unsigned> b){
   return (a.at(0) < b.at(0));
}

bool Terrain::peutSeDeplacer(unsigned x, unsigned y) const {
   
   if(x > largeur || y > longeur || x == 0 || y == 0) {
      return true;
   }
   return false;
}

void Terrain::eliminerRobot(unsigned x, unsigned y, unsigned id) {

//   for(vector<Robot>::iterator it = robots.begin(); it != robots.end(); ++it)
   for(Robot& robot : robots) {
      if(robot.getPosX() == x && robot.getPosY() == y && robot.getEstEnVie()) {

         robot.tuer();

         robotTue += " -> Robot "s + to_string(id) + " a tué robot "s + to_string(robot.getId()) + "\n";

      }
   }

}

void Terrain::deplacerRobot(Robot& monRobot) {


   unsigned x;
   unsigned y;

   enum direction{ UP, DOWN, RIGHT, LEFT };
   do {
            
            switch(aleatoireEntreDeuxEntiersPositifs(0,3)){
               case direction::UP :
                  x =   monRobot.getPosX();
                  y =   monRobot.getPosY()+1;
                  break;
               case direction::DOWN :
                  x =   monRobot.getPosX();
                  y =   monRobot.getPosY()-1;
                  break;
               case direction::RIGHT :
                  x =   monRobot.getPosX()+1;
                  y =   monRobot.getPosY();
                  break;
               case direction::LEFT :
                  x =   monRobot.getPosX()-1;
                  y =   monRobot.getPosY();
            }

   }while(peutSeDeplacer(x,y));

   if(existeDeja(x, y)) {
      eliminerRobot(x,y, monRobot.getId());
   }
   monRobot.deplacer(x,y);
}
unsigned Terrain::combatRobots() {


   // Le générateur aléatoire ci-dessous est celui que notre IDE nous à suggérer.
   // Il est possible d'en choisir un autre si on en préfère un en particulier.
   shuffle(robots.begin(), robots.end(), std::mt19937(std::random_device()()));

      unsigned nbrDeRobots = 0;

      for(Robot& robot : robots) {

         if(robot.getEstEnVie()){
            
            deplacerRobot(robot);

            ++nbrDeRobots;
         }
         
      }

      return nbrDeRobots;

}
void Terrain::simulerCombat() {

   unsigned nbrDeRobotsVivants;

   do{
      
      nbrDeRobotsVivants = combatRobots();
      afficherTerrain();

   }while(nbrDeRobotsVivants != 1 && nbrDeRobotsVivants > 0);

}


void Terrain::afficherTerrain() {
   #if defined(__linux__)  // Or #if __linux__
      system("clear");
   #elif _WIN32
      system("CLS");
   #else
      system("clear");
   #endif


   const unsigned largeurTerrainAffichee = largeur + 2;
   const unsigned largeurTerrainEspace   = largeur + 1;
   const unsigned longeurTerrainAffichee = longeur + 1;

   const string TITRE_DU_JEU = "Robot battle simulator©\n";

   const char MUR_HAUT = '-';
   const char MUR_COTE = '|';

   string haut_bas(largeurTerrainAffichee, MUR_HAUT);
   haut_bas.append(1, '\n');

   vector<vector<unsigned>> robotQuiSontAY;

   cout << TITRE_DU_JEU;

   cout << haut_bas;

   for(int i = 1 ; i <= longeur; ++i){

      unsigned decalage = 0;

      postionsRobotsAY( robotQuiSontAY, i );

      cout << MUR_COTE;

      for( vector<unsigned> j : robotQuiSontAY ){

         cout << right << setw( j.at(0)-decalage ) << j.at(1);

         decalage = j.at(0);
      }

      cout << right << setw( largeurTerrainEspace - decalage) << MUR_COTE << endl;
   }

   cout << haut_bas;

   cout << robotTue;

   this_thread::sleep_for(100ms);
}
void Terrain::postionsRobotsAY( vector<vector<unsigned>>& robotsAY, unsigned y ){

   robotsAY.clear();

   robotsAY.reserve(nombreRobots);


   for( Robot robot : robots ){
      if( robot.getPosY() == y && robot.getEstEnVie() ){

         robotsAY.push_back({ robot.getPosX(), robot.getId() });

      }
   }

   stable_sort(robotsAY.begin(), robotsAY.end(), trierIntVector);

}

void Terrain::initialiserRobot() {

   const int min = 1;

   unsigned x;
   unsigned y;

   for ( unsigned i = 1; i <= Terrain::nombreRobots; ++i ) {
      do {

         x = aleatoireEntreDeuxEntiersPositifs(min, getlargeur());
         y = aleatoireEntreDeuxEntiersPositifs(min, getLongeur());

      }while( existeDeja(x, y) );
      robots.emplace_back(x, y, i, true);
   }
}

unsigned Terrain::getlargeur() const {
   return largeur;
}

unsigned Terrain::getLongeur() const {
   return longeur;
}
// à revoir en foncteur (selon indication du prof)
bool Terrain::existeDeja( unsigned x, unsigned y) {
//   for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it)
   for(Robot monRobot : robots) {
      if(monRobot.getPosX() == x and monRobot.getPosY() == y) {
         return true;
      }
   }

   return false;
}