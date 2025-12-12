#include "cellule.h"
#include "jeu.h"
#include "string"

#pragma region Constructeurs
cellule::cellule() { this->cellsize = 10; }
cellule::cellule(int cellsize) { this->cellsize = cellsize; }

cellule_morte::cellule_morte() { this->cellsize = 10; }
cellule_morte::cellule_morte(int cellsize) { this->cellsize = cellsize; }

cellule_vivante::cellule_vivante() { this->cellsize = 10; }
cellule_vivante::cellule_vivante(int cellsize) { this->cellsize = cellsize; }

cellule_obstacle::cellule_obstacle() { this->cellsize = 10; }
cellule_obstacle::cellule_obstacle(int cellsize) { this->cellsize = cellsize; }

cellule_morte::~cellule_morte() {}
cellule_vivante::~cellule_vivante() {}
cellule_obstacle::~cellule_obstacle() {}
#pragma endregion

#pragma region getters
int cellule::get_cellsize() { return this->cellsize; }
#pragma endregion

#pragma region setters
void cellule::set_cellsize(int cellsize) { this->cellsize = cellsize; }
#pragma endregion

#pragma region méthodes
void cellule::dessin_rectangle(RenderWindow& window, grille current_grid) {
    int x, y;

    window.clear();
    RectangleShape cell(Vector2f(current_grid.get_grille(0, 0)->get_cellsize() - 1.0f, current_grid.get_grille(0, 0)->get_cellsize() - 1.0f));
    for (x = 0; x < current_grid.get_width(); ++x) {
        for (y = 0; y < current_grid.get_height(); ++y) {
            if (current_grid.get_grille(x, y)->is_alive() == 1) {
                cell.setPosition((float)x * current_grid.get_grille(0, 0)->get_cellsize(), (float)y * current_grid.get_grille(0, 0)->get_cellsize());
                int R = x * (255 / current_grid.get_width());
                int Vx = 127 - (x * (127 / current_grid.get_width()));
                int Vy = 127 - (y * (127 / current_grid.get_width()));
                int B = y * (255 / current_grid.get_width());
                cell.setFillColor(Color(R, Vx + Vy, B));
                window.draw(cell);
            }
            else if (current_grid.get_grille(x, y)->is_alive() == 2) {
                cell.setPosition((float)x * current_grid.get_grille(0, 0)->get_cellsize(), (float)y * current_grid.get_grille(0, 0)->get_cellsize());
                cell.setFillColor(sf::Color(255, 0, 0));
                window.draw(cell);
            }
        }
    }
    window.display();
}
#pragma endregion