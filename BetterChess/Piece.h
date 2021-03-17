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

enum class move_type {
	move,
	capture,
	none
};

struct moveType {
	moveType(Vector2i move, move_type type) : move(move), type(type) {};
	Vector2i move;
	move_type type;
};

#include <iostream>
class Piece{
public:
	Piece() = default;
	Piece(const char* path, IntRect texRect);
	virtual move_type update(std::vector<Piece*>& board, Vector2i newPos) = 0;
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);
	move_type checkNewPos(Vector2i newPos);
	void updatePos();

	piece pieceType = piece::empty;
	color_type color;
	Vector2i currentPos;
protected:
	Texture texture;
	RectangleShape sprite;
	std::vector<moveType> possibleMoves;
};