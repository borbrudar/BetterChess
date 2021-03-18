#pragma once
#include "Piece.h"


class Pawn : public Piece {
public:
	Pawn(color_type pieceColor);
	move_type update(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
	bool isPromoted();
private:
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
};