#pragma once
#include "Piece.h"


class Pawn : public Piece {
public:
	Pawn(const char* path, IntRect texRect);
	move_type update(std::vector<Piece*>& pieces, Vector2i newPos);

private:
	void generatePossibleMoves(std::vector<Piece*>& pieces);
};