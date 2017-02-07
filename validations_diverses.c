#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prend le nombre de notes donnees en entree
#define TAILLE argc-1
#define NOM argv[0]

//valider ce quentre le user est bien des donnees numeros
void validerNotesFournies(const char *notes);
//valider que le code permanent fourni respecte le bon format
void validerCodePerm(const char* codePerm);
//valider que notre array de notes recu est dans les limites
void validerValeursPermises(char *notesPermises, const char *notes);
//remplissage des tableaux des pondeérations et des notes max
void remplissage ( int tableaux[],int taille);




int main(int argc, char *argv[]){
    
    int nombreEval ;
    double seuils[11];
    int iterateur;
    char leCar[5];
    
    if (argc != 12) {
        fprintf(stderr, "Le nombre d'arguments n'est pas valide.\n");
        exit(EXIT_FAILURE);
    }
    
    
    for (iterateur=1 ; iterateur< argc ;  ++iterateur) {
        seuils[iterateur-1] = strtold(argv[iterateur],NULL);
        printf ("%.2f\n",seuils[iterateur-1]);
    }
    scanf("%s",leCar);
    nombreEval = (int)strtol(leCar,NULL,10);
    printf("%d\n",nombreEval);
    
    int ponderation [nombreEval];
    int noteMax[nombreEval];
    remplissage (ponderation, nombreEval);
    remplissage (noteMax,nombreEval);

    char codePerm[12];
    scanf("%s",codePerm);
     validerCodePerm(codePerm);
    
    
    return(0);
    
}


void remplissage (int tableaux[],int taille){
    char charLu[10];
    int i;
    for (i= 0; i < taille; ++i) {
        scanf("%s",charLu);
        tableaux[i] = strtol(charLu,NULL,10);
        printf("%d ",tableaux[i]);
    }
    printf("\n");
    
}


/*void validerNotesFournies(const char *notes){  //need to handle floats
	
	if (sizeof(notes) > TAILLE) {
 
 fprintf(stderr, "%s: Trop de valeurs fournies \n", NOM);
 exit(EXIT_FAILURE);
 
	}
	
	for (int i = 0; i <= TAILLE; ++i){
	
 if {!isdigit(argv[i]){
 fprintf(stderr, "%s: Au moins une note entree n'est pas conforme \n", NOM);
 exit(EXIT_FAILURE);
 }
	
	}
 
 }
 
 
 */
void validerCodePerm(const char* codePerm){
    int i;
	for (i = 0; i < 4; ++i){
        printf("%c",codePerm[i]);
            if(!(isalpha(codePerm[i]))){
            fprintf(stderr, ": Code Permanent non conforme \n");
            exit(EXIT_FAILURE);
            }
    }
    for (i=4; i<12; ++i) {
        printf("%c",codePerm[i]);
            if(!(isdigit(codePerm[i]))){
            fprintf(stderr, "Code Permanent non conforme \n");
            exit(EXIT_FAILURE);
                
            }
    }
 }
 /*
 
 void validerValeursPermises(char *notesPermises, const char *notes){
	
	int noteDonnee;
	int notePermise;
 
	for (int i = 0; i < TAILLE; i++){
 noteDonnee = notes[i];
 notePermise = notesPermises[i];
 if (noteDonnee > notePermise){
 fprintf(stderr, "%s: Au moins une note entree n'est pas conforme \n", NOM);
 exit(EXIT_FAILURE);
 }
	}
	
	
 }*/
