#include "Personnage.h"

Personnage::Personnage(double a, int b, string c, int d, string e, int f, string g, int h, string i, int j, string k, int l, string m, int n, string o)
{
    pdv = a;
    mana = b;

    pdv_max = a;
    mana_max = b;

    competence1 = c;
    degats_comp1 = d;
    type_comp1 = e;
    cout_comp1 = f;

    competence2 = g;
    degats_comp2 = h;
    type_comp2 = i;
    cout_comp2 = j;

    competence3 = k;
    degats_comp3 = l;
    type_comp3 = m;
    cout_comp3 = n;

    classe = o;
}


void Personnage::afficherClasse()
{
    cout << "Classe : " << classe << endl << endl;

    cout << "Point de Vie : " << pdv << endl;
    cout << "Jauge de Mana : " << mana << endl << endl;

    cout << "Competence 1 :" << endl;
    cout << "\tNom : " << competence1 << endl;
    cout << "\tDegats : " << degats_comp1 << endl;
    cout << "\tType : " << type_comp1 << endl;
    cout << "\tCout en Mana : " << cout_comp1 << endl << endl;


    cout << "Competence 2 :" << endl;
    cout << "\tNom : " << competence2 << endl;
    cout << "\tDegats : " << degats_comp2 << endl;
    cout << "\tType : " << type_comp2 << endl;
    cout << "\tCout en Mana : " << cout_comp2 << endl << endl;


    cout << "Competence 3 :" << endl;
    cout << "\tNom : " << competence3 << endl;
    cout << "\tDegats : " << degats_comp3 << endl;
    cout << "\tType : " << type_comp3 << endl;
    cout << "\tCout en Mana : " << cout_comp3 << endl << endl << endl << endl;
}


void Personnage::Etat()
{
    cout << endl << endl << "Classe : " << classe << endl;
    cout << "Points de Vie : " << pdv << endl;
    cout << "Jauge de Mana : " << mana << endl;

    if(poison == true)
        cout << "Statut : Empoissone" << endl;

    if(protecte == true)
        cout << "Effet : Protege a la prochainne attaque ennemi" << endl;
}

void Personnage::Hub()
{
    cout << endl << endl << "Que faire " << classe << " ? \t1. " << competence1 << " (" << degats_comp1 << " degats, " << cout_comp1 << " cout mana, type " << type_comp1 << ")" << endl;
    cout << "\t\t\t2. " << competence2 << " (" << degats_comp2 << " degats, " << cout_comp2 << " cout mana, type " << type_comp2 << ")" << endl;
    cout <<  "\t\t\t3. " << competence3 << " (" << degats_comp3 << " degats, " << cout_comp3 << " cout mana, type " << type_comp3 << ")"<< endl;
    cout << "Choix : ";
}


void Personnage::attaque(Entity* cible, int numComp)
{
    switch(numComp)
    {
        case 1: if(manaSuffisant(cout_comp1) && cible->cibleVivante())
                {
                    mana -= cout_comp1;
                    cout << classe << " lance " << competence1;
                    cout << endl << classe << " utilise " << cout_comp1 << " points de sa Jauge de MANA !" << endl;
                    cible->subitDegats(degats_comp1, type_comp1);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;

        case 2: if(manaSuffisant(cout_comp2) && cible->cibleVivante())
                {
                    mana -= cout_comp2;
                    cout << classe << " lance " << competence2 << endl;
                    cout << classe << " Utilise " << cout_comp2 << " points de sa Jauge de MANA !" << endl;
                    cible->subitDegats(degats_comp2, type_comp2);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;

        case 3: if(manaSuffisant(cout_comp3) && cible->cibleVivante())
                {
                    mana -= cout_comp3;
                    cout << classe << " lance " << competence3;
                    effet(type_comp3);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;
    }

    if(poison == true)
    {
        cout << classe << " souffre du poison..." << endl;
        cout << "Il perd " << (0.05 * pdv_max) << " PDV !" << endl;

        pdv -= ((0.05 * pdv_max));
    }
}



void Personnage::regenAuto(int tour)
{
    if((tour >= 5))
    {
        mana += 50;

        if(mana > mana_max)
            mana = mana_max;

        cout << classe << " recupere 50 points de mana grace a la regeneration automatique !" << endl;
    }
}

void Personnage::reset()
{
    pdv = pdv_max;
    mana = mana_max;
    poison = false;
    protecte = false;
}

bool Personnage::manaSuffisant(int cout_mana)
{
    if(mana < cout_mana)
        return false;

    return true;
}


Personnage::~Personnage()
{
    //dtor
}
