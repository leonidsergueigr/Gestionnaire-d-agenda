#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 50
struct evenement{
    char titre[TAILLE];
    char date[11];
    char heure_debut[6];
    char heure_fin[6];
    char description[TAILLE];
};
char titre[TAILLE];
char str_heure_debut[6];
char str_heure_fin[6];
char str_date[10];
char description[50];
char titre[TAILLE];

void afficher_menu();
int date_valide();
int heure_valide();
int hd_av_hf();
void afficher_evenement();
void ajouter_evenement();

int main(){
    int nb_evenement = 0;
    int choix;
    struct evenement agenda[51];
    do {
        system("cls");
        afficher_menu();
        scanf("%d", &choix);
        switch(choix){
            case 1:
                ajouter_evenement(agenda, nb_evenement);
                nb_evenement++;
                break;
            case 2:
                system("cls");
                printf("\nSUPPRESSION EVENEMENT\n");
                char titre_supprime[50];
                if(nb_evenement ==0){
                    printf("Il y a pas d'evenement a supprimer!\n");
                }
                else{
                    int choix2;
                    do{
                        int choix2;
                        printf("1.Supprimer un evenement\n");
                        printf("2.Supprimer tout les evenements\n");
                        printf("3.Retour\n");
                        printf("Que voulez?: \n>");
                        scanf("%d", &choix2);
                        if(choix2==1){
                            system("cls");
                            printf("\nSUPPRESSION EVENEMENT\n");
                            printf("Entrez le titre de l'evenement a supprimer?: ");
                            getchar();
                            fgets(titre_supprime, TAILLE, stdin);
                            for(int i = 0; i<nb_evenement; i++){
                                int test = strcmp(agenda[i].titre,titre_supprime);
                                if(test==0){
                                    for (int j = i; j < nb_evenement - 1; j++) {
                                        agenda[j] = agenda[j+1];
                                    }
                                    printf("Evenement supprime avec succes!\n\n");
                                    printf("Appuyez sur une touche pour continuer...\n");
                                    getch();
                                    nb_evenement--;
                                }
                                else{
                                    printf("Evenement introuvable!\n");
                                }

                            }
                            break;
                        }else if(choix2==2){
                            for(int i=0;i<nb_evenement;i++){
                                agenda[i]=agenda[51];
                                nb_evenement = 0;
                            }
                            system("cls");
                            printf("Tout les evenement sont supprimes\n");
                            printf("Appuyez sur une touche pour continuer...\n");
                            getch();
                            break;
                        }else if(choix2==3){
                            break;
                        } else{
                            system("cls");
                            printf("Choix invalide!\n");
                        }
                    }while(choix2 != 3);
                break;
                }
            case 3:
                system("cls");
                afficher_evenement(agenda, nb_evenement);
                break;
            case 4:
                system("exit");
                system("cls");
                printf("Arret programme!\nAu revoir\n");

                break;
            default:
                system("cls");
                printf("Entrer un choix valide!\n\n");
                printf("Appuyer sur une touche pour continuer...\n");
                getch();
                break;
        }
    }while (choix != 4);
    return 0;
}

void afficher_menu(){
    printf(" --------------------- \n");
    printf("|GESTIONNAIRE D'AGENDA|\n");
    printf(" --------------------- \n");
    printf("\nMenu\n");
    printf("1. Ajouter un evenement\n");
    printf("2. Supprimer evenement\n");
    printf("3. Afficher evenement\n");
    printf("4. Quitter\n\n");
    printf("Que voulez?: \n>");
}
int date_valide(char *date){
    int jour, mois, annee;
    if(sscanf(date, "%d/%d/%d",&jour,&mois,&annee)!=3){
        return 0;
    }
    if (jour<0 || jour>31 || mois <0 || mois>12 || annee<23){
        return 0;
    }
    return 1;
}
int heure_valide(char *heure){
    int h, m;
    if(sscanf(heure, "%d:%d", &h,&m)!=2){
        return 0;
    }
    if (h<0 || h>23 || m<0 || m>59){
        return 0;
    }
    return 1;
}
int hd_av_hf(char *heure1, char *heure2){
    int h1, h2, m1, m2;
    sscanf(heure1, "%d:%d", &h1,&m1);
    sscanf(heure2, "%d:%d", &h2,&m2);
    if(h1>h2 || (h1==h2 && m1>m2)){
        return 0;
    }
    return 1;
}
void afficher_evenement(struct evenement *agenda, int *nb_evenement){
    int n = nb_evenement;
    printf("\nAFFICHAGE EVENEMENT\n");
    if(nb_evenement==0){
        printf("Il y a pas d'evenement en cours!\n\n");
        printf("Appuyez sur une touche pour continuer...\n");
        getch();
    }
    else {
        int choix3;
        do{
            printf("1.Afficher un evenement\n");
            printf("2.Afficher tout les evenements\n");
            printf("3.Retour\n");
            printf("Votre choix\n>");
            scanf("%d", &choix3);
            char date[11];
            switch(choix3){
                case 1:
                    system("cls");
                    printf("\nAFFICHAGE EVENEMENT\n");
                    do{
                        printf("Entrez la date de l'evenement: ");
                        scanf("%s", date);
                        if(!date_valide(date)){
                            printf("Veuillez entrez une date correcte!\n");
                        }
                    }while(!date_valide(date));
                    system("cls");
                    printf("AFFICHAGE EVENEMENT\n");
                    int nb_evenement_trouve = 0;
                    for(int i = 0; i<n;i++){
                        int date_trouve = strcmp(date,agenda[i].date);
                        if(date_trouve==0){
                            printf("Titre : %s", agenda[i].titre);
                            printf("Date : %s \n", agenda[i].date);
                            printf("Heure de debut : %s \n", agenda[i].heure_debut);
                            printf("Heure de fin : %s \n", agenda[i].heure_fin);
                            printf("Description : %s \n", agenda[i].description);
                            nb_evenement_trouve++;
                        }
                    }
                    if(nb_evenement_trouve==0){
                        system("cls");
                        printf("Desole, evenement introuvable!\n");
                    }
                    printf("Appuyer sur une touche pour continuer...");
                    getch();
                    break;
                case 2:
                    system("cls");
                    for (int i = 0; i < n; i++) {
                        printf("Titre : %s", agenda[i].titre);
                        printf("Date : %s \n", agenda[i].date);
                        printf("Heure de debut : %s \n", agenda[i].heure_debut);
                        printf("Heure de fin : %s \n", agenda[i].heure_fin);
                        printf("Description : %s \n\n", agenda[i].description);
                        if(i==n-1){
                            printf("Appuyez sur une touche pour continuer...\n");
                            getch();
                            break;
                        }
                    }
                    break;
                case 3:
                    break;
                default:
                    printf("Choix invalide!\n");
                    break;
            }
            break;
        }while(choix3!=3);
    }
}
void ajouter_evenement(struct evenement *agenda,int *nb_evenement){
    int n = nb_evenement;
    system("cls");
    printf("\nAJOUT EVENEMENT\n");
    if(n<50){
        do{
            printf("Titre de l'evenement: ");
            getchar(); // pour vider le buffer avant de lire la chaîne avec fgets()
            fgets(titre, TAILLE, stdin);
            //titre[strcspn(titre, "\n")] = '\0';
            if(strlen(titre)==0){
                printf("Veuillez entrez un titre a votre evenement S.V.P!\n");

            }
        }while(strlen(titre)==0);
        strcpy(agenda[n].titre, titre);
        do{
            printf("Date de l'evenement(JJ/MM/AA) : ");
            scanf("%s", str_date);
            if(!date_valide(str_date)){
                printf("Veuillez entrer une date valide S.V.P!\n");
            }
        }while(!date_valide(str_date));
        strcpy(agenda[n].date, str_date);
        do{
            do{
                printf("Heure du debut(hh:mm) en format 24h: ");
                scanf("%s", str_heure_debut);
                if(!heure_valide(str_heure_debut)){
                    printf("Entrez une heure valide S.V.P!\n");
                }
            }while(!heure_valide(str_heure_debut));
            do{
                printf("Heure fin (hh:mm) en format 24h: ");
                scanf("%s", str_heure_fin);
                if(!heure_valide(str_heure_fin)){
                    printf("Entrez une heure valide S.V.P!\n");
                }
            }while(!heure_valide(str_heure_fin));
            if(!hd_av_hf(str_heure_debut,str_heure_fin)){
                printf("L'heure du fin ne doit pas etre avant l'heure du debut!\n");
            }
        }while(!heure_valide(str_heure_debut)&&!heure_valide(str_heure_fin) || !hd_av_hf(str_heure_debut,str_heure_fin));
        strcpy(agenda[n].heure_debut, str_heure_debut);
        strcpy(agenda[n].heure_fin, str_heure_fin);
        printf("Description de l'evenement : ");
        getchar();
        fgets(description, TAILLE, stdin);
        if(strlen(description)-1==0){
            strcpy(agenda[n].description, "Pas de description");
        }else{
            strcpy(agenda[n].description, description);
        }
        printf("\nL'evenement a ete ajoute avec succes!\n\n");
        printf("Appuyez sur une touche pour continuer...\n");
        getch();
    }else{
        printf("Desole, le stockage est plein!\n");
        printf("Appuyez sur une touche pour continuer...");
        getch();
    }
}

