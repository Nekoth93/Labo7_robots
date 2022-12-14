/*
  ---------------------------------------------------------------------------
  Fichier     : aleatoire.cpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Définition de la fonction aleatoireEntreDeuxEntiersPositifs.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#include <random>
#include "aleatoire.hpp"

using namespace std;

unsigned aleatoireEntreDeuxEntiersPositifs(unsigned min, unsigned max) {

   random_device                  rand_dev;
   default_random_engine          generator(rand_dev());
   uniform_int_distribution<int>  distr(min, max);

   return distr(generator);
}