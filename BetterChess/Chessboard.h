#pragma once
#include "Piece.h"
#include "BoardV.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "PromotionMenu.h"
#include "Board.h"
#include <vector>

class Chessboard {
public:
	void init();
	void draw(RenderWindow& window);
	void update(Event &event, Vector2i mousePos);
private:
	void movePiece(Vector2i mousePos);
	void checkPromotion(int promoted);
	std::vector<Piece::ptr> pieces;
	BoardV background;
	Texture t;
	
	Board *board;

	PromotionMenu menu;
	Vector2i selectedSquare;
	bool isPieceSelected = false;
	int selectedPiece = -1;
	const char* path = "res/chess-pieces.png";
};