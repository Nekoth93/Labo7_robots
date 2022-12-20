/*
  ---------------------------------------------------------------------------
  Fichier     : aleatoire.hpp
  Nom du labo : Labo7 - Robots
  Auteur(s)   : Delétraz Alexandre - Germano Hugo
  Date        : 13.12.2022
  But         : Déclaration de la fonction aleatoireEntreDeuxEntiersPositifs.

  Remarque(s) : à compléter

  Compilateur : gcc version 11.2.0
  ---------------------------------------------------------------------------
*/
#ifndef LABO7_ROBOTS_ALEATOIRE_HPP
#define LABO7_ROBOTS_ALEATOIRE_HPP

/**
 * @name aleatoireEntreDeuxEntiersPositifs
 * @brief Génerer un nombre aléatoire dans l'intervalle entre deux entiers positif
 *        reçu en paramètre.
 * @param min un entier non signé. Borne inférieur de l'intervalle.
 * @param max un entier non signé. Borne supérieur de l'intervalle.
 * @return
 */
unsigned aleatoireEntreDeuxEntiersPositifs(unsigned min, unsigned max);

#endif //LABO7_ROBOTS_ALEATOIRE_HPP
