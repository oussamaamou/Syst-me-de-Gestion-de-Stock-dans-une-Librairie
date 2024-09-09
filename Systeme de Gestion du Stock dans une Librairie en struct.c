#include<stdio.h>
#include<string.h>

char Titre[100];
char Auteur[100];
float Prix;
int Quantite;
int i,j;

typedef struct{
    char Titre[100];
    char Auteur[100];
    float Prix;
    int Quantite;

}Livre;

int NbrLivres = 0;
Livre Livres[100];
int Recherche = 0;

void AjouterUnLivre(){
    printf("Veuillez entrer le titre du livre :");
    scanf("%[^\n]%*c",&Livres[NbrLivres].Titre);
    printf("Veuillez entrer l'auteur du livre :");
    scanf("%[^\n]%*c",&Livres[NbrLivres].Auteur);
    printf("Veuillez entrer le prix du livre :");
    scanf("%f",&Livres[NbrLivres].Prix);
    printf("Veuillez entrer la quantite du livre :");
    scanf("%d",&Livres[NbrLivres].Quantite);
    NbrLivres ++;
    printf("\t Le livre a ete ajouter avec succes.");

}

void AfficherTousLesLivres(){
    if(NbrLivres == 0){
        printf("\t Aucun livre au stock !!!");
    }
    else{
        for(i=0;i<NbrLivres;i++){
           printf("Le titre du livre : %s\n",Livres[i].Titre);
           printf("L'auteur du livre : %s\n",Livres[i].Auteur);          
           printf("Le prix du livre : %.2f\n",Livres[i].Prix);
           printf("La quantite du livre : %d\n",Livres[i].Quantite);        
           printf("----------------------------------------------------------------\n");
        }
    }

}

void MettreJourQuttLivre(){
    printf("Veuillez entrer le titre du livre :");
    scanf("%[^\n]s",&Titre);
     for(i=0;i<NbrLivres;i++)
        if(strcmp(Livres[NbrLivres].Titre,Titre) == 0){
            printf("Veuillez entrer la nouvelle quantite:");
            scanf("%d",&Livres[i].Quantite);
            printf("La quantite a ete modifier avec succes.");
            Recherche = 1;
            break;
        }   
        
    if (!Recherche)
        printf("\t Le titre que vous avez entrer est incorrect!!!");

}

void SupprimerUnLivre(){
    printf("Veuillez entrer le titre du livre :");
    scanf("%[^\n]s",&Titre);   
    for(i=0;i<NbrLivres;i++){
        if(strcmp(Livres[i].Titre,Titre)==0){
            for(j=i;j<NbrLivres - 1;j++){
                Livres[j]=Livres[j+1];
                NbrLivres --;
                printf("Le livre a ete supprimer avec succes.");
                Recherche = 1;
                break;
            }
        }
    }    
    if (!Recherche)
        printf("\t Le titre que vous avez entrer est incorrect!!!");
}

void NbrTtleLivresStock(){
    printf("Les livres qui se trouvent en stock sont:\n");
    for(i=0;i<NbrLivres;i++){
        printf("%[^\n]s\n",Livres[i].Titre);
        NbrLivres += Livres[i].Quantite;
    }
    printf("----------------------------------------------------------------\n");
    printf("La quantite total des livres en stock est : %d",NbrLivres);



}

int main(){
    int Choix;
    int Recherche = 0;
    printf("\n\t------Gestion du Stock dans la Librairie------\t\n");
    do {
        
        printf("\n------------------------------------------\n");
        printf("Appuyer sur 1 pour Ajouter un livre:\n");
        printf("Appuyer sur 2 pour Afficher tous les livres disponobles:\n");
        printf("Appuyer sur 3 pour Mettre a jour la quantite d'un livre:\n");
        printf("Appuyer sur 4 pour Supprimer un livre du stock:\n");
        printf("Appuyer sur 5 pour Afficher le nombre totale des livres disponobles dans le stock:\n");
        printf("Appuyer sur 6 pour Sortir du programme:\n");
        printf("\n------------------------------------------\n");
        printf("\tVeuillez entrer votre choix:");
       
        scanf("%d",&Choix);
        getchar();
        
        switch(Choix){
            case 1:
                AjouterUnLivre();
                break;
            
            case 2:
                AfficherTousLesLivres();
                break;
            
            case 3:
                MettreJourQuttLivre();
                break;
            
            case 4:
                SupprimerUnLivre();
                break;
            
            case 5:
                NbrTtleLivresStock();
                break;
            
            case 6:
                printf("\t Le programme est ferme :(");
                break;
            
            default : 
                printf("Choix invalide!! Veuillez entrer un autre choix.");
                break;


        }

    } while( Choix != 6);





   return 0; 
}
