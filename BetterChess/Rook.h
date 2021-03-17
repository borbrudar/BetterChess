#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(const char* path, IntRect texRect);
	move_type update(std::vector<Piece*> &pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<Piece*>& pieces);
};
