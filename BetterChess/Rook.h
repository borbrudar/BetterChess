#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook() = default;
	Rook(const char* path, IntRect texRect);
	void generatePossibleMoves(std::vector<Piece*>& pieces);
	move_type update(std::vector<Piece*> &pieces, Vector2i newPos);
	bool checkLine(int& posx, int& posy, std::vector<Piece*> pieces);
};
