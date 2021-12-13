#include "composants.h"
#include <stdio.h>
#include <unistd.h>

void inputName(Joueur *joueur){
printf("%s Entrer nom :     ",rouge);
  scanf("%s",joueur->nom);
  printf("%s",stopColor);
}
void askLevel(char *level){
printf("choisir niveau :\n");
  while((*level = getchar()) != EOF) 
    if(*level == '\n') 
        break;
  scanf("%c",level);
  }
void printGrille(int rowIndex,int colIndex){
  printf("\n%s%s ------ ------- ------- %s\n",jeune,fond,stopColor);
   for (int row= 0; row<MAX; row++) {
                printf("%s%s|%s",jeune,fond,stopColor);
                for (int column= 0; column<MAX; column++) {                  
                   printf((column==3 ||column==6)?" \033[1;33m\033[40m|\033[0m":"");
                   if (row==rowIndex && column==colIndex)
                      printf("%s %d%s",rouge,grille[row][column],stopColor);
                   else
                      printf(" %d",grille[row][column]);
                }
                printf("%s%s|%s\n",jeune,fond,stopColor);
                printf(((row==2 || row==5)?"\033[1;33m\033[40m ------ ------- ------- \033[0m\n":""));
            }
  printf("%s%s ------ ------- ------- %s\n",jeune,fond,stopColor);
}


void display(){  
  printf("\n        Niveau :\n");
  printf("              1.Très Très facile\n");	
	printf("              2.Très facile\n");	
	printf("              3.facile\n");	
	printf("              4.Moyen\n");	
	printf("              5.Difficile\n");	
	printf("              6.Très Difficile\n");
  printf("              7.Très Très Difficile\n");
	printf("              0.QUIT\n\n");          
}
//les regles
void rules(){
  printf("**************************  SUDOKU ******************************\n");
  printf("***  Les règles:                                              ***\n");
printf("***    Pour terminer une grille de Sudoku vous devez remplir  *** \n***    toutes les cases vides avec des chiffres de 1 à 9      ***\n***    en respectant les 3 règles suivantes :                 ***\n");

printf("***    1- Une même ligne de 9 cases ne doit pas contenir      ***\n***    2 fois le même chiffre                                 ***\n");

printf("***    2- Une même colonne de 9 cases ne doit pas contenir    ***\n***    2 fois le même chiffre                                 ***\n");

printf("***    3 -Un même petit carré de 9 cases (3x3) ne doit pas    ***\n***    contenir 2 fois le même chiffre                        ***\n");
 printf("*****************************************************************\n");
}
