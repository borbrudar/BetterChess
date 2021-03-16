#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace sf;

class Game {
public:
	Game();
	void run();
private:
	void draw();
	void update();

	Board board;

	RenderWindow window;
	Event event;
	const int SCR_WIDTH = 600, SCR_HEIGHT = SCR_WIDTH ;
};