#include <stdio.h>
#include <stdlib.h>

//prend le nombre de notes donnees en entree 
#define TAILLE argc-1
#define NOM argv[0]

//valider ce quentre le user est bien des donnees numeros
void validerNotesFournies(const char *notes);
//valider que le code permanent fourni respecte le bon format
void validerCodePerm(char *codePermanent);
//valider que notre array de notes recu est dans les limites
void validerValeursPermises(char *notesPermises, const char *notes);





int main(int argc, char *argv[]){

    int nombreEval ;
    char seuils[11];
    int iterateur;
    


	if (argc != 12) {
		fprintf(stderr, "Le nombre d'arguments n'est pas valide.\n");
		exit(EXIT_FAILURE);	
	}
    
    for (iterateur=1 ; iterateur< argc ;  ++iterateur) {
        seuils[iterateur-1] = *argv[iterateur];
    }
    FILE *fichierEntree = stdin;

    fscanf(fichierEntree, "%d", &nombreEval);
    printf("%d",nombreEval);

	/*printf("Entrer le code permanent de l'etudiant a evaluer sous format AAAA111111111111: ");
	scanf("%s", codePerm);
	
	printf("Entrer les notes maximum permises, separees par un espace: ");
	scanf("%s", notesPermises);
	
	
	validerNotesFournies(argv[1]);
	validerCodePerm(codePerm[0]);
	validerValeursPermises(notesPermises[0], argv[1]);*/
	
	
	return(0);

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


void validerCodePerm(char *codePermanent){
	
	for (i = 0; i < 12; i++){
		
		if (i < 4){
			
			!(isalpha(codePermanent[i]));
			fprintf(stderr, "%s: Code Permanent non conforme \n", NOM);
			exit(EXIT_FAILURE);
		} else {
			
			!(isdigit(codePermanent[i]));
			fprintf(stderr, "%s: Code Permanent non conforme \n", NOM);
			exit(EXIT_FAILURE);			
		}		
	}	
}


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
