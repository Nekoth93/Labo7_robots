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

   // nom         deplacer
   // but         permet le déplacement du robot
   //
   // param       x : un entier non signé. Représente la coordonnée x de la position du
   //                 robot.
   // param       y : en entier non signé. Représente la coordonnée y de la position du
   //                 robot.
   // param       implicitement un objet de la classe Robot.
   // return      aucun
   // exception   n/a
   void deplacer(unsigned x, unsigned y);

   // nom         getPosX
   // but         Obtenir la valeur de posX
   //
   // param       implicitement un objet de la classe Robot.
   // return      un entier non signé.
   // exception   n/a
   unsigned getPosX() const;

   // nom         getPosY
   // but         Obtenir la valeur de posY
   //
   // param       implicitement un objet de la classe Robot.
   // return      un entier non signé.
   // exception   n/a
   unsigned getPosY() const;

   // nom         getId
   // but         Obtenir la valeur de Id
   //
   // param       implicitement un objet de la classe Robot.
   // return      un entier non signé.
   // exception   n/a
   unsigned getId() const;

   // nom         getEstEnVie
   // but         Obtenir l'état du robot (en vie ou mort).
   //
   // param       implicitement un objet de la classe Robot.
   // return      un booléen.
   // exception   n/a
   bool getEstEnVie() const;

   // nom         tuer
   // but         Permet de passer l'état estEnVie du robot de true à false.
   //
   // param       implicitement un objet de la classe Robot.
   // return      aucun
   // exception   n/a
   void tuer();

private:
   unsigned posX;
   unsigned posY;
   const unsigned id;
   bool estEnVie;
};


#endif //LABO7_ROBOTS_ROBOT_HPP
