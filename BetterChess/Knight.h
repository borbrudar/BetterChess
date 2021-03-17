#pragma once
#include "Piece.h"


class Knight : public Piece {
public:
	Knight(const char* path, IntRect texRect);
	move_type update(std::vector<Piece*>& board, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<Piece*>& pieces);
};