#include "carte.h"
#include <cstdlib>
#include <ctime>
carte::carte()
{
max=0;
joueur = 'J';
decorInaccessible = 'X';
monstre ='M';
positionLigne = 0;
positionColonne = 0;
nbObstacles = max%2;
nbMonstres = 3;


parametrerTailleMap(10);
int i,j;
    for(j = 0; j < max; j++ )
    {
        for(i = 0; i < max; i++ )
        {
            map[i][j] = ' ';
        }
    }
map[positionLigne][positionColonne] = joueur;
placerMonstres(nbMonstres);
placerObstacle(nbObstacles);


}

void carte::parametrerTailleMap(int m)
{
	max = m;
	map = new char*[m];
	for(int i = 0; i < m ; i++)
	{
		map[i] = new char[m];
	}
}

void carte::placerObstacle(int nbObst)
{
	cout << "ALLO";
	int rand1, rand2;	
	srand (time(NULL));
	for(int i = 0; i <= nbObst-1; i++)
	{
		rand1 = rand() % (max-1) +1;
		rand2 = rand() % (max-1) +1;
		map[rand1][rand2] = decorInaccessible;	
		cout << "ALLO2"<< rand1 << " et " << rand2;
	}

}
void carte::placerMonstres(int nbMonstres)
{
	int rand1, rand2;	
	srand (time(NULL));
	for(int i = 0; i <= nbMonstres-1; i++)
	{
		rand1 = rand() % (max-1) +1;
		rand2 = rand() %(max-1) +1;
		map[rand1][rand2] = monstre;	
	}

}

void carte::seDeplacer(char direction)
{
	switch(direction)
	{
		case 'z'://en haut; j-1
			if(positionColonne  <= 0 || map[positionLigne][positionColonne-1] == decorInaccessible)
			{
				cout << "Le personnage ne peut pas aller plus en haut" << endl;
			}
			else
			{
				map[positionLigne][positionColonne] = '.';
				positionColonne = positionColonne-1;
				map[positionLigne][positionColonne] = joueur;
			}
			break;
		case 's'://en bas; j+1
			if(positionColonne  >= max-1 || map[positionLigne][positionColonne+1] == decorInaccessible)
			{
				cout << "Le personnage ne peut pas aller plus en bas" << endl;
			}
			else
			{
				map[positionLigne][positionColonne] = '.';
				positionColonne = positionColonne+1;
				map[positionLigne][positionColonne] = joueur;
			}
			break;
		case 'q'://a gauche; i-1
			if(positionLigne  <= 0 || map[positionLigne-1][positionColonne] == decorInaccessible)
			{
				cout << "Le personnage ne peut pas aller plus a gauche" << endl;
			}
			else
			{
				map[positionLigne][positionColonne] = '.';
				positionLigne = positionLigne-1;
				map[positionLigne][positionColonne] = joueur;
			}
			break;
		case 'd'://a droite; i+1
			if(positionLigne  >= max-1 || map[positionLigne+1][positionColonne] == decorInaccessible)
			{
				cout << "Le personnage ne peut pas aller plus a droite" << endl;
			}
			else
			{
				map[positionLigne][positionColonne] = '.';
				positionLigne = positionLigne+1;
				map[positionLigne][positionColonne] = joueur;
			}
			break;
		default://a rien
			cout << "deplacement inconnu, réessayez" << endl;
			cin >> direction;
			seDeplacer(direction);
			break;
	}
}

void carte::afficher()
{
int i,j;
    for(j = 0; j < max; j++ )
    {
        for(i = 0; i < max; i++ )
        {
            cout << map[i][j] << " | ";
	    
	  
	}
        cout << endl;
	
    }
}
