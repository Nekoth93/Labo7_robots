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


   // nom         simulerCombat
   // but         Permet de démarrer le jeu.
   //
   // param       Implicitement un objet de la classe Terrain.
   // return      aucun
   // exception   n/a
   void simulerCombat();


private:
   unsigned largeur;
   unsigned longeur;
   unsigned nombreRobots;
   std::vector<Robot> robots;
   std::vector<std::string> terrain;
   std::string robotTue;

   // nom         afficherTerrain
   // but         Permet d'afficher le terrain de combat, indique qui a tué qui et permet
   //             d'avoir un délai entre chaque action des robots pour que l'on ait le
   //             temps de voir ce qu'il se passe.
   //
   // param       implicitement un objet de classe Terrain.
   // return      aucun
   // exception   n/a
   void afficherTerrain();

   // nom         getLargeur
   // but         Permet d'obtenir la valeur de la largeur du terrain.
   //
   // param       implicitement un objet de la classe Terrain.
   // return      un entier non signé.
   // exception   n/a
   unsigned getlargeur() const;

   // nom         getLongueur
   // but         Permet d'obtenir la valeur de la longueur du terrain.
   //
   // param       implicitement un objet de la classe Terrain.
   // return      un entier non signé.
   // exception   n/a
   unsigned getLongeur() const;

   // nom         initialiserRobot
   // but         Permet d'initialiser des instances de la class Robot.
   //
   // param       Implicitement un objet de la classe Terrain.
   // return      aucun
   // exception   n/a
   void initialiserRobot();

   // nom         existeDeja
   // but         Permet de verifier si un robot existe deja à cette position.
   //
   // param       x : un entier non signé. Représente la coordonnée x de la position du
   //                 robot.
   // param       y : en entier non signé. Représente la coordonnée y de la position du
   //                 robot.
   // param       Implicitement un objet de la classe Terrain.
   // return      un booléen.
   // exception   n/a
   bool existeDeja(unsigned x, unsigned y);

   // nom         peutSeDeplacer
   // but         Vérifie si le robot peut effectuer le déplacement suivant en fonction
   //             des limites du terrain.
   //
   // param       x : un entier non signé.
   // param       y : un entier non signé.
   // param       Implicitement un objet de la classe Terrain.
   // return      Un booléen.
   // exception   n/a
   bool peutSeDeplacer(unsigned x, unsigned y) const;

   // nom         eliminerRobot
   // but         Permet d'éliminer un robot de la partie.
   //
   // param       x : un entier non signé. Représente la coordonnée x de la position du
   //                 robot.
   // param       y : en entier non signé. Représente la coordonnée y de la position du
   //                 robot.
   // param       Implicitement un objet de la classe Terrain.
   // return      aucun
   // exception   n/a
   void eliminerRobot(unsigned x, unsigned y, unsigned id);

   // nom         constructionTerrain
   // but         Permet de construire le terrain de base en fonction de ce que
   //             l'utilisateur choisi comme dimension.
   //
   // param       Implicitement un objet de la classe Terrain.
   // return      aucun
   // exception   n/a
   void constructionTerrain();

   // nom         mettreAJour
   // but         Permet de mettre à jour le terrain en prenant en compte les déplacements
   //             des robots et les éliminations.
   //
   // param       Implicitement un objet de la classe Terrain.
   // return      aucun
   // exception   n/a
   void mettreAJour();

   // nom         combatRobots
   // but         Permet aux robots de se combattre.
   //
   // param       Implicitement un objet de la classe Terrain.
   // return      un entier non signé. Indique le nombre de robots restant.
   // exception   n/a
   unsigned combatRobots();

   // nom         deplacerRobot
   // but         Permet à un robot de se déplacer dans une direction aléatoire.
   //             Dans le cas où un robot est déjà présent à l'arrivée, ce dernier est éliminé.
   //
   // param       x : un entier non signé reçu par référence. Représente la coordonnée x de la
   //                 position du robot.
   // param       y : en entier non signé reçu par référence. Représente la coordonnée y de la
   //                 position du robot.
   // param       Un objet de la classe Robot reçu par référence.
   // return      aucun
   // exception   n/a
   void deplacerRobot(unsigned& x, unsigned& y, Robot& monRobot);

};


#endif //LABO7_ROBOTS_TERRAIN_HPP