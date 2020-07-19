/*
 * ASTEROID DODGE, affichage.cpp
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : Gère tout ce qui apparait à l'écran lors de l'utilisation du programme
 * 
 */
 
#include <Gamebuino-Meta.h>
#include "constantes.h"
#include "variables.h"
#include "sprites.h"




void affichage()
{  
  //AFFICHAGE
  gb.display.clear();
  switch(ecran)
  {
    case LOGO :
      gb.display.setColor(BLACK);
      gb.display.fillRect(0, 0, gb.display.width(), gb.display.height());
      gb.display.drawImage(0, 0, logo);
      delay(2000);
      ecran = MAIN;
      break;
    case MAIN :
      //On affiche l'image du menu
      gb.display.setColor (BLACK);
      gb.display.fillRect(0, 0, gb.display.width(), gb.display.height());
      gb.display.drawImage(0, 0, titre); 
      //On affiche les différentes options 
      gb.display.setColor (WHITE);
      gb.display.setCursorX(CHOIX_X);
      gb.display.setCursorY(CHOIX_JEU_Y);
      gb.display.print("New Game");
      gb.display.setCursorX(CHOIX_X);
      gb.display.setCursorY(CHOIX_SCORE_Y);
      gb.display.print("High Scores");
      gb.display.setCursorX(CHOIX_X);
      gb.display.setCursorY(CHOIX_REGLES_Y);
      gb.display.print("Rules");
      //On affiche le curseur
      gb.display.drawImage(CURS_X, cursY, curseur);
      break;
    case JEU :
      //Infos
      gb.display.print("score : ");
      gb.display.print(score);
      //Affichage du fond
      //gb.display.setColor(YELLOW);
      gb.display.drawImage(0, 6, espace);
      //gb.display.fillRect(0, 0, 80, 64);
      //Affichage du vaisseau
      gb.display.drawImage(vaisseauX, vaisseauY, vaisseau);
      //Affichage des astéroides
      gb.display.setColor(GRAY);
      for(int i = 0 ; i < nbreAstero ; i++) {
        gb.display.fillRect(asteroX[i], asteroY[i], asteroL[i], asteroH[i]);
      }
      break;
    case SCORE :
      gb.display.setColor(WHITE);
      gb.display.setFontSize(2);
      gb.display.setCursorX(BEST_SCORES_X);
      gb.display.setCursorY(BEST_SCORES_Y);
      gb.display.print("PANTHEON");
      gb.display.setFontSize(1); //On réduit la taille de la police pour afficher les scores
      gb.display.setColor(YELLOW); //On affiche les noms associés au 1er meilleur score
      gb.display.setCursorX(NOM_X);
      gb.display.setCursorY(SCORE_1_Y);
      gb.display.print(nom1);
      gb.display.setCursorX(SCORE_X);
      gb.display.print(score1);
      gb.display.setColor(GRAY); //On affiche les noms associés au 2eme meilleur score
      gb.display.setCursorX(NOM_X);
      gb.display.setCursorY(SCORE_2_Y);
      gb.display.print(nom2);
      gb.display.setCursorX(SCORE_X);
      gb.display.print(score2);
      gb.display.setColor(ORANGE); //On affiche les noms associés au 3eme meilleur score
      gb.display.setCursorX(NOM_X);
      gb.display.setCursorY(SCORE_3_Y);
      gb.display.print(nom3);
      gb.display.setCursorX(SCORE_X);
      gb.display.print(score3);
      gb.display.setColor(WHITE); //On affiche la consigne pour sortir de l'écran des scores
      gb.display.setCursorX(OUT_X);
      gb.display.setCursorY(OUT_Y);
      gb.display.print("B : MENU");      
      break;
    case REGLES :
      gb.display.print("-Move with dir. pad\n");
      gb.display.print("-Avoid asteroids\n which are coming\n from the right.\n");
      gb.display.print("-When asteroids\n leave the screen by\n the left, score\n increase.\n");
      gb.display.print("-Have fun !\n");
      gb.display.setCursorX(OUT_X);
      gb.display.setCursorY(OUT_Y);
      gb.display.print("B : MENU");
      break;
  }
  
}

