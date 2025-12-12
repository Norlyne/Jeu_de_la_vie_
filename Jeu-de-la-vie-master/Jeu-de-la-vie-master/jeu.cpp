#include "jeu.h"


#pragma region Constructeur
jeu::jeu() {
    this->indexe = 4;
    this->mode_depart = "1";
}

jeu::jeu(grille current_grid, grille next_grid, int ind) {
    this->indexe = ind;
    this->mode_depart = "1";
    this->current_grid = current_grid;
    this->next_grid = next_grid;
}

ModeNormal::ModeNormal() {}
ModeLifeIsShort::ModeLifeIsShort() {}
ModeDayAndLight::ModeDayAndLight() {}
labyrinthiques::labyrinthiques() {}
ExplosionsAndChaos::ExplosionsAndChaos() {}
MotifsRepliquants::MotifsRepliquants() {}
HighLife::HighLife() {}
Corail::Corail() {}

ModeNormal::ModeNormal(int ind) { this->indexe = ind; }
ModeLifeIsShort::ModeLifeIsShort(int ind) { this->indexe = ind; }
ModeDayAndLight::ModeDayAndLight(int ind) { this->indexe = ind; }
labyrinthiques::labyrinthiques(int ind) { this->indexe = ind; }
ExplosionsAndChaos::ExplosionsAndChaos(int ind) { this->indexe = ind; }
MotifsRepliquants::MotifsRepliquants(int ind) { this->indexe = ind; }
HighLife::HighLife(int ind) { this->indexe = ind; }
Corail::Corail(int ind) { this->indexe = ind; }
#pragma endregion

#pragma region getters
int jeu::get_attente() { return this->attente[this->indexe]; }
int jeu::get_indexe() { return this->indexe; }
grille& jeu::get_current_grid() { return this->current_grid; }
grille& jeu::get_next_grid() { return this->next_grid; }
int jeu::get_mode_depart() { return std::stoi(this->mode_depart); }
#pragma endregion

#pragma region setters
void jeu::set_indexe(bool variation) {
    if (variation) {
        if (this->indexe == (sizeof(attente) / sizeof(attente[0]))) {}
        else { this->indexe++; }

    }
    else {
        if (this->indexe == 0) {}
        else { this->indexe--; }
    }
}

void jeu::set_current_grid(grille current_grid) { this->current_grid = current_grid; }
void jeu::set_next_grid(grille next_grid) { this->next_grid = next_grid; }
void jeu::set_mode_depart(string mode_depart) { this->mode_depart = mode_depart; }
#pragma endregion

#pragma region demarrage
void jeu::demarer(string& nom_Dossier) {
    string rep;
    cout << "Avez-vous un fichier ? (o/n) " << endl;
    cin >> rep;
    if (rep == "o") {
        string fic;
        cout << "Quel est sont nom ? (.txt)" << endl;
        cin >> fic;
        //nom_Dossier = "../../output/" + fic.substr(0, fic.length() - 4) + "_out";
        nom_Dossier = "output/" + fic.substr(0, fic.length() - 4) + "_out";
        int retour = _mkdir(nom_Dossier.c_str());
        this->current_grid.fichier_init(fic);
        this->next_grid.fichier_init(fic);
    }
    else if (rep == "n") {
        //nom_Dossier = "../../output/default";
        nom_Dossier = "output/default";
        string pattern_depart;
        cout << "Voici une liste de blinkers disponible : " << endl;
        cout << "1." << "Glidres" << endl;
        cout << "2." << "vide" << endl;
        cout << "3." << "lab ( teste du mode labirinthe ) " << endl;
        cout << "4." << "expetchaos ( teste du mode exp et chaos ) " << endl;
        cout << "5." << "Motrep ( teste du mode Motifs repetion ) " << endl;
        cout << "Soutaitez-vous un grille alleatoire ou une grilles avec des blikers ? (a/1)" << endl;
        cin >> pattern_depart;
        if (pattern_depart == "a") {
            string obs;
            cout << "Soutaitez-vous des obstacles dans la grille ? (o/n) " << endl;
            cin >> obs;
            cout << "Voici une liste de mode disponible : " << endl;
            cout << "1." << "normal" << endl;
            cout << "2." << "Life is short ( attention pour les epileptiques)" << endl;
            cout << "3." << "Day and light" << endl;
            cout << "4." << "Labyrinthiques" << endl;
            cout << "5." << "Explosions And Chaos" << endl;
            cout << "6." << "Motifs Repliquants" << endl;
            cout << "7." << "HighLife" << endl;
            cout << "8." << "Corail" << endl;
            cout << "Quel mode de jeu souhaitez-vous ?" << endl;
            cin >> this->mode_depart;
            if (mode_depart != "1" && mode_depart != "2" && mode_depart != "3" && mode_depart != "4" && mode_depart != "5" && mode_depart != "6" && mode_depart != "7" && mode_depart != "8") { cout << "Erreur : mauvaise reponse" << endl; }
            if (obs == "o") {
                this->current_grid.random_init_obs();
                this->next_grid.random_init_obs();
            }
            else if (obs == "n") {
                this->current_grid.random_init();
                this->next_grid.random_init();
            }
            else {
                cout << "Erreur : mauvaise reponse" << endl;
            }
        }
        else if (pattern_depart == "1") {
            this->current_grid.fichier_init("Gliders.txt");
            this->next_grid.fichier_init("Gliders.txt");
        }
        else if (pattern_depart == "2") {
            this->current_grid.fichier_init("vide.txt");
            this->next_grid.fichier_init("vide.txt");
        }
        else if (pattern_depart == "3") {
            this->mode_depart = "4";
            this->current_grid.fichier_init("lab.txt");
            this->next_grid.fichier_init("lab.txt");
        }
        else if (pattern_depart == "4") {
            this->mode_depart = "5";
            this->current_grid.fichier_init("expetchaos.txt");
            this->next_grid.fichier_init("expetchaos.txt");
        }
        else if (pattern_depart == "5") {
            this->mode_depart = "6";
            this->current_grid.fichier_init("Motrep.txt");
            this->next_grid.fichier_init("Motrep.txt");
        }
        else {
            cout << "Erreur : mauvaise reponse" << endl;
        }
    }
    else {
        cout << "Erreur : mauvaise reponse" << endl;
    }
};
#pragma endregion

#pragma region affichagetouche
void jeu::touche() {
    cout << "-----------------------------------------------" << endl;
    cout << "                Options & Mode                    " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << " Espace : Pause" << endl;
    cout << " A : Grille aleatoire" << endl;
    cout << " O : Grille aleatoire avec obstacle" << endl;
    cout << " R : Reset" << endl;
    cout << " <- : reduis la vitesse d'iteration " << endl;
    cout << " -> : augmente la vitesse d'iteration " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << " N : Mode Normal" << endl;
    cout << " S : Mode Life is short" << endl;
    cout << " D : Mode Day and light" << endl;
    cout << " L : Mode Labyrinthiques" << endl;
    cout << " E : Mode Explosions and chaos" << endl;
    cout << " M : Mode Motifs repliquants" << endl;
    cout << " H : Mode High life" << endl;
    cout << " C : Mode Corail" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "               Poser des Patternes             " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << " 0+Click gauche : une cellule obsacle " << endl;
    cout << " 1+Click gauche : une cellule " << endl;
    cout << " 2+Click gauche : un carre " << endl;
    cout << " 3+Click gauche : un rectangle " << endl;
    cout << " 4+Click gauche : un glider " << endl;
    cout << " 5+Click gauche : un ocsillateur 1" << endl;
    cout << " 6+Click gauche : un ocsillateur 2" << endl;
    cout << " 7+Click gauche : un canon un gliders" << endl;
}
#pragma endregion
