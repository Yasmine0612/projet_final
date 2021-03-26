#ifndef __RESEAU_H__
#define __RESEAU_H__
#include "Chaine.h"

typedef struct noeud Noeud;

/* Liste chainee de noeuds (pour la liste des noeuds du reseau ET les listes des voisins de chaque noeud) */
typedef struct cellnoeud {
    Noeud *nd;                     /* Pointeur vers le noeud stocke */
    struct cellnoeud *suiv;        /* Cellule suivante dans la liste */
} CellNoeud;

/* Noeud du reseau */
struct noeud{
   int num;                        /* Numero du noeud */
   double x, y;                    /* Coordonnees du noeud*/
   CellNoeud *voisins;             /* Liste des voisins du noeud */
};

/* Liste chainee de commodites */
typedef struct cellCommodite {
    Noeud *extrA, *extrB;          /* Noeuds aux extremites de la commodite */
    struct cellCommodite *suiv;    /* Cellule suivante dans la liste */
} CellCommodite;

/* Un reseau */
typedef struct {
    int nbNoeuds;                  /* Nombre de noeuds du reseau */
    int gamma;                     /* Nombre maximal de fibres par cable */
    CellNoeud *noeuds;             /* Liste des noeuds du reseau */
    CellCommodite *commodites;     /* Liste des commodites a relier */
} Reseau;

void inserer_noeud_en_tete (Reseau * R, Noeud * n);
Noeud * creer_noeud(int num, double x, double y);
void inserer_com_en_tete (Reseau * R, CellCommodite * com);
CellCommodite creer_commodite(Noeud* extrA, Noeud* extrB);
Reseau * creer_reseau(int nbNoeuds, int gamma, CellNoeud* noeuds, CellCommodite* commodites);
void afficher_noeud(Noeud * n);
void afficher_commodite(CellCommmodite * n);
void afficher_reseau(Reseau * r);

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y);
Reseau* reconstitueReseauListe(Chaines *C);
void ecrireReseau(Reseau *R, FILE *f);
int nbLiaisons(Reseau *R);
int nbCommodites(Reseau *R);
void afficheReseauSVG(Reseau *R, char* nomInstance);
#endif