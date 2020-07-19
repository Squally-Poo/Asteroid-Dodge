/*
 * ASTEROID DODGE, entrees.cpp
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : gère les entrées utilisateurs et leurs conséquences
 * 
 */
 
#include <Gamebuino-Meta.h>
#include "constantes.h"
#include "variables.h"
#include "fonctions.h"

void entrees()
{
  if (gb.buttons.repeat(BUTTON_DOWN, 0)) { //si on appui sur BAS
    switch (ecran)
    {
      case MAIN :
        gb.sound.playTick();
        switch (cursY)
        {
          case CHOIX_JEU_Y : 
            cursY = CHOIX_SCORE_Y;
            delay(TEMPOCURSEUR);
            break;
          case CHOIX_SCORE_Y : 
            cursY = CHOIX_REGLES_Y;
            delay(TEMPOCURSEUR);
            break;
          case CHOIX_REGLES_Y :
            cursY = CHOIX_JEU_Y;
            delay(TEMPOCURSEUR);
            break;
        }
        break;
      case JEU :
        if (vaisseauY + VAISSEAU_H < gb.display.height() - 1) {
          vaisseauY += VAISSEAU_V;
        }
        break;
    }
  }

  if (gb.buttons.repeat(BUTTON_UP, 0)) { //On appui sur HAUT
    switch (ecran)
    {
      case MAIN :
        gb.sound.playTick();
        switch (cursY)
        {
          case CHOIX_JEU_Y :
            cursY = CHOIX_REGLES_Y;
            delay(TEMPOCURSEUR);
            break;
          case CHOIX_SCORE_Y :
            cursY = CHOIX_JEU_Y;
            delay(TEMPOCURSEUR);
            break;
          case CHOIX_REGLES_Y : 
            cursY = CHOIX_SCORE_Y;
            delay(TEMPOCURSEUR);
            break;
        }
        break;
      case JEU :
        if (vaisseauY > 6) { //On laisse 6 pixels en haut pour le score
          vaisseauY -= VAISSEAU_V;
        }
        break;
    }
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 0)) { //si on appuie sur GAUCHE
    switch (ecran)
    {
      case JEU : 
        if (vaisseauX - 1 > 0) {
          vaisseauX -= VAISSEAU_V;
        }
        break;
    }
  }

  if (gb.buttons.repeat(BUTTON_RIGHT, 0)) { //Si on appui sur droite
    switch (ecran)
    {
      case JEU :
        if (vaisseauX + VAISSEAU_L + 1 < gb.display.width()) {
          vaisseauX += VAISSEAU_V;
        }
        break;
    }
  }
  
  if (gb.buttons.pressed(BUTTON_A)) { //si on appuie sur le bouton A
    switch(ecran)
    {
      case MAIN :
        gb.sound.playTick();
        switch (cursY)
        {
          case CHOIX_JEU_Y :
            reinitialiser();
            audio = gb.sound.play("VOID'S LEGACY.WAV", true);
            ecran = JEU;
            break;
          case CHOIX_SCORE_Y :
            ecran = SCORE;
            break;
          case CHOIX_REGLES_Y :
            ecran = REGLES;
            break;
        }
        break;
    }
  }

  if (gb.buttons.pressed(BUTTON_B)) { //Si on appui sur le bouton B
    gb.sound.playTick();
    switch(ecran)
    {
      case SCORE :
        ecran = MAIN;
        break;
      case REGLES :
        ecran = MAIN;
        break;
    }
  }
}

