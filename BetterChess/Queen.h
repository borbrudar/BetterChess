#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(color_type pieceColor);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
	move_type update(std::vector< std::unique_ptr<Piece>>& pieces, Vector2i newPos);
};