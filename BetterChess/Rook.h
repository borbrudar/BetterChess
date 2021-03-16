#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook() = default;
	Rook(const char* path, IntRect texRect);
	void update(std::vector<Piece*> &board, Vector2i newPos);
};
