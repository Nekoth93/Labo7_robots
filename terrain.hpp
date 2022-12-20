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
   std::vector<std::string> terrain;
   std::string robotTue;

   /// @brief affiche le terrain
   void afficherTerrain();
   /// @brief getter de la largeur
   /// @return la largeur
   unsigned getlargeur() const;
   /// @brief getter de la longeur
   /// @return la longeur
   unsigned getLongeur() const;
   /// @brief initialise les robots qui vont se combattre à mort
   void initialiserRobot();
   /// @brief vérifie si un robot ne se trouve pas à cet emplacement
   /// @param x coordonnée x
   /// @param y coordonnée y
   /// @return si il y a un robot
   bool existeDeja(unsigned x, unsigned y);
   /// @brief vérifie si un robot peut se déplacer à cet endroit
   /// @param x coordonnée x
   /// @param y coordonnée y
   /// @return s'il peut se déplacer
   bool peutSeDeplacer(unsigned x, unsigned y) const;
   /// @brief tue un robot à un emplacement donné
   /// @param x coordonnée x
   /// @param y coordonnée y
   /// @param id id du robot qui est le meurtrier
   void eliminerRobot(unsigned x, unsigned y, unsigned id);
   /// @brief fait un tour de combat de robot
   /// @return le nombre de robot vivant
   unsigned combatRobots();
   /// @brief déplace un robot de manière aléatoire au case qui sont proches de lui, si un robot se trouve sur cette case, il l'élimine
   /// @param monRobot le robot à déplacer
   void deplacerRobot(Robot& monRobot);
   /// @brief modifie une vecteur avec les coordonnées et leurs ids de tous les robots à un y données
   /// @param robotsAY le vecteur ou stocker les données
   /// @param y la coordonnées y
   void postionsRobotsAY(std::vector<std::vector<unsigned>>& robotsAY, unsigned y);

};


#endif //LABO7_ROBOTS_TERRAIN_HPP