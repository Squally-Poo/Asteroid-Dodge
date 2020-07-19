/*
 * ASTEROID DODGE, variables.cpp
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : déclaration des variables utilisées dans le programme
 * 
 */
 
#include "constantes.h"
#include "variables.h"

/*===================================
======Définition des variables======
===================================*/

//Variables d'écran
enum ecranEtats ecran = LOGO;

//Variables de menu
int cursY; //position du curseur

//Variables du vaisseau
int vaisseauX, vaisseauY; //position du vaisseau

//Variables des astéroides
int asteroX[ASTERO_MAX] = {}, asteroY[ASTERO_MAX] = {}; //génération des asteroides via leur positions
int asteroL[ASTERO_MAX] = {}, asteroH[ASTERO_MAX] = {}; //et leurs dimensions
int nbreAstero; //nombre d'astéroides à afficher

//Variables de score
int score = 0;
int score1 = 10, score2 = 5, score3 = 1; //scores enregistrés
char nom1[LETTRES_MAX] = "Triss", nom2[LETTRES_MAX] = "Yen", nom3[LETTRES_MAX] = "Gerald"; //noms associés aux meilleurs scores

//Variables de bande son
int audio = -1;
