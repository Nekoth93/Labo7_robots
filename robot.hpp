/*
  ---------------------------------------------------------------------------
  Fichier     : robot.hpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Déclaration de la classe Robot.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO7_ROBOTS_ROBOT_HPP
#define LABO7_ROBOTS_ROBOT_HPP


class Robot {
public:
   Robot(unsigned x, unsigned y,  const unsigned identifiant) : posX(x), posY(y), id(identifiant) {}

   void deplacer();
   unsigned getPosX() const;
   unsigned getPosY() const;

private:
   unsigned posX;
   unsigned posY;
   const unsigned id;


};


#endif //LABO7_ROBOTS_ROBOT_HPP
