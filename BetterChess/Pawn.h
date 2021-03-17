#pragma once
#include "Piece.h"


class Pawn : public Piece {
public:
	Pawn(const char* path, IntRect texRect);
	move_type update(std::vector<Piece*>& pieces, Vector2i newPos);
	bool hasMoved = false;
private:
	void generatePossibleMoves(std::vector<Piece*>& pieces);
	// -1 white, 1 black
	int captureDirection = -1;
};