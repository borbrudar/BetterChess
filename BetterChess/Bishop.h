#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	Bishop(IntRect texRect);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};