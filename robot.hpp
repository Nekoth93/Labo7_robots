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

   /**
    * @name  deplacer
    * @brief permet le déplacement du robot
    * @param x un entier non signé. Représente la coordonnée x de la position du
    *          robot.
    * @param y un entier non signé. Représente la coordonnée y de la position du
    *          robot.
    */
   void deplacer(unsigned x, unsigned y);

   /**
    * @name   getPosX
    * @brief  Obtenir la valeur de posX
    * @return la coordonnée x du robot
    */
   unsigned getPosX() const;

   /**
    * @name   getPosY
    * @brief  Obtenir la valeur de posY
    * @return la coordonnée y du robot
    */
   unsigned getPosY() const;

   /**
    * @name   getId
    * @brief  Obtenir la valeur de Id
    * @return l'id du robot
    */
   unsigned getId() const;

   /**
    * @name   getEstEnVie
    * @brief  Obtenir l'état du robot (en vie ou mort).
    * @return l'état du robot sous forme de booléen.
    */
   bool getEstEnVie() const;

   /**
    * @name tuer
    * @brief Permet de passer l'état estEnVie du robot de true à false.
    *        (tue un robot)
    */
   void tuer();

private:
   unsigned posX;
   unsigned posY;
   const unsigned id;
   bool estEnVie;
};


#endif //LABO7_ROBOTS_ROBOT_HPP
