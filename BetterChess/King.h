#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(color_type pieceColor);
	bool isChecked(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};