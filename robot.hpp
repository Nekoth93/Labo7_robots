//
// Created by P51 on 13.12.2022.
//

#ifndef LABO7_ROBOTS_ROBOT_HPP
#define LABO7_ROBOTS_ROBOT_HPP


class Robot {
public:
   Robot(unsigned x, unsigned y,  const unsigned identifiant) : posX(x), posY(y), id(identifiant) {}

private:
   unsigned posX;
   unsigned posY;
   const unsigned id;


};


#endif //LABO7_ROBOTS_ROBOT_HPP
