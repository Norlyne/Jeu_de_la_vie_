#pragma once
#include <vector>
#include <iostream>
#include "cellule.h"

#pragma region grille
class grille
{
private:
    int width;
    int height;
    std::vector<std::vector<cellule*>> grid;

public:
    //Constructors
    grille();
    grille(int width, int height);
    grille(const grille& g);
    ~grille();  // destructeur pour delete les cellules

    //getters
    int get_width();
    int get_height();
    cellule* get_grille(int x, int y);

    //setters
    void set_width(int width);
    void set_height(int height);
    void set_grille(int x, int y, int state);

    //Methodes
    void random_init();
    void random_init_obs();
    void fichier_init(string filename);
    int compt_voisin(int x, int y);
    int compt_voisin_thorique(int x, int y);
};
#pragma endregion