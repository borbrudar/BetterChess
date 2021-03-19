#pragma once
#include "Piece.h"

enum class check {
	check, 
	not_check,
	empty
};

class King : public Piece {
public:
	King(color_type pieceColor);
	bool isChecked(std::vector<std::unique_ptr<Piece>>& pieces, Vector2i newPos);
	void generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces);
	check checkLine(int& posx, int& posy, std::vector<std::unique_ptr<Piece>>& pieces, bool diag = 0);
	bool helper(Vector2i check, int &inc);
	bool knightsCheck(std::vector<std::unique_ptr<Piece>>& pieces,Vector2i newPos);
};