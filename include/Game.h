#pragma once
#include <SFML/Graphics.hpp>
#include "Chessboard.h"
#include "consts.h"

using namespace sf;

class Game {
public:
	Game();
	void run();
private:
	void draw();
	void update();

	Chessboard chessboard;

	RenderWindow window;
	Event event;
	Mouse mouse;
};