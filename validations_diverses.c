#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//prend le nombre de notes donnees en entree
#define TAILLE argc-1
#define NOM argv[0]
#define TAILLE_LETTRES 12

//valider ce quentre le user est bien des donnees numeros
void validerNotesFournies(const char *notes);
//valider que le code permanent fourni respecte le bon format
void validerCodePerm(const char* codePerm);
//valider que notre array de notes recu est dans les limites
void validerValeursPermises(char *notesPermises, const char *notes);
//remplissage des tableaux des pondérations et des notes max
void remplissage ( int tableaux[],int taille);
// renvoie la note pondérée pour un étudiant
double calculNote (int ponderation[], int noteMax[], int nombreEval);
// assigne la note Lettrée en fonction de la note pondérée
int calculNoteLettree(double seuils [], double note, double nbEtudiantsParNote[]);
// Affichage de l'histogramme
void affichage(double nbEtudiantsParNote[], char *notationLettree[]);




int main(int argc, char *argv[]){
    
    int nombreEval ;
    double seuils[11];
    int iterateur;
    char leCar[5];
    double nbEtudiants =0;
    double nbEtudiantsParNote [TAILLE_LETTRES];
    char *notationLettree [TAILLE_LETTRES] = {"E","D","D+","C-","C","C+","B-","B","B+","A-","A","A+"};
   
    
    if (argc != TAILLE_LETTRES) {
        fprintf(stderr, "Le nombre d'arguments n'est pas valide.\n");
        exit(EXIT_FAILURE);
    }

    for (iterateur = 0; iterateur < TAILLE_LETTRES; ++iterateur){
        nbEtudiantsParNote[iterateur] = 0;
    }
    
    for (iterateur=1 ; iterateur< argc ;  ++iterateur) {
        seuils[iterateur-1] = strtold(argv[iterateur],NULL);
//        printf ("%.2f\n",seuils[iterateur-1]);
    }
    scanf("%s",leCar);
    nombreEval = (int)strtol(leCar,NULL,10);
//    printf("%d\n",nombreEval);
    
    int ponderation [nombreEval];
    int noteMax[nombreEval];
    remplissage (ponderation, nombreEval);
    remplissage (noteMax,nombreEval);

    char codePerm[12];
    int carac =getchar();
    
    
    while (carac!= EOF ){
        while (isspace(carac)){
            carac = getchar();
            if (carac == EOF)
                break;
        }
        ungetc(carac,stdin);
        scanf("%s",codePerm);
        validerCodePerm(codePerm);
        double note = calculNote(ponderation,noteMax,nombreEval);
        calculNoteLettree(seuils,note,nbEtudiantsParNote);
        carac =getchar();
        ++nbEtudiants;
    }
    
//    printf("%.0f\n",nbEtudiants);
    int i;
    for (i = 0; i < 12; ++i) {
        printf("%.0f\n",nbEtudiantsParNote[i]);
    }
    affichage(nbEtudiantsParNote,notationLettree);
    
    return(0);
    
}
/*
 
 
 */
void remplissage (int tableaux[],int taille){
    char charLu[10];
    int i;
    for (i= 0; i < taille; ++i) {
        scanf("%s",charLu);
        tableaux[i] = strtol(charLu,NULL,10);
//        printf("%d ",tableaux[i]);
    }
//    printf("\n");
    
}
/*
 
 
 */
void validerCodePerm(const char* codePerm){
  int i;
	for (i = 0; i < 4; ++i){
        if(!(isalpha(codePerm[i]))){
        fprintf(stderr, ": Code Permanent non conforme \n");
        exit(EXIT_FAILURE);
        }
    }
    for (i=4; i<12; ++i) {
        if(!(isdigit(codePerm[i]))){
        fprintf(stderr, "Code Permanent non conforme \n");
        exit(EXIT_FAILURE);
        }
    }
}
/*
 
 
 */
double calculNote (int ponderation[], int noteMax[], int nombreEval){
    double notes[nombreEval];
    char charLu[10];
    int i;
    double noteTotal=0;
    for (i=0; i<nombreEval; i++) {
        scanf ("%s",charLu);
        notes[i]= strtold(charLu,NULL);
//        printf ("%.2f ",notes[i]);
        noteTotal += (notes[i]/noteMax[i])*ponderation[i];
//        printf("%.2f\n",noteTotal);
    }
//    printf("%.2f\n",noteTotal);
    return (noteTotal);
}

/*
 
 
 */
int calculNoteLettree(double seuils [], double note, double nbEtudiantsParNote[]){
    int noteLettree =0;
    if (note >=0 && note <= 100)
    {
        
        if (note >= seuils[0]){
            noteLettree = 1;
            ++nbEtudiantsParNote[0];
        }
        else if (note > seuils[1] && note  <=seuils[0]){
            noteLettree = 2;
            ++nbEtudiantsParNote[1];
        }
        else if (note > seuils[2] && note <= seuils[1]){
            noteLettree = 3;
            ++nbEtudiantsParNote[2];
        }
        else if (note > seuils[3] && note <= seuils[2]){
            noteLettree = 4;
            ++nbEtudiantsParNote[3];
        }
        else if (note > seuils[4] && note <= seuils[3]){
            noteLettree = 5;
            ++nbEtudiantsParNote[4];
        }
        else if (note > seuils[5] && note <= seuils[4]){
            noteLettree = 6;
            ++nbEtudiantsParNote[5];
        }
        else if (note > seuils[6] && note <= seuils[5]){
            noteLettree = 7;
            ++nbEtudiantsParNote[6];
        }
        else if (note > seuils[7] && note <= seuils[6]){
            noteLettree = 8;
            ++nbEtudiantsParNote[7];
        }
        else if (note > seuils[8] && note <= seuils[7]){
            noteLettree = 9;
            ++nbEtudiantsParNote[8];
        }
        else if (note > seuils[9] && note <= seuils[8]){
            noteLettree = 10;
            ++nbEtudiantsParNote[9];
        }
        else if (note > seuils[10]&& note <= seuils[9]){
            noteLettree = 11;
            ++nbEtudiantsParNote[10];
        }
        else{
            noteLettree = 12;
            ++nbEtudiantsParNote[11];
        }
    }
    else
    {
        fprintf(stderr,"La note %.2f n'est pas valide",note);
    }
   
//    printf("%d\n",noteLettree);
    return noteLettree;
    
}
/*
 
 
 */

void affichage(double nbEtudiantsParNote[], char *notationLettree[]){
    int i,j;
    int nbX;
    double div1;
    for (i=0; i <TAILLE_LETTRES; ++i) {
        printf("%-5s",notationLettree[i]);
        nbX = nbEtudiantsParNote[11-i];
        if (nbEtudiantsParNote[11-i] > 50){
            div1 = nbEtudiantsParNote[11-i]/50;
            nbX = (nbEtudiantsParNote[11-i]/div1);
        }
//        printf("******** nb etudiants :%.2f   nbEtudiants par note %.2f     \n *********",nbEtudiants,nbEtudiantsParNote[TAILLE_LETTRES-1-i]);
//        printf("%d\n",nbX);
        for (j=0; j<nbX; ++j) {
            printf ("X");
        }
        printf("\n");
    }
    
}


