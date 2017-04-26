#ifndef MOBS_H
#define MOBS_H

#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

class Mobs
{
	public:
		Mobs(double a,  string c, int d, string g, int h, string o);
		void Etat();
		void attaque(Personnage &cible, int num);
		void effet(string type, Personnage &cible);
		void subitDegat(double degat);
		bool cibleVivante();
		friend class Personnage;
	protected:
		double *pdv = new double;
		double pdv_max;
		
		string competence1;
       		double degats_comp1;

        	string competence2;
        	double degats_comp2;

		string classe;

		bool vivant = true;
		bool poison =false;
	private:
		string terrain;
};

#endif // Mobs_H
