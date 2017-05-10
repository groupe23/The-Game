#include "carte.h"
#include <utility>
#include <cstdlib>
#include <ctime>
Carte::Carte()
{
    max=0;
joueur = 'J';
decorInaccessible = 'X';
monstre = 'M';
positionLigne = 0;
positionColonne = 0;
nbObstacles = 6;
nbMonstres = 5;



parametrerTailleMap(12);
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

void Carte::parametrerTailleMap(int m)
{
	max = m;
	map = new char*[m];
	for(int i = 0; i < m ; i++)
	{
		map[i] = new char[m];
	}
}




void Carte::placerObstacle(int nbObst)
{
	int rand1, rand2;
	srand (time(NULL));
	int i=0;
	int nbO=0;
	do{
		rand1 = rand() % (max-1) +1;
		rand2 = rand() % (max-1) +1;
		if(map[rand1][rand2] != 'M' &&  map[rand1][rand2] != 'X')
		{
			map[rand1][rand2] = decorInaccessible;

			i++;
			nbO++;
		}
	}while(i<=nbObst-1);
}


void Carte::placerMonstres(int nbMonstres)
{
	int rand1, rand2;
	srand (time(NULL));
	int i=0;
	int nbM=0;
	do{
		rand1 = rand() % (max-1) +1;
		rand2 = rand() %(max-1) +1;
		if(map[rand1][rand2] != 'M' &&  map[rand1][rand2] != 'X')
		{
			map[rand1][rand2] = monstre;

			i++;
			nbM++;
		}
	}while(i<=nbMonstres-1);
}

bool Carte::seDeplacer(char direction)
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
				if(map[positionLigne][positionColonne-1] == monstre)
				{
                    map[positionLigne][positionColonne-1] = ' ';
                    nbMonstres--;
                    return true;
                }

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
				if(map[positionLigne][positionColonne+1] == monstre)
				{
                    map[positionLigne][positionColonne+1] = ' ';
                    nbMonstres--;
                    return true;
                }
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
				if(map[positionLigne-1][positionColonne] == monstre)
                {
                    map[positionLigne-1][positionColonne] = ' ';
                    nbMonstres--;
                    return true;
                }

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
				if(map[positionLigne+1][positionColonne] == monstre)
                {
                    map[positionLigne+1][positionColonne] = ' ';
                    nbMonstres--;
                    return true;
                }
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
	return false;
}

void Carte::afficher()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
    int i,j;
    for(j = 0; j < max; j++ )
    {
        for(i = 0; i < max; i++ )
        {
            if(map[i][j] == monstre)    cout<<"  | ";
            else cout << map[i][j] << " | ";


	}
        cout << endl;

    }
}
