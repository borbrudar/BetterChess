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

enum class color_type {
	white,
	black
};


class Piece{
public:
	Piece() = default;
	Piece(const char* path, IntRect texRect);
	void update(std::vector<Piece>& board, Vector2i mousePos) {};
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);
	void updatePos();

	piece pieceType = piece::empty;
	color_type color;
	Vector2i currentPos;
private:
	Texture texture;
	RectangleShape sprite;
};