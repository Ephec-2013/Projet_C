#include "constante.h"
/*
  STRUCTURE ETUDIANTS
*/
typedef struct {
    short annee;
    char section;
  }T_ClasseEtu;

typedef struct {
    char rue[L_STRING];      // appartement -> chiffre et lettres
    int CP;
    char ville[M_STRING];
  } T_Adresse;

typedef struct {
  int id;
  T_ClasseEtu classe;
  char nom[M_STRING];
  char prenom[M_STRING];
  T_Adresse adresse;
  int cote[5];
} T_Etu;

/*
  STRUCTURE PROFS
*/
/*
typedef struct {
  int id;
  char nom[M_STRING];
  char prenom[M_STRING];
  struct {
    char rue[L_STRING];      // appartement -> chiffre et lettres
    int CP;
    char ville[M_STRING];
  } Adresse;
} T_Prof;

*/
/*
  STRUCTURE CLASSE (INDEX)
*/
//TODO (Xavier#3#):Mettre la structure en un seul morceau.
/*
typedef struct {
  int id[MAXETUCLASSE];
  int nbEtu;              // nb d'etudiant composant la classe.
} T_Classe;

typedef struct {
  char nom[M_STRING];
  T_Classe Classe;
} T_Section;

typedef struct {
  T_Section Section[NB_SECTION];
} T_Annee;

typedef struct {
  T_Annee Annee[NB_ANNEES];
} Classe_Ephec;

*/
