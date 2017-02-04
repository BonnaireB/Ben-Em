/*
* Programme qui calcule la moyenne des notes obtenues pour des travaux donnes 
* Produit dans le cadre du cours INF-3135
* 
* Ecrit par Emilie Paquin PAQE19528909 
* Ecrit par Benjamin Bonnaire (CODE PERMANENT)
*
* 20 Fevrier 2017
*/



/* TODO Changer les variables selon l'enonce
*  TODO Commenter ce que prend en entree une methode et ce quelle ressort
*/

#include <stdio.h>
#include <stdlib.h>

/*************************
*Declaration des methodes 
*************************/

/* Methode servant a valider et sauvegarder le nombre d'evaluations*/
int validerNbTravaux(int travaux);

/*Methode servant a savoir sur combien de points chaque evaluation est*/
int validerNbPtsParTravail(int points);

/*Methode qui valide si le code permanent de l'etudiant est valide*/
void validerCodePerm(char code); //ne retourne pas un nombre mais un oui/non

/*Methode servant a obtenir les notes pour chaque travail*/
int validerNotes(int notes);

/*Methode qui sert a valider les seuils pour A+ allant jusqu'a D*/
int validerSeuils(int seuils); //a utiliser si on ne controle pas les seuils

/*Methode qui sert a faire le calcul de sup(nbÉtudiants(note)/sup(nbMaxÉtudiants/largeurHistogramme))*/
int validerMoyenne(int moyenne); //pour les calculs

/*Methode qui sert a afficher lhistogramme*/
char afficherResultat(char[] notes, int x);



/************************
Declaration des variables
************************/


static char notes[] = {'A+', 'A', 'A-', 'B+', 'B', 'B-', 'C+', 'C', 'C-', 'D+', 'D'}
int tableauTravaux[]; //prend la longueur du nombre de travaux, sera rempli par les notes pour chacun
int moyenneX;		


main (argc, *argv[]) {
	
	moyenneX = validerMoyenn(arguments a donner)
	
	
}



validerCodePerm(const char code){
	
	iterer sur un tableau.
	first longueur tableau, max 12
	ensuite les 4 premiers doivent etre des lettres
	ensuite les 4 suivants des nombres
	
}


int validerMoyenne(int moyenne){

//calculer en fonction du nombre d<etudiant (max 50)

}

char afficherResultat(&notes, moyenneX) {
	while (*note != A+){
		printf("%-5s", *note);
		printf("nombre de X requis \n");
		//note = la prochaine dans le tableau de notes donc --pointeur si on le debute a la fin, sinon refaire le tableau des lettres pour ordre croissant
		
	}
	
}
