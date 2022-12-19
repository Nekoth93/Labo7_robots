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
#include <thread>
#include "terrain.hpp"
#include "saisie.hpp"
#include "aleatoire.hpp"

using namespace std;


const char MUR_HAUT = '-';
const char MUR_COTE = '|';
const char VIDE     = ' ';

vector<std::string> terrain;

string robotTue;

bool Terrain::peutSeDeplacer(unsigned x, unsigned y){
   
   if(x > largeur || y > longeur || x == 0 || y == 0){
      return true;
   }
   return false;
}
void Terrain::eliminerRobot(unsigned x, unsigned y, unsigned id){
   
   for(vector<Robot>::iterator it = robots.begin(); it != robots.end(); ++it) {
      if((*it).getPosX() == x && (*it).getPosY() == y && (*it).getEstEnVie()){

         (*it).tuer();

         robotTue += "Robot " + to_string(id) + " a tué robot " + to_string((*it).getId()) + "\n";

      }
   }

}

void Terrain::simulerCombat() {

   enum direction{UP, DOWN, RIGHT, LEFT };

   constructionTerrain();


   unsigned nbrDeRobot;

   do{
      //random_shuffle(robots.begin(), robots.end());

      for(vector<Robot>::iterator it = robots.begin(); it != robots.end(); ++it) {

         unsigned x;
         unsigned y;


         do{
            
            switch(aleatoireEntreDeuxEntiersPositifs(0,3)){
               case direction::UP :
                  x =   (*it).getPosX();
                  y =   (*it).getPosY()+1;
                  break;
               case direction::DOWN :
                  x =   (*it).getPosX();
                  y =   (*it).getPosY()-1;
                  break;
               case direction::RIGHT :
                  x =   (*it).getPosX()+1;
                  y =   (*it).getPosY();
                  break;
               case direction::LEFT :
                  x =   (*it).getPosX()-1;
                  y =   (*it).getPosY();
            }

         }while(peutSeDeplacer(x,y));

         if(existeDeja(x, y)){
            eliminerRobot(x,y, (*it).getId());
         }

         (*it).deplacer(x,y);

      }
      afficherTerrain();
      nbrDeRobot = 0;
      for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it) {
         Robot monRobot = *it;

         if(monRobot.getEstEnVie()){
            ++nbrDeRobot;
         }
      }
   }while(nbrDeRobot != 1);

}

void Terrain::constructionTerrain(){

   // + 2, car on souhaite un terrain qui soit effectivement d'une largeur de 20, or
   // les murs prennent chacun une place.
   // Pour la longueur, nous faisons que +1, parce qu'on commence la boucle à 1.
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

   for(int i = 0; i < longeur; ++i){
      terrain.push_back(milieu);
   }
   terrain.push_back(haut_bas);

}

void Terrain::mettreAJour(){
   const string ESPACE_LIBRE (largeur, VIDE);

   for(int i = 1 ; i <= longeur; ++i){
      terrain.at(i).replace(1, largeur , ESPACE_LIBRE);
   }

   for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it) {
      Robot monRobot = *it;

      if(monRobot.getEstEnVie()){
         terrain.at(monRobot.getPosY()).replace(monRobot.getPosX(), 1, to_string(monRobot.getId()));
      }
   }
}

void Terrain::afficherTerrain() {

   system("clear");

   mettreAJour();

   for(vector<string>::const_iterator it = terrain.cbegin() ; it != terrain.cend(); ++it){
      cout << *it;
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

   for(vector<Robot>::const_iterator it = robots.cbegin(); it != robots.cend(); ++it) {
      Robot monRobot = *it;

      if(monRobot.getPosX() == x and monRobot.getPosY() == y) {
         return true;
      }
   }

   return false;
}
