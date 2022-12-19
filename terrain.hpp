/*
  ---------------------------------------------------------------------------
  Fichier     : terrain.hpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Déclaration de la classe Terrain.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO7_ROBOTS_TERRAIN_HPP
#define LABO7_ROBOTS_TERRAIN_HPP

#include <vector>
#include <string>
#include "robot.hpp"


class Terrain {
public:
   Terrain() : Terrain(20, 20, 6) {}
   Terrain(unsigned la, unsigned lo, unsigned nbrRobot) : largeur(la), longeur(lo),
           nombreRobots(nbrRobot) { initialiserRobot();}
   
   void simulerCombat();


private:
   unsigned largeur;
   unsigned longeur;
   unsigned nombreRobots;
   std::vector<Robot> robots;


   void afficherTerrain();
   unsigned getlargeur() const;
   unsigned getLongeur() const;
   void initialiserRobot();
   bool existeDeja(unsigned x, unsigned y);
   bool peutSeDeplacer(unsigned x, unsigned y);
   void eliminerRobot(unsigned x, unsigned y, unsigned id);
   void constructionTerrain();
   void mettreAJour();
   unsigned combatRobots();

};


#endif //LABO7_ROBOTS_TERRAIN_HPP