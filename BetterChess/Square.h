#pragma once
#include "consts.h"

struct Square {
	Square() = default;
	Square(bool out) : outOfBounds(out) {};
	Square(piece type, color_type color) : pieceType(type), color(color) { };

	piece pieceType = piece::empty;
	color_type color = color_type::none;
	bool outOfBounds = false;
};