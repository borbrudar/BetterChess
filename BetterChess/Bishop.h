#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	Bishop(color_type pieceColor);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};