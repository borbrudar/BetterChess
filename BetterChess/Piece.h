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

#include <iostream>
class Piece{
public:
	Piece() = default;
	Piece(const char* path, IntRect texRect);
	virtual void update(std::vector<Piece*>& board, Vector2i newPos) {
		std::cout << "base" << std::endl;
	};
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