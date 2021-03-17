#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"
#include <iostream>
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
	none,
	passant,
	twice
};

struct moveType {
	moveType(Vector2i move, move_type type) : move(move), type(type) {};
	Vector2i move;
	move_type type;
};

struct check_struct {
	check_struct(bool good) : good(good) {};
	check_struct(bool good, move_type type) :good(good), type(type) {};
	bool good;
	move_type type;
};

class Piece{
public:
	Piece() = default;
	Piece(const char* path, IntRect texRect);
	virtual move_type update(std::vector<Piece*>& board, Vector2i newPos) = 0;
	void init(const char* path, IntRect texRect);
	void draw(RenderWindow& window);
	void updatePos();
	void resetPassant();


	bool hasMoved = false;
	piece pieceType = piece::empty;
	color_type color;
	Vector2i currentPos;
	//for pawns
	bool enPassant = false;
	int captureDirection = -1; // -1 white, 1 black
protected:
	move_type checkNewPos(Vector2i newPos);
	bool checkLine(int& posx, int& posy, std::vector<Piece*> pieces);
	check_struct checkIfNewPosOk(Vector2i pos, std::vector<Piece*>& pieces);

	Texture texture;
	RectangleShape sprite;
	std::vector<moveType> possibleMoves;

};