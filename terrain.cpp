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
#include "terrain.hpp"
#include "saisie.hpp"
#include "aleatoire.hpp"

using namespace std;

const char VIDE     = ' ';

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

         robotTue += "Robot "s + to_string(id) + " a tué robot "s + to_string(robot
            .getId()) + "\n";

      }
   }

}

void Terrain::deplacerRobot(unsigned& x, unsigned& y, Robot& monRobot) {

   enum direction{UP, DOWN, RIGHT, LEFT };
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

   if(existeDeja(x, y)){
      eliminerRobot(x,y, monRobot.getId());
   }
   monRobot.deplacer(x,y);
}
unsigned Terrain::combatRobots(){

   random_shuffle(robots.begin(), robots.end());
   //random_shuffle trop vieux. Il faudrait utiliser le shuffle ci-dessous.
   //shuffle(robots.begin(), robots.end(), std::mt19937(std::random_device()()));

      unsigned nbrDeRobots = 0;

//   for(vector<Robot>::iterator it = robots.begin(); it != robots.end(); ++it)
      for(Robot& robot : robots) {

         unsigned x;
         unsigned y;

         if(robot.getEstEnVie()){
            
            deplacerRobot(x, y, robot);

            ++nbrDeRobots;
         }
         
      }

      return nbrDeRobots;

}
void Terrain::simulerCombat() {

   constructionTerrain();

   unsigned nbrDeRobots;

   do{
      
      nbrDeRobots = combatRobots();
      afficherTerrain();

   }while(nbrDeRobots != 1 && nbrDeRobots > 0);

}

void Terrain::constructionTerrain(){

   // + 2, car on souhaite un terrain qui soit effectivement d'une largeur de 20, or
   // les murs prennent chacun une place.
   // Pour la longueur, nous faisons que +1, parce qu'on commence la boucle à 1.


   const char MUR_HAUT = '-';
   const char MUR_COTE = '|';

   const unsigned largeurTerrainAffichee = largeur + 2;
   const unsigned longeurTerrainAffichee = longeur + 1;
   terrain.reserve(longeurTerrainAffichee);

   const string ESPACE_LIBRE (largeur, VIDE);

   string haut_bas(largeurTerrainAffichee, MUR_HAUT);
   haut_bas.append(1, '\n');

   string milieu(1, MUR_COTE);
   milieu.append(ESPACE_LIBRE);
   milieu.append(1, MUR_COTE);
   milieu.append(1, '\n');

   terrain.push_back(haut_bas);

   for(unsigned i = 0; i < longeur; ++i){
      terrain.push_back(milieu);
   }
   terrain.push_back(haut_bas);

}

void Terrain::mettreAJour(){
   const string ESPACE_LIBRE (largeur, VIDE);

   for(unsigned i = 1 ; i <= longeur; ++i){
      terrain.at(i).replace(1, largeur , ESPACE_LIBRE);
   }
//   for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it)
   for(Robot monRobot : robots) {
      if(monRobot.getEstEnVie()){
         terrain.at(monRobot.getPosY()).replace(monRobot.getPosX(), 1, to_string(monRobot.getId()));
      }
   }
}

void Terrain::afficherTerrain() {
   #if defined(__linux__)  // Or #if __linux__
      system("clear");
   #elif _WIN32
      system("CLS");
   #else
      system("clear");
   #endif

   mettreAJour();
//   for(vector<string>::const_iterator it = terrain.cbegin() ; it != terrain.cend(); ++it)
   for(const string& it : terrain){
      cout << it;
   }

   cout << robotTue;

   this_thread::sleep_for(100ms);
}

void Terrain::initialiserRobot() {
   const int min = 1;

   unsigned x;
   unsigned y;

   for (unsigned i = 1; i <= Terrain::nombreRobots; ++i) {
      do {
         x= aleatoireEntreDeuxEntiersPositifs(min, getlargeur());
         y = aleatoireEntreDeuxEntiersPositifs(min, getLongeur());
      }while(existeDeja(x, y));
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