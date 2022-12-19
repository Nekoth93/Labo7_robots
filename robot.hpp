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

   Robot(unsigned x, unsigned y,  const unsigned identifiant, bool vivant) : posX(x), posY(y), id(identifiant) , estEnVie(vivant){}
   Robot& operator=(const Robot& r);

   void deplacer(unsigned x, unsigned y);
   unsigned getPosX() const;
   unsigned getPosY() const;
   unsigned getId() const;
   bool getEstEnVie() const;
   void tuer();

private:
   unsigned posX;
   unsigned posY;
   const unsigned id;
   bool estEnVie;
};


#endif //LABO7_ROBOTS_ROBOT_HPP
