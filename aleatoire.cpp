//
// Created by P51 on 13.12.2022.
//

#include <random>

#include "aleatoire.hpp"

using namespace std;

int aleatoireEntreDeuxEntiers(int min, int max){

   random_device                  rand_dev;
   default_random_engine          generator(rand_dev());
   uniform_int_distribution<int>  distr(min, max);

   return distr(generator);
}