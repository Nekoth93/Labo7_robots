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

/**
 * @name  viderBuffer
 * @brief vide le buffer
 */
void viderBuffer();

/**
 * @name  saisirIntervaleInt
 * @brief Permet de faire une saisie sécurisée d'un entier.
 * @param minInt          valeur minimale acceptée
 * @param maxInt          valeur maximale acceptée
 * @param message         Un message qui explique les limites
 * @param message_erreur  un message en cas de mauvaise saisie
 * @return
 */
int saisirIntervaleInt(int minInt, int maxInt, const std::string& message,
                       const std::string& message_erreur);

#endif //LABO7_ROBOTS_SAISIE_HPP
