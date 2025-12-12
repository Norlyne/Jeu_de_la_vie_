#pragma once
#include "grille.h"

#pragma region pattern
class pattern {
protected:
    int x;
    int y;
    int x2;
    int y2;

public:
    //contructor
    pattern();
    pattern(int x, int y, cellule* cell);

    //getters
    int get_x();
    int get_y();
    int get_x2();
    int get_y2();

    //setters
    void set_x(int x);
    void set_y(int y);
    void set_x2(int x2);
    void set_y2(int y2);

    //methodes
    virtual void poser(int x, int y, grille& current_grid) = 0;
    void random(grille& current_grid);
    void random_obs(grille& current_grid);
    void reset(grille& current_grid);
};
#pragma endregion

#pragma region point
class point : public pattern {
public:
    point();
    point(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 1);
    }
};
#pragma endregion

#pragma region stable1
class stable1 : public pattern {
public:
    stable1();
    stable1(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
            "##",
            "##",
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }
    }
};
#pragma endregion

#pragma region stable2
class stable2 : public pattern {
public:
    stable2();
    stable2(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
            ".##.",
            "#..#",
            ".##.",
            "....",
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }
    }
};
#pragma endregion

#pragma region glider
class glider : public pattern {
public:
    glider();
    glider(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
            ".#.",
            "..#",
            "###",
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }
    }
};
#pragma endregion

#pragma region oscillateur1
class oscilateur1 : public pattern {
public:
    oscilateur1();
    oscilateur1(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
            "...",
            "###",
            "...",
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }
    }
};
#pragma endregion

#pragma region oscillateur2
class oscilateur2 : public pattern {
public:
    oscilateur2();
    oscilateur2(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
            "....",
            "###.",
            ".###",
            "....",
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }
    }
};
#pragma endregion

#pragma region canonglider
class canon_glider : public pattern {
public:
    canon_glider();
    canon_glider(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        std::vector<std::string> grid = {
        "........................#...............",
        "......................#.#...............",
        "............##......##............##....",
        "...........#...#....##............##....",
        "##........#.....#...##..................",
        "##........#...#.##....#.#...............",
        "..........#.....#.......#...............",
        "...........#...#........................",
        "............##.........................."
        };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') current_grid.set_grille(this->x2 + j, this->y2 + i, 1);
            }
        }

    }
};

class obstacle : public pattern {
public:
    obstacle();
    obstacle(int x, int y, cellule* cell);

    void poser(int x, int y, grille& current_grid) override {
        current_grid.set_grille(x2, y2, 2);
    }
};
#pragma endregion