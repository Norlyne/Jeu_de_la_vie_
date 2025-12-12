#include <ctime>
#include <iostream>
#include <fstream>
#include <fontsub.h>
#include "cellule.h"
#include "grille.h"
#include "jeu.h"
#include "patternes.h"
#include "source.h"

int console()
{
    srand(time(0));

    jeu* jeu;
    jeu = new ModeNormal();

    string nom_Dossier = "";
    string nomFichier = "";

    jeu->demarer(nom_Dossier);

    cout << jeu->get_mode_depart() << endl;
    if (jeu->get_mode_depart() == 1) { delete jeu; jeu = new ModeNormal; }
    else if (jeu->get_mode_depart() == 2) { delete jeu; jeu = new ModeLifeIsShort; }
    else if (jeu->get_mode_depart() == 3) { delete jeu; jeu = new ModeDayAndLight; }
    else if (jeu->get_mode_depart() == 4) { delete jeu; jeu = new labyrinthiques; }
    else if (jeu->get_mode_depart() == 5) { delete jeu; jeu = new ExplosionsAndChaos; }
    else if (jeu->get_mode_depart() == 6) { delete jeu; jeu = new MotifsRepliquants; }
    else if (jeu->get_mode_depart() == 7) { delete jeu; jeu = new HighLife; }
    else if (jeu->get_mode_depart() == 8) { delete jeu; jeu = new Corail; }
    else { return 1; }

    for (int i = 0; i < 5; i++) {

        nomFichier = nom_Dossier + "/iteration" + to_string(i) + ".txt";
        std::ofstream fichier(nomFichier, ios::out);

        for (int dx = 0; dx < jeu->get_current_grid().get_width(); dx++) {
            for (int dy = 0; dy < jeu->get_current_grid().get_height(); dy++) {
                cellule* d = jeu->get_current_grid().get_grille(dx, dy);
                if (d && d->is_alive() == 2) {
                    cout << "O";
                    fichier << 2 << " ";
                }
                if (d && d->is_alive() == 1) {
                    cout << "#";
                    fichier << 1 << " ";
                }
                else {
                    cout << ".";
                    fichier << 0 << " ";
                }
            }
            cout << "\n";
            fichier << endl;
        }
        jeu->regle_base();
        cout << "---------------------------------------------------------------------------------------" << endl;
        fichier.close();
        sleep(milliseconds(1000));


    }

    delete jeu;
    return 0;
}