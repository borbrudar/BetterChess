#pragma once
#include "Piece.h"


class Knight : public Piece {
public:
	Knight(color_type pieceColor);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};