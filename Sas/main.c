#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int annee;
    int mois;
    int jour;
} Date;
typedef enum
{
    a_realiser=0,
    en_cours_de_realisation=1,
    finalisee=2,
} Statut;

typedef struct
{
    int id;
    char titre[30];
    char description[300];
    Date daedline;
    Statut S;
} Tache;
int nombredetache=0;
void ajouteruneTache(Tache T[])
{
    if(nombredetache<200)
    {
        getchar();
        T[0].id=nombredetache;
        printf("l'identifient est: %d\n",T[0].id);

        printf("donner le titre\n");
        gets(T[nombredetache].titre);//pour lire les espaces;
        printf("donner la description\n");
        gets(T[nombredetache].description);
        if(T[nombredetache].S==0)
        {
            printf("le statut est a realiser");
        }
        nombredetache++;
    }
    else
    {
        printf("c'est impossible d'ajouter une tache.\n");
    }

}
int main()
{
    int ntaches;
    int choix;
    Tache T[200];
while(1){
    printf("**********MENU**********\n");
    printf("1- Ajouter une nouvelle tache\n");
    printf("2- Ajouter plusieurs nouvelles taches\n");
    printf("3- Afficher la liste de toutes les taches\n");
    printf("4- Modifier une tache\n");
    printf("5- Supprimer une tache par identifiant\n");
    printf("6- Rechercher les taches\n");
    printf("7- Statistiques\n");
    printf("8- Exit\n\n\n");
    printf("Saisir votre choix: ");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        ajouteruneTache(T);
        break;
    case 2:


        printf("combien de taches voulez-vous ajouter?\n");
        scanf("%d",&ntaches);
        int N=nombredetache+ntaches; //nbr_taches existantes et ajoutees;
        for(int i=nombredetache; i<N; i++)
        {

            ajouteruneTache(T);

        }

        break;

    case 3:
    {

        int soustest=0;
        do
        {
            printf("---------------Sous-Menu-----------------\n");
            printf("1- Trier les taches par ordre alphabetique\n");
            printf("2- Trier les taches par deadline\n");
            printf("3- Afficher les taches dont le deadline est dans 3 jours ou moins\n");
            printf("4- Retour au menu principal\n");
            printf("Saisir votre choix:");
            scanf("%d",&choix);

            switch (choix)
            {
            case 1:
            {
                int ind,i,j;
                Tache v;
                for(i=0; i<nombredetache-1; i++)
                {
                    ind =i;
                    for(j=i+1; j<nombredetache; j++)
                    {
                        if(strcmp(T[j].titre,T[ind].titre)==-1)
                        {
                            ind=j;
                        }
                    }
                    if(i!=ind)
                    {
                        v= T[i];
                        T[i]=T[ind];
                        T[ind]=v;
                    }
                }
            }
            break;
            case 2:{
                int idf;
                printf("Entrez l'identifiant de la tache que vous voulez modifier:");
                scanf("%d",&idf);
                int loc_idf = trouver idf(Tache,nombredetache,idf);
                if(loc_idf != -1)
                {
                    switch (choix)
                {
                case 1:
                    getchar();//lire retour en ligne
                    printf("Description:");
                    fgets(tache[loc_idf].description,sizeof(tache[loc_idf].description),stdin);
                    break;
                case 2:
                    changer_statut(tache,loc_idf);
                    break;
                case 3:
                    entrer_deadline(tache,loc_idf);
                    break ;
                default:
                    printf("Impossible choix,entrez un choix possible.\n");
                    break ;

                    }
                }
                break;
            }
            case 3:
                //affiche
                break;
            case 4:
                soustest=1;
                break;
            }
        }
        while(soustest==0);
    }
    break;


    case 4:
        printf("1- Modifier la description d'une tache\n");
        printf("2- Modifier le statut d'une tache\n");
        printf("3- Modifier le deadline d'une tache\n");
        printf("4- Retour au menu principal\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
                int idf;
                printf("Entrez l'identifiant de la tache que vous voulez modifier:");
                scanf("%d",&idf);
                int loc_idf = trouver idf(Tache,nombredetache,idf);
                if(loc_idf != -1)
                {
                    switch (choix)
                {
                case 1:
                    getchar();//lire retour en ligne
                    printf("Description:");
                    fgets(tache[loc_idf].description,sizeof(tache[loc_idf].description),stdin);
                    break;
                case 2:
                    changer_statut(tache,loc_idf);
                    break;
                case 3:
                    entrer_deadline(tache,loc_idf);
                    break ;
                default:
                    printf("Impossible choix,entrez un choix possible.\n");
                    break ;

                    }
                }
               else
               {
                   printf("l'identifiant est introuvable.\n");
               }
        }
        while(!retour_menu_principal);
    }
    else{

        printf("la liste des taches est vide.\n");
    }

            break;
        case 2:
            break;
        }
case 8:exit(1);break;
    }
}
    return 0;
}
