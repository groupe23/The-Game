#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Personnage : public Entity
{
    public:
        Personnage(double a, int b, string c, int d, string e, int f, string g, int h, string i, int j, string k, int l, string m, int n, string o);


        void attaque(Entity* cible, int numComp);
        void afficherClasse();
        void Etat();

        void reset();

        bool manaSuffisant(int cout_mana);
        void Hub();
        void regenAuto(int tour);


        virtual ~Personnage();

    protected:

        int mana;
        int mana_max;

        int cout_comp1;
        int cout_comp2;
        int cout_comp3;

    private:



};

#endif // PERSONNAGE_H
