#pragma once
#include "cellule.h"
#include "grille.h"
#include <direct.h>
#include <filesystem>

#pragma region Jeu

class jeu {
private:
protected:
    const int attente[6] = { 2000, 1000, 500, 200, 100, 50 };
    static int indexe;
    static string mode_depart;
    static grille current_grid;
    static grille next_grid;

public:

    //Constructeurs
    jeu();
    jeu(grille current_grid, grille next_grid, int ind);
    virtual ~jeu() {}

    //getters
    int get_attente();
    int get_indexe();
    grille& get_current_grid();
    grille& get_next_grid();
    int get_mode_depart();

    //setters
    void set_indexe(bool variation);
    void set_current_grid(grille current_grid);
    void set_next_grid(grille next_grid);
    void set_mode_depart(string mode_depart);

    void demarer(string& nom_Dossier);
    void touche();

    virtual void regle_base() = 0;
};

#pragma endregion

#pragma region Mode

#pragma region ModeNormal

class ModeNormal : public jeu {
public:
    ModeNormal();
    ModeNormal(int ind);
    ~ModeNormal() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n < 2 || n > 3) {
                        this->next_grid.set_grille(x, y, 0);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 1);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ModeLifeIsShort

class ModeLifeIsShort : public jeu {
public:
    ModeLifeIsShort();
    ModeLifeIsShort(int ind);
    ~ModeLifeIsShort() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    this->next_grid.set_grille(x, y, 0);
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 2) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ModeDayAndLight

class ModeDayAndLight : public jeu {
public:
    ModeDayAndLight();
    ModeDayAndLight(int ind);
    ~ModeDayAndLight() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 3 || n == 4 || n == 6 || n == 7 || n == 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3 || n == 6 || n == 7 || n == 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region labyrinthiques

class labyrinthiques : public jeu {
public:
    labyrinthiques();
    labyrinthiques(int ind);
    ~labyrinthiques() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 2 || n == 3 || n == 4 || n == 5) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region ExplosionsAndChaos

class ExplosionsAndChaos : public jeu {
public:
    ExplosionsAndChaos();
    ExplosionsAndChaos(int ind);
    ~ExplosionsAndChaos() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    this->next_grid.set_grille(x, y, 0);
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 2) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region MotifsRepliquants

class MotifsRepliquants : public jeu {
public:
    MotifsRepliquants();
    MotifsRepliquants(int ind);
    ~MotifsRepliquants() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 1 || n == 3 || n == 5 || n == 7) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region HighLife

class HighLife : public jeu {
public:
    HighLife();
    HighLife(int ind);
    ~HighLife() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n == 2 || n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3 || n == 6) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma region Corail

class Corail : public jeu {
public:
    Corail();
    Corail(int ind);
    ~Corail() override {}

    void regle_base() override {
        for (int x = 0; x < this->current_grid.get_width(); ++x) {
            for (int y = 0; y < this->current_grid.get_height(); ++y) {
                int n = this->current_grid.compt_voisin_thorique(x, y);
                if (this->current_grid.get_grille(x, y)->is_alive() == 1) {
                    if (n >= 4 || n <= 8) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else if (this->current_grid.get_grille(x, y)->is_alive() == 0) {
                    if (n == 3) {
                        this->next_grid.set_grille(x, y, 1);
                    }
                    else {
                        this->next_grid.set_grille(x, y, 0);
                    }
                }
                else {
                    this->next_grid.set_grille(x, y, 2);
                }
            }
        }
        for (int dx = 0; dx < this->next_grid.get_width(); dx++) {
            for (int dy = 0; dy < this->next_grid.get_height(); dy++) {
                if (this->next_grid.get_grille(dx, dy)->is_alive() == 1) {
                    this->current_grid.set_grille(dx, dy, 1);
                }
                else if (this->next_grid.get_grille(dx, dy)->is_alive() == 0) {
                    this->current_grid.set_grille(dx, dy, 0);
                }
                else {
                    this->current_grid.set_grille(dx, dy, 2);
                }
            }
        }
    }
};

#pragma endregion

#pragma endregion
