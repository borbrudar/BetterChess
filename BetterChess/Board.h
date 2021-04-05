#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Board {
public:
	void init(const char* path);
	void draw(RenderWindow& window);
	void flip();
private:
	Texture boardT;
	Sprite board;

	int rotation = 90;
};
