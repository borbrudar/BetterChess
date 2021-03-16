#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Board {
public:
	Board();
	void draw(RenderWindow& window);

	Texture boardT;
	Sprite board;
};
