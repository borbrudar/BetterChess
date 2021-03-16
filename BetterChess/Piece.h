#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"
using namespace sf;

enum class piece {
	rook,
	knight,
	bishop,
	king,
	queen,
	pawn,
	empty
};

enum class color {
	white,
	black
};

class Piece {
public:
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);

	color color;
	piece pieceType;
	Vector2i currentPos;
private:
	Texture texture;
	RectangleShape sprite;
};