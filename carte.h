#include <iostream>
using namespace std;
class carte
{
	public:
	carte();
	void afficher();
	void seDeplacer(char direction);
	void parametrerTailleMap(int max);
	void placerObstacle(int nbObstacles);
	void placerMonstres(int nbMonstres);
	private:
	char **map;
	int max;
	char joueur;
	int positionLigne;
	int positionColonne;
	char decorInaccessible;
	char monstre;
	int nbObstacles;
	int nbMonstres;

};
