#ifndef composants_H

#define MIN 3
#define MAX 9
#define jeune "\033[1;33m"
#define rouge "\033[1;31m"
#define stopColor "\033[0m"
#define vert "\033[1;32m"
#define fond "\033[40m"// "\033[46m"//"\033[40m"//
#define fondBlanche "\033[107m"

unsigned int grille[MAX][MAX];

typedef
	struct Joueur
	{
		struct tm * temps;
		char nom[30];
	}Joueur;


#define composant_H

#endif
