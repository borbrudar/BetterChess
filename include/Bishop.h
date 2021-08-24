#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	Bishop(color_type pieceColor);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};