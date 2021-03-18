#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	Bishop(Vector2i square);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};