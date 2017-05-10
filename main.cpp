#include <iostream>
#include "Magicien.h"
#include "Guerrier.h"
#include "Archer.h"
#include "Gobelin.h"
#include "Dragon.h"
#include "Orc.h"
#include "carte.h"
#include <stdlib.h>
#include <ctime>
#include <limits>

using namespace std;

bool read_choice(int &N);

int main()
{
    int choix, tour = 0, nbCombat = 0;
    string terrainAssocie;
    string pause;

    Personnage *Joueur;
    Mobs *Ennemi;



    cout << "---------------------------------- Choississez une classe ----------------------------------"  << endl << endl;
    cout << "1. Magicien - Peut se soigner et degats de type GLACE" << endl;
    cout << "2. Guerrier - Peut se proteger et degats de type FEU" << endl;
    cout << "3. Archer - Peut se proteger et degats de type ELECTRIQUE" << endl << endl;
    cout << "Choix : ";

    while(!read_choice(choix))
        {}


    switch(choix)
    {
        case 1: Joueur = new Magicien;
        break;

        case 2: Joueur = new Guerrier;
        break;

        case 3: Joueur = new Archer;
        break;
    }



    cout << endl << "---------------------------------- Choississez un type de terrain ----------------------------------" << endl << endl;
    cout << "1. ENFER (+20% degats FEU)" << endl;
    cout << "2. BANQUISE (+20% degats GLACE)" << endl;
    cout << "3. ORAGE (+20% degats ELECTRIQUE)" << endl << endl;
    cout << "Choix : ";

    while(!read_choice(choix))
        {}


    switch(choix)
    {
        case 1: terrainAssocie = "ENFER";
        break;

        case 2: terrainAssocie = "BANQUISE";
        break;

        case 3: terrainAssocie = "ORAGE";
        break;

    }

    Joueur->typeTerrain(terrainAssocie);

    Carte plateau;
    cout << endl;
	int i = 0;
	char mouvement;
	bool combat = false;

    while(Joueur->cibleVivante() && plateau.nbMonstres > 0)
    {
        do
        {

            plateau.afficher();
            cout << "où aller ?" << endl;
            cin >> mouvement;
            combat = plateau.seDeplacer(mouvement);

            #ifdef __linux__
                system("clear");
            #elif _WIN32
                system("cls");
            #endif

            i++;
        }while(!combat);

        nbCombat++;

        if(plateau.nbMonstres == 0)
            Ennemi = new Dragon;

        else if(nbCombat <= 2 && plateau.nbMonstres != 1)
            Ennemi = new Gobelin;

        else
            Ennemi = new Orc;


        Ennemi->typeTerrain(terrainAssocie);

        tour = 0;
        Joueur->reset();

        cout << "Vous venez d'entrer en combat contre un  " << Ennemi->getClasse() << " !" << endl;

        do
        {
            tour++;
            cout << endl;

            #ifdef __linux__
                cout << "Pressez une touche puis ENTREE pour continuer... ";
                cin >> pause;
                system("clear");
            #elif _WIN32
                system("pause");
                system("cls");
            #endif


            cout << endl << endl << "---------------------------------- Tour " << tour << " ----------------------------------" << endl << endl;
            Joueur->regenAuto(tour);
            Ennemi->regenAuto(tour);

            Joueur->Etat();
            Ennemi->Etat();

            cout << endl << endl << "----------------- Combat -----------------" << endl;

            Joueur->Hub();

            while(!read_choice(choix))
                {}

            cout << endl;

            Joueur->attaque(Ennemi, choix);

            cout << endl;

            if(Ennemi->cibleVivante() && Joueur->cibleVivante())
            {
                Ennemi->IA(tour, Joueur);

                cout << endl << endl << "------ Bilan Fin De Tour ------" << endl;

                Joueur->Etat();
                Ennemi->Etat();
            }

            if(!Ennemi->cibleVivante())
            {
                cout << endl << Ennemi->getClasse() << " est K.O. !" << endl << endl;

                #ifdef __linux__
                    cout << "Pressez une touche puis ENTREE pour continuer... ";
                    cin >> pause;
                #elif _WIN32
                    system("pause");
                #endif
            }

        }while(Ennemi->cibleVivante() && Joueur->cibleVivante());

        delete Ennemi;
    }

    if(Joueur->cibleVivante())
        cout << endl << "---------------------------------- Bravo tu as gagné, tu a tué touts les monstres ! ---------------------------------- " << endl << endl;

    else
        cout << endl << Joueur->getClasse() << " est K.O. !" << endl << endl << "---------------------------------- GAME OVER ! ----------------------------------" << endl << endl;

    return 0;
}

bool read_choice(int &N)
{
    while (!(cin >> N) || N < 1 || N > 3 )
    {
        if ( cin.eof() )
            return false;

        else if (cin.fail())
        {
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
        }
    }
    return true; // succès
}

