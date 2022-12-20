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
           nombreRobots(nbrRobot) {}

   /**
    * @name simulerCombat
    * @brief Permet de démarrer le jeu.
    */
   void simulerCombat();


private:
   unsigned largeur;
   unsigned longeur;
   unsigned nombreRobots;
   std::vector<Robot> robots;
   std::vector<std::string> terrain;
   std::string robotTue;

   /**
    * @name  afficherTerrain
    * @brief Permet d'afficher le terrain de combat, indique qui a tué qui et permet
    *        d'avoir un délai entre chaque action des robots pour que l'on ait le
    *        temps de voir ce qu'il se passe.
    */
   void afficherTerrain();

   /**
    * @name   getlargeur
    * @brief  Permet d'obtenir la valeur de la largeur du terrain.
    * @return la largeur
    */
   unsigned getlargeur() const;

   /**
    * @name   getLongeur
    * @brief  Permet d'obtenir la valeur de la longueur du terrain.
    * @return la longueur
    */
   unsigned getLongeur() const;

   /**
    * @name  initialiserRobot
    * @brief initialise les robots qui vont se combattre à mort
    */
   void initialiserRobot();

   /**
    * @name   existeDeja
    * @brief  vérifie si un robot ne se trouve pas à cet emplacement
    * @param  x coordonnée x
    * @param  y coordonnée y
    * @return si il y a un robot
    */
   bool existeDeja(unsigned x, unsigned y);

   /**
    * @name   peutSeDeplacer
    * @brief  vérifie si un robot peut se déplacer à cet endroit
    * @param  x coordonnée x
    * @param  y coordonnée y
    * @return un booléen
    */
   bool peutSeDeplacer(unsigned x, unsigned y) const;

   /**
    * @name  eliminerRobot
    * @brief tue un robot à un emplacement donné
    * @param x coordonnée x
    * @param y coordonnée y
    * @param id id du robot qui est le meurtrier
    */
   void eliminerRobot(unsigned x, unsigned y, unsigned id);

   /**
    * @name   combatRobots
    * @brief  Permet aux robots de se combattre.
    * @return le nombre de robot vivant
    */
   unsigned combatRobots();


   /**
    * @name  deplacerRobot
    * @brief déplace  un robot de manière aléatoire au case qui sont proches de lui,
    *                 si un robot se trouve sur cette case, il l'élimine
    * @param monRobot le robot à déplacer
    */
   void deplacerRobot(Robot& monRobot);

   /**
    * @name  postionsRobotsAY
    * @brief modifie une vecteur avec les coordonnées et leurs ids de tous les robots à un y données
    * @param robotsAY le vecteur ou stocker les données
    * @param y la coordonnées y
    */
   void postionsRobotsAY(std::vector<std::vector<unsigned>>& robotsAY, unsigned y);

};


#endif //LABO7_ROBOTS_TERRAIN_HPP