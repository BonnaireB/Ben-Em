//
//  lab3.c
//  LabosInf3135
//
//  Created by Bonnaire Benjamin on 17-01-31.
//  Copyright © 2017 Bonnaire Benjamin. All rights reserved.
//

#include <stdio.h>
void inverse(int a[], int taille);
void echange_valeurs(int *a, int *b);
void affiche_vecteur_int(int a[]);
int main(int argc, const char * argv[]) {
    
    return 0;
}
void inverse(int a[], int taille){
    echange_valeurs(a[0],a[taille-1]);
}

void echange_valeurs(int *a, int *b)  {
    int z = *a;
    *a=*b;
    *b=z;
}
