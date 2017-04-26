#include "Entity.h"

Entity::Entity()
{
    //ctor
}

void Entity::attaque(Entity &cible, int numComp)
{
    switch(numComp)
    {
        case 1: if(cible.cibleVivante())
                {
                    cout << endl << classe << " utilise " << cout_comp1 << " points de sa Jauge de MANA !" << endl;
                    cible.subitDegats(degats_comp1, type_comp1);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;

        case 2: if(cible.cibleVivante())
                {
                    cout << classe << " Utilise " << cout_comp2 << " points de sa Jauge de MANA !" << endl;
                    cible.subitDegats(degats_comp2, type_comp2);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;

        case 3: if(cible.cibleVivante())
                {
                    effetSurSoi(type_comp3);
                }

                else
                    cout << endl << classe << " n'a pas suffisemment de MANA ! L'attaque n'a pas aboutie." << endl;
        break;
    }
}


void Entity::subitDegats(double degats, string type)
{
    double degatFinal = degats + (degats * effetTerrain(type));

    if(!protecte)
    {
        *pdv -= degatFinal;
        cout << classe << " perd " << degatFinal << " PDV ! " << endl << endl;
    }


    else
    {
        cout << classe << " est protege ! L'attaque n'a aucun effet" << endl;
        protecte = false;
    }
}


void Entity::effetSurSoi(string type)
{
    if(type == "SOIN")
    {
        *pdv += 50;

        if(*pdv > pdv_max)
            *pdv = pdv_max;

        cout << "SOIN EFFECTUE !" << endl;
    }

    else if(type == "PROTECTION")
    {
        protecte = true;
        cout << "Le " << classe << " se protege...";
    }
}


void Entity::typeTerrain(string type)
{
    terrain = type;
}

double Entity::effetTerrain(string type)
{
    if((terrain == "ENFER" && type == "FEU") || (terrain == "ORAGE" && type == "ELECTRIQUE") || (terrain == "BANQUISE" && type == "GLACE"))
    {
         cout << "Le terrain '" << terrain << "' fait effet, l'attaque est augmentee de 20%" << endl;
         return 0.02;
    }


    return 0;
}






bool Entity::cibleVivante()
{
    if(*pdv <= 0)
    {
        cout << endl << endl << classe << " est K.O. ! " << endl << endl;
        return false;
    }


    return true;
}



Entity::~Entity()
{
    //dtor
}
