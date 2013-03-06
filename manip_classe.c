#include "constante.h"
#include "manip_classe.h"


void supprimer_Etu(T_Etu classe[], int id)
//TODO (Xavier#3#):mettre une option de sortie sans modifier
{
   int i;
   printf("\nSupprimer un etudiant\nID de l'etudiant: ");
   scanf("%d",&id);
   fflush(stdin);
   //TODO (Xavier#1#): rajouter sous fonction qui recupere le numero en fct de l'id
  strcpy(classe[id].nom,"");
  strcpy(classe[id].prenom,"");
  strcpy(classe[id].Adresse.rue,"");
  classe[id].Adresse.CP = 0;
  strcpy(classe[id].Adresse.ville,"");
  for(i=0;i<5;i++)
    {classe[id].cote[i] = 0;}
  printf("\nEtudiant supprime!\n");
}

void encoder_cote(T_Etu classe[],int id)
{
  printf("\n1ere cote: ");scanf("%d",&classe[id].cote[1]);fflush(stdin);
  printf("\n2eme cote: ");scanf("%d",&classe[id].cote[2]);fflush(stdin);
  printf("\n3eme cote: ");scanf("%d",&classe[id].cote[3]);fflush(stdin);
  printf("\n4eme cote: ");scanf("%d",&classe[id].cote[4]);fflush(stdin);
  printf("\n5eme cote: ");scanf("%d",&classe[id].cote[5]);fflush(stdin);
  printf("enregistrer!\n");
}

int encoder_Etu(T_Etu classe[], int nbEtu)
/*
  Encoder un nouvel etudiant ou reencoder un ancient etudiant.
*/
//TODO (Xavier#3#): rajouter une fct pour mettre le nom en MAJ.
//TODO (Xavier#5#): FAIT - mettre nbEtu dans la structure de classe.
{
    char check;
    do{
    nbEtu++;
    printf("Encoder ETU\n");
    printf("id: ");
    scanf("%d",&classe[0].id);
    fflush(stdin);
    printf("Nom: "); gets(classe[0].nom);
    printf("Prenom: "); gets(classe[0].prenom);
    printf("Adresse:\nRue: "); gets(classe[0].Adresse.rue);
    printf("Ville: "); gets(classe[0].Adresse.ville);
    printf("CP: "); scanf("%d",classe[0].Adresse.CP);
    fflush(stdin);

    printf("\n\nID: %d\n",classe[0].id);
    printf("%s ",classe[0].nom);
    printf("%s",classe[0].prenom);
    printf("\n%s",classe[0].Adresse.rue);
    printf("\n%s ",classe[0].Adresse.ville);
    printf("%d",classe[0].Adresse.CP);
    printf("\nCes informations sont-elles correctes? [O/n] 'E' pour annuler\n");
    scanf("%c",&check);
    }while(check = ('O'|'o'|'e'|'E'));
    if(check = ('O'|'o')) {
      classe[nbEtu] = classe[0];
      printf("\nChangement enregistre!\n");
    }
    return nbEtu;
};
