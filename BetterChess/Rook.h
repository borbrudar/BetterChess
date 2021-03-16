#pragma once
#include "Piece.h"


class Rook : public Piece {
public:
	Rook();
	void update(std::vector<piece> board, Vector2i newPos);
};
