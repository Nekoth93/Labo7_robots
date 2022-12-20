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
   const string MSG_LARG_TERRAIN = "Veuillez choisir la largeur du terrain de combat"
                                   ".\n"s +
                                   "Elle doit etre comprise entre "s +
                                   to_string(MIN_TERRAIN) +
                                   " et "s +
                                   to_string(MAX_TERRAIN)
                                   + " : "s;
   const string MSG_LONG_TERRAIN = "Veuillez choisir la longeur du terrain de "
                                    "combat"
                                    ".\n"s +
                                   "Elle doit etre comprise entre "s +
                                   to_string(MIN_TERRAIN) +
                                   " et "s +
                                   to_string(MAX_TERRAIN)
                                   + " : "s;
   const string MSG_ERR_TAILLE      = "Taille invalide, veuillez recommencer"s;


   const string MSG_SAISIE_ROBOT = "Choisisez combien de robot devront combattre.\n"s +
                                   "Ce nombre doit etre compris entre "s +
                                   to_string(MIN_ROBOT) +
                                   " et "s +
                                   to_string(MAX_ROBOT)
                                   + " : "s;
                                 
   const string MSG_ERR_ROBOT    = "Valeur invalide, veuillez recommencer"s;

   const string MSG_FIN         = "Merci d'avoir utiliser notre programme.\n"s +
                                  "Veuillez appuyer sur enter pour quitter."s;

   //======================== Début du programme ===================================


   Terrain t1((unsigned)saisirIntervaleInt(MIN_TERRAIN, MAX_TERRAIN,
                                           MSG_LARG_TERRAIN, MSG_ERR_TAILLE),
              (unsigned)saisirIntervaleInt(MIN_TERRAIN, MAX_TERRAIN, MSG_LONG_TERRAIN,
                                           MSG_ERR_TAILLE),
              (unsigned)saisirIntervaleInt(MIN_ROBOT, MAX_ROBOT, MSG_SAISIE_ROBOT, MSG_ERR_ROBOT));

   t1.simulerCombat();

   cout << MSG_FIN << endl;
   viderBuffer();

   return EXIT_SUCCESS;
}
