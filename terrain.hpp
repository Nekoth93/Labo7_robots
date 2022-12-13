//
// Created by P51 on 13.12.2022.
//

#ifndef LABO7_ROBOTS_TERRAIN_HPP
#define LABO7_ROBOTS_TERRAIN_HPP


class Terrain {
public:
   Terrain() : Terrain(20, 20, 6) {}
   Terrain(unsigned la, unsigned lo, unsigned nbrRobot) : largeur(la), longeur(lo),
   nombreRobots (nbrRobot) {}
   void simulerCombat();

private:
   unsigned largeur;
   unsigned longeur;
   unsigned nombreRobots;

    void afficherTerrain();
    void initialiserRobot();

};


#endif //LABO7_ROBOTS_TERRAIN_HPP