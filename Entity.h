#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

using namespace std;

class Entity
{
    public:
        Entity();

        void attaque(Entity &cible, int numComp);
        void subitDegats(double degats, string type);

        double effetTerrain(string type);
        void effetSurSoi(string type);
        void typeTerrain(string type);

        bool manaSuffisant(int cout_mana);
        bool cibleVivante();

        virtual ~Entity();
    protected:

        double *pdv = new double;
        double pdv_max;

        string competence1;
        double degats_comp1;
        string type_comp1;
        int cout_comp1;

        string competence2;
        double degats_comp2;
        string type_comp2;
        int cout_comp2;

        string competence3;
        double degats_comp3;
        string type_comp3;
        int cout_comp3;

        string classe;
        string terrain;

        bool vivant = true;
        bool protecte = false;

    private:
};

#endif // ENTITY_H
