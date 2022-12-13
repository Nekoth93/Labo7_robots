/*
  ---------------------------------------------------------------------------
  Fichier     : saisie.hpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Déclaration des fonctions nécessaires à la saisie sécurisée d'un
                entier.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO7_ROBOTS_SAISIE_HPP
#define LABO7_ROBOTS_SAISIE_HPP

#include <string>

int saisirIntervaleInt(int minInt, int maxInt, const std::string& message,
                       const std::string& message_erreur);

#endif //LABO7_ROBOTS_SAISIE_HPP
