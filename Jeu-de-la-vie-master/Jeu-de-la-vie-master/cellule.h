#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

#pragma region initialisationclasses
class grille;
class ModeNormal;
class ModeLifeIsShort;
class ModeDayAndLight;
class labyrinthiques;
class ExplosionsAndChaos;
class MotifsRepliquants;
class HighLife;
class Corail;
#pragma endregion

using namespace std;
using namespace sf;

#pragma region cellule
class cellule
{
protected:
	int cellsize;

public:
	//Constructor
	cellule();
	cellule(int cellsize);
	virtual ~cellule() = default;

	//getters
	int get_cellsize();

	//setters
	void set_cellsize(int cellsize);

	//methodes
	virtual int is_alive() = 0;
	void dessin_rectangle(RenderWindow& window, grille current_grid);
};


#pragma region cellulemorte
class cellule_morte : public cellule {
public:
	//Constructor
	cellule_morte();
	cellule_morte(int cellsize);
	~cellule_morte();


	//methodes
	int is_alive() override { return 0; }


};
#pragma endregion

#pragma region cellulevivante
class cellule_vivante : public cellule {
public:
	//Constructor
	cellule_vivante();
	cellule_vivante(int cellsize);
	~cellule_vivante();

	//methodes
	int is_alive() override { return 1; }


};
#pragma endregion

#pragma region celluleobstacle
class cellule_obstacle : public cellule {
public:
	//Constructor
	cellule_obstacle();
	cellule_obstacle(int cellsize);
	~cellule_obstacle();


	//methodes
	int is_alive() override { return 2; }


};
#pragma endregion

#pragma endregion