#pragma once
#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <vector>

class Chessboard {
public:
	void init();
	void draw(RenderWindow& window);
	void update(Event &event, Vector2i mousePos);
private:
	void movePiece(Vector2i mousePos);
	std::vector<Piece*> pieces;
	Board board;
	Texture t;
	
	Vector2i selectedSquare;
	bool isPieceSelected = false;
	int selectedPiece = -1;
};