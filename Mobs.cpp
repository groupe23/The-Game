#include "Gobelin.h"

Mobs::Mobs(double a,  string c, int d, string g, int h, string o)
{
    *e_pdv = a;
    e_pdv_max = a;

    e_competence1 = c;
    e_degats_comp1 = d;


    e_competence2 = g;
    e_degats_comp2 = h;


 
    classe = o;
}

Mobs::~Mobs()
{
	poison = false;
	
}

void Mobs::Etat()
{

	cout << endl << endl << "Ennemi " << classe <<" vous attaque !"<< endl;
   	cout << "Points de Vie : " << *e_pdv << endl;

}

void Mobs::attaque(Personnage &cible, int &num)
{
	switch(num)
   	{
        case 1: if(cible.cibleVivante())
                {
                    	cout << endl << classe << " utilise " << e_competence1 << " !" << endl;
                   	cible.subitDegats(e_degats_comp1);
			cible.subitDegats(e_degats_comp1);
			if(classe=="Gobelin")
			{
				cible.subitDegats(e_degats_comp1);
				cout << endl << classe <<" attaque trois fois !"<<endl;
			}
			else cout << endl << classe <<" attaque deux fois !"<<endl;
                }

                else
                    cout << endl << classe << " n'a pas attaqué car son opposant est mort." << endl;
        break;

        case 2: if(cible.cibleVivante() && poison == false)
                {
			if(classe=="Bwork")
			{
				cible.subitDegats(e_degats_comp1);
  				cout << endl << classe << " utilise " << competence2 << " !" << endl;
			}
			else
			{
                  		cout << endl << classe << " utilise " << competence2 << " !" << endl;
				cible.effet(cout << endl << classe <<competence2);
                	}
		}

                else cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;

    	}

}

void Mobs::effet(string type, Personnage &cible)
{
	if(type == "Poison" && poison == false)
	{
		double degatP = 0.05*cible->pdv_max;
		cible.subitDegat(degatP);
		poison = true;
	}
	else cout<<"La cible est déja sous l'emprise du poison."<<endl;
}

void Mobs::subitDegats(double degats)
{
    if(!protecte)
    {
	if(degats => *pdv)	degats = *pdv;
        *pdv -= degats;
        cout << classe << " perd " << degats << " PDV ! " << endl << endl;
    }
    else cout << classe << " est protege ! L'attaque n'a aucun effet" << endl;
}

bool Mobs::cibleVivante()
{
    if(*e_pdv <= 0)
    {
        cout << endl << endl << classe << " est K.O. ! " << endl << endl;
        return false;
    }
    return true;
}




