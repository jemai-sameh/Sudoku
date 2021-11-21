#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//const
#define MIN 3
#define MAX 9

unsigned int grille[MAX][MAX];
void Level(int level);
void affiche_grille(int iIndex,int jIndex);
int saisie_grille(void);
void saisie_case();
unsigned int saisie_value();

bool checkRow( int value, int index);
bool checkCol(int value, int index);
bool checkSub(int value, int rowIndex, int colIndex);

int main(void) {
  int level;
  char  c;
  printf("**********************  SUDOKU ************************\n");
  printf("choisir niveau :");
  scanf("%d",&level);
  Lvel(level);
  while(true){
  printf("--------------------- Niveau %d ----------------------\n",niveau);
          affiche_grille(-1,-1); 
          saisie_case(); 
          printf("final:\n");
          affiche_grille(-1,-1);     

  printf("Voulez-vous continuer 'C' ou recommancer 'R'?\n");
     
    c = fgetc(stdin);
    if(c=='c' || c=='C')
        level=level+1;
    if (c=='q'|| c=='Q')
        break;
  }
  return 0;


}
void  Level(int level){ 
	int i,j;
	FILE * source;
  printf("\n");
	source = fopen("level1","r");
	for (i = 0; i <MAX; i++)
	{
		for(j= 0; j <MAX; j++)
		{
			fscanf(source,"%d",&grille[i][j]);
		}
	}
	fclose(source);
}
void affiche_grille(int iIndex,int jIndex){
  printf("\n\033[1;33m\033[40m ------ ------- ------- \033[0m\n");
   for (int i = 0; i <MAX; i++) {
                printf("\033[1;33m\033[40m|\033[0m");
                for (int j = 0; j <MAX; j++) {                  
                   printf((j==3 ||j==6)?" \033[1;33m\033[40m|\033[0m":"");
                   if (i==iIndex && j==jIndex)
                      printf("\033[1;31m %d\033[0m",grille[i][j]);
                   else
                      printf(" %d",grille[i][j]);
                }
                printf("\033[1;33m\033[40m|\033[0m\n");
                printf((i==2 || i==5)?"\033[1;33m\033[40m ------ ------- ------- \033[0m\n":"");
            }
  printf("\033[1;33m\033[40m ------ ------- ------- \033[0m\n");
}
    bool checkRow( int value, int index){
        //row check
        for (int j = 0; j <MAX; j++) {
            if(grille[index][j] == value){
                return  false;
            }
        }
        return true;
    }
   bool checkCol( int value, int index){
       for (int i = 0; i <MAX; i++) {
            if(grille[i][index] == value){
                return  false;
            }
        }
        return true;
    }
    
    bool checkSub(int value, int rowIndex, int colIndex){

          int baseRowIndex = rowIndex - (rowIndex % 3);
        int baseColumnIndex =  colIndex - (colIndex % 3);
        for (int i = baseRowIndex; i < baseRowIndex + 3; i++) {
            for (int j = baseColumnIndex; j < baseColumnIndex + 3; j++) {
                if(grille[i][j] == value){
                    return  false;
                }

            }
        }
                    return true;

    }
unsigned int saisie_value(){
  unsigned int value;
    do{
      printf("    ¤ value [1-9] :");
      scanf("%d",&value);
    }while(value<1 || value> MAX);
    return value;
}
void saisie_case(){
    unsigned int i,j;
    unsigned int value;
      for (i = 0; i <MAX; i++) {
            for (j = 0; j <MAX; j++) {
                if(grille[i][j] == 0){

                   printf("----------[%d][%d]----------",i,j);

                   printf("\n");
                   affiche_grille(i,j);
                   do{
                     value=saisie_value();
                   }while (!checkRow(value,i) || !checkCol(value,j)|| !checkSub(value,i,j));                  
                      grille[i][j]=value;                
                  
                }
            }
      }
}
