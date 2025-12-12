#include "patternes.h"
#include "grille.h"
#include "cellule.h"


#pragma region constructeurs
pattern::pattern() {
	this->x = 0;
	this->y = 0;
	this->x2 = 0;
	this->y2 = 0;
}

pattern::pattern(int x, int y, cellule* cell) {
	this->x = x;
	this->y = y;
	this->x2 = this->x / cell->get_cellsize();
	this->y2 = this->y / cell->get_cellsize();
}

point::point() {}
stable1::stable1() {}
stable2::stable2() {}
glider::glider() {}
oscilateur1::oscilateur1() {}
oscilateur2::oscilateur2() {}
canon_glider::canon_glider() {}
obstacle::obstacle() {}

point::point(int x, int y, cellule* cell) {}
stable1::stable1(int x, int y, cellule* cell) {}
stable2::stable2(int x, int y, cellule* cell) {}
glider::glider(int x, int y, cellule* cell) {}
oscilateur1::oscilateur1(int x, int y, cellule* cell) {}
oscilateur2::oscilateur2(int x, int y, cellule* cell) {}
canon_glider::canon_glider(int x, int y, cellule* cell) {}
obstacle::obstacle(int x, int y, cellule* cell) {}
#pragma endregion

#pragma region getters
int pattern::get_x() { return x; }
int pattern::get_y() { return y; }
int pattern::get_x2() { return x2; }
int pattern::get_y2() { return y2; }
#pragma endregion

#pragma region setters
void pattern::set_x(int x) { this->x = x; }
void pattern::set_y(int y) { this->y = y; }
void pattern::set_x2(int x2) { this->x2 = x2; }
void pattern::set_y2(int y2) { this->y2 = y2; }
#pragma endregion

#pragma region methodes
void pattern::random(grille& current_grid) {
	current_grid.random_init();
}

void pattern::random_obs(grille& current_grid) {
	current_grid.random_init_obs();
}

void pattern::reset(grille& current_grid) {
	for (int dx = 0; dx < current_grid.get_width(); dx++) {
		for (int dy = 0; dy < current_grid.get_height(); dy++) {
			current_grid.set_grille(dx, dy, 0);
		}
	}
}
#pragma endregion