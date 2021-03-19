#pragma once
#include "Piece.h"


class Knight : public Piece {
public:
	Knight(color_type pieceColor);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};