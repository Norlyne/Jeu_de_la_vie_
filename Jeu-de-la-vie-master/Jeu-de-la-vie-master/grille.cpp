#include "grille.h"
#include <cstdlib>  
#include <fstream>
using namespace std;


#pragma region Constructeurs
grille::grille() {
    this->width = 100;
    this->height = 100;
    grid.resize(width, std::vector<cellule*>(height, nullptr));

    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            grid[dx][dy] = new cellule_morte();
        }
    }
}

grille::grille(int width, int height) {
    this->width = width;
    this->height = height;
    grid.resize(width, std::vector<cellule*>(height, nullptr));

    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            grid[dx][dy] = new cellule_morte();
        }
    }
}

grille::grille(const grille& g) {
    this->width = g.width;
    this->height = g.height;
    grid.resize(width, std::vector<cellule*>(height, nullptr));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            cellule* c = g.grid[x][y];
            if (c->is_alive() == 2) {
                grid[x][y] = new cellule_obstacle();
            }
            else if (c->is_alive() == 1) {
                grid[x][y] = new cellule_vivante();
            }
            else {
                grid[x][y] = new cellule_morte();
            }
        }
    }
}


grille::~grille() {
    for (int dx = 0; dx < width; dx++) {
        for (int dy = 0; dy < height; dy++) {
            delete grid[dx][dy];
            grid[dx][dy] = nullptr;
        }
    }
}
#pragma endregion

#pragma region getters
int grille::get_width() { return this->width; }
int grille::get_height() { return this->height; }
cellule* grille::get_grille(int x, int y) { return this->grid[x][y]; }
#pragma endregion

#pragma region setters
void grille::set_width(int width) { this->width = width; }
void grille::set_height(int height) { this->height = height; }
void grille::set_grille(int x, int y, int state) {
    x = x % this->width;
    y = y % this->height;
    if (grid[x][y] != nullptr) {
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
    if (state == 1) {
        grid[x][y] = new cellule_vivante();
    }
    else if (state == 0) {
        grid[x][y] = new cellule_morte();
    }
    else {
        grid[x][y] = new cellule_obstacle();
    }
}
#pragma endregion

#pragma region methodes
void grille::random_init() {
    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            int random = rand() % 100;
            if (random >= 50) {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_vivante();
            }
            else if (random < 50) {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_morte();
            }
        }
    }
}

void grille::random_init_obs() {
    for (int dx = 0; dx < this->width; dx++) {
        for (int dy = 0; dy < this->height; dy++) {
            int random = rand() % 100;
            if (random >= 60) {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_vivante();
            }
            else if (random >= 1 && random < 60) {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_morte();
            }
            else {
                if (grid[dx][dy]) delete grid[dx][dy];
                grid[dx][dy] = new cellule_obstacle();
            }
        }
    }
}


void grille::fichier_init(string filename) {
    //ifstream fichier("../../input/" + filename, ios::in);
    ifstream fichier("input/" + filename, ios::in);

    if (fichier)
    {
        string chaine1, chaine2;
        int state;
        fichier >> this->width >> this->height;
        grid.resize(width, std::vector<cellule*>(height, nullptr));

        for (int dx = 0; dx < this->width; dx++) {
            for (int dy = 0; dy < this->height; dy++) {
                fichier >> state;
                if (state == 0) {
                    delete grid[dx][dy];
                    grid[dx][dy] = new cellule_morte();
                }
                else {
                    delete grid[dx][dy];
                    grid[dx][dy] = new cellule_vivante();
                }
            }
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}


int grille::compt_voisin(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // gestion des bords: ignore les voisins hors grille
            if (nx >= 0 && nx < this->width && ny >= 0 && ny < this->height) {
                if (grid[nx][ny]->is_alive() == 1) {
                    count++;
                }
            }
        }
    }
    return count;
};

int grille::compt_voisin_thorique(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // gestion des bords: ignore les voisins hors grille
            if (nx < 0) { nx = this->width - 1; }
            if (ny < 0) { ny = this->height - 1; }
            if (nx > (this->width - 1)) { nx = 0; }
            if (ny > (this->height - 1)) { ny = 0; }

            if (grid[nx][ny]->is_alive() == 1) {
                count++;
            }
        }
    }
    return count;
}
#pragma endregion
