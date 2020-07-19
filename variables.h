/*
 * ASTEROID DODGE, variables.h
 * 
 * Auteur : Baptiste BOUGEANT
 * Date : 19 Juillet 2020
 * Support : GAMEBUINO META
 * 
 * Rôle : déclaration en extern de toutes les variables (toutes les variables initialisées ici sont globales
 * 
 */
 
#include "constantes.h"

#ifndef VARIABLES
#define VARIABLES

/*===================================
======Declaration des variables======
===================================*/

//Variables d'écran
extern enum ecranEtats ecran; //Variable de type écran, stock l'écran actuel

//Variables de menu
extern int cursY; //position verticale du curseur

//Variables du vaisseau
extern int vaisseauX, vaisseauY; //Position du vaisseau

//Variables des astéroides
extern int asteroX[ASTERO_MAX], asteroY[ASTERO_MAX]; //génération des asteroides via leur positions
extern int asteroL[ASTERO_MAX], asteroH[ASTERO_MAX]; //et leurs dimensions
extern int nbreAstero; //nombre d'astéroides à afficher

//Variables de score
extern int score; //score de la partie en cours
extern int score1, score2, score3; //scores enregistrés
extern char nom1[LETTRES_MAX], nom2[LETTRES_MAX], nom3[LETTRES_MAX]; //noms associés aux meilleurs scores

//Variables de bande son
extern int audio;



#endif
