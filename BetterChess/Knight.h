#pragma once
#include "Piece.h"

struct knight_struct {
	knight_struct(bool good) : good(good) {};
	knight_struct(bool good, move_type type) :good(good), type(type) {};
	bool good;
	move_type type;
};

class Knight : public Piece {
public:
	Knight(const char* path, IntRect texRect);
	move_type update(std::vector<Piece*>& board, Vector2i newPos);
private:
	void generatePossibleMoves(std::vector<Piece*>& pieces);
	knight_struct checkIfNewPosOk(Vector2i pos, std::vector<Piece*> &pieces);
};