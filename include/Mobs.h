#ifndef MOBS_H
#define MOBS_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Mobs : public Entity
{
	public:
		Mobs(double a,  string b, int c, string x, string d, int e, string y, string f, int g,   string z, string o);
		void regenAuto(int tour);
		void IA(int tour, Entity* cible);
		virtual ~Mobs();
	protected:
        int souvenir;

	private:
};

#endif // MOBS_H
