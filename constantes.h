/*
 * ASTEROID DODGE, constantes.h
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : Contient toutes les constantes utilisées par la programme
 * 
 */
 

#ifndef CONSTANTES
#define CONSTANTES

/*===================================
======Declaration des constantes=====
===================================*/

//Constantes d'écran
enum ecranEtats {LOGO, MAIN, JEU, SCORE, REGLES}; //liste des écrans possibles

//Constantes du menu
const int CHOIX_X = 20, CHOIX_JEU_Y = 29, CHOIX_SCORE_Y = 36, CHOIX_REGLES_Y = 43; //emplacement des choix du menu principal
const int CURS_X = 9;
const int TEMPOCURSEUR = 150; //"latence" du curseur dans le menu

//Constantes du vaisseau
const int VAISSEAU_H = 5, VAISSEAU_L = 10; //dimensions du vaisseau
const int VAISSEAU_V = 2; //Vitesse du vaisseau

//Constantes d'astéroides
const int ASTERO_MAX = 20, ASTERO_MIN = 3; //Min et max d'astéroides générés
const int ASTERO_L_MIN = 2, ASTERO_L_MAX = 5, ASTERO_H_MIN = 2, ASTERO_H_MAX = 5; //Fourchettes de dimensions
const int ASTERO_V = 2; //Vitesse de déplacement des astéroides

//Constantes de score
const int LETTRES_MAX = 7; //Nombre de lettres maximum pour le nom d'un joueur
const int BEST_SCORES_X = 10, BEST_SCORES_Y = 5; //Position du titre "PANTEON"
const int NOM_X = 20, SCORE_X = 50; //Position en X des noms et des scores
const int SCORE_1_Y = 22, SCORE_2_Y = 32, SCORE_3_Y = 42; //Position en Y des noms et des scores
const int OUT_X = 45, OUT_Y = 57; //Position de l'option "A : Menu"
#endif
