#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(Vector2i square);
	move_type update(std::vector<std::unique_ptr<Piece>> &pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};
