#pragma once
#include "Piece.h"


class Knight : public Piece {
public:
	Knight( IntRect texRect);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};