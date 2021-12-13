#ifndef dynamicSteps_h
#include <stdbool.h>

void Level(const char * level);
bool isExistValue(unsigned int value,unsigned int row,unsigned int column);
unsigned int suggestedValue(unsigned int rowIndex,unsigned int colIndex);
void fillGrille();
bool isFull();
unsigned int inputValue(unsigned int taille);
bool isEmptySquare(unsigned int row,unsigned int column);
void saveStatus(struct Joueur *joueur,int niveau);

bool isExistInRow(int value, int row);
bool isExistInCol(int value, int column);
bool isExistInSub(int value, int rowIndex, int colIndex);


#define dynamicSteps_h
#endif
