/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Le programme va créer un terrain et des robots qui se détruiront
                lorsqu'ils se rencontreront. Le terrain et les robots seront affichés
                à chaque mouvement des robots jusqu'à la fin de la bataille.
                Chaque élimination sera notée à l'écran.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include "saisie.hpp"
#include "terrain.hpp"

using namespace std;

int main() {

   //========================== Constantes =========================================

   //---------------------------- Numeriques ---------------------------------------
   const int MIN_ROBOT   = 0;
   const int MAX_ROBOT   = 9;
   const int MIN_TERRAIN = 10;
   const int MAX_TERRAIN = 1000;

   //------------------------------ Textes -----------------------------------------
   const string msgLargeurTerrain = "Veuillez choisir la largeur du terrain de combat"
                                   ".\n"s +
                                    "Elle doit etre comprise entre "s +
                                    to_string(MIN_TERRAIN) +
                                    " et "s +
                                    to_string(MAX_TERRAIN);
   const string msgLongeurTerrain = "Veuillez choisir la longeur du terrain de "
                                    "combat"
                                    ".\n"s +
                                    "Elle doit etre comprise entre "s +
                                    to_string(MIN_TERRAIN) +
                                    " et "s +
                                    to_string(MAX_TERRAIN);
   const string msgErrTaille      = "Taille invalide, veuillez recommencer"s;


   const string msgSaisieRobot = "Choisisez combien de robot devront combattre.\n"s +
                                 "Ce nombre doit etre compris entre "s +
                                 to_string(MIN_ROBOT) +
                                 " et "s +
                                 to_string(MAX_ROBOT);
   const string msgErrRobot    = "Valeur invalide, veuillez recommencer"s;

   //======================== Début du programme ===================================


   Terrain t1((unsigned)saisirIntervaleInt(MIN_TERRAIN, MAX_TERRAIN,
                                         msgLargeurTerrain, msgErrTaille),
              (unsigned)saisirIntervaleInt(MIN_TERRAIN, MAX_TERRAIN, msgLongeurTerrain,
                                          msgErrTaille),
              (unsigned)saisirIntervaleInt(MIN_ROBOT, MAX_ROBOT, msgSaisieRobot, msgErrRobot));

   t1.afficherTerrain();

   return EXIT_SUCCESS;
}
