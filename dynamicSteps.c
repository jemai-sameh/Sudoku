#include <stdio.h>
#include "composants.h"
#include "dynamicSteps.h"
#include "view.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void  Level(const char *level){
	int row,column;
  char  path [10]= "LEVEL";
	FILE * source;
  printf("\n");
  strcat(path, level);
	source = fopen(path,"r");
	for (row= 0; row <MAX; row++)
	{
		for(column=0; column<MAX; column++)
		{
			fscanf(source,"%d",&grille[row][column]);
		}
	}
	fclose(source);
}

    bool isExistInRow( int value, int row){
        for (int column= 0; column<MAX; column++) {
            if(grille[row][column] == value){
                return  false;
            }
        }
        return true;
    }
   bool isExistInCol( int value, int column){
       for (int row= 0; row<MAX; row++) {
            if(grille[row][column] == value){
                return  false;
            }
        }
        return true;
    }
    
    bool isExistInSub(int value, int rowIndex, int colIndex){

          int baseRowIndex = rowIndex - (rowIndex % 3);
        int baseColumnIndex =  colIndex - (colIndex % 3);
        for (int row= baseRowIndex; row< baseRowIndex + 3; row++) {
            for (int column= baseColumnIndex; column< baseColumnIndex + 3; column++) {
                if(grille[row][column] == value){
                    return  false;
                }

            }
        }
                    return true;

    }
 
void fillGrille(){
  unsigned int value,row,column;
  unsigned int i;
  char help;
  while(!isFull()){
    do{
      printf("donnée ligne   : ");
      row=inputValue(10);
      printf("donnée colonne : ");
      column=inputValue(10);
    }while(!isEmptySquare(row,column));

    i=0;
    do{
      if (i>=3){
        printf("%s Avez-vous besoin d'aide? 'O/n'%s\n",rouge,stopColor);
        while((help = getchar()) != EOF) 
          if (help == '\n') 
            break;
        
        scanf("%c",&help);
        if (help!='n'|| help!='n'){
            value=suggestedValue(row,column);
            goto end;
        }
  
        }
      printf("valeur         :");
      value=inputValue(9);
      end:i++;       
    }while(!isExistValue(value,row,column));
      grille[row][column]=value;
      printGrille(row,column);
  }
}

bool isFull(){     
    unsigned int row,column;
    unsigned int value;
    for (row= 0; row<MAX; row++) {
      for (column= 0; column<MAX; column++) {
          if(grille[row][column] == 0)
            return false;
      }
    }
    return true;
}
unsigned int suggestedValue(unsigned int rowIndex,unsigned int colIndex){
  unsigned int i;
  for (i= 1; i<=MAX; i++) {
      if (isExistValue(i,rowIndex,colIndex))
        break;
  }
      return i;
}
unsigned int inputValue(unsigned int taille)
{
    unsigned int value;
    do{
      scanf("%d",&value);
    }while(value<1 || value> taille);
    return value;
    
}
bool isEmptySquare(unsigned int ligne,unsigned int  colonne){
   return grille[ligne][colonne]==0;

}
bool isExistValue(unsigned int value,unsigned int row,unsigned int column){
  return isExistInRow(value,row) && isExistInCol(value,column)&& isExistInSub(value,row,column); 
}

void saveStatus(struct Joueur *joueur,int niveau){
    FILE* fichier = NULL; 
    fichier = fopen("SAVE", "a"); 
    if (fichier != NULL)
    {        
        fprintf(fichier, " - %s résoudre le niveau %d  dans %02d:%02d:%02d\n",joueur->nom,niveau,joueur->temps->tm_hour, joueur->temps->tm_min, joueur->temps->tm_sec);
        fclose(fichier);
    }
}

