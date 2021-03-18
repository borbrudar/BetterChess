#include "Rook.h"
#include <iostream>

Rook::Rook(Vector2i square)
{
	pieceType = piece::rook;
	init(square);
}

void Rook::generatePossibleMoves(std::vector<std::unique_ptr<Piece>>& pieces)
{
	possibleMoves.clear();
	for (int i = currentPos.x + 1; i < squareNumber; i++) {
		if (checkLine(i, currentPos.y, pieces)) break;
	}
	for (int i = currentPos.x - 1; i >= 0; i--) {
		if (checkLine(i, currentPos.y, pieces)) break;
	}
	for (int i = currentPos.y + 1; i < squareNumber; i++) {
		if (checkLine(currentPos.x, i, pieces)) break;
	}
	for (int i = currentPos.y - 1; i >= 0; i--) {
		if (checkLine(currentPos.x, i, pieces)) break;
	}
}

move_type Rook::update(std::vector< std::unique_ptr<Piece>>& pieces, Vector2i newPos)
{	
	generatePossibleMoves(pieces);
	return checkNewPos(newPos);
}

