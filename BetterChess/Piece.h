#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class color {
	white,
	black
};

class Piece {
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);

	color color;
	Texture texture;
	Sprite sprite;
};