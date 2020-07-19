/*
 * ASTEROID DODGE, Main
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : Fichier principal du programme
 * 
 */

#include <Gamebuino-Meta.h>
#include "constantes.h"
#include "variables.h"
#include "fonctions.h"
#include "entrees.h"
#include "miseAJour.h"
#include "affichage.h"


void setup() {
  gb.begin();
  reinitialiser();
  //Chargement de la sauvegarde
  gb.save.get(0, nom1, LETTRES_MAX);
  gb.save.get(1, nom2, LETTRES_MAX);
  gb.save.get(2, nom3, LETTRES_MAX);
  score1 = gb.save.get(3);
  score2 = gb.save.get(4);
  score3 = gb.save.get(5);

}

void loop() {
  while(!gb.update());

  entrees();
  miseAJour();
  affichage();

}
