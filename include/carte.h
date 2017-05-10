#include <iostream>
using namespace std;
class Carte
{
	public:
        Carte();
        void afficher();
        bool seDeplacer(char direction);
        void parametrerTailleMap(int max);
        void placerObstacle(int nbObstacles);
        void placerMonstres(int nbMonstres);
        int nbMonstres;

	private:
        char **map;
        int max;
        char joueur;
        int positionLigne;
        int positionColonne;
        char decorInaccessible;
        char monstre;
        int nbObstacles;

};
