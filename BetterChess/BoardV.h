#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class BoardV {
public:
	void init(const char* path);
	void draw(RenderWindow& window);
private:
	Texture boardT;
	Sprite board;

	int rotation = 90;
};
