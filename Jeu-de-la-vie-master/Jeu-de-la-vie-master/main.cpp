#include <ctime>
#include <iostream>
#include <fstream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"
#include "source.h"

int jeu::indexe = 4;
string jeu::mode_depart = "1";
grille jeu::current_grid = grille();
grille jeu::next_grid = grille();

int main()
{
    string demarage;
    while (demarage != "1" || demarage != "2" || demarage != "3") {
        cout << "Quel mode de demarrage ?" << endl;
        cout << "1." << "Console" << endl;
        cout << "2." << "Test unitaire" << endl;
        cout << "3." << "Window" << endl;
        cin >> demarage;
        if (demarage == "1") {
            console();
            break;
        }
        else if (demarage == "2") {
            test();
            break;
        }
        else if (demarage == "3") {
            window();
            break;
        }
        else {
            cout << "Ce mode de demarrage n'existe pas" << endl;
        }
    }

    return 0;
}