#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(color_type pieceColor);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};
