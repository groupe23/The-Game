#include "carte.h"
#include <cstdlib>
int main()
{
	carte plateau;
	//plateau.afficher();
        cout << endl;
	int i = 0;
	char choix;
	int taille;
	//cout <<"Quelle taille de map ? "<< endl;
	//cin >> taille;
	//plateau.parametrerTailleMap(taille);
	do
	{

		plateau.afficher();
		cout << "où aller ?" << endl;
		cin >> choix;
		plateau.seDeplacer(choix);
		system("clear");
		i++;
	}while(i <=50);
}
