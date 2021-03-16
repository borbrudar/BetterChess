#pragma once
#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <vector>

class Chessboard {
public:
	Chessboard();
	void draw(RenderWindow& window);
private:
	Board board;
};