#include <ctime>
#include <iostream>
#include <fstream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"
#include "source.h"

using namespace std;
using namespace sf;


////////////////////////////////////////////////////////////////////////////////////////
//                                  Test unitaire                                     //
////////////////////////////////////////////////////////////////////////////////////////
string test1()
{
    grille test;
    test.fichier_init("test1.txt");

    jeu* jeu;
    jeu = new ModeNormal();

    jeu->get_current_grid().fichier_init("test1.txt");
    jeu->get_next_grid().fichier_init("test1.txt");

    for (int i = 0; i < 6; i++) {
        jeu->regle_base();
        sf::sleep(milliseconds(500));
    }
    for (int dx = 0; dx < jeu->get_current_grid().get_width(); dx++) {
        for (int dy = 0; dy < jeu->get_current_grid().get_height(); dy++) {
            cellule* d = jeu->get_current_grid().get_grille(dx, dy);
            cellule* c = test.get_grille(dx, dy);
            if (d->is_alive() == c->is_alive()) {
                return "le test est concluant";
            }
            else {
                return "Erreur :  le test n'est pas concluant";
            }
        }
    }
};

string test2()
{
    grille test;
    test.fichier_init("test2.txt");

    jeu* jeu;
    jeu = new ModeNormal();

    jeu->get_current_grid().fichier_init("test2.txt");
    jeu->get_next_grid().fichier_init("test2.txt");

    for (int i = 0; i < 3; i++) {
        jeu->regle_base();
        sf::sleep(milliseconds(500));
    }
    for (int dx = 0; dx < jeu->get_current_grid().get_width(); dx++) {
        for (int dy = 0; dy < jeu->get_current_grid().get_height(); dy++) {
            cellule* d = jeu->get_current_grid().get_grille(dx, dy);
            cellule* c = test.get_grille(dx, dy);
            if (d->is_alive() == c->is_alive()) {
                return "le test a marche";
            }
            else {
                return "Erreur :  le test n'est pas fluctuant";
            }
        }
    }
};

string test3()
{
    grille test;
    test.fichier_init("test3.txt");

    jeu* jeu;
    jeu = new ModeNormal();

    jeu->get_current_grid().fichier_init("depart.txt");
    jeu->get_next_grid().fichier_init("depart.txt");

    for (int i = 0; i < 4; i++) {
        jeu->regle_base();
        sf::sleep(milliseconds(500));
    }
    for (int dx = 0; dx < jeu->get_current_grid().get_width(); dx++) {
        for (int dy = 0; dy < jeu->get_current_grid().get_height(); dy++) {
            cellule* d = jeu->get_current_grid().get_grille(dx, dy);
            cellule* c = test.get_grille(dx, dy);
            if (d->is_alive() == c->is_alive()) {
                return "le test a marche";
            }
            else {
                return "Erreur :  le test n'est pas fluctuant";
            }
        }
    }
    delete jeu;
};

int test() {
    string rep1;
    string rep2;
    string rep3;

    rep1 = test1();
    rep2 = test2();
    rep3 = test3();

    cout << rep1 << endl;
    cout << rep2 << endl;
    cout << rep3 << endl;
    return 0;
}