#pragma once
#include "Piece.h"


class Pawn : public Piece {
public:
	Pawn(color_type pieceColor);
	bool isPromoted();
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
	move_type lastMove;
};