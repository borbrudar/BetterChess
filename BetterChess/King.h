#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(IntRect texRect);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};