#include "main.h"
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

  systeme d'id a 2 partie? AnneeSectionID (1TL01)

  2.passage de parametre pour les fonctions.

*/

int main() {
  char choix;
  int nbEtu=0;
  T_Etu EtuEphec[100];
  do{
    nbEtu = encoder_Etu(EtuEphec,nbEtu);
    printf("\n\nq pour quitter");
    getch(choix);
  } while(!(choix = 'q'));
  return 0;
}



