/* Gérer une classe de max. 25 étudiants
   1 étudiant = - identifiant unique
                - nom, prénom
                - adresse (rue, numéro, code postal, ville)
                - tableau de 5 cotes (réel/20)

   Faire des procédure pour encoder, supprimer et modifier un étudiant sur base de son identifiant,
   Faire une fonction encoder cotes,
   Afficher la classe.
*/




#include <stdio.h>
#include <stdlib.h>
#define NE 25       // Le nombre d'étudiants vaut 25
#define NC 5

   typedef struct{         // Définition d'une adresse (enregistrement)
           char rue[50];
           int numero;
           int CP;
           char ville[20];
   }Tadresse;

    typedef struct{
            char cours[20];
            double cote;
    }TCote;


   typedef struct{         // Définition d'un étudiant
           int id;
           char nom[25];
           char prenom[20];
           Tadresse adresse;
           TCote tbCote[NC];
    }Tetudiant;




Tetudiant etu[NE];
int  nb=0;
int idRech =0 ;
int ident =1 ;                      //L'identifiant qui augmente de 1 à chaque élèves enregistré




int Recherche() {
int i;
for(i=0;i<nb && idRech!=etu[i].id;i++);     //condition de sortie
if(etu[i].id == idRech) return i;           // si l'id demandé est présent dans le tebleau -> renvoie la case concerné
else return -1;                             //si pas -> renvoie -1

}


void encoderEtudiant(){
    if (ident > NE){
        printf("Erreur, la classe est au maximum\n");
        system("pause");
        initialisation();
    }
    int i=0;                           // PROCEDURE encoder un étudiant
    printf("Entrez le prenom de l'etudiant: \n");
    gets(etu[nb].prenom);
    printf("Entrez le nom de l'etudiant: \n");
    gets(etu[nb].nom);
    etu[nb].id = ident;
    fflush(stdin);
}

void encoderAdresse(){
    printf("Entrez la ville de l'etudiant: \n");
    gets(etu[nb].adresse.ville);
    printf("Entrez la rue de l'etudiant: \n");
    gets(etu[nb].adresse.rue);
    printf("Entrez le numero de l'etudiant: \n");
    scanf("%d",&etu[nb].adresse.numero);
    fflush(stdin);
    printf("Entrez le code postal de l'etudiant: \n");
    scanf("%d",&etu[nb].adresse.CP);
    fflush(stdin);
    ident = ident + 1;

}

void afficherClasse() {
    int i;                            //afficher les élèves enregistrés
    if (nb == 0)  printf("Aucun eleve n'est enregistre\n");          //Si aucun eleve enregistré = erreur
    else
        printf("Voici le nom, prenom et ID des eleves enregistres\n\n");    //affiche tout les eleves enregistré
    for(i=0;i<nb;i++) {
        printf("%d) %s - ",i+1, etu[i].nom);
        printf("%s - ",etu[i].prenom);
        printf("%d \n",(etu[i].id));
        printf("\n");
    }
}

void inverser(){
    int i;
    i = Recherche();
    etu[i] = etu[nb-1];
}

void supprimerEleve() {                             //Supprimer un élèves enregistré
    char rep;
    printf("Indiquez l'ID de l'eleve que vous souhaitez supprimer : ");     // recherche depuis l'id
    scanf("%d",&idRech);
    fflush(stdin);
    int i;
    i=Recherche();                                                             //fonction recherche
    if ( i == -1)
        printf("Cet eleve n'est pas enregistre\n");                         //si la fonction rechrche renvoie -1 c'est que l'id n'est pas présent

    else printf("Etes-vous sur de vouloir suprimer cet eleve (o/n) ? %s %s \n",etu[i].nom, etu[i].prenom); //si présent -> confirmation de la demande
    scanf("%c",&rep);
    fflush(stdin);
        if (rep == 'o'){                     //si oui
                inverser();
                nb--;             // une case en moins
                }

        else {initialisation();             //retour menu
        }

}


void MenuModification(){                            //Menu pour modifier un eleve enregistré
    int choix;
    int i;
    i = Recherche();

    system("cls");                                  // le menu
    printf("Que voulez-vous modifier ?\n\n");
    printf("1) Modifier le nom\n");
    printf("2) Modifier le prenom\n");
    printf("3) Modifier la rue\n");
    printf("4) Modifiez le numero\n");
    printf("5) Modifier le code postal\n");
    printf("6) Modifier la ville\n\n");
    printf("7) Retour\n");

    scanf("%d",&choix);
    fflush(stdin);

    switch (choix) {

        case 1 :    system("cls");                      //modifie le nom
                    printf("modifiez le nom : \n");
                    scanf("%s",&etu[i].nom);
                    MenuModification();
                    break;

        case 2 :    system("cls");                      //modifie le prenom
                    printf("Modifiez le prenom : \n");
                    scanf("%s",&etu[i].prenom);
                    MenuModification();
                    break;


        case 3 :    system("cls");                      //modifie la rue
                    printf("Modifiez la rue : \n");
                    scanf("%s",&etu[i].adresse.rue);
                    MenuModification();
                    break;

        case 4 :    system("cls");                      //Modifie le numero
                    printf("Modifiez le numero : \n");
                    scanf("%d",&etu[i].adresse.numero);
                    MenuModification();
                    break;

        case 5 :    system("cls");                      //Modifie le CP
                    printf("Modifiez le code postal : \n");
                    scanf("%d",&etu[i].adresse.CP);
                    MenuModification();
                    break;

        case 6 :    system("cls");                      //Modifie la ville
                    printf("Modifiez la ville : \n");
                    scanf("%s",&etu[i].adresse.ville);
                    MenuModification();
                    break;

        case 7 : initialisation();                      //retour menu
    }

}


void modifierEtudiant() {
    int i;                          //Modifier un eleve
    char rep;
    printf("Indiquez l'ID de l'eleve que vous voulez mofifier : ");         //recherche de l'eleve via son ID
    scanf("%d",&idRech);
    fflush(stdin);
    i=Recherche();                                //fonction recherche
    if (Recherche() == -1)                      // erreur si l'ID n'est pas enregistré
        printf("Cet eleve n'est pas enregistre\n");

    else printf("Confirmez-vous de vouloir modifier cette etudiant ? (o/n) %s %s \n",etu[i].nom, etu[i].prenom);    //confirmation de l'eleve
    scanf("%c",&rep);
    fflush(stdin);
        if (rep == 'o'){
            MenuModification();                         // aller au menu de modification

        }
        else {
            initialisation();                           //Retour Menu
        }

}

void ajouterCote(){
    int i;
    int j=0;
    int rep;
    i = Recherche();
    do {
        system("cls");
        printf("Quelle matière ?\n");
        gets( etu[i].tbCote[j].cours);
        printf("La cote ( /20) : \n");
        scanf("%lf\n", & etu[i].tbCote[j].cote);
        fflush(stdin);
        j = j+1;
        printf("Voulez-vous ajouter une autre cote ? (o/n)");
        scanf("%c\n", &rep);
        fflush(stdin);
    }
    while  (rep == 'n');
}



void encoderCote(){                                 //encoder une cote pour un eleve donné
  int i;
  char rep;
  printf("Indiquez l'ID de l'eleve que vous voulez mofifier : ");         //recherche de l'eleve via son ID
  scanf("%d",&idRech);
  fflush(stdin);
  i=Recherche();                                //fonction recherche
  if (Recherche() == -1)                      // erreur si l'ID n'est pas enregistré
      printf("Cet eleve n'est pas enregistre\n");

  else printf("Confirmez-vous de vouloir modifier cette etudiant ? (o/n) %s %s \n",etu[i].nom, etu[i].prenom);    //confirmation de l'eleve
  scanf("%c",&rep);
  fflush(stdin);
    if (rep == 'o'){
            ajouterCote();
    }
    else{
        initialisation();
    }
}




void initialisation(){                              //MEnu de base
    int choix;
    char rep;

    system("cls");
    printf("-------------------------------------------------------------------------------\n");
    printf("                                  BIENVENUE\n");
    printf("-------------------------------------------------------------------------------\n");
    printf(" \n");
    printf(" \n");
    printf("Que voulez-vous faire?\n");
    printf(" \n");
    printf("1) Afficher la classe\n");
    printf("2) Encoder un etudiant\n");
    printf("3) Supprimer un etudiant\n");
    printf("4) Modifier un etudiant\n");
    printf("5) Encoder une cote\n");
    printf("6) Exit\n");

    scanf("%d",&choix);
    fflush(stdin);

    switch (choix){
        case 1 : afficherClasse();
                 break;
        case 2 :
                  do {                //enregistre un nouvel eleve jusque 'n'
                    system("cls");
                    encoderEtudiant();
                    encoderAdresse();
                    nb++;
                    printf("Voulez-vous encoder un nouvel eleve ? (o/n) \n\n");
                    scanf("%c",&rep);
                    fflush(stdin);
                 }while (rep == 'o');
                    break;

          case 3 : supprimerEleve();
                   break;

          case 4 : modifierEtudiant();
                   break;

          case 5 : encoderCote();
                   break;

          case 6 : printf("au revoir\n");
                   return 0;
                   break;

                 }
        printf("\n");
}


int comeBack(){                                     //Fonction retour menu
    char choix;
    choix='0';

    printf("voulez-vous revenir au menu principal? o/n  \n");
    scanf("%c",&choix);

    if(choix=='o') return 0;
    else return -1;
}




int main(void){

    do {
    initialisation();
    }
    while (comeBack()==0);

}
