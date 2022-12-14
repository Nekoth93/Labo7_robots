/*
  ---------------------------------------------------------------------------
  Fichier     : robot.cpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Définition de la classe Robot.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include "robot.hpp"

void Robot::deplacer(unsigned x, unsigned y) {
   posX = x;
   posY = y;
}

unsigned Robot::getPosX() const {
   return posX;
}

unsigned Robot::getPosY() const {
   return posY;
}

unsigned Robot::getId() const {
   return id;
}

void Robot::tuer(){
   estEnVie = false;
}

bool Robot::getEstEnVie() const{
   return estEnVie;
}

// pas convaincu de ça...
Robot& Robot::operator=(const Robot &r)  {
   Robot temp(0, 0, r.getId(), true);
   temp.posX = r.posX;
   temp.posY = r.posY;

   return *this;
}
