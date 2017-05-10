#include "Mobs.h"

Mobs::Mobs(double a,  string b, int c, string x, string d, int e, string y, string f, int g,   string z, string o)
{
    pdv = a;
    pdv_max = a;

	competence1 = b;
	degats_comp1 = c;
	type_comp1 = x;

	competence2 = d;
	degats_comp2 = e;
	type_comp2 = y;

	competence3 = f;
	degats_comp3 = g;
	type_comp3 = z;

	classe = o;
	souvenir = -3;
}

void Mobs::regenAuto(int tour)
{
    if((tour >= 5))
    {
        pdv += 20;

        if(pdv > pdv_max)
            pdv = pdv_max;

        cout << classe << " recupere 20 points de vie grace a la regeneration automatique !" << endl;
    }
}

void Mobs::IA(int tour, Entity* cible)
{
    if(getClasse() == "Gobelin")
    {
        	if(cible->poison == false && tour - souvenir >= 3)
            {
                attaque(cible, 3);
                souvenir = tour;
            }


            else if(terrain == "ENFER")
                attaque(cible, 2);

            else
            {
                attaque(cible, 1);
                attaque(cible, 1);
            }
      }

    else if(getClasse() == "Orc")
    {


            if(pdv<=20)
                attaque(cible, 3);

        	else if(terrain == "BANQUISE")
                attaque(cible, 2);

            else
                attaque(cible, 1);
    }


    else
    {
            if(cible->poison == false && tour - souvenir >= 3)
            {
                attaque(cible, 3);
                souvenir = tour;
            }
        	else if(terrain == "ENFER")
                attaque(cible, 1);

            else if(terrain == "BANQUISE")
                attaque(cible, 2);

    }
}


Mobs::~Mobs()
{
    //dtor
}


