#pragma once
#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <vector>

class Chessboard {
public:
	Chessboard();
	void draw(RenderWindow& window);
	void update(Event &event, Vector2i mousePos);
private:
	std::vector<piece> chessboard;
	Board board;
	Rook rook;
};