#include "Rook.h"
#include <iostream>

Rook::Rook(const char* path, IntRect texRect)
{
	pieceType = piece::rook;
	init(path, texRect);
}

void Rook::update(std::vector<Piece*> &board, Vector2i newPos)
{
	std::cout << "derived" << std::endl;
	if (newPos.x < 0 || newPos.x > 7 || newPos.y < 0 || newPos.y > 7) return;
	
	if ((newPos.x != currentPos.x) && ( newPos.y != currentPos.y)) return;

	for (int i = 0; i < board.size(); i++) {
		if (board[i]->currentPos == newPos && board[i]->color == color) return;
	}


	currentPos = newPos;
	updatePos();
}
