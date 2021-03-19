#include "Rook.h"
#include <iostream>

Rook::Rook(color_type pieceColor)
{
	pieceType = piece::rook;
	init(pieceColor);
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
