#pragma once
#include "consts.h"

struct Square {
	Square() = default;
	Square(piece type, color_type color) : pieceType(type), color(color) { };

	piece pieceType = piece::empty;
	color_type color = color_type::none;
};