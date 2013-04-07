#include "classe.h"


/*
  PROJET C
  1.Gerer une classe de max 25 étudiants
  1 etudiant -id unique
  -nom
  -prenom
  -adresse(rue,#nCP,ville)
  tableau de 5 cotes

  procedures => encoder un etudiant
                supprimer "" (avec son id)
                modifier ""  ("")
                afficher la classe
                encoder cotes.

  ID unique en integer!

  2.passage de parametre pour les fonctions.

  3.calculer et stocker le % d'un etu
    trier les etu en fct du %

  4.Faire un programme setup qui initialise les fichier pour une nouvelle année.
  enregistrer les struct sous fichier binaire
  1TI.txt : config du fichier binaire

*/

int main() {
 // char choix;
  int nbEtu=0;
  FILE* fopen(config.cfg, );
  T_Etu EtuEphec[100];
  //do{
    nbEtu = encoder_Etu(EtuEphec,nbEtu);
    printf("\n\nq pour quitter");
//    getch(choix);
  //} while(!(choix = 'q'));

  return 0;
}



