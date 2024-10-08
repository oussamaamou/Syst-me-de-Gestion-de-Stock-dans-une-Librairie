#include<stdio.h>
#include<string.h>


#define LONG_MAX_LIVRE 100
#define TAILLE_MAX_TABLEAU 100

char Titre[LONG_MAX_LIVRE][TAILLE_MAX_TABLEAU];
char Auteur[LONG_MAX_LIVRE][TAILLE_MAX_TABLEAU];
float Prix[LONG_MAX_LIVRE];
int Quantite[LONG_MAX_LIVRE];

int NomLivres = 0;
int NomTotal = 0;


int main(){
    int choix;
    char Recherche_Livre[TAILLE_MAX_TABLEAU];
    printf("\n\t------Gestion du Stock dans la Librairie------\t\n");
    do{        
        printf("\n------------------------------------------\n");
        printf("Appuyer sur 1 pour Ajouter un livre:\n");
        printf("Appuyer sur 2 pour Afficher tous les livres disponobles:\n");
        printf("Appuyer sur 3 pour Chercher un livre:\n");
        printf("Appuyer sur 4 pour Mettre a jour la quantite d'un livre:\n");
        printf("Appuyer sur 5 pour Supprimer un livre du stock:\n");
        printf("Appuyer sur 6 pour Afficher le nombre totale des livres disponobles dans le stock:\n");
        printf("Appuyer sur 7 pour Sortir du programme:\n");
        printf("\n------------------------------------------\n");
        printf("\tVeuillez entrer votre choix:");
        scanf("%d", &choix);
        getchar();
        switch(choix){
            
            case 1:
                  if (NomLivres >= LONG_MAX_LIVRE)
                     printf("Le stock est deja plein, vous ne pouvez pas ajouter de livre !!\n");
                  else{
                    printf("Entrer le titre du livre:");
                    scanf("%[^\n]%*c", Titre[NomLivres] );
                    printf("Entrer l'auteur du livre:");
                    scanf("%[^\n]%*c", Auteur[NomLivres] );
                    printf("Entrer le prix du livre:");
                    scanf("%f", &Prix[NomLivres] );
                    printf("Entrer la quantite du livre:");
                    scanf(" %d", &Quantite[NomLivres] );
                  }   
                  NomLivres ++;
                  printf("\nVotre livre est ajoute avec succee.");
                  break;
            
            case 2:
                  if (NomLivres  == 0) {
                printf("Aucun livre en stock.\n");
                  }
                  else{
                     for (int i = 0; i < NomLivres; i++) {
                        printf("Titre: %s\n", Titre[i]);
                        printf("Auteur: %s\n", Auteur[i]);
                        printf("Prix: %.2f\n", Prix[i]);
                        printf("Quantité: %d\n", Quantite[i]);                        
                    }
                }
                break;
           
            case 3: 
                    int Recherche = 0;
                    printf("Entrez le titre du livre a rechercher : ");
                    scanf("%[^\n]%*c", Recherche_Livre);

                    for (int i = 0; i < NomLivres; i++) {
                        if (strcmp(Titre[i], Recherche_Livre) == 0) {
                            printf("Livre trouve!\n");
                            printf("Titre: %s\n", Titre[i]);
                            printf("Auteur: %s\n", Auteur[i]);
                            printf("Prix: %.2f\n", Prix[i]);
                            printf("Quantité: %d\n", Quantite[i]);
                            Recherche=1;
                            break;
                        }
                    }
                    if (!Recherche){
                        printf("Livre indisponible.\n");
                    }
                
                break;
                 
            case 4:
                    printf("Entrez le titre du livre pour mettre à jour la quantité : ");
                    scanf("%[^\n]%*c", Recherche_Livre);

                    for (int i = 0; i < NomLivres; i++) {
                        if (strcmp(Titre[i], Recherche_Livre) == 0) {
                            printf("Entrez la nouvelle quantité : ");
                            scanf("%d", &Quantite[i]);
                            printf("Quantité mise à jour.\n");
                            Recherche=1;
                            break;
                        }
                    }
                    if (!Recherche){
                        printf("Livre non trouvé.\n");
                    }
                    break;
               
            case 5:
                    printf("Entrez le titre du livre à supprimer : ");
                    scanf("%[^\n]%*c", Recherche_Livre);

                    for (int i = 0; i < NomLivres; i++) {
                        if (strcmp(Titre[i], Recherche_Livre) == 0) {
                            for (int j = i; j < NomLivres - 1; j++) {
                                strcpy(Titre[j], Titre[j + 1]);
                                strcpy(Auteur[j], Auteur[j + 1]);
                                Prix[j] = Prix[j + 1];
                                Quantite[j] = Quantite[j + 1];
                            }
                            NomLivres--;
                            printf("Livre supprime avec succee.\n");
                            Recherche=1;
                            break;
                        }
                    }
                    if (!Recherche){
                        printf("Livre non trouvé.\n");
                    }
                    break;
            
            case 6:
                    for (int i = 0; i < NomLivres; i++) {
                    NomTotal += Quantite[i];
                }
                printf("Nombre total de livres en stock est: %d\n", NomTotal);
                break;
            
            case 7: 
                printf("Programme Ferme.\n");
                break;   

            default : 
                printf("Choix invalide!! Choisissez un autre choix.");
                break;        
        }                   
    }while( choix != 7);


    return 0;
}
