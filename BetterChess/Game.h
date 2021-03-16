#pragma once
#include <SFML/Graphics.hpp>
#include "Chessboard.h"

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
	const int SCR_WIDTH = 600, SCR_HEIGHT = SCR_WIDTH ;
};