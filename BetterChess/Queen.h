#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(const char* path, IntRect texRect);
	void generatePossibleMoves(std::vector<Piece*>& pieces);
	move_type update(std::vector<Piece*>& pieces, Vector2i newPos);
};