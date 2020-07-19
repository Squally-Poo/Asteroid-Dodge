/*
 * ASTEROID DODGE, miseAJour.cpp
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : fonction de mise à jour du programme : La fonction agit sur toutes les actions "automatiques" du programmes
 * (déplacement et régénérations des astéroides etc...)
 * 
 */
 
#include <Gamebuino-Meta.h>
#include "constantes.h"
#include "variables.h"
#include "fonctions.h"

void miseAJour(){

  if (ecran == JEU) {
    //Ajustement du nombre d'astéroides en fonction du score
    if (score > 10 && nbreAstero < ASTERO_MAX) {
      nbreAstero = score / 3;
      //On limite le nombre d'astéroides
      if (nbreAstero >= ASTERO_MAX){
        nbreAstero = ASTERO_MAX - 1;
      }
    } else {
      nbreAstero = ASTERO_MIN;
    }

    //On génère les astéroides
    for (int i = 0 ; i < nbreAstero ; i++){
      asteroX[i] -= ASTERO_V; //On déplace les asteroides vers la gauche

      if (asteroX[i] < 0 - asteroL[i]) { //Si l'astéroide sort de l'écran par la gauche, on en créé un nouveau
        //On incrémente le score
        score++;
        
        //On place le nouvel astéroide en dehors de l'écran
        asteroX[i] = random(gb.display.width(), 2 * gb.display.width());
        asteroY[i] = random(6, gb.display.height() - ASTERO_L_MAX);

        //On défini aléatoirement les dimensions du nouvel astéroide
        asteroL[i] = random(ASTERO_L_MIN, ASTERO_L_MAX);
        asteroH[i] = random(ASTERO_H_MIN, ASTERO_H_MAX);
      }

      //Collision entre le vaisseau et l'astéroide
      if (gb.collide.rectRect(vaisseauX, vaisseauY, VAISSEAU_L, VAISSEAU_H,
      asteroX[i], asteroY[i], asteroL[i], asteroH[i])) { //Game Over
        gb.sound.playTick();
        //On allume les lumières en rouge
        gb.lights.fill(RED);
        delay(10);
        gb.lights.clear();
        //On coupe la bande son
        gb.sound.stop(audio);
        //On compare le score aux meilleurs score et on entre un nouveau nom si besoin
        if (score > score1) {
          strcpy(nom3, nom2);
          strcpy(nom2, nom1);
          gb.gui.keyboard(" Name? (6 letters)", nom1);
          score3 = score2;
          score2 = score1;
          score1 = score;
          sauvegarder();
        } else if (score > score2) { 
          strcpy(nom3, nom2);
          gb.gui.keyboard("Name ? (6 letters)", nom2);
          score3 = score2;
          score2 = score;
          sauvegarder();
        } else if (score > score3) {
          gb.gui.keyboard("Name ? (6 letters)", nom3);
          score3 = score;
          sauvegarder();
        }
        ecran = SCORE;
      }
    }
  } 
}

