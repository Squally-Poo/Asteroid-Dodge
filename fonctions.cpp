/*
 * ASTEROID DODGE, fonctions.cpp
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : fonctions mineures du programme
 * 
 */
 
#include <Gamebuino-Meta.h>
#include "constantes.h"
#include "variables.h"

void reinitialiser()
{
  //Position du curseur
  cursY = CHOIX_JEU_Y;

  //Reinitialiser le score
  score = 0;

  //Reinitialiser la position du vaisseau
  vaisseauX = gb.display.width() / 2 - VAISSEAU_L / 2;
  vaisseauY = gb.display.height() / 2 - VAISSEAU_H / 2;

  //Reinitialiser les astéroides
  nbreAstero = ASTERO_MIN;
  for (int i = 0 ; i < ASTERO_MAX ; i++) {
    //On place les astéroides aléatroirement à droite de l'écran
    asteroX[i] = random(gb.display.width(), 2 * gb.display.width());
    asteroY[i] = random(6, gb.display.height());
    //On défini aléatoirement la pasition des astéroides
    asteroL[i] = random(ASTERO_L_MIN, ASTERO_L_MAX);
    asteroH[i] = random(ASTERO_H_MIN, ASTERO_H_MAX);
  }

}

void sauvegarder()
{
  gb.save.set(0, nom1);
  gb.save.set(1, nom2);
  gb.save.set(2, nom3);
  gb.save.set(3, score1);
  gb.save.set(4, score2);
  gb.save.set(5, score3);
}

